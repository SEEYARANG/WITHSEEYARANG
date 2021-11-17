from django.db import models
from user.models import User

class TTSname(models.Model):
    class_name = models.CharField(max_length=100)
    TTS_name = models.CharField(max_length=100)

class PredictedResult(models.Model):
    user = models.ForeignKey(
        User, 
        on_delete=models.CASCADE, 
        null=False,
    )
    type = models.CharField(max_length=100)
    prediction = models.CharField(max_length=100)
    predicted_at = models.DateTimeField(auto_now_add=True)
    img_path = models.TextField()

class Lotte_class(models.Model):
    menu = models.CharField(max_length=100)
    price = models.CharField(max_length=100)

class Info(models.Model):
    user = models.ForeignKey(
        User, 
        on_delete=models.CASCADE, 
        null=False,
    )
    type = models.CharField(max_length=100)    
    name = models.CharField(max_length=100)
    image_path = models.TextField(null=True, default='/images/forinfo/default.png')
    information = models.TextField(null=True, default='')

class new_item(models.Model):
    name = models.CharField(max_length=100)
    image_path = models.TextField()


class Infoplus(models.Model): 
    objname = models.ForeignKey(
        new_item,
        on_delete = models.CASCADE,
        null=True
    )
    information = models.TextField(null=True, default='')
    create_date = models.DateTimeField(auto_now_add = True)

class Problem(models.Model):
    user = models.ForeignKey(
        User, 
        on_delete=models.CASCADE, 
        null=False,
    )
    problem_title = models.TextField()
    problem =  models.TextField()
    create_date = models.DateTimeField(auto_now_add = True)


class Feedback(models.Model):
    problem = models.ForeignKey(
        Problem,
        on_delete=models.CASCADE,
        null=True
    )
    feedback=models.TextField()
    create_date = models.DateTimeField(auto_now_add = True)

