from django.db import models
from rest_framework.serializers import ModelSerializer
from rest_framework import fields, serializers
from .models import PredictedResult,TTSname,Lotte_class,Info

class PredictedResultSerializer(ModelSerializer):
    class Meta:
        model = PredictedResult
        fields = ('id','type','prediction','predicted_at','img_path')


class TTSnameSerializer(ModelSerializer):
    class Meta:
        model = TTSname
        fields = '__all__'


class Lotte_classSerializer(ModelSerializer):
    class Meta:
        model = Lotte_class
        fields = '__all__'


class InfoSerializer(ModelSerializer):
    class Meta:
        model = Info
        fields = '__all__'