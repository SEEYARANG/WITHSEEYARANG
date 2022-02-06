from django.shortcuts import get_object_or_404, render, redirect
from yolo_app.models import Infoplus, new_item
from yolo_app.serializers import new_itemSerializer
from django.http.response import JsonResponse

def Home(request):
    if request.method == 'GET':
        return render(request, 'Home.html')

def info_detail_plus(request):
    if request.method == 'POST':
        new_item_id = int(request.POST['id'])
        information = request.POST['information']
        Infoplus.objects.create(
            objname_id =  new_item_id, 
            information = information,
        )
        return render(request, 'Info_detail.html')
    return render(request, 'Info_detail.html')

def info_detail(request, pk):
    if request.method == 'GET':
        post = get_object_or_404(new_item, id = pk)
        info = post.infoplus_set.all()
        context = {'post':post, 'info': info}
        return render(request, 'Info_detail.html', context)
    return render(request, 'Info_detail.html')

def get_for_info_ajax(request):
    if request.method == 'GET':
        item = new_item.objects.all().values()
        serializer = new_itemSerializer(item, many = True)
        data = {'items':serializer.data}
        return JsonResponse(data)

def get_for_info(request):
    return render(request, 'Info.html')

#seeyarang이란
def whatis(request):
    if request.method == 'GET':
        return render(request, 'whatis.html')

#사용설명서 
def manual(request):
    if request.method == 'GET':
        return render(request, 'manual.html')

    
