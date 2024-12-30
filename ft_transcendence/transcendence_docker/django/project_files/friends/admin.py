from django.contrib import admin
from firstApp.models import Profile
from .models import Relationship

# Register your models here.

admin.site.register(Profile)
admin.site.register(Relationship)