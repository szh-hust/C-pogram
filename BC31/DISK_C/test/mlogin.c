#include "common.h"
#include "draw.h"
#include "mlogin.h"
/*用于实现主登录界面*/
int mainlogin(void)
{
	int judge = 1;
	clrmous(MouseX,MouseY);
	delay(500);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(220,220,420,260)==1)//用户登录界面
		{
			judge = 2;
			
		}
		else if(mouse_press(220,220+40+40,420,220+80+40)==1)//进入管理员登录界面
		{
			judge = 3;
			
		}
		else if(mouse_press(565,0,615,80)==1)//退出程序
		{
			judge = 5;
		}
		switch(judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY);
				//delay(100);
				drawmainlogin();
				judge = 0;
				break;
			}
			case 2:
			{
				return 2;
			}
			case 3:
			{
				return 3;
			}
			case 4:
			{
				return 4;
			}
			case 5:
			{
				clrmous(MouseX,MouseY);
				delay(100);
				judge  =jueding("离开程序",4);
				break;
			}
		}
	}
}
/*绘制登录注册主界面*/
void drawmainlogin()
{
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,650,480);
	puthz(200,70,"平安好车主",48,50,DARKGRAY);
	puthz(320,155,"一亿车主都在用",16,30,BLACK);
    //drawlittlecar(10,300,LIGHTBLUE,12);
	drawhust(170,230-30,LIGHTGRAY,2);
	setfillstyle(1,LIGHTCYAN);
	floodfill(204,363,LIGHTGRAY);
	floodfill(300,370,LIGHTGRAY);
	floodfill(500,240,LIGHTGRAY);
	Barshadow(220,220,420,260,CYAN,LIGHTGRAY);
	Barshadow(220,300,420,340,CYAN,LIGHTGRAY);
	//Barshadow(0,430,90,470,CYAN,LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	
	puthz(230,230,"账号登录",16,30,BLACK);
	puthz(230,310,"管理员登录",16,30,BLACK);
	//puthz(10,445,"退出",16,30,BLACK);
	setlinestyle(0, 0, 3);
	
	setcolor(LIGHTRED);
	arc(590, 50, 110, 430, 25);
	arc(590, 50, 110, 430, 23);
	setlinestyle(0, 0, 3);
	line(589, 15, 589, 51);
	line(591,15,591,51);
	
	setcolor(BROWN);
	settextstyle(2,0,6);
	outtextxy(5,450,"Copyright@2021-2024HUST-Shaozonghe,Sunjikai.All rights reserved.");
	drawhaochezhu(10,10,LIGHTGRAY,LIGHTRED,100);
}
