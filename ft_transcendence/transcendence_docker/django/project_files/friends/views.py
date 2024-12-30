from django.shortcuts import render
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from .models import Relationship
from firstApp.models import Profile
import json

# Create your views here.

@csrf_exempt
def send_friend_request(request):
    if request.method == 'POST':
        # Parse the JSON body
        data = json.loads(request.body)  # Load JSON data from the request body
        sender = request.user  # User who is sending the request
        receiver_username = data.get('username')  # Extract username from JSON

        # Check if the receiver username is provided
        if not receiver_username:
            return JsonResponse({'error': 'Username is required'}, status=400)

        # Find the receiver user and create a relationship
        try:
            receiver = Profile.objects.get(user__username=receiver_username)

            # Create a relationship instance with status 'sent'
            relationship, created = Relationship.objects.get_or_create(
                sender=Profile.objects.get(user=sender),
                receiver=receiver,
                defaults={'status': 'sent'}
            )

            if created:
                return JsonResponse({'message': 'Friend request sent successfully!'}, status=200)
            else:
                return JsonResponse({'message': 'Friend request already sent!'}, status=400)

        except Profile.DoesNotExist:
            return JsonResponse({'message': 'User not found'}, status=400)

    return JsonResponse({'message': 'Invalid request'}, status=400)

@csrf_exempt
def accept_friend_request(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        username = data.get('username')

        try:
            receiver = request.user.profile  # Current user (receiver)
            sender = Profile.objects.get(user__username=username)  # Sender of the request

            # Update the Relationship model to set status to 'accepted'
            relationship = Relationship.objects.get(sender=sender, receiver=receiver, status='sent')
            relationship.status = 'accepted'
            relationship.save()

            # Add each other as friends
            receiver.friends.add(sender.user)
            sender.friends.add(receiver.user)

            return JsonResponse({'message': 'Friend request accepted successfully!'}, status=200)
        except Profile.DoesNotExist:
            return JsonResponse({'error': 'User not found'}, status=404)
        except Relationship.DoesNotExist:
            return JsonResponse({'error': 'Friend request not found'}, status=404)

    return JsonResponse({'error': 'Invalid request'}, status=400)

@csrf_exempt
def reject_friend_request(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        username = data.get('username')

        try:
            receiver = request.user.profile  # Current user (receiver)
            sender = Profile.objects.get(user__username=username)  # Sender of the request

            # Attempt to get the existing relationship
            relationship = Relationship.objects.get(sender=sender, receiver=receiver, status='sent')

            # Update the Relationship model to set status to 'rejected'
            relationship.status = 'rejected'
            relationship.save()


            return JsonResponse({'message': 'Friend request rejected successfully!'}, status=200)
        except Profile.DoesNotExist:
            return JsonResponse({'error': 'User not found'}, status=404)
        except Relationship.DoesNotExist:
            return JsonResponse({'error': 'Friend request not found'}, status=404)

    return JsonResponse({'error': 'Invalid request'}, status=400)

def remove_friend(request):
    if request.method == 'POST':
        data = json.loads(request.body)
        username = data.get('username')

        try:
            receiver = request.user.profile  # Current user (receiver)
            friend = Profile.objects.get(user__username=username)  # Friend to be removed

            # Remove each other as friends
            receiver.friends.remove(friend.user)
            friend.friends.remove(receiver.user)

            return JsonResponse({'message': 'Friend removed successfully!'}, status=200)
        except Profile.DoesNotExist:
            return JsonResponse({'error': 'User not found'}, status=400)

    return JsonResponse({'error': 'Invalid request'}, status=400)
