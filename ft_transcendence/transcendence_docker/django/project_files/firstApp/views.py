from django.shortcuts import render, redirect, HttpResponse

from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, login, logout
from django.http import JsonResponse
from django.contrib.auth.decorators import login_required
from django.contrib.auth.hashers import check_password, make_password
from django.views.decorators.csrf import csrf_exempt
import json  #
import re
from .models import Profile, MatchHistory, GameCustomization
from django.core.files.storage import default_storage
from django.core.files.base import ContentFile
import os
import sys
from django.db import IntegrityError
from django.views.decorators.http import require_POST
from friends.models import Relationship
from remote.models import GameInvitation
from django.shortcuts import get_object_or_404
from django.core.exceptions import ValidationError
from django.utils import timezone
from datetime import timedelta
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync
from django.dispatch import receiver
from django.db.models.signals import post_save
from django.contrib.auth.signals import user_logged_in
import logging
logger = logging.getLogger(__name__)

# Create your views here.
from .models import *

def homepage(request):
	return render(request, 'index.html')

@login_required
@csrf_exempt
def profile(request):
	user = request.user
	try:
		profile = Profile.objects.get(user=user)
	except Profile.DoesNotExist:
		return JsonResponse({'message': 'Profile does not exist'}, status=404)

	profile_picture_url = profile.profile_picture.url if profile.profile_picture else None

	return JsonResponse({
			'username': user.username,
			'email': user.email,
			'profile_picture': profile_picture_url,
	})

@login_required
@csrf_exempt
def current_user(request):
	user = request.user
	try:
		profile = Profile.objects.get(user=user)
		profile_picture = profile.profile_picture.url if profile.profile_picture else None
	except ObjectDoesNotExist:
			logger.warning(f"No profile found for user {user.username}")
			profile_picture = None

	return JsonResponse({
			'username': user.username,
			'profile_picture': profile_picture,
	})

@csrf_exempt
def logout_view(request):
	logout(request)
	return JsonResponse({'message': 'Logged out successfully'})


@csrf_exempt
def login_view(request):
	if request.method == 'POST':
		try:
			data = json.loads(request.body)
			username = data['username']
			password = data['password']

			user = authenticate(request, username=username, password=password)

			profile = Profile.objects.get(user=user)

			if profile.online_status:
				return JsonResponse({'message': 'User already logged in'}, status=400)

			if user is not None:
				login(request, user)
				return JsonResponse({'message': 'Login successful'}, status=200)
			else:
				return JsonResponse({'message': 'Invalid credentials'}, status=400)
		except KeyError:
			return JsonResponse({'message': 'Missing fields'}, status=400)
	else:
		return JsonResponse({'message': 'Invalid request'}, status=400)

@csrf_exempt
def create_account(request):
	if request.method == 'POST':
		data = json.loads(request.body)

		username = data.get('username')
		email = data.get('email')
		password = data.get('password')
		confirm_password = data.get('confirmPassword')

		if User.objects.filter(username=username).exists():
			return JsonResponse({'message': 'Username already exists'}, status=400)

		if User.objects.filter(email=email).exists():
			return JsonResponse({'message': 'Email already exists'}, status=400)

		if not re.match(r'^[a-zA-Z0-9]+$', username):
			return JsonResponse({'message': 'Username can only contain letters and numbers'}, status=400)

		if password != confirm_password:
			return JsonResponse({'message': 'Passwords do not match'}, status=400)

		if len(password) < 8:
			return JsonResponse({'message': 'Password must be at least 8 characters long'}, status=400)

		if not any(char.isdigit() for char in password):
			return JsonResponse({'message': 'Password must contain at least one number'}, status=400)

		if not any(char.isupper() for char in password):
			return JsonResponse({'message': 'Password must contain at least one uppercase letter'}, status=400)

		user = User.objects.create_user(username=username, email=email, password=password)
		user.save()

		game_customization = GameCustomization.objects.create(
			user=user,
			ship = 1,
			color = '#00ff00'
		)
		game_customization.save()
		return JsonResponse({'message': 'Account created successfully'}, status=200)

	return JsonResponse({'message': 'Invalid request method'}, status=405)

