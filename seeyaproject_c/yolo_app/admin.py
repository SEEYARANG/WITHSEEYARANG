from django.contrib import admin
 
# Register your models here.
from .models import Info, TTSname, PredictedResult, Lotte_class
from user.models import UserManager , User

## 아래의 코드를 입력하면 BlogData를 admin 페이지에서 관리할 수 있습니다.


'''class TTSnameAdmin(admin.ModelAdmin):
    list_display = ['user','class_name','TTS_name']
    search_fields = ['user']

admin.site.register(TTSname,  TTSnameAdmin)'''

class PredictedResultAdmin(admin.ModelAdmin):
    list_display = ['user', 'type','prediction','predicted_at']
    search_fields = ['user']

admin.site.register(PredictedResult, PredictedResultAdmin)


class InfoAdmin(admin.ModelAdmin):
    list_display = ['type','name','information']
    search_fields = ['name']

admin.site.register(Info, InfoAdmin)


class Lotte_classAdmin(admin.ModelAdmin):
    list_display = ['menu','price']
    search_fields = ['menu']

admin.site.register(Lotte_class, Lotte_classAdmin)
