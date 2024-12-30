from django.shortcuts import render
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from .models import GameInvitation, GameByRank
from firstApp.models import Profile
import json
import random
import logging
logger = logging.getLogger(__name__)

@csrf_exempt
def send_game_invitation(request):
    if request.method == 'POST':

        data = json.loads(request.body)
        sender = request.user
        receiver_username = data.get('username')
        game_name = data.get('game_name')
        random_number = random.randint(100, 999)
        game_id = f"{game_name}{random_number}"

        if not receiver_username or not game_name:
            return JsonResponse({'error': 'Username and game name are required'}, status=400)

        try:
            receiver = Profile.objects.get(user__username=receiver_username)

            game_invitation, created = GameInvitation.objects.update_or_create(
                sender=Profile.objects.get(user=sender),
                receiver=receiver,
                game_id=game_id,
                status='sent'
            )
            if created:
                return JsonResponse({'message': f'Game invitation sent successfully!', 'game_id': game_invitation.game_id }, status=200)
            else:
                return JsonResponse({'message': f'Game invitation already sent!'}, status=400)

        except Profile.DoesNotExist:
            return JsonResponse({'message': 'User not found'}, status=400)

    return JsonResponse({'message': 'Invalid request'}, status=400)


@csrf_exempt
def accept_game_invitation(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        sender_username = data.get('username')
        game_id = data.get('game_id')
        receiver_username = request.user

        try:
            receiver = request.user.profile
            sender = Profile.objects.get(user__username=sender_username)

            game_invitation = GameInvitation.objects.get(
                sender=sender,
                receiver=receiver,
                game_id=game_id,
                status='sent'
            )
            game_invitation.status = 'accepted'
            game_invitation.save()

            return JsonResponse({'message': f'Game invitation accepted successfully!', 'game_id': game_invitation.game_id, 'sender': game_invitation.sender.user.username, 'receiver': game_invitation.receiver.user.username }, status=200)
        except Profile.DoesNotExist:
            return JsonResponse({'message': 'User not found'}, status=400)
        except GameInvitation.DoesNotExist:
            return JsonResponse({'message': 'Game invitation not found'}, status=400)

    return JsonResponse({'error': 'Invalid request'}, status=400)


@csrf_exempt
def reject_game_invitation(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        username = data.get('username')
        game_id = data.get('game_id')

        try:
            receiver = request.user.profile
            sender = Profile.objects.get(user__username=username)

            game_invitation = GameInvitation.objects.get(
                sender=sender,
                receiver=receiver,
                game_id=game_id,
                status='sent'
            )

            game_invitation.status = 'rejected'
            game_invitation.save()

            return JsonResponse({'message': f'Game invitation rejected successfully!', 'game_id': game_invitation.game_id }, status=200)
        except Profile.DoesNotExist:
            return JsonResponse({'message': 'User not found'}, status=400)
        except GameInvitation.DoesNotExist:
            return JsonResponse({'message': 'Game invitation not found'}, status=400)

    return JsonResponse({'error': 'Invalid request'}, status=400)

@csrf_exempt
def finish_game_invitation(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        username = data.get('username')
        game_id = data.get('game_id')

        try:
            receiver = Profile.objects.get(user__username=username)
            sender = request.user.profile

            game_invitation = GameInvitation.objects.get(
                sender=sender,
                receiver=receiver,
                game_id=game_id,
                status='sent'
            )

            game_invitation.status = 'finish'
            game_invitation.save()

            return JsonResponse({'message': f'Game invitation finish successfully!', 'game_id': game_invitation.game_id }, status=200)
        except Profile.DoesNotExist:
            return JsonResponse({'message': 'User not found'}, status=400)
        except GameInvitation.DoesNotExist:
            return JsonResponse({'message': 'Game invitation not found'}, status=400)

    return JsonResponse({'error': 'Invalid request'}, status=400)

@csrf_exempt
def finish_game_rank(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        game_id = data.get('game_id')

        game_by_rank = GameByRank.objects.get(game_id=game_id)
        if game_by_rank:
            game_by_rank.status = 'finish'
            game_by_rank.save()
            return JsonResponse({'message': f'Game by rank finish successfully!', 'game_id': game_by_rank.game_id }, status=200)

        if GameByRank.DoesNotExist:
            return JsonResponse({'message': 'Game not found'}, status=400)

@csrf_exempt
def start_game_by_rank(request):
    if request.method == 'POST':
        try:
            data = json.loads(request.body)
            rank = data.get('rank')
            game_name = data.get('game_name')

            try:
                currentUser = request.user
            except Profile.DoesNotExist:
                return JsonResponse({'error': 'User profile not found'}, status=404)

            second_rank = {
                'NoRank': 'Bronze',
                'Bronze': 'Silver',
                'Silver': 'Gold',
                'Gold': 'Platinum',
                'Platinum': 'Gold',
            }.get(rank, None)

            if second_rank is None:
                return JsonResponse({'error': 'Invalid rank provided'}, status=400)

            game_by_rank = GameByRank.objects.filter(
                game_name=game_name, rank=rank, status='sent'
            ).order_by('created').first()

            if game_by_rank:
                game_by_rank.receiver = currentUser.username
                game_by_rank.status = 'accepted'
                game_by_rank.save()
                sender_username = game_by_rank.sender
                return JsonResponse({
                    'message': 'Game invitation found successfully!',
                    'game_id': game_by_rank.game_id,
                    'sender': sender_username,
                }, status=200)

            game_by_rank = GameByRank.objects.filter(
                game_name=game_name, rank=second_rank, status='sent'
            ).order_by('created').first()

            if game_by_rank:
                game_by_rank.receiver = currentUser.username
                game_by_rank.status = 'accepted'
                game_by_rank.save()
                sender_username = game_by_rank.sender
                return JsonResponse({
                    'message': 'Game invitation found successfully!',
                    'game_id': game_by_rank.game_id,
                    'sender': sender_username,
                }, status=200)

            random_number = random.randint(100, 999)
            game_id = f"{game_name}{random_number}"
            game_by_rank, created = GameByRank.objects.update_or_create(
                sender=currentUser.username,
                receiver='undefined',
                game_id=game_id,
                game_name=game_name,
                rank=rank,
                status='sent',
            )
            if created:
                return JsonResponse({
                    'message': 'Game created successfully!',
                    'game_id': game_by_rank.game_id,
                }, status=200)
            else:
                return JsonResponse({'error': 'Game could not be created!'}, status=400)

        except json.JSONDecodeError:
            return JsonResponse({'error': 'Invalid JSON'}, status=400)
        except Exception as e:
            return JsonResponse({'error': str(e)}, status=500)

    return JsonResponse({'error': 'Invalid request method'}, status=400)


@csrf_exempt
def find_receiver(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        game_id = data.get('game_id')

        game_by_rank = GameByRank.objects.get(game_id=game_id)
        receiver_username = game_by_rank.receiver
        if game_by_rank:
            return JsonResponse({'message': f'Receiver found', 'receiver': receiver_username }, status=200)

        return JsonResponse({'message': 'User not found'}, status=400)

    return JsonResponse({'error': 'Invalid request'}, status=400)