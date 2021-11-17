from rest_framework.response import Response
from rest_framework import status
from rest_framework import viewsets
from .models import Info, PredictedResult, TTSname, Lotte_class, Info
from .serializers import PredictedResultSerializer,TTSnameSerializer, Lotte_classSerializer, InfoSerializer
from rest_framework.decorators import action


class PredictionViewset(viewsets.ModelViewSet):
    queryset = PredictedResult.objects.all()
    serializer_class = PredictedResultSerializer
    
    @action(detail=False)
    def yolo_list(self, request):
        qs_y = self.queryset.filter(type = "YOLO")
        serializer = self.get_serializer(qs_y, many=True)
        return Response(serializer.data)

    @action(detail=False)
    def ocr_list(self, request):
        qs = self.queryset.filter(type = "CLOVA_OCR")
        serializer = self.get_serializer(qs, many=True)
        return Response(serializer.data)


class TTSnameViewset(viewsets.ModelViewSet):
    queryset = TTSname.objects.all()
    serializer_class = TTSnameSerializer



class Lotte_classViewset(viewsets.ModelViewSet):
    queryset = Lotte_class.objects.all()
    serializer_class = Lotte_classSerializer

class Info_Viewset(viewsets.ModelViewSet):
    queryset = Info.objects.all()
    serializer_class = InfoSerializer