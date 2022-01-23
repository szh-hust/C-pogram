/**************************************
Function List :   int service(setuser *person) 
				  int xiche(setuser * person)
				  int weizhang(setuser *person)
				  int baoyang(setuser *person)
                  void drawservice()
				  void drawxiche()
				  void drawweizhang(setuser *person)
				  void drawbaoyang()
**************************/
#include "service.h"
#include "common.h"
#include "draw.h"
#include "daolu.h"
#include <stdlib.h> 
#include "chesun.h"
#include "bywz.h"
/***********************************************
Function :service(setuser * person,struct POLICY policy[10])
Attention:���뱣���ṹ�� 
Description:
Return :usermain������judge 
***************************************************/
int service(setuser * person,struct POLICY policy[10])
{
	int judge = 0;
	int press,MouseX,MouseY;
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//��������ϴ������
		if(MouseX >=20 &&MouseX <=110 &&MouseY >= 110&&MouseY <=250 &&press)
		{
			judge = 1;
		}
		//����������
		if(MouseX >120 &&MouseX <=210 &&MouseY >= 110&&MouseY <=250 &&press)
		{
			judge = 2;
		}
		//��������Υ��
		if(MouseX >=250 &&MouseX <=350 &&MouseY >= 110&&MouseY <=250&&press)
		{
			judge =3;
		}
		//�������������
		if(MouseX >=370 &&MouseX <=470 &&MouseY >= 110&&MouseY <=250&&press)
		{
			judge =4;
		}
		//��������·��Ԯ
		if(MouseX >=530 &&MouseX <=640 &&MouseY >= 110&&MouseY <=250&&press)
		{
			judge =5;
		}
		//������˳���¼
		if(MouseX >=505 &&MouseX <=590 &&MouseY >= 10&&MouseY <=40 &&press)
		{
			clrmous(MouseX,MouseY);
			return 1;
		}
		//�����ҳ
		if(MouseX >=0 &&MouseX <=160 &&MouseY >= 430&&MouseY <=480 &&press)
		{
			
			return -1;
		}
		 //�����ұ��ս��� 
	    if (MouseX>=160 && MouseX<=320 && MouseY >=430 && MouseY<=480 && press)
	    {
	    	judge = 6;
	    }
		//�����������
		if(MouseX >=480 &&MouseX <=640 &&MouseY >= 430&&MouseY <=480 &&press)
		{
			return 2;
		}
		switch(judge)
		{
			case -1:
				{
					clrmous(MouseX,MouseY);
					drawservice(person);
					judge = 0;
					break;
				}
			case 1://ϴ��
			{
				drawxiche();
				judge = xiche(person);
				break;
			}
			case 2://����
			{
				clrmous(MouseX,MouseY);
				drawbaoyang();
				judge = baoyang (person);
				break;
			}
			case 3://��Υ��
			{
				drawweizhang(person);
				judge = weizhang(person);
				break;
			}
			case 4://�������
			{
				drawchesun(person,policy);
				judge = chesun(person,policy);
				break;
			}
			case 5:
			{
				drawdaolujiuyuan();
				judge=daolujiuyuan(policy);
				break;
			}
			case 6:
				{
					clrmous(MouseX,MouseY);
					delay(100);
		   			judge = jueding("����Ͷ��",1);
		   			if(judge== 1)
		   			{
		   				return 10;
					   }
					   else 
					   break;
				}
		}
	}
}
/***********************************************
Function :drawservice(setuser *person)
Attention:�����û����� 
Description:
Return :�� 
***************************************************/
void drawservice(setuser *person)
{
	char a[10];
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(510,17,"�˳���¼",16,20,WHITE);
	puthz(20,10,"ƽ���ó���",32,50,WHITE);
	setlinestyle(SOLID_LINE,0,3);
	/*
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,3);
	//�����˳���¼���߿�
	line(505,10,590,10);
	line(590,10,590,40);
	line(590,40,505,40);
	line(505,40,505,10);
	setfillstyle(1,DARKGRAY);
	bar(0,430,640,480);
	line(160,430,160,480);
	line(320,430,320,480);
	line(480,430,480,480);
	puthz(30 ,450,"��ҳ",16,40,WHITE);
	puthz(180,450,"�ұ���",16,40,WHITE);
	puthz(350,450,"�����",16,40,WHITE);
	puthz(490,450,"��������",16,40,WHITE);
	*/
	
	
	setcolor(WHITE);
	settextstyle(2,0,6);
	//�����˳���¼���߿�
	line(505,10,590,10);
	line(590,10,590,40);
	line(590,40,505,40);
	line(505,40,505,10);
	
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,1);
	line(50,100,590,100);
	ellipse(50,120,90,180,50,20);
	ellipse(590,120,0,90,50,20);
	putbmp(20,110,"./bmp/xi.bmp");
	puthz(40,170+50,"ϴ��",16,25,BLACK);
	putbmp(130,110,"./bmp/bao.bmp");
	puthz(125,170+50,"ԤԼ����",16,25,BLACK);
	putbmp(250,110,"./bmp/wei.bmp");
	puthz(250,170+50,"��Υ��",16,30,BLACK);
	putbmp(380,110,"./bmp/sun.bmp");
	puthz(374,170+50,"�������",16,25,BLACK);
	putbmp(530,110,"./bmp/jiu.bmp");
	puthz(530,170+50,"��·��Ԯ",16,25,BLACK);
	line(0,200+50,640,200+50);
	
	drawhaochezhu(220,290,LIGHTGRAY,LIGHTRED,100);
	drawhust(360,280,LIGHTGRAY,1);
	setfillstyle(1,LIGHTCYAN);
	floodfill(380,356,LIGHTGRAY);
	floodfill(425,358,LIGHTGRAY);
	floodfill(500,380,LIGHTGRAY);
	floodfill(550,300,LIGHTGRAY);
	setfillstyle(1,CYAN);
	
	setfillstyle(1,DARKGRAY);
	bar(0,430,640,480);
	line(160,430,160,480);
	line(320,430,320,480);
	line(480,430,480,480);
	puthz(30 ,450,"��ҳ",16,40,WHITE);
	puthz(180,450,"�ұ���",16,40,WHITE);
	puthz(350,450,"�����",16,40,WHITE);
	puthz(490,450,"��������",16,40,WHITE);
	setcolor(GREEN);
	itoa(1900+p->tm_year,a,10);
	outtextxy(20,60,a);
	puthz(60,62,"��",16,16,GREEN);
	itoa(1+p->tm_mon,a,10);
	outtextxy(80,60,a);
	puthz(90,62,"��",16,16,GREEN);
	itoa(p->tm_mday,a,10);
	outtextxy(110,60,a);
	puthz(140,62,"��",16,20,GREEN);
	puthz(500,62,"�û�",16,16,LIGHTGRAY);
	outtextxy(540,60,person->accounts);
	puthz(40,310,"������",16,25,GREEN); 
	puthz(70,340,"������",16,25,GREEN); 
	puthz(100,370,"������",16,25,GREEN); 
}
void drawditu() 
{
	setlinestyle(SOLID_LINE,0,3);
	setfillstyle(1,WHITE);
	bar(0,0,640,280);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	bar(0,50,640,60);
	line(560,50,560,10);
	circle(560,30,10);
	line(550,60,550,260);
	circle(550,250,10);
	line(550,200,590,200);
	circle(570,200,10);
	line(550,250,100,250);
	circle(100,250,10);
	line(400,60,400,200);
	circle(400,150,10);
	line(400,150,500,150);
	line(400,200,200,200);
	circle(300,200,10);
	line(200,200,200,100);
	line(200,170,100,170);
	circle(200,170,10);
	line(400,100,100,100);
	circle(100,100,10);
	line(100,100,100,250);
	line(100,200,50,200);
	line(50,60,50,150);
	circle(50,150,10);
	line(20,150,100,150);
	fillellipse(560,30,10,10);
	puthz(570,20,"���ﳵ��ϴ��",16,16,GREEN);
	fillellipse(550,250,10,10);
	puthz(560,230,"˳��ϴ����",16,16,GREEN);
	fillellipse(570,200,10,10);
	puthz(555,170,"����ϴ����",16,16,GREEN);
	fillellipse(100,250,10,10);
	puthz(10,240,"����ϴ��",16,16,GREEN);
	fillellipse(400,150,10,10);
	puthz(410,160,"����ϴ������",16,16,GREEN);
	fillellipse(300,200,10,10);
	puthz(280,220,"���������",16,16,GREEN);
	fillellipse(200,170,10,10);
	puthz(220,150,"����ϴ��",16,16,GREEN);
	fillellipse(100,100,10,10);
	puthz(110,65,"�����ڷ���",16,16,GREEN);
	fillellipse(50,150,10,10);
	puthz(10,160,"ϴ���˼�",16,16,GREEN);
	puthz(20,20,"��ѡ��ϴ����",16,20,GREEN);
}
/***********************************************
Function :drawxiche()
Attention:
Description:
Return :�� 
***************************************************/
void drawxiche()
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	
	drawditu() ;
	setlinestyle(SOLID_LINE,0,1);
	
	setcolor(RED);
	line(0,285,640,285);
	puthz(10,290,"���ĵ�ǰλ�ã�",16,20,BLACK);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	fillellipse(160,300,10,10);
	//drawlittlecar(150,280,GREEN,2);
	puthz(20,325,"����������ĵ�ǰλ�������飬�������˹���λ",16,16,GREEN);
	puthz(20,350,"�ڵ�ͼѡ�����ĵص㼴��",16,16,GREEN);