@csrf_exempt
@login_required
def update_profile(request):
	if request.method == 'POST':

		user = request.user
		profile = get_object_or_404(Profile, user=user)

		profile_picture = request.FILES.get('profile-picture')

		new_email = request.POST.get('email')
		new_password = request.POST.get('new-password')
		new_confirm_password = request.POST.get('new-confirmPassword')
		old_password = request.POST.get('old-password')

		if not check_password(old_password, user.password):
			return JsonResponse({'message': 'Wrong password!'}, status=400)

		if new_password:
			if new_password != new_confirm_password:
				return JsonResponse({'message': 'New passwords do not match'}, status=400)

			if len(new_password) < 8:
				return JsonResponse({'message': 'Password must be at least 8 characters long'}, status=400)

			if not any(char.isdigit() for char in new_password):
				return JsonResponse({'message': 'Password must contain at least one number'}, status=400)

			if not any(char.isupper() for char in new_password):
				return JsonResponse({'message': 'Password must contain at least one uppercase letter'}, status=400)

		if new_email and User.objects.filter(email=new_email).exists() and new_email != user.email:
			return JsonResponse({'message': 'Email already exists!'}, status=400)

		if new_email and new_email != user.email:
			user.email = new_email

		if new_password:
			user.password = make_password(new_password)

		if profile_picture:
					if not profile_picture.content_type.startswith('image/'):
									return JsonResponse({'message': 'Invalid file type. Please upload an image file.'}, status=400)
					try:
						profile.profile_picture = profile_picture
						profile.save()
					except ValidationError as e:
						return JsonResponse({'message': str(e)}, status=400)

		user.save()
		login(request, user)

		return JsonResponse({'message': 'Account updated successfully'}, status=200)

	return JsonResponse({'message': 'Invalid request method'}, status=405)

@require_POST
@login_required
@csrf_exempt
def save_match_history(request):
	if request.method == 'POST':
			try:
				data = json.loads(request.body)

				match = MatchHistory.objects.create(
					user=request.user,
					score=data['score'],
					result=data['result'],
					game=data['game']
				)

				return JsonResponse({'message': 'Match history saved successfully'}, status=200)
			except json.JSONDecodeError:
				return JsonResponse({'error': 'Invalid JSON data'}, status=400)
			except Exception as e:
				return JsonResponse({'error': str(e)}, status=500)
	else:
			return JsonResponse({'error': 'Invalid request method'}, status=405)


@login_required
@csrf_exempt
def load_match_history(request):
	try:
			match_history = MatchHistory.objects.filter(user=request.user).values('timestamp', 'score', 'result', 'game')
			""" friends = Profile.objects.filter(user=request.user).values_list('friends__username', flat=True) """
			friend_requests = Relationship.objects.filter(receiver__user=request.user, status='sent').values_list('sender__user__username', flat=True)
			profile = Profile.objects.get(user=request.user)
			friends_count = profile.friends.count()
			friends_status = []
			for friend in profile.get_friends():
				friend_profile = Profile.objects.get(user=friend)
				online_status = friend_profile.is_online()
				friends_status.append({
				'username': friend.username,
				'status': online_status
				})
			user = request.user
			game_customization = GameCustomization.objects.filter(user=request.user).values('ship', 'color')
			return JsonResponse({
			'username': user.username,
			'match_history': list(match_history),
			'friends': friends_status,
			'friends_count': friends_count,
			'game_customization': list(game_customization),
			'friend_requests': list(friend_requests)},
			safe=False)
	except Exception as e:
			return JsonResponse({'error': str(e)}, status=500)  # Return error as JSON

