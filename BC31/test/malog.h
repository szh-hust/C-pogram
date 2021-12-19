#ifndef _malog_h_
#define _malog_h_

#include "common.h"
#include "malog.h"

/***************************************************
用户登录界面的账号输入函数
大小写字母与数字
1到10位
*x与*y传递鼠标位置，且以指针的形式传入
***************************************************/
int mcinloginaccouhts(char *accounts,int *MouseX,int *MouseY);

/***************************************************
用户登录界面的密码输入函数 
大写、小写英文、数字
1到10位
*MouseX与*MouseY传递鼠标位置，且以指针的形式传入
***************************************************/
int mcinlogincode(char *mode , int *MouseX,int *MouseY);
int mastercpy(char *a,char *c);

/***************************************************
用户登录界面的后台函数
***************************************************/
int  manage_login(setuser *head,char *accounts,char *code);

#endif

