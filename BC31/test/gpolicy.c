#include "common.h"
#include <string.h>
#include "policy1.h"
#include "policy2.h"
#include "gpolicy.h"
#include "draw.h"
/***************************************************
function:drawgetpolicy(char money_str[][10],int *flagnew,char *plate,char *pinpai,char baofei[][10],int *flag)
Attention:绘制购买保险的界面 
Description:
return :无 
***************************************************/
void drawgetpolicy(char money_str[][10],int *flagnew,char *plate,char *pinpai,char baofei[][10],int *flag)
{
	
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setcolor(CYAN);
	rectangle(20,20,620,440);
	if(plate[0]=='\0')
	{
		puthz(30,30,"新车暂无车牌",16,16,BLACK);
	}
	else
	{
		puthz(30,30,"鄂",16,220,BLACK);
		setcolor(BLACK);
		outtextxy(60,30,plate);
	}
	puthz(140,35,pinpai,16,20,LIGHTGRAY);	
	puthz(300,35,"湖北省武汉市投保",16,20,BLACK);
	setcolor(CYAN);
	line(20,70,620,70);	
	puthz(40,80,"投保",32,40,DARKGRAY);
	puthz(40,120,"方案",32,40,DARKGRAY);
	puthz(40,170,"已选",32,40,DARKGRAY);
	puthz(40,210,"投保",32,40,DARKGRAY);
	puthz(40,250,"方案",32,40,DARKGRAY);
	line(130,20,130,440);	
	puthz(140,80,"交强险",16,20,BLACK);	
	puthz(315,80,"投保",16,16,BLACK);	
	puthz(315+60,80,"否",16,16,BLACK);
	line(130,110,620,110);
	puthz(140,125,"商业综合保障",16,20,BLACK);
	puthz(315,125,"投保",16,16,BLACK);
	setcolor(LIGHTGRAY);
	circle(300,90,10);
	circle(300+60,90,10);
	circle(300,135,10);
	circle(300+60,135,10);
	setcolor(CYAN);
	puthz(315+60,125,"否",16,16,BLACK);
	line(20,160,620,160);
	//puthz(150,180,"交强险与商业综合保障至少选择其中之一！",16,20,RED);

	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	bar(540,445,640,480);
	puthz(10,455,"上一页",16,30,WHITE);
	puthz(550,455,"确认投保",16,20,WHITE);
	setfillstyle(1,CYAN);
	puthz(160,170,"保障项目",16,20,LIGHTGRAY);
	puthz(160+150,170,"保额（元）",16,20,LIGHTGRAY);
	puthz(160+150+150,170,"保费（元）",16,20,LIGHTGRAY);
	if(flagnew[0]==1) 
	{
		fillellipse(300,90,10,10);
		puthz(440,80,"金额：    元",16,16,BLACK);
		outtextxy(500,80,"950");
		strcpy(money_str[0],"950");
	}
	else if(flagnew[0]==2) 
	{
		fillellipse(360,90,10,10);
		strcpy(money_str[0],"0");
	}
	if(flagnew[5]==1) fillellipse(300,135,10,10);
	    else if(flagnew[5]==2) fillellipse(360,135,10,10);
	puthz(160,400,"合计",16,30,BLACK);
}
/***************************************************
function:getpolicy(char money_str[][10],int *flagnew,char *plate,
			char *pinpai,char baofei[][10],int *flag,char *time)
Attention:购买保险功能 
Description:
return :3
***************************************************/
int getpolicy(char money_str[][10],int *flagnew,char *plate,char *pinpai,char baofei[][10],int *flag,char *time)
{
	int judge = 0;
	int press,MouseX,MouseY;
	int money[5]={0,0,0,0,0};
	int i=0,j=0;
	char name[4][10]={"车损险","三者险","司机险","乘客险"};
	long  moneysum,money0;
	int baofeisum,baofei0;
	for(i=1;i<5;i++)
	{
		if(flagnew[i]==1)
		{
			puthz(160,200+j*50,name[i-1],16,20,BLACK);
			outtextxy(310,200+50*j,money_str[i]);
			outtextxy(460,200+50*j,baofei[i]);
			j++;
		}
	}
	moneysum = atol(money_str[5]);
	baofeisum = atol(baofei[5]);
	outtextxy(160+150,400,money_str[5]);
	outtextxy(160+150+150,400,baofei[5]);
	delay(100);
//	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=0 &&MouseX <=100 &&MouseY >=445  &&MouseY <= 480 &&press)
		{
			return 1;
		}
		if(MouseX >=290 &&MouseX <=310 &&MouseY >=80  &&MouseY <= 100 &&press&&flagnew[0]!=1)
		{
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(300+60,90,10,10);
			bar(300,390,500,420);
			setfillstyle(1,CYAN);
			fillellipse(300,90,10,10);
			puthz(440,80,"金额：    元",16,16,BLACK);
			setcolor(CYAN);
			outtextxy(500,80,"950");
			money[0] = 950;
			moneysum+=950;
			baofeisum = atol(baofei[5]);
			baofeisum += 50;
			itoa(money[0],money_str[0],10);
			strcpy(baofei[0],"50");
			ltoa(baofeisum,baofei[5],10);
			ltoa(moneysum,money_str[5],10);
			outtextxy(310,400,money_str[5]);
			outtextxy(460,400,baofei[5]);
			flagnew[0]=1;
			delay(300);
		}
		if(MouseX >=290+60 &&MouseX <=310+60 &&MouseY >=80  &&MouseY <= 100 &&press&&flagnew[0]!=2)
		{
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			bar(300,390,600,420);
			fillellipse(300,90,10,10);
			bar(430,80,610,100);
			setfillstyle(1,CYAN);
			fillellipse(300+60,90,10,10);
			money[0] = 0;
			
			if(flagnew[0]==1)
			{
				moneysum-=950;
				baofeisum -=50;
			}
			ltoa(baofeisum,baofei[5],10);
			itoa(money[0],money_str[0],10);
			ltoa(moneysum,money_str[5],10);
			setcolor(CYAN);
			outtextxy(310,400,money_str[5]);
			outtextxy(460,400,baofei[5]);
			strcpy(baofei[0],"0");
			baofei[0][9]='\0'; 
			delay(300);
			flagnew[0]=2;
		}
		if(MouseX >=290 &&MouseX <=310 &&MouseY >=80+45  &&MouseY <= 100+45 &&press)
		{
			//flagnew2=1;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(300+60,90+45,10,10);
			setfillstyle(1,CYAN);
			fillellipse(300,90+45,10,10);
			judge = 1;	
		}
		if(MouseX >=290+60 &&MouseX <=310+60 &&MouseY >=80+45  &&MouseY <= 100+45 &&press)
		{
			flagnew[5]=2;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(300,90+45,10,10);
			setfillstyle(1,CYAN);
			fillellipse(300+60,90+45,10,10);
			setfillstyle(1,WHITE);
			bar(160,200,600,390);
			bar(300,390,500,420);
			strcpy(money_str[5],money_str[0]);
			strcpy(baofei[5],baofei[0]);
			setcolor(CYAN);
			outtextxy(310,400,money_str[5]);
			outtextxy(460,400,baofei[5]);
			for(i=1;i<5;i++)
			{
				strcpy(money_str[i],"0");
				strcpy(baofei[i],"0");
				flagnew[i]=0;
			}
		}
		/*完成投保*/
		if(MouseX >=550 &&MouseX <=640 &&MouseY >=445  &&MouseY <= 480 &&press)
		{
			judge = 2;
		}
		switch(judge)
		{
			case -1:
			{
				drawgetpolicy(money_str,flagnew,plate,pinpai,baofei,flag);
				j=0;
				for(i=1;i<5;i++)
				{
					if(flagnew[i]==1)
					{
						puthz(160,200+j*50,name[i-1],16,20,BLACK);
						outtextxy(310,200+50*j,money_str[i]);
						outtextxy(460,200+50*j,baofei[i]);
						j++;
					}
				}
				moneysum = atol(money_str[5]);
				baofeisum = atol(baofei[5]);
				if(flagnew[0]==1) 
				{
					money0=atol(money_str[0]);
					moneysum += money0;
					ltoa(moneysum,money_str[5],10);
				}
				outtextxy(310,400,money_str[5]);
				outtextxy(460,400,baofei[5]);
				save_bk_mou(MouseX,MouseY);
				judge  = 0;
				delay(100);
				break;
			}
			case 1:
			{
				drawtoubao(flagnew,money_str,baofei,flag);
				judge = toubao(flagnew,money_str,baofei,flag,time,pinpai);
				break;
			}
			case 2:
			{
				if(flagnew[0]!=1&&flagnew[5]!=1)
				{
					puthz(160,200,"交强险与商业综合保障至少选择其中之一！",16,20,RED);
					judge = 0;
				}
				else {
					return 3;
				}
				break;
			}
		}
	}
}
/***************************************************
function:drawtoubao(int *flagnew,char money_str[][10],char baofei[][10],int *flag)
Attention:绘制投界面 
Description:
return :无 
***************************************************/
void drawtoubao(int *flagnew,char money_str[][10],char baofei[][10],int *flag)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setcolor(CYAN);
	setlinestyle(SOLID_LINE,0,1);
	line(20,20,20,50);
	puthz(30,20,"未选险种及服务",32,40,BLACK);
	setfillstyle(1,LIGHTGRAY);
	bar(30,80,610,440);
					setfillstyle(1,WHITE);
					bar(40,90,600,430);
	puthz(50,100,"保障项目",16,20,DARKGRAY);
	puthz(150,100,"投保状态",16,20,DARKGRAY);
	puthz(300,100,"保额（元）",16,16,BLACK);
	
	puthz(50,150,"车损险",16,20,BLACK);
	if(flagnew[1]==0) 
	{
		puthz(150,150,"点击投保",16,20,LIGHTGRAY);
		puthz(320,150,"无",16,20,LIGHTGRAY);
	}
	else if(flagnew[1]==1)
	{
		puthz(150,150,"已投保",16,20,LIGHTGRAY);
		
		drawjiajian(300,145);
		setcolor(CYAN);
		outtextxy(310,150,money_str[1]);
	}
	puthz(50,200,"三者险",16,20,BLACK);
	if(flagnew[2]==0) 
	{
		puthz(150,200,"点击投保",16,20,LIGHTGRAY);
		puthz(320,200,"无",16,20,LIGHTGRAY);
	}
	else if(flagnew[2]==1)
	{
		puthz(150,200,"已投保",16,20,LIGHTGRAY);
		
		drawjiajian(300,195);
		setcolor(CYAN);
		outtextxy(310,200,money_str[2]);
	}
	puthz(50,250,"司机险",16,20,BLACK);
	if(flagnew[3]==0) 
	{
		puthz(150,250,"点击投保",16,20,LIGHTGRAY);
		puthz(320,250,"无",16,20,LIGHTGRAY);
	}
	else if(flagnew[3]==1)
	{
		puthz(150,250,"已投保",16,20,LIGHTGRAY);
		drawjiajian(300,245);
		setcolor(CYAN);
		outtextxy(310,250,money_str[3]);
	}
	puthz(50,300,"乘客险",16,20,BLACK);
	if(flagnew[4]==0) 
	{
		puthz(150,300,"点击投保",16,20,LIGHTGRAY);
		puthz(320,300,"无",16,20,LIGHTGRAY);
	}
	else if(flagnew[4]==1)
	{
		puthz(150,300,"已投保",16,20,LIGHTGRAY);
		drawjiajian(300,295);
		setcolor(CYAN);
		outtextxy(310,300,money_str[4]);
		
	}
	puthz(500,150,"查看详情",16,20,CYAN);
	puthz(500,200,"查看详情",16,20,CYAN);	
	puthz(500,250,"查看详情",16,20,CYAN);
	puthz(500,300,"查看详情",16,20,CYAN);
	
	puthz(400,340,"保额合计    元",16,20,BLACK);
	puthz(500,400,"完成选择",16,20,CYAN);
	
	puthz(50,340,"点击投保状态即更改投保状态",16,16,LIGHTGRAY);
	puthz(50,370,"您可自己设定投保保额",16,16,LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	bar(0,450,100,480);
	puthz(10,455,"返回",16,25,WHITE);
}
/***************************************************
function:drawjiajian(int x,int y)
Attention:绘制投保时的加减 按钮 
Description:
return :无 
***************************************************/
void drawjiajian(int x,int y)
{
	//x,y为金额输出是矩形框的左上角
	setcolor(LIGHTGRAY);
	rectangle(x,y,x+80,y+30);
	setfillstyle(1,CYAN);
	bar(x-20,y,x,y+30);
	bar(x+80,y,x+100,y+30);
	setcolor(WHITE);
	line(x-18,y+15,x-2,y+15);
	line(x+80+1,y+15,x+80+19,y+15);
	line(x+80+10,y+5,x+80+10,y+25);
	setfillstyle(1,WHITE);
	bar(x+2,y+1,x+78,y+28);
}
/***************************************************
function:toubao(int *flagnew,char money_str[][10],char baofei[][10],int *flag,char *time,char *pinpai)
Attention:投保主功能函数 
Description:
return :-1/1 
***************************************************/
int toubao(int *flagnew,char money_str[][10],char baofei[][10],int *flag,char *time,char *pinpai)
{
	int MouseX,MouseY,press;
	int judge =0;
	int money;
	long moneysum=0;
	int i=0;
	int j;
	long  sum=0,bao;
	for(i=1;i<5;i++)
	{
		money = atoi(money_str[i]);
		moneysum+=money;
	}
	ltoa(moneysum,money_str[5],10);
	setcolor(CYAN);
	outtextxy(500,345,money_str[5]);
	save_bk_mou(MouseX,MouseY);
	delay(100);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=150 &&MouseX <=150+100 &&MouseY >=150 &&MouseY <= 150+30 &&press)
			judge = 1;
		if(MouseX >=150 &&MouseX <=150+100 &&MouseY >=200 &&MouseY <= 200+30 &&press)
			judge = 2;
		if(MouseX >=150 &&MouseX <=150+100 &&MouseY >=250 &&MouseY <= 250+30 &&press)
			judge = 3;
		if(MouseX >=150 &&MouseX <=150+100 &&MouseY >=300 &&MouseY <= 300+30 &&press)
			judge = 4;
		if(flagnew[1] == 1)
		{
			if(MouseX >=300-20 &&MouseX <=300 &&MouseY >=150-5 &&MouseY <= 150+30-5 &&press)
			{
				judge = 5;
				j = 1;
			}
			if(MouseX >=380 &&MouseX <=380+20 &&MouseY >=150-5 &&MouseY <= 150+30-5 &&press)
			{
				judge = 6;
				j = 1;
			}
		}
		if(flagnew[2] == 1)
		{
			if(MouseX >=300-20 &&MouseX <=300 &&MouseY >=200-5 &&MouseY <= 200+30-5 &&press)
			{
				judge = 5;
				j = 2;
			}
			if(MouseX >=380 &&MouseX <=380+20 &&MouseY >=200-5 &&MouseY <= 200+30-5 &&press)
			{
				judge = 6;
				j = 2;
			}
		}
		if(flagnew[3] == 1)
		{
			if(MouseX >=300-20 &&MouseX <=300 &&MouseY >=250-5 &&MouseY <= 250+30-5 &&press)
			{
				judge = 5;
				j = 3;
			}
			if(MouseX >=380 &&MouseX <=380+20 &&MouseY >=250-5 &&MouseY <= 250+30-5 &&press)
			{
				judge = 6;
				j = 3;
			}
		}
		if(flagnew[4] == 1)
		{
			if(MouseX >=300-20 &&MouseX <=300 &&MouseY >=300-5 &&MouseY <= 300+30-5 &&press)
			{
				judge = 5;
				j = 4;
			}
			if(MouseX >=380 &&MouseX <=380+20 &&MouseY >=300-5 &&MouseY <= 300+30-5 &&press)
			{
				judge = 6;
				j = 4;
			}
		}
		//完成选择
		if(MouseX >=500 &&MouseX <=600 &&MouseY >=400  &&MouseY <= 430 &&press)
		{
			judge = 8;
		}
		//返回
		if(MouseX >=0 &&MouseX <=100 &&MouseY >=450  &&MouseY <= 480 &&press)
		{
			judge = 9;
		}
		//查看详情
		//车损险
		if(MouseX >=500 &&MouseX <=600 &&MouseY >=150  &&MouseY <= 180 &&press)
		{
			judge = 11;
		}//三者险
		if(MouseX >=500 &&MouseX <=600 &&MouseY >=200  &&MouseY <= 230 &&press)
		{
			judge = 12;
		}//司机险
		if(MouseX >=500 &&MouseX <=600 &&MouseY >=250  &&MouseY <= 280 &&press)
		{
			judge = 13;
		}//乘客险
		if(MouseX >=500 &&MouseX <=600 &&MouseY >=300  &&MouseY <= 330 &&press)
		{
			judge = 14;
		}	
		switch(judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY);
				drawtoubao(flagnew,money_str,baofei,flag);
				moneysum = 0;
				for(i=1;i<5;i++)
				{
					money = atoi(money_str[i]);
					moneysum+=money;
				}
				ltoa(moneysum,money_str[5],10);
				setcolor(CYAN);
				outtextxy(500,340,money_str[5]);
				judge = 0;
				break;
			}
			case 1:
			{
				if(flagnew[1]==0)
				{
					clrmous(MouseX,MouseY);
					setfillstyle(1,WHITE);
					bar(150,150,250,180);
					drawjiajian(300,150-5);
					strcpy(money_str[1],"1000");
					puthz(150,150,"已投保",16,20,LIGHTGRAY);
					setcolor(CYAN);
					outtextxy(310,155-5,money_str[1]);
					flagnew [1] = 1;
				}
				else if(flagnew[1]==1)
				{
					clrmous(MouseX,MouseY);
					flagnew [1] = 0;
					setfillstyle(1,WHITE);
					bar(150,150,250,150+30);
					bar(250,150-5,400,190-5);
					puthz(150,150,"点击投保",16,20,LIGHTGRAY);
					puthz(320,150,"无",16,20,LIGHTGRAY);
					strcpy(money_str[1],"0");
				}
				delay(300);
				judge = 7;
				break;
			}
			case 2:
			{
				if(flagnew[2]==0)
				{
					clrmous(MouseX,MouseY);
					setfillstyle(1,WHITE);
					bar(150,200,250,230);
					drawjiajian(300,200-5);
					strcpy(money_str[2],"1000");
					puthz(150,200,"已投保",16,20,LIGHTGRAY);
					setcolor(CYAN);
					outtextxy(310,205-5,money_str[2]);
					flagnew[2] = 1;
				}
				else if(flagnew[2]==1)
				{
					clrmous(MouseX,MouseY);
					flagnew[2] = 0;
					setfillstyle(1,WHITE);
					bar(150,200,250,200+30);
					bar(250,200-5,400,240-5);
					puthz(150,200,"点击投保",16,20,LIGHTGRAY);
					puthz(320,200,"无",16,20,LIGHTGRAY);
					strcpy(money_str[2],"0");
				}
				delay(300);
				judge = 7;
				break;
			}
			case 3:
			{
				if(flagnew[3]==0)
				{
					clrmous(MouseX,MouseY);
					setfillstyle(1,WHITE);
					bar(150,250,250,280);
					drawjiajian(300,250-5);
					strcpy(money_str[3],"1000");
					puthz(150,250,"已投保",16,20,LIGHTGRAY);
					setcolor(CYAN);
					outtextxy(310,255-5,money_str[3]);
					flagnew[3] = 1;
				}
				else if(flagnew[3]==1)
				{
					clrmous(MouseX,MouseY);
					flagnew[3] = 0;
					setfillstyle(1,WHITE);
					bar(150,250,250,250+30);
					bar(250,250-5,400,280-5);
					puthz(150,250,"点击投保",16,20,LIGHTGRAY);
					puthz(320,250,"无",16,20,LIGHTGRAY);
					strcpy(money_str[3],"0");
				}
				delay(300);
				judge = 7;
				break;
			}
			case 4:
			{
				if(flagnew[4]==0)
				{
					clrmous(MouseX,MouseY);
					setfillstyle(1,WHITE);
					bar(150,300,250,330);
					drawjiajian(300,300-5);
					strcpy(money_str[4],"1000");
					puthz(150,300,"已投保",16,20,LIGHTGRAY);
					setcolor(CYAN);
					outtextxy(310,305-5,money_str[4]);
					flagnew[4] = 1;
				}
				else if(flagnew[4]==1)
				{
					clrmous(MouseX,MouseY);
					flagnew[4] = 0;
					setfillstyle(1,WHITE);
					bar(150,300,250,300+30);
					bar(250,300-5,400,340-5);
					puthz(150,300,"点击投保",16,20,LIGHTGRAY);
					puthz(320,300,"无",16,20,LIGHTGRAY);
					strcpy(money_str[4],"0");
				}
				delay(300);
				judge = 7;
				break;
			}
			case 5:
			{
				money = atoi(money_str[j]);
				money -= 1000;
				if(money<=0)
				{
					flagnew[j]=1;
					judge = j;
					delay(300);
					break;
				}
				else 
				{
					clrmous(MouseX,MouseY);
					itoa(money,money_str[j],10);
					setfillstyle(1,WHITE);
					bar(302,100+50*j+2-5,378,100+50*j+26-5);
					setcolor(CYAN);
					outtextxy(310,5+100+50*j-5,money_str[j]);
					judge = 7;
					delay(300);
					break;
				}
			}
			case 6:
			{
				clrmous(MouseX,MouseY);
				money = atoi(money_str[j]);
				money += 1000;
				if(money>=31000)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("保额不能再多了",250,170,16,20,-1);
				}
				else
				{
					itoa(money,money_str[j],10);
					setfillstyle(1,WHITE);
					bar(302,100+50*j+2-5,378,100+50*j+26-5);
					setcolor(CYAN);
					outtextxy(310,5+100+50*j-5,money_str[j]);
					judge = 7;
					delay(300);
				}
				break;
			}
			case 7://运算总保额
			{
				moneysum = 0;
				for(i=1;i<5;i++)
				{
					money = atoi(money_str[i]);
					moneysum += money;
				}	
				ltoa(moneysum,money_str[5],10);
				setfillstyle(1,WHITE);
				bar(500,340,560,380);
				setcolor(CYAN);
				outtextxy(500,343,money_str[5]);
				judge = 0;
				break;
			}
			case 8://完成投保
			{
				if(strcmp(money_str[5],"0")==0)
				{
					//clrmous(MouseX,MouseY);
					judge = queren("您还没选择任何商业险",250,170,16,20,-1);
					flagnew[5] = 2;
					break;
				}
				else 
				{
					sum = atoi(baofei[0]);
					bao = 0;
					for(i=1;i<5;i++)
					{
						if(flagnew[i]==1)
						{
							getbaofei(i,money_str,baofei,flag,time,pinpai);
						}	
						bao = atoi(baofei[i]);
						sum += bao;
					}
					ltoa(sum,baofei[5],10);
					flagnew[5] = 1;
					return -1;
				}
			}
			case 9:
			{
				clrmous(MouseX,MouseY);
				judge = tips(1);
				if(judge == 1 )
				{
					for(i=1;i<5;i++)
					{
						strcpy(money_str[i],"0");
						flagnew[i]=0;
						strcpy(baofei[i],"0");
					}
					flagnew[5]=  2;
					strcpy(money_str[5],"0");
					strcpy(baofei[5],baofei[0]);
					return -1;
				}
				break;
			}
			case 11:
			{
				drawxiangqing(1,money_str);
				judge = xiangqing(1,money_str,flagnew);
				break;
			}
			case 12:
			{
				drawxiangqing(2,money_str);
				judge = xiangqing(2,money_str,flagnew);
				break;
			}
			case 13:
			{
				drawxiangqing(3,money_str);
				judge = xiangqing(3,money_str,flagnew);
				break;
			}
			case 14:
			{
				drawxiangqing(4,money_str);
				judge = xiangqing(4,money_str,flagnew);
				break;
			}
		}
		
	}
	return 0;
}
int tips(int returnnum)
{
	int press;
	int MouseX,MouseY;
	
	setfillstyle(1,LIGHTGRAY);
	bar(155,115,485,365);
	setfillstyle(1,WHITE);
	bar(160,120,480,360);//320*240
	Drawbeautiful(160,120,0.5);
	puthz(240,170,"取消您已选择的保险？",16,20,GREEN);
	setfillstyle(1,CYAN);
	bar(210,280,270,320);
	bar(370,280,430,320);
	puthz(230,290,"是",16,16,WHITE);
	puthz(390,290,"否",16,20,WHITE);
	delay(100);
	clrmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=370 && MouseX <= 430 && MouseY >=280 && MouseY <= 320 && press)
			return -1;	
		if(MouseX >=210 && MouseX <= 270 && MouseY >=280 && MouseY <= 320 && press)
			return returnnum;
	}
}
/***************************************************
function:drawxiangqing(int i,char money_str[][10])
Attention:绘制查看详情界面 
Description:
return :无
***************************************************/
void  drawxiangqing(int i,char money_str[][10])
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setcolor(CYAN);
	setlinestyle(SOLID_LINE,0,1);
	line(20,20,20,50);
	puthz(30,20,"未选险种及服务",32,40,BLACK);
	setfillstyle(1,LIGHTGRAY);
	bar(30,80,610,440);
	setfillstyle(1,WHITE);
	bar(40,90,600,430);
	puthz(50,100,"投保小贴士",16,20,CYAN);
	puthz(50,130,"简介：",16,20,GREEN);
	
	puthz(50,255,"适用人群：",16,20,GREEN);
	setcolor(LIGHTGRAY);
	rectangle(550,90,600,140);
	setcolor(RED);
	line(560,100,590,130);
	line(560,130,590,100);

	switch(i)
	{
		case 1:
		{	setcolor(BLACK);
			puthz(200,100,"车损险",16,20,CYAN);
			puthz(80,160,"赔付由于自然灾害或者意外事故造成的车辆自身损失；",16,16,BLACK);
			puthz(60,190,"综改后新增了盗抢、无法找到第三方、自燃、发动机涉水损坏 ",16,16,BLACK);
			puthz(60,220,"玻璃单独破碎等损失。",16,20,BLACK);
			puthz(60,280,"所有车主",16,16,BLACK);
			puthz(50,310,"案例",16,16,GREEN);
			puthz(60,340,"开车不慎碰撞导致车辆受损；将车停在路边被挡风玻璃被掉落的花盆砸碎",16,16,BLACK);
			puthz(60,370,"停放时被碰擦受损，找不到肇事者；车子因线路老化自燃",16,16,BLACK);
			puthz(60,400,"自然灾害、涉水行驶导致发动机进水损坏",16,16,BLACK);
			//puthz(60,430,"",16,16,BLACK);
			break;
		}
		case 2:
		{
			setcolor(BLACK);
			puthz(200,100,"三者险",16,20,CYAN);
			puthz(80,160,"被保险员允许的合格驾驶员在使用被保险车辆过程中发生的意",16,16,BLACK);
			puthz(60,190,"外事故致使第三方遭受人身伤亡或财产损失保险公司依法予以赔偿",16,16,BLACK);
			puthz(60,220,"若保险公司不同意赔付，相关仲裁费由用户支付",16,20,BLACK);
			puthz(60,280,"所有车主",16,16,BLACK);
			puthz(50,310,"案例",16,16,GREEN);
			puthz(60,340,"小李开车时不慎和前车发生追尾。经交警判定小李全责，前车修车花费",16,16,BLACK);
			puthz(60,370,"一万元，扣除交强险赔付的两千元后，剩余的八千元由三者险进行",16,16,BLACK);
			puthz(60,400,"理赔。",16,16,BLACK);
			break;
		}
		case 3:
		{
			setcolor(BLACK);
			puthz(200,100,"司机险",16,20,CYAN);
			puthz(80,160,"赔付本车车内驾驶员的人身伤亡费用",16,16,BLACK);
			puthz(60,190,"若用户在其他车辆中出现交通事故，本保险依旧生效",16,16,BLACK);
			puthz(60,220,"若在投保车辆上的车主并非投保人，本险不生效",16,16,BLACK);
			puthz(60,280,"所有车主尤其是用车较为频繁的车主",16,16,BLACK);
			puthz(50,310,"案例",16,16,GREEN);
			puthz(60,340,"小李投保了车上人员司机险一万元，自驾游途中发生碰撞导致头部受伤",16,16,BLACK);
			puthz(60,370,"住院治疗共计花费五千元。小李报案理赔后，最终获得五千元的赔款。",16,16,BLACK);
			break;
		}
		case 4:
		{
			setcolor(BLACK);
			puthz(200,100,"乘客险",16,20,CYAN);
			puthz(80,160,"赔付本车车内乘客（非驾驶员）的人身伤亡费用",16,16,BLACK);
			puthz(60,190,"保险车辆出现意外时，车上乘客出现人身伤亡或财产损失",16,16,BLACK);
			puthz(60,220,"司机和乘客的投保人数不得多于投保车辆核定座位数",16,16,BLACK);
			puthz(60,280,"所有车主",16,16,BLACK);
			puthz(50,310,"案例",16,16,GREEN);
			puthz(60,340,"小李投保了车上人员乘客险每座一万元，自驾游途中发生碰撞，导致副",16,16,BLACK);
			puthz(60,370,"驾上的儿子腿部受伤，住院治疗共计花费三千元。小李报案理赔后，",16,16,BLACK);
			puthz(60,400,"最终获得三千元的赔款。",16,16,BLACK);
			break;
		}
	}
}
/***************************************************
function:xiangqing(int i,char money_str[][10],int *flagnew)
Attention:查看详情界面 
Description:
return :-1
***************************************************/
int xiangqing(int i,char money_str[][10],int *flagnew)
{
	int judge ;
	int MouseX,MouseY,press;
	save_bk_mou(MouseX,MouseY);
	delay(100);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=550 &&MouseX <=600 &&MouseY >=90  &&MouseY <= 140 &&press)
		{
	
			return -1;
		}
	}	
}
/***********************************************
Function :int getbaofei(int i,char money_str[][10],char baofei[][10],int *flag,char *time,char *pinpai)
Attention:i表示第几个保险
Description:计算得到应交的保费
Return :0 
***************************************************/
int getbaofei(int i,char money_str[][10],char baofei[][10],int *flag,char *time,char *pinpai)
{  
	int j;
	int t;
	int  mon;
	int  bao;
	int time1;
	char name[16][10]={"奥迪","宝马","别克","比亚迪","长安",
	                 "雪弗兰","保时捷","福特","长城","本田"	,				
					 "现代","起亚","日产","丰田","大众","其他" 
	};
	/*
	30-60
	30-60
	18-20
	10-18
	7-18
	
	16-33
	50-200
	20-40
	6-15
	10-30
	
	10-15
	10-15
	10-40
	20-40
	15-30
	20
	*/
	int pinpaimoney[16]={45,45,19,16,12, 25,125,30,10,20, 13,13,25,30,26,20};
	for(j=0;j<16;j++)
	{
		if(strcmp(pinpai,name[j])==0)
		{
			t= j;
			break;
		}
	}
	time1 = atoi(time);
	mon = atoi(money_str[i]);
	if(mon<5000)
	{
		bao=mon/100+i*3+flag[1]*3+flag[2]*3+flag[3]*3+time1*4+pinpaimoney[t]*2/5;
	}
	else if(mon>=5000&&mon<9000)
	{
		bao = (mon-5000)/90+i*4+20+flag[1]*3+flag[2]*3+flag[3]*3+time1*4+pinpaimoney[t]*2/5;
	}
	else if(mon>=9000&&mon<15000)
	{
		bao = (mon-9000)/80+i*5+3000/80+20+flag[1]*3+flag[2]*3+flag[3]*3+time1*4+pinpaimoney[t]*2/5;
	}
	else if(mon>=15000) 
	{
		bao = (mon-5000)/80+i*5+3000/80+20+flag[1]*3+flag[2]*3+flag[3]*3+time1*4+pinpaimoney[t]*2/5;
	}
	itoa(bao,baofei[i],10);
	return 0;
}

