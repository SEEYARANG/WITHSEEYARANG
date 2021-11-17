from os import name
from django.conf.urls import url
from django.urls import path
from . import views
from foruser.views import Userlogin

urlpatterns = [
    path('seeyarang/', views.Home, name='seeyarang'),
    path('seeyarang/login/', Userlogin, name='login'),
    
    path('seeyarang/info/', views.get_for_info, name='info'),
    path('seeyarang/info/<int:pk>/', views.info_detail, name='info_detail'),
    path('seeyarang/info/detail/', views.info_detail_plus),
    path('seeyarang/infoajax/', views.get_for_info_ajax, name='info_ajax'),

    path('seeyarang/whatis', views.whatis, name='whatis'),
    path('seeyarang/manual', views.manual, name='manual'),
]
