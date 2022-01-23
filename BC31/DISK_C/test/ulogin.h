#ifndef _ulogin_h_
#define _ulogin_h_

int cinloginaccouhts(char *accounts,int *MouseX,int *MouseY);
//用户登录界面的账号输入函数

int cinlogincode(char *mode , int *MouseX,int *MouseY);
//用户登录界面的密码输入函数 


int user_login(setuser *head,char *accounts,char *code);
//用户登录界面的后台函数

#endif

