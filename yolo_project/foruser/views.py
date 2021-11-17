import json
from django.http.response import HttpResponse
from django.shortcuts import render,redirect
from django.contrib import auth
from django.contrib.auth.decorators import login_required

def Userlogin(request):
    if request.method == 'POST':
        user_name = request.POST.get('product')
        pass_word = str(int(user_name)+100)
        user = auth.authenticate(request, username=user_name, password = pass_word)   
        if user is not None:
            auth.login(request, user)
            return HttpResponse()
    else:
        return render(request, 'Userlogin.html')

# 로그아웃
def Userlogout(request):
    auth.logout(request)
    return redirect('login')

# home
@login_required(login_url='login')
def Userhome(request):
    if request.method == 'GET':
        data = {"user": request.user}
        return render(request, 'Userhome.html',data)
    