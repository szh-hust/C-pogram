#include "common.h"
#include "draw.h"
#include "mlogin.h"
/*����ʵ������¼����*/
int mainlogin(void)
{
	int judge = 1;
	clrmous(MouseX,MouseY);
	delay(500);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(220,220,420,260)==1)//�û���¼����
		{
			judge = 2;
			
		}
		else if(mouse_press(220,220+40+40,420,220+80+40)==1)//�������Ա��¼����
		{
			judge = 3;
			
		}
		else if(mouse_press(565,0,615,80)==1)//�˳�����
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
				judge  =jueding("�뿪����",4);
				break;
			}
		}
	}
}
/*���Ƶ�¼ע��������*/
void drawmainlogin()
{
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,650,480);
	puthz(200,70,"ƽ���ó���",48,50,DARKGRAY);
	puthz(320,155,"һ�ڳ���������",16,30,BLACK);
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
	
	puthz(230,230,"�˺ŵ�¼",16,30,BLACK);
	puthz(230,310,"����Ա��¼",16,30,BLACK);
	//puthz(10,445,"�˳�",16,30,BLACK);
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
