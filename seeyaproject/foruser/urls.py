from os import name
from django.urls import path
from . import views

urlpatterns = [
    path('home/login/', views.Userlogin, name='login'),
    path('home/logout/', views.Userlogout, name='logout'),
    path('home/objectimg/', views.Userobject_img, name = 'objectimg'),
    path('home/objectajax/', views.Userobject_img_ajax, name = 'objectimg_ajax'),

    path('home/objectinfo/', views.Userobject_info, name = 'object_info'),
    path('home/objectinfo/plus/', views.Userinfo_plus, name = 'object_plus'),

    path('home/problem/', views.Userproblem,name='problem' ),
    path('home/problemajax/', views.Userproblem_ajax, name='problem_ajax' ),
    path('home/problem/plus/', views.Userproblem_plus, name='problem_plus'),
    path("home/problem/<int:pk>/",views.Userproblem_detail, name = "problem_detail"),

    path('home/', views.Userhome, name='home'),
]
