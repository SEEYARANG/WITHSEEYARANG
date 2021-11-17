from django.db import models

class TTSname(models.Model):
    class_name = models.CharField(max_length=100)
    TTS_name = models.CharField(max_length=100)

class PredictedResult(models.Model):
    type = models.CharField(max_length=100)
    prediction = models.CharField(max_length=100)
    predicted_at = models.DateTimeField(auto_now_add=True)
    img_path = models.TextField()

class Lotte_class(models.Model):
    menu = models.CharField(max_length=100)
    price = models.CharField(max_length=100)

class Info(models.Model):
    type = models.CharField(max_length=100)    
    name = models.CharField(max_length=100)
    information = models.TextField(null=True, default='')
