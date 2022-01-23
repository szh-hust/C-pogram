#ifndef _SERVICE_H_
#define _SERVICE_H_
#include "service.h"
#include "common.h"
#include "draw.h"
int service(setuser * person,struct POLICY policy[10]);//用户“享服务”后台主函数
void drawservice(setuser *person);//绘制"享服务"界面函数
void drawditu() ;
void drawxiche();//绘制洗车界面函数
int xiche(setuser * person);//用户进行洗车功能函数
int dingwei(int *x,int *y);
extern int MouseS;
#endif
