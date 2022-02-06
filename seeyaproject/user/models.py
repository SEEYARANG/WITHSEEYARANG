from django.db import models
from django.contrib.auth.models import AbstractBaseUser,BaseUserManager,PermissionsMixin

#출처: https://cocook.tistory.com/20 

class UserManager(BaseUserManager):
    use_in_migrations = True
    def create_user(self, username, password):
        user = self.model(
            username = username,
        )
        user.set_password(password) 
        user.save(using=self._db)
        return user

    def create_superuser(self,  username, password):
        user = self.create_user(
            username= username,
            password=password
        )
        user.is_admin = True
        user.is_superuser = True
        user.is_staff = True
        user.save(using=self._db)
        return user

class User(AbstractBaseUser,PermissionsMixin): 
    objects = UserManager()

    username = models.CharField(
        '아이디',
        max_length=100,
        null=False,
        unique=True
    )
    is_active = models.BooleanField(default=True)    
    is_admin = models.BooleanField(default=False)    
    is_superuser = models.BooleanField(default=False)    
    is_staff = models.BooleanField(default=False)     
    date_joined = models.DateTimeField('가입 일',auto_now_add=True)

    USERNAME_FIELD = 'username'    

    class Meta:
        verbose_name_plural = "관리자 페이지 사용자"
