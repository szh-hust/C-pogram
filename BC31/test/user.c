#include "common.h"
#include "user.h"
#include "userself.h"
#include "service.h"
#include "policy1.h"
#include "policy2.h"
#include "duqu.h"
#include "lipei1.h"
#include "lipei2.h"
#include "gpolicy.h"
/****************************************
Function : usermain(setuser *head,setuser *person)
Description: 用户个主函数
Attention:上一级功能函数：main.c->main;
return ：main函数的judge值 
***************************************/
int usermain(setuser *head,setuser *person)
{
	int i;
	int judge  = 0;
	int num=0;
    int press,MouseX,MouseY;
	char nowaccounts[11];//存储用户的账号
	int flag1 = 0,flag2 = 0;
	int flag3;
	struct POLICY policy[10];
	struct CLAIM claim[10];
	int cn = 0;
	long  money;
	char mon[10];
	for(i=0;i<10;i++)
	{
		policy[i].p=0;
	}
	for(i=0;i<10;i++)
	{
		num=duqu(person,policy,i);
	}
	for(i=0;i<=num-1;i++)
	{
		policy[i].p=1;
	}
	for(i=0;i<10;i++)
	{
		claim[i].p = 0;
	}
	dumoney(person->accounts,&money);
	person->money = money;
	delay(100);
	//save_bk_mou(MouseX,MouseY);
	while(1)
	{
	   newmouse(&MouseX,&MouseY,&press);
	   //进入找保险界面 
	   if (MouseX>=160 && MouseX<=320 && MouseY >=430 && MouseY<=480 && press)
	   {
		   judge = 9;
	   }
	   //进入享服务界面
	   if(MouseX >=320  && MouseX <= 480 && MouseY >= 430 && MouseY <= 480 && press)
	   {
		   judge = 3;
	   }
	   //点击个人中心
	   if(MouseX >=480  && MouseX <= 640 && MouseY >= 430 && MouseY <= 480 && press)
	   {
		   judge = 4;
	   }  
	   //点击买保险(125,145,485,235)
	   if(MouseX >= 125 && MouseX <= 485 && MouseY >= 145 && MouseY <= 235)
	   {
		   if(flag1 == 0)
		   {
			   setfillstyle(1,WHITE);
			   clrmous(MouseX,MouseY);
			   bar(125,145,485,235);
			   drawtianjiatubiao(170+5,150-5,DARKGRAY);
			   save_bk_mou(MouseX,MouseY);
			   flag1 = 1;
		   }
		   if(press)
		   {
			   judge = 9;
		   } 
	   }
	   else if(flag1 == 1&&!(MouseX >= 125 && MouseX <= 485 && MouseY >= 145 && MouseY <= 235))
	   {
		   setfillstyle(1,WHITE);
		    clrmous(MouseX,MouseY);
		   bar(125+5,145-5,485+5,235-5);
		   drawtianjiatubiao(170,150,LIGHTGRAY);
		   save_bk_mou(MouseX,MouseY);
		   flag1 = 0;
	   }
	   //点击办理理赔(125,275,485,365)
	   if(MouseX >= 125 && MouseX <= 485 && MouseY >= 275 && MouseY <= 365)
	   {
		   if(flag2 == 0)
		   {
			   setfillstyle(1,WHITE);
			    clrmous(MouseX,MouseY);
			   bar(125,275,485,365);
			   drawbaopeitubiao(200+5,320-5,DARKGRAY);
			save_bk_mou(MouseX,MouseY);
			   flag2 = 1;
		   }
		   if(press)
		   {
			   judge = 5;
		   }
	   }  
	   else if(flag2 == 1&&!(MouseX >= 125 && MouseX <= 485 && MouseY >= 275 && MouseY <= 365))
	   {
			setfillstyle(1,WHITE);
            clrmous(MouseX,MouseY);			
			bar(125+5,275-5,485+5,365-5);
			drawbaopeitubiao(200,320,LIGHTGRAY);
		    save_bk_mou(MouseX,MouseY);
			flag2 = 0;
	   }
	   //点击退出登录
	   if (MouseX >=505  && MouseX <= 590 && MouseY >= 10 && MouseY <= 40 && press)
	   {
		   judge = 1;
	   }
	   switch(judge)
	   {
		   case -1://从其他界面返回用户主界面
		   {
			   drawusermain();
			   save_bk_mou(MouseX,MouseY);
			   judge = 0;
			   break;
		   }
		   case 1://退出登录
		   {
			   clrmous(MouseX,MouseY);
			   //delay(100);
			   judge = jueding("退出登录",6);
			   delay(100);
			   break;
		   }
		   case 3://进入享服务界面
		   {
			   drawservice(person);
			   judge = service(person,policy);
			   break;
		   }
		   case 4://进入个人中心
		   {
			   drawuserself();
			   judge = userself(head,person,policy);
			   break;
		   }
		   case 5://进行保单理赔
		   {
			    delay(100);
				strcpy(claim[cn].accounts,person->accounts);
			    judge = lipeimain(person,policy,claim,cn);
			    break;
		   }
		   case 6:
		   {
			   return 1;
		   }
		   case 9:
		   {
			    clrmous(MouseX,MouseY);
			    delay(100);
			    judge = jueding("进行投保",10);
				delay(100);
				break;			   
			}
			case 10:
			{
				if(policy[9].p==1)
			    {
					clrmous(MouseX,MouseY);
					judge = nopolicy(person);
					delay(100);
					break;
			    }
				else
				{
					judge = policymain(person,policy,num);
					for(i=0;i<10;i++)
					{
						num=duqu(person,policy,i);
					}	
					for(i=0;i<=num-1;i++)
					{
						policy[i].p=1;
					}
					break;
				}
			}
	   }  
	}	
}
/*****************************************
Function :    绘制找保险
Attention:    x y表示找保险左上角
**********************************************/
void drawtianjiatubiao(int x,int y,int color)
{
	setlinestyle(SOLID_LINE,0,3);
	setcolor(color);
	ellipse(x+30,y+40,48,132,40,27);
	line(x+55,y+20,x+55,y+60);
	line(x+5,y+20,x+5,y+60);
	line(x+5,y+60,x+30,y+70);
	line(x+55,y+60,x+30,y+70);
	line(x+13,y+37,x+27,y+50);
	line(x+27,y+50,x+50,y+30);
	
	
	
	line(x,y,x+60,y);
	line(x+60,y,x+100,y+40);
	line(x+100,y+40,x+60,y+80);
	line(x+60,y+80,x,y+80);
	line(x,y+80,x-40,y+40);
	line(x-40,y+40,x,y);
	
	line(x+70,y+10,x+280,y+10);
	line(x+280,y+10,x+310,y+40);
	line(x+310,y+40,x+280,y+70);
	line(x+280,y+70,x+70,y+70);
	
	puthz(x+130,y+20,"买车险",32,30,color);
}
/*************************************************
Function  :绘制办理baopei
Attention :x,y为六边形中心坐标
************************************************/
void drawbaopeitubiao(int x,int y,int color)
{
	setlinestyle(SOLID_LINE,0,3);
	setcolor(color);
	
	line(x-30,y-40,x+30,y-40);
	line(x+30,y-40,x+70,y);
	line(x+70,y,x+30,y+40);
	line(x+30,y+40,x-30,y+40);
	line(x-30,y+40,x-70,y);
	line(x-70,y,x-30,y-40);
	
	line(x+40,y-30,x+250,y-30);
	line(x+250,y-30,x+280,y);
	line(x+280,y,x+250,y+30);
	line(x+250,y+30,x+40,y+30);

	line(x-22,y-30,x+22,y-30);
	line(x-22,y-30,x-25,y-27);
	line(x-25,y-27,x-25,y+27);
	line(x-25,y+27,x-22,y+30);
	line(x-22,y+30,x+15,y+30);
	line(x+15,y+30,x+25,y+20);
	line(x+22,y-30,x+25,y-27);
	line(x+25,y-27,x+25,y+20);
	
	line(x-10,y-15-3,x,y-5-3);
	line(x,y-5-3,x+10,y-15-3);
	line(x-15,y-5-3,x+15,y-5-3);
	line(x-17,y+5-3+2,x+17,y+5-3+2);
	line(x,y-5-3,x,y+20-3);
	/*
	line(x-10,y-30,x,y-15);
	line(x+10,y-30,x,y-15);
	line(x-25,y-15,x+25,y-15);
	line(x-30,y+10,x+30,y+10);
	line(x,y-15,x,y+40);*/
	
	puthz(x+100,y-20,"保单理赔",32,30,color);
}
/****************************************
Function : drawusermain
Description: 绘制用户主函数
Attention:上一级功能函数：main.c->main;
return ：无
***************************************/
void drawusermain()
{
	
	cleardevice();
	setbkcolor(BLACK);
	
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"平安好车主",32,50,WHITE);
	puthz(510,17,"退出登录",16,20,WHITE);
	
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,3);
	//绘制退出登录的线框
	line(505,10,590,10);
	line(590,10,590,40);
	line(590,40,505,40);
	line(505,40,505,10);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,DARKGRAY);
	bar(0,430,640,480);
	line(160,430,160,480);
	line(320,430,320,480);
	line(480,430,480,480);
	puthz(30 ,450,"首页",16,40,WHITE);
	puthz(180,450,"找保险",16,40,WHITE);
	puthz(350,450,"享服务",16,40,WHITE);
	puthz(490,450,"个人中心",16,40,WHITE);
    drawtianjiatubiao(170,150,LIGHTGRAY);
	drawbaopeitubiao(200,320,LIGHTGRAY);
}
