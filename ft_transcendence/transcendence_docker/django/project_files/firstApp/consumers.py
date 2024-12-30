# consumers.py
# consumers.py
import json
from channels.generic.websocket import AsyncWebsocketConsumer
from .models import Profile
from datetime import timedelta
from django.utils import timezone
from .signals import status_change_signal
from asgiref.sync import async_to_sync, sync_to_async
from channels.layers import get_channel_layer
from django.dispatch import receiver
import logging
logger = logging.getLogger(__name__)


class StatusConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        # Join a channel group (e.g., based on user ID or friends group)
        self.user = self.scope["user"]
        self.group_name = f"user_{self.user.username}"
        if self.user.is_authenticated:
            # Add the user to a WebSocket group
            await self.channel_layer.group_add(self.group_name, self.channel_name)

            # Update user's status to online
            profile = await sync_to_async(Profile.objects.get)(user=self.user)
            profile.online_status = True
            await sync_to_async(profile.save)()

        await self.accept()

    async def disconnect(self, close_code):
        await self.channel_layer.group_discard(self.group_name, self.channel_name)
        if self.scope["user"].is_authenticated:
            profile = await sync_to_async(Profile.objects.get)(user=self.scope["user"])
            profile.online_status = False
            await sync_to_async(profile.save)()
        # Notify the user's friends about the status change
        friends = await sync_to_async(list)(profile.get_friends())
        for friend in friends:
            friend_group_name = f"user_{friend}"
            await self.channel_layer.group_send(
                friend_group_name,
                {
                    "type": "status_update",
                    "username": self.user.username,
                    "status": "offline",
                },
            )

    async def receive(self, text_data):
        data = json.loads(text_data)
        # This part will depend on any specific requests, if necessary

    async def status_update(self, event):
        await self.send(text_data=json.dumps({
            'friend_': event['username'],
            'status': event['status']
        }))

@receiver(status_change_signal)
def status_change_handler(sender, username, status, **kwargs):
    channel_layer = get_channel_layer()
    friend_group_name = f"user_{username}"
    profile = Profile.objects.get(user__username=username)
    friends = profile.get_friends()  # Assuming `get_friends` returns a QuerySet or list of `User` objects
    for friend in friends:
        friend_group_name = f"user_{friend}"  # Using friend's user ID for the group name
        async_to_sync(channel_layer.group_send)(
            friend_group_name,
            {
                "type": "status_update",
                "username": username,  # Use the current user's username
                "status": status,  # The new status ("online" or "offline")
            },
        )

