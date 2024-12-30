from django.dispatch import Signal
from django.contrib.auth.signals import user_logged_in, user_logged_out
from django.dispatch import receiver
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync
from .models import Profile
import logging
logger = logging.getLogger(__name__)


# Define a custom signal for when the user's status changes
status_change_signal = Signal()

@receiver(user_logged_in)
def handle_user_login(sender, request, user, **kwargs):
	profile = Profile.objects.get(user=user)
	profile.online_status = True
	profile.save()
	# Emit custom status change signal on login
	status_change_signal.send(sender=user.__class__, username=user.username, status="online")

@receiver(user_logged_out)
def handle_user_logout(sender, request, user, **kwargs):
	profile = Profile.objects.get(user=user)
	profile.online_status = False
	profile.save()
	# Emit custom status change signal on logout
	status_change_signal.send(sender=user.__class__, username=user.username, status="offline")
