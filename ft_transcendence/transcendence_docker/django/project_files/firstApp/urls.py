from django.urls import path, re_path
from . import views
from django.conf import settings
from django.conf.urls.static import static
from .views import create_account, login_view, current_user, logout_view, profile, update_profile, save_match_history, load_match_history, save_customization, get_ship_and_color, get_profile_friend, get_data_remote, get_ship_and_color_remote

urlpatterns = [
    path('', views.homepage, name="homepage"),
    path('create-account/', views.create_account, name='create_account'),
    path('login/', login_view, name='login'),
    path('current-user/', current_user, name='current_user'),
    path('logout/', logout_view, name='logout'),
    path('profile/', profile, name='profile'),
    path('update_profile/', update_profile, name='update_profile'),
    path('api/save-match-history/', save_match_history, name='save_match_history'),
    path('api/load-match-history/', load_match_history, name='load_match_history'),
    path('save-customization/', save_customization, name='save_customization'),
    path('api/get-ship-and-color/', get_ship_and_color, name='get-ship-and-color'),
    path('get-profile-friend/', get_profile_friend, name='get_profile_friend'),
    path('api/get-data-remote/', get_data_remote, name='get_data_remote'),
    path('api/get-ship-and-color-remote/', get_ship_and_color_remote, name='get-ship-and-color_remote'),
]

if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
#    urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)


#urlpatterns += [re_path(r'^(?!static/|media/).*$', views.homepage)]