@login_required
@csrf_exempt
def save_customization(request):
	if request.method == 'POST':
		try:
			data = json.loads(request.body)

			user = request.user
			ship = data.get('ship')
			color = data.get('color')

			if not ship:
				ship = 1

			try:
				ship = int(ship)
			except ValueError:
				return JsonResponse({'error': 'Invalid ship ID.'}, status=400)

			customization, created = GameCustomization.objects.update_or_create(
				user=user,
				defaults={'ship': ship, 'color': color},
			)
			return JsonResponse({'status': 'success', 'message': 'Customization saved.'})
		except json.JSONDecodeError:
			return JsonResponse({'error': 'Invalid JSON.'}, status=400)

@csrf_exempt
def get_ship_and_color(request):
	if request.user.is_authenticated:
		try:
			game_customization = GameCustomization.objects.get(user=request.user)
			ship_number = game_customization.ship
			hexagon_color = game_customization.color
		except GameCustomization.DoesNotExist:
			ship_number = 1
			hexagon_color = '#00ff00'
	else:
		ship_number = 1
		hexagon_color = '#00ff00'
	return JsonResponse({
		'ship': ship_number,
		'color': hexagon_color,
	})

@csrf_exempt
def get_profile_friend(request):
	if request.method == 'POST':
			data = json.loads(request.body)
			username = data.get('username')  # Retrieve the friend's username

			try:
				# Retrieve the friend's user object based on username
				friend_user = User.objects.get(username=username)

				# Fetch the friend's match history using the user's ID
				match_history = MatchHistory.objects.filter(user=friend_user).values('timestamp', 'score', 'result', 'game')
				profile = Profile.objects.get(user=friend_user)

				return JsonResponse({
					'match_history': list(match_history),
					'profile_picture': profile.profile_picture.url if profile.profile_picture else None},
				safe=False)

			except User.DoesNotExist:
				# Handle case where the username does not exist
				return JsonResponse({'message': 'User not found'}, status=404)
	return JsonResponse({'message': 'Invalid request'}, status=400)

@csrf_exempt
def get_data_remote(request):
	try:
			user = request.user
			try:
				remote_game_invitations = GameInvitation.objects.filter(receiver__user=request.user, status='sent').values('sender__user__username', 'game_id')
				match_history = MatchHistory.objects.filter(user=request.user).values('timestamp', 'score', 'result', 'game')
			except remote_game_invitations.DoesNotExist:
				return JsonResponse({'error': 'Something went wrong'}, status=400)  # Return error as JSON
			return JsonResponse({
			'username': user.username,
			'match_history': list(match_history),
			'remote_game_invitations': list(remote_game_invitations)},
			safe=False)
	except Exception as e:
			return JsonResponse({'error': 'Not logged'}, status=404)  # Return error as JSON
	return JsonResponse({'error': str(e)}, status=500)

@csrf_exempt
def get_ship_and_color_remote(request):
	if request.method == 'POST':
		try:
			data = json.loads(request.body)
			user_player_one = request.user
			username_guest = data.get('username_guest')
			try:
				user_player_two = User.objects.get(username=username_guest)
			except User.DoesNotExist:
				return JsonResponse({'error': 'User does not exist'}, status=404)
			try:
				game_customization_player_one = GameCustomization.objects.get(user=user_player_one)
				ship_number_player_one = game_customization_player_one.ship
				hexagon_color = game_customization_player_one.color
				game_customization_player_two = GameCustomization.objects.get(user=user_player_two)
				ship_number_player_two = game_customization_player_two.ship
			except GameCustomization.DoesNotExist:
				ship_number_player_one = 1
				hexagon_color = '#00ff00'
				ship_number_player_two = 2
		except json.JSONDecodeError:
			return JsonResponse({'error': 'Invalid JSON.'}, status=400)
		return JsonResponse({
			'username': user_player_one.username,
			'ship_player_one': ship_number_player_one,
			'color': hexagon_color,
			'ship_player_two': ship_number_player_two
		})
	return JsonResponse({'error': 'Invalid request'}, status=400)