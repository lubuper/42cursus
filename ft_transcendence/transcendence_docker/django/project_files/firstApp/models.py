from django.db import models

# Create your models here.
from django.contrib.auth.models import User
from django.db.models.signals import post_save
from django.dispatch import receiver
from django.utils import timezone
from datetime import timedelta

class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    profile_picture = models.ImageField(
            upload_to="profile_pics/",
            default='profile_pics/default_profile.png',
            blank=True,
            null=True,
    )
    friends = models.ManyToManyField(User, related_name="friends", blank=True)
    friend_requests = models.ManyToManyField(User, related_name="friend_requests", blank=True)
    updated = models.DateTimeField(auto_now=True)
    created = models.DateTimeField(auto_now_add=True)
    last_seen = models.DateField(null=True, blank=True)
    online_status = models.BooleanField(default=False)

    def get_friends(self):
        return self.friends.all()

    def get_friends_no(self):
        return self.friends.all().count()

    def get_pending_requests(self):
        pending_requests = Relationship.objects.filter(receiver=self, status='sent')
        if pending_requests.exists():
            return pending_requests
        else:
            return "You have no friend requests."

    def is_online(self):
        return self.online_status # This always returns True/False

    def __str__(self):
        return f"{self.user.username}"


@receiver(post_save, sender=User)
def create_user_profile(sender, instance, created, **kwargs):
    if created:
        Profile.objects.create(user=instance)

@receiver(post_save, sender=User)
def save_user_profile(sender, instance, **kwargs):
    instance.profile.save()


class MatchHistory(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    timestamp = models.DateTimeField(auto_now_add=True)
    score = models.CharField(max_length=255) # number-number (on single games) / username of the winner (om tournaments)
    result = models.CharField(max_length=255)  # Win, Lose, or Draw (on single games) / Winner (on tournaments)
    game = models.CharField(max_length=255) # Pong, Asteroids, Pong Remote, Asteroids Remote, Pong Tournament, Asteroids Tournament

    def __str__(self):
        return f'{self.user.username} - {self.result} at {self.timestamp}'

class GameCustomization(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    ship = models.IntegerField(null=False)
    color = models.CharField(max_length=10)

    def __str__(self):
        return f'{self.user.username} - {self.ship} and {self.color}'

class UpdateLastSeenMiddleWare:
    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        if request.user.is_authenticated:
            Profile.objects.filter(user=request.user).update(last_seen=timezone.now())
        return self.get_response(request)
