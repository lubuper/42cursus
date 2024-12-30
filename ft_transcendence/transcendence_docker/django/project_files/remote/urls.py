from django.urls import path
from . import views

urlpatterns = [
    path('send-game-invitation/', views.send_game_invitation, name='send_game_invitation'),
    path('accept-game-invitation/', views.accept_game_invitation, name='accept_game_invitation'),
    path('reject-game-invitation/', views.reject_game_invitation, name='reject_game_invitation'),
    path('finish-game-invitation/', views.finish_game_invitation, name='finish_game_invitation'),
    path('start-game-by-rank/', views.start_game_by_rank, name='start_game_by_rank'),
    path('find-receiver/', views.find_receiver, name='find_receiver'),
    path('finish-game-rank/', views.finish_game_rank, name='finish_game_rank'),
]