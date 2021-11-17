from os import name
from django.urls import path
from . import views

urlpatterns = [
    path('home/login/', views.Userlogin, name='login'),
    path('home/logout/', views.Userlogout, name='logout'),
    path('home/', views.Userhome, name='home'),
]