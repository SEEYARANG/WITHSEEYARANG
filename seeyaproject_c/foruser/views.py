import json
from django.http.response import HttpResponse, JsonResponse
from django.shortcuts import render
from django.contrib import auth
from django.contrib.auth.decorators import login_required
from django.shortcuts import render, redirect, get_object_or_404 
from yolo_app.models import Feedback, PredictedResult, Info, Problem
from yolo_app.serializers import FeedbackSerializer, InfoSerializer, PredictedResultSerializer, ProblemSerializer
from time import process_time, timezone

def Userlogin(request):
    if request.method == 'POST':
        user_name = request.POST.get('product')
        print(user_name)
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
    return redirect('seeyarang')

# home
@login_required(login_url='login')
def Userhome(request):
    if request.method == 'GET':
        data = {"user": request.user}
        return render(request, 'Userhome.html',data)

#user_object
@login_required
def Userobject_img(request):
    return render(request, 'Userobject.html')

@login_required
def Userobject_img_ajax(request):
    if request.method == 'GET':
        obj = PredictedResult.objects.all().values()
        serializer = PredictedResultSerializer(obj, many=True)
        data =  {"object": serializer.data} 
        return JsonResponse(data)

#user_info
@login_required
def Userobject_info(request):
    if request.method == 'GET':
        object = Info.objects.filter(user = request.user).values()
        context = {'object':object}
        return render(request, 'Userinfo.html',context)
    return render(request, 'Userinfo.html')
 

@login_required
def Userinfo_plus(request):
    if request.method == 'POST':
        user = request.user
        type = request.POST['type']
        id = request.POST['id']
        information = request.POST['information']
        try:
            Info.objects.get(user = request.user, id = id)
            a = Info.objects.get(user = request.user, id = id)
            a.information = information
            a.save()
            return render(request, 'Userinfo.html')
        except:
            return render(request, 'Userinfo.html')            
    return render(request, 'Userinfo.html')


#problem
@login_required
def Userproblem(request):
    return render(request, 'Userproblem.html') 

@login_required
def Userproblem_ajax(request):
    if request.method == 'GET':
        problem = Problem.objects.all().values()
        feedback = Feedback.objects.all().values()
        serializer_p = ProblemSerializer(problem, many=True)
        serializer_f = FeedbackSerializer(feedback, many = True)
        data =  {"problem": serializer_p.data, "feedback":serializer_f.data} 
        return JsonResponse(data)

@login_required
def Userproblem_plus(request):
    if request.method == 'POST':
        user = request.user
        problem_title = request.POST['Userproblem_title']
        problem = request.POST['Userproblem']
        Problem.objects.create(
            user = user,
            problem_title = problem_title,
            problem = problem,
        )           
        print(Problem.objects.all().values())
    return render(request, 'Userproblem.html')

@login_required
def Userproblem_detail(request,pk):
    if request.method == 'GET':
        problem = Problem.objects.get(id=pk)
        feedback = Feedback.objects.filter(problem_id = pk)
        context={
            'problem' :problem,
            'feedback': feedback
        }

        return render(request,'Userproblem_detail.html',context)
