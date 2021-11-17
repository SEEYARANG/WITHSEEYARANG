from django.db import models
from rest_framework.serializers import ModelSerializer
from rest_framework import fields, serializers
from .models import PredictedResult, Problem,TTSname, new_item, Infoplus,Info, Feedback
from user.models import User

class PredictedResultSerializer(ModelSerializer):
    class Meta:
        model = PredictedResult
        fields = ('id','type','prediction','predicted_at','img_path')


class TTSnameSerializer(ModelSerializer):
    class Meta:
        model = TTSname
        fields = '__all__'

class InfoSerializer(ModelSerializer):
    class Meta:
        model = Info
        fields = ('type','name','information')

class UsernameSerializer(ModelSerializer):
    class Meta:
        model = User
        fields = '__all__'

class new_itemSerializer(ModelSerializer):
    class Meta:
        model = new_item
        fields = '__all__'

class InfoplusSerializer(ModelSerializer):
    class Meta:
        model = Infoplus
        fields = ('information')

class ProblemSerializer(ModelSerializer):
    class Meta:
        model = Problem
        fields = ('id','problem','problem_title','create_date')

class FeedbackSerializer(ModelSerializer):
    class Meta:
        model = Feedback
        fields = '__all__'