//	puthz(50,410,"ȷ������󼴿�ѡ������Ҫ��ϴ����",16,16,GREEN);
	setfillstyle(1,CYAN);
	bar(0,440,100,480);
	puthz(20,450,"����",16,30,WHITE);
	bar(540,380,640,420);
	puthz(555,390,"�˹���λ",16,20,WHITE);
	bar(540,440,640,480);
	puthz(555,450,"ȷ������",16,20,WHITE);
}

/***********************************************
Function :xiche(setuser * person)
Attention:�����û���� 
Description:
Return :service.c->service������judge 
***************************************************/
int xiche(setuser * person)
{
	int x= 410,y=55;
	int judge = 0;
	int flag = 0;//�������Ƿ��Ѿ�ѡ����ϴ���� 0��ʾδѡ��
	int press,MouseX,MouseY;
	int p = 0;
	int shoudong;
	int k;
	int  feiyongnum = 0;
	int juli ;
	char julistr[6];
	char dianming[9][16]={
		{"ϴ���˼�"},
		{"����ϴ��"},
		{"�����ڷ���"},
		{"����ϴ��"},
		{"���������"},
		{"����ϴ������"},
		{"˳��ϴ����"},
		{"���ﳵ��ϴ��"},
		{"����ϴ����"}
	};
	char feiyong[9][10]={"40","50","55","58","45","52","61","89","55"};
	char lianxi [9][13]=
	{
		{"027-88888880"},
		{"027-88888881"},
		{"027-88888882"},
		{"027-88888883"},
		{"027-88888884"},
		{"027-88888885"},
		{"027-88888886"},
		{"027-88888887"},
		{"027-8888888"}
	};
	char pingfen[9][5]=
	{
		{"4.6"},
		{"4.8"},
		{"4.3"},
		{"5.0"},
		{"4.7"},
		{"4.6"},
		{"4.8"},
		{"4.7"},
		{"4.5"},
	};
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	fillellipse(410,55,10,10);
	//drawlittlecar(x,y,GREEN,2);
	clrmous(MouseX,MouseY);
	delay(100);
	//save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(p == 0)
		{
			//���ȷ��
			if(MouseX >=540 && MouseX <= 640&& MouseY >= 440&& MouseY <= 480 &&press )
			{
				p = 1;
				setfillstyle(1,WHITE);
				bar(0,286,100,440);
				bar(100,286,430,480);
				puthz(20,290,"������Ϣ����",16,20,GREEN);
				setcolor(LIGHTBLUE);
				setlinestyle(SOLID_LINE,0,3);
				line(120,340,140,320);
				line(140,320,500,320);
				line(500,320,520,340);
				line(520,340,520,440);
				line(520,440,500,460);
				line(500,460,140,460);
				line(140,460,120,440);
				line(120,440,120,340);
				puthz(180,330,"������",16,20,BLACK);
				puthz(140,355,"�������֣�",16,20,BLACK);
				puthz(140,380,"�������룺",16,20,BLACK);
				puthz(140,405,"ϴ���۸�",16,20,BLACK);
				puthz(140,425,"��ϵ�绰��",16,20,BLACK);
				setfillstyle(1,LIGHTGRAY);
				bar(540,380,640,420);
				puthz(555,390,"ȡ��ѡ��",16,20,WHITE);
				clrmous(MouseX,MouseY);
				bar(540,440,640,480);
				puthz(555,450,"ȷ��ѡ��",16,20,WHITE);
				delay(100);
			}
			//����ֶ���λ
			if(shoudong != 1&&MouseX >=540 && MouseX <= 640&& MouseY >= 380&& MouseY <= 420 &&press)
			{
				shoudong = 1;
				judge = 5;
			}
		}
		if(p == 1)
		{
			if(MouseX>= 50-10 &&MouseX<= 50+10 &&MouseY>= 150-10 &&MouseY<= 150+10 &&press)
			{
				k = 0;
				juli = abs( x-50)+abs(150-y);	
				judge = 4;
			}
			if(MouseX>= 100-10 &&MouseX<= 100+10 &&MouseY>= 100-10 &&MouseY<= 100+10 &&press)
			{
				k = 1;
				juli = abs( x-100)+abs(100-y);
				judge = 4;
			}
			if(MouseX>= 100-10 &&MouseX<= 100+10 &&MouseY>= 250-10 &&MouseY<= 250+10 &&press)
			{
				k = 2;
				juli = abs( x-100)+abs(250-y);
				judge = 4;
			}
			if(MouseX>= 200-10 &&MouseX<= 200+10 &&MouseY>= 170-10 &&MouseY<= 170+10 &&press)
			{
				k = 3;
				juli = abs( x-200)+abs(170-y);
				judge = 4;
			}if(MouseX>= 300-10 &&MouseX<= 300+10 &&MouseY>=200-10 &&MouseY<= 200+10 &&press)
			{
				k = 4;
				juli = abs( x-300)+abs(200-y);
				judge = 4;
			}
			if(MouseX>= 400-10 &&MouseX<= 400+10 &&MouseY>= 150-10 &&MouseY<= 150+10 &&press)
			{
				k = 5;
				juli = abs( x-400)+abs(150-y);
				judge = 4;
			}
			if(MouseX>= 550-10 &&MouseX<= 550+10 &&MouseY>= 250-10 &&MouseY<= 250+10 &&press)
			{
				k = 6;
				juli = abs( x-550)+abs(250-y);
				judge = 4;
			}
			if(MouseX>= 560-10 &&MouseX<= 560+10 &&MouseY>= 30-10 &&MouseY<= 30+10 &&press)
			{
				k = 7;
				juli = abs( x-560)+abs(30-y);
				judge = 4;
			}
			if(MouseX>= 570-10 &&MouseX<= 570+10 &&MouseY>= 200-10 &&MouseY<= 200+10 &&press)
			{
				k = 8;
				juli = abs( x-570)+abs(200-y);
				judge = 4;
			}
			//���ȷ��
			if(MouseX >=540 && MouseX <= 640&& MouseY >= 440&& MouseY <= 480 &&press && flag == 1)
			{
				judge = 2;
			}
			//���ȡ��
			if(MouseX >=540 && MouseX <= 640&& MouseY >= 380&& MouseY <= 420 &&press && flag == 1)
			{
				judge = 3;
			}
			if(MouseX >=0 && MouseX <= 100&& MouseY >= 380&& MouseY <= 420 &&press )
			{
				setfillstyle(1,LIGHTGRAY);
				bar(540,380,640,420);
				puthz(555,390,"�˹���λ",16,20,WHITE);
				setfillstyle(1,CYAN);
				bar(540,440,640,480);
				puthz(555,450,"ȷ������",16,20,WHITE);
				judge  = 5;
			}
		}
		//�������
		if(MouseX >=0 && MouseX <= 100&& MouseY >= 440&& MouseY <= 480 &&press)
		{
			return -1;
		}	
		switch(judge)
		{
			case -1:
			{
				flag = 0;
				p =0;
				shoudong = 0;
				clrmous(MouseX,MouseY);
				drawxiche();
				setcolor(GREEN);
				setfillstyle(1,GREEN);
				fillellipse(x,y,10,10);
				//drawlittlecar(x,y,GREEN,2);
				judge = 0;
				break;
			}
			case -2:
			{
				clrmous(MouseX,MouseY); 
				drawxiche()	;
				setfillstyle(1,WHITE);
				bar(0,286,100,440);
				bar(100,286,430,480);
				puthz(20,290,"������Ϣ����",16,20,GREEN);
				setcolor(LIGHTBLUE);
				setlinestyle(SOLID_LINE,0,3);
				line(120,340,140,320);
				line(140,320,500,320);
				line(500,320,520,340);
				line(520,340,520,440);
				line(520,440,500,460);
				line(500,460,140,460);
				line(140,460,120,440);
				line(120,440,120,340);
				puthz(180,330,"������",16,20,BLACK);
				puthz(140,355,"�������֣�",16,20,BLACK);
				puthz(140,380,"�������룺",16,20,BLACK);
				puthz(140,405,"ϴ���۸�",16,20,BLACK);
				puthz(140,425,"��ϵ�绰��",16,20,BLACK);
				setfillstyle(1,LIGHTGRAY);
				bar(540,380,640,420);
				puthz(555,390,"ȡ��ѡ��",16,20,WHITE);
				clrmous(MouseX,MouseY);
				bar(540,440,640,480);
				puthz(555,450,"ȷ��ѡ��",16,20,WHITE);
				itoa(juli,julistr,10);
				setfillstyle(1,WHITE);
				bar(250,330,250+190,450);
				settextstyle(SMALL_FONT,0,6);
				puthz(250,330,dianming[k],16,16,BLACK);
				setcolor(BLACK);
				outtextxy(250,355,pingfen[k]);
				outtextxy(250,380,julistr);
				outtextxy(300,380,"m");
				outtextxy(250,405,feiyong[k]);
				puthz(300,405,"Ԫ",16,20,BLACK);
				outtextxy(250,428,lianxi[k]);
				setfillstyle(1,CYAN);
				bar(540,380,640,420);
				puthz(555,390,"ȡ��ѡ��",16,20,WHITE);
				clrmous(MouseX,MouseY);
				bar(540,440,640,480);
				puthz(555,450,"ȷ��ѡ��",16,20,WHITE);
				setcolor(GREEN);
				setfillstyle(1,GREEN);
				fillellipse(x,y,10,10);
				judge = 0;
				break;
				
			}
			case 2://���ȷ��
			{
				setfillstyle(1,WHITE);
				bar(250,330,250+190,450);
				feiyongnum = atoi(feiyong[k]);
				judge = zhifu("ϴ������",feiyongnum,person,-2);
				flag = 0;
				break;
			}
			case 3://���ȡ��
			{
				setfillstyle(1,WHITE);
				bar(250,330,250+190,450);
				clrmous(MouseX,MouseY);
				setfillstyle(1,LIGHTGRAY);
				bar(540,380,640,420);
				puthz(555,390,"ȡ��ѡ��",16,20,WHITE);
				clrmous(MouseX,MouseY);
				bar(540,440,640,480);
				puthz(555,450,"ȷ��ѡ��",16,20,WHITE);
				judge = 0;
				flag = 0;
				break;
			}
			case 4:
			{
				itoa(juli,julistr,10);
				setfillstyle(1,WHITE);
				bar(250,330,250+190,450);
				settextstyle(SMALL_FONT,0,6);
				puthz(250,330,dianming[k],16,16,BLACK);
				setcolor(BLACK);
				outtextxy(250,355,pingfen[k]);
				outtextxy(250,380,julistr);
				outtextxy(300,380,"m");
				outtextxy(250,405,feiyong[k]);
				puthz(300,405,"Ԫ",16,20,BLACK);
				outtextxy(250,428,lianxi[k]);
				setfillstyle(1,CYAN);
				bar(540,380,640,420);
				puthz(555,390,"ȡ��ѡ��",16,20,WHITE);
				clrmous(MouseX,MouseY);
				bar(540,440,640,480);
				puthz(555,450,"ȷ��ѡ��",16,20,WHITE);
				flag = 1;
				judge = 0;
				break;
			}
			case 5:
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,LIGHTGRAY);
				bar(540,380,640,420);
				puthz(555,390,"�˹���λ",16,20,WHITE);
				puthz(150,440,"���ڽ����˹���λ",16,20,RED);
				judge = dingwei(&x,&y);
				break;
			}
			case 6:
			{
				shoudong = 0;
				p = 1;
				setfillstyle(1,WHITE);
				bar(0,286,100,440);
				bar(100,286,430,480);
				puthz(20,290,"������Ϣ����",16,20,GREEN);
				setcolor(LIGHTBLUE);
				setlinestyle(SOLID_LINE,0,3);
				line(120,340,140,320);
				line(140,320,500,320);
				line(500,320,520,340);
				line(520,340,520,440);
				line(520,440,500,460);
				line(500,460,140,460);
				line(140,460,120,440);
				line(120,440,120,340);
				puthz(180,330,"������",16,20,BLACK);
				puthz(140,355,"�������֣�",16,20,BLACK);
				puthz(140,380,"�������룺",16,20,BLACK);
				puthz(140,405,"ϴ���۸�",16,20,BLACK);
				puthz(140,425,"��ϵ�绰��",16,20,BLACK);
				setfillstyle(1,LIGHTGRAY);
				bar(540,380,640,420);
				puthz(555,390,"ȡ��ѡ��",16,20,WHITE);
				clrmous(MouseX,MouseY);
				bar(540,440,640,480);
				puthz(555,450,"ȷ��ѡ��",16,20,WHITE);
				setfillstyle(1,CYAN);
				bar(0,380,100,420);
				puthz(15,390,"����ѡ��",16,20,WHITE);
				delay(100);
				judge = 0;
				break;
			}
		}
	}
}
/***********************************************
Function :dingwei(int *x,int *y)
Attention:�����û�λ�õ����꣬��ָ����ʽ���� 
Description: 
Return :�� 
***************************************************/
int dingwei(int *x,int *y)
{
	int judge = 0;
	int flag = 0;
	int press,MouseX,MouseY;
	clrmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if( MouseY >= 60 &&MouseY <= 280&&flag==0)
		{
			MouseS=3;
			flag=1;
		}
		if(flag==1&&( MouseY < 60 ||MouseY > 280))
		{
			MouseS=0;
			flag=0;
		}
		if(MouseX!=*x&&MouseY!=*y && MouseY >= 70 &&MouseY <= 270&&press)
		{
		    judge=1;
		}
		if(MouseX >=540 && MouseX <= 640&& MouseY >= 440&& MouseY <= 480 &&press )
		{
			return 6;
		}
		switch(judge)
		{
			case 1:
			{
				clrmous(MouseX,MouseY);
				drawditu();
				*x = MouseX;
				*y = MouseY;
				setcolor(GREEN);
				setfillstyle(1,GREEN);
				fillellipse(*x,*y,10,10);
				
				judge = 0;
				break;
			} 
		}
	}
	
}
