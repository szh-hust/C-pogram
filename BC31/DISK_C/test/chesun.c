#include"common.h"
#include "service.h"
#include "chesun.h"
int chesun(setuser *person,struct POLICY policy[10])
{
	int judge = 0;
	char pcity[3];
	char plate[7];
	char pinpai[15];
	int k=1;//用于判定第几步以及要贴的图
	int press,MouseX,MouseY;
	char kstr[2]={'\0','\0'};
	int  m[4]={0,0,0,0};
	long sdje = 0;
	char mstr[7];
	int a[4][4];
	int i=0,j=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j]=0;
		}
	}
	if(policy[0].p==0)
	{
		puthz(140,85,"暂无车辆",16,16,GREEN);
		puthz(100,115,"游客试用",16,16,GREEN);
	}
	else
	{
		strcpy(pcity,policy[0].pcity);
		strcpy(plate,policy[0].plate);
		strcpy(pinpai,policy[0].pinpai);
		puthz(140,85,pcity,16,20,GREEN);
		outtextxy(160,85,plate);
		puthz(100,115,pinpai,16,20,GREEN);
	}
	delay(100);
	save_bk_mou(MouseX,MouseY);
	kstr[0]=k+'0';
	outtextxy(540,250,kstr);
	putbmp(40,260,"./bmp/a.bmp");
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	pieslice(40+98,260+129,0,360,10);
	puthz(40+98,260+129+20,"前左车轮",16,16,GREEN);
	pieslice(40+200,260+100,0,360,10);
	puthz(40+200,260+100+30,"左车门",16,16,GREEN);
	pieslice(40+355,260+130,0,360,10);
	puthz(40+355,260+130+20,"后左车门",16,16,GREEN);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//button(400,110,100,40,CYAN,CYAN,1);
		if(policy[0].p !=0&&MouseX >=350 &&MouseX <=450 &&MouseY >= 90 &&MouseY <= 130 &&press)
		{
			judge = 3;
		}
		/*返回上一页*/
		if(MouseX >=20 &&MouseX <=50 &&MouseY >= 10 &&MouseY <= 50 &&press)
		{
			judge = 1;
		}
		/*下一步*/
		if(k!=4&&MouseX >=530 &&MouseX <=630 &&MouseY >= 300 &&MouseY <= 340 &&press)
		{
			k++;
			judge = -1;
		}
		/*无车损*/
		if(MouseX >=530 &&MouseX <=630 &&MouseY >= 360 &&MouseY <= 400 &&press)
		{
			if(k==4)
			{
				judge = 2;
			}
			else 
			{
				for(j= 0;j<4;j++)
				{
					a[k-1][j]= 0;
				}
				k++;
				judge = -1;
			}
		}
		/*完成车损*/
		if(k==4&&MouseX >=530 &&MouseX <=630 &&MouseY >= 420 &&MouseY <= 460 &&press)
		{
			judge = 2;
		}
	if(judge != 4)	
	{
		if(k==1)
		{
			if(MouseX >=40+98-10 &&MouseX <=40+98+10 &&MouseY >= 260+129-10 &&MouseY <= 260+129+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[0][0]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+98,260+129,0,360,10);
					m[0]++;
					delay(200);
					a[0][0]=1;
				}
				else if(a[0][0]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+98,260+129,0,360,10);
					m[0]--;
					delay(200);
					a[0][0]=0;
				}	
			}
			if(MouseX >=40+200-10 &&MouseX <=40+200+10 &&MouseY >= 260+100-10 &&MouseY <= 260+100+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[0][1]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+200,260+100,0,360,10);
					m[0]++;
					delay(200);
					a[0][1]=1;
				}
				else if(a[0][1]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+200,260+100,0,360,10);
					m[0]--;
					delay(200);
					a[0][1]=0;
				}
			}
			if(MouseX >=40+355-10 &&MouseX <=40+355+10 &&MouseY >= 260+130-10 &&MouseY <= 260+130+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[0][2]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+355,260+130,0,360,10);
					m[0]++;
					delay(200);
					a[0][2]=1;
				}
				else if(a[0][2]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+355,260+130,0,360,10);
					m[0]--;
					delay(200);
					a[0][2]=0;
				}
			}
		}
		if(k==2)
		{
			if(MouseX >=40+260-10 &&MouseX <=40+260+10 &&MouseY >= 260+100-10 &&MouseY <= 260+100+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[1][0]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+260,260+100,0,360,10);
					m[1]++;
					delay(200);
					a[1][0]=1;
				}
				else if(a[1][0]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+260,260+100,0,360,10);
					m[1]--;
					delay(200);
					a[1][0]=0;
				}
			}
			if(MouseX >=40+350-10 &&MouseX <=40+350+10 &&MouseY >= 260+130-10 &&MouseY <= 260+130+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[1][1]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+350,260+130,0,360,10);
					m[1]++;
					delay(200);
					a[1][1]=1;
				}
				else if(a[1][1]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+350,260+130,0,360,10);
					m[1]--;
					delay(200);
					a[1][1]=0;
				}
			}
			if(MouseX >=40+90-10 &&MouseX <=40+90+10 &&MouseY >= 260+130-10 &&MouseY <= 260+130+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[1][2]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+90,260+130,0,360,10);
					m[1]++;
					delay(200);
					a[1][2]=1;
				}
				else if(a[1][2]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+90,260+130,0,360,10);
					m[1]--;
					delay(200);
					a[1][1]=0;
				}
			}
		}
		if(k==3)
		{
			if(MouseX >=40+380-10 &&MouseX <=40+380+10 &&MouseY >= 260+100-10 &&MouseY <= 260+100+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[2][0]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+380,260+100,0,360,10);
					m[2]++;
					delay(200);
					a[2][0]=1;
				}
				else if(a[2][0]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+380,260+100,0,360,10);
					m[2]--;
					delay(200);
					a[2][0]=0;
				}
			}
			if(MouseX >=40+190-10 &&MouseX <=40+190+10 &&MouseY >= 260+100-10 &&MouseY <= 260+100+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[2][1]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+190,260+100,0,360,10);
					m[2]++;
					delay(200);
					a[2][1]=1;
				}
				else if(a[2][1]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+190,260+100,0,360,10);
					m[2]--;
					delay(200);
					a[2][1]=0;
				}
			}
		}
		if(k==4)
		{
			if(MouseX >=40+105-10 &&MouseX <=40+105+10 &&MouseY >= 260+40-10 &&MouseY <= 260+40+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[3][0]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+105,260+40,0,360,10);
					m[3]++;
					delay(200);
					a[3][0]=1;
				}
				else if(a[3][0]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+105,260+40,0,360,10);
					m[3]--;
					delay(200);
					a[3][0]=0;
				}
			}
			if(MouseX >=40+110-10 &&MouseX <=40+110+10 &&MouseY >= 260+100-10 &&MouseY <= 260+100+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[3][1]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(40+110,260+100,0,360,10);
					m[3]++;
					delay(200);
					a[3][1]=1;
				}
				else if(a[3][1]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(40+110,260+100,0,360,10);
					m[3]--;
					delay(200);
					a[3][1]=0;
				}
			}
			if(MouseX >=270+110-10 &&MouseX <=270+110+10 &&MouseY >= 260+45-10 &&MouseY <= 260+45+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[3][2]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(270+110,260+45,0,360,10);
					m[3]++;
					delay(200);
					a[3][2]=1;
				}
				else if(a[3][2]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(270+110,260+45,0,360,10);
					m[3]--;
					delay(200);
					a[3][2]=0;
				}
			}
			if(MouseX >=270+110-10 &&MouseX <=270+110+10 &&MouseY >= 260+110-10 &&MouseY <= 260+110+10 &&press)
			{
				clrmous(MouseX,MouseY);
				if(a[3][3]==0)
				{
					setcolor(GREEN);
					setfillstyle(1,RED);
					pieslice(270+110,260+110,0,360,10);
					m[3]++;
					delay(200);
					a[3][3]=1;
				}
				else if(a[3][3]==1)
				{
					setfillstyle(1,GREEN);
					pieslice(270+110,260+110,0,360,10);
					m[3]--;
					delay(200);
					a[3][3]=0;
				}
			}
		}
	}
			if(judge == 4&&MouseX >=270 &&MouseX <=370 &&MouseY >= 300 &&MouseY <= 340 &&press)
			{
				return -1;
			}
		switch(judge)
		{
			case -2:
			{
				clrmous(MouseX,MouseY);
				drawchesun();
				puthz(140,85,pcity,16,20,GREEN);
				outtextxy(160,85,plate);
				puthz(100,115,pinpai,16,20,GREEN);
				setfillstyle(1,WHITE);
				bar(40,260,490,435);
				bar(540,250,565,280);
				kstr[0]=k+'0';
				outtextxy(540,250,kstr);
				switch(k)
				{
					case 1: 
					{
						putbmp(40,260,"./bmp/a.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+98,260+129,0,360,10);
						puthz(40+98,260+129+20,"前左车轮",16,16,GREEN);
						pieslice(40+200,260+100,0,360,10);
						puthz(40+200,260+100+30,"左车门",16,16,GREEN);
						pieslice(40+355,260+130,0,360,10);
						puthz(40+355,260+130+20,"后左车门",16,16,GREEN);
						break;
					}
					case 2:
					{
						putbmp(40,260,"./bmp/b.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+260,260+100,0,360,10);
						puthz(40+260,260+100+30,"右车门",16,16,GREEN);
						pieslice(40+350,260+130,0,360,10);
						puthz(40+350,260+130+20,"后右车轮",16,16,GREEN);
						pieslice(40+90,260+130,0,360,10);	
						puthz(40+90,260+130+20,"前右车轮",16,16,GREEN);
						break;
					}				
					case 3: 
					{
						putbmp(40,260,"./bmp/c.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+380,260+100,0,360,10);
						puthz(40+380,260+100+40,"前车擎盖",16,16,GREEN);
						pieslice(40+190,260+100,0,360,10);
						puthz(40+190,260+100+30,"车顶",16,16,GREEN);
						break;
					}
					case 4:
					{
						putbmp(40,260,"./bmp/d.bmp");
						putbmp(270,260,"./bmp/e.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+105,260+40,0,360,10);
						puthz(40+105+30,260+40,"前玻璃",16,16,GREEN);
						pieslice(40+110,260+100,0,360,10);
						puthz(40+110,260+100+30,"前保险杠",16,16,GREEN);
						pieslice(270+110,260+45,0,360,10);
						puthz(270+110+30,260+45,"后玻璃",16,16,GREEN);
						pieslice(270+110,260+110,0,360,10);
						puthz(270+110,260+110+30,"后保险杠",16,16,GREEN);
						break;
					}		
				}
				judge = 0;
				break;
			}
			case -1:
			{
				setfillstyle(1,WHITE);
				bar(40,260,490,435);
				bar(540,250,565,280);
				kstr[0]=k+'0';
				outtextxy(540,250,kstr);
				clrmous(MouseX,MouseY);
				if(k==4)
				{
					Barshadow(530,420,630,460,CYAN,LIGHTGRAY);
					puthz(540,430,"完成测损",16,20,WHITE);
					Barshadow(530,300,630,340,LIGHTGRAY,CYAN);
					puthz(540,310,"下一步",16,20,WHITE);
					
				}
				switch(k)
				{
					case 1: 
					{
						putbmp(40,260,"./bmp/a.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+98,260+129,0,360,10);
						puthz(40+98,260+129+20,"前左车轮",16,16,GREEN);
						pieslice(40+200,260+100,0,360,10);
						puthz(40+200,260+100+30,"左车门",16,16,GREEN);
						pieslice(40+355,260+130,0,360,10);
						puthz(40+355,260+130+20,"后左车门",16,16,GREEN);
						break;
					}
					case 2:
					{
						putbmp(40,260,"./bmp/b.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+260,260+100,0,360,10);
						puthz(40+260,260+100+30,"右车门",16,16,GREEN);
						pieslice(40+350,260+130,0,360,10);
						puthz(40+350,260+130+20,"后右车轮",16,16,GREEN);
						pieslice(40+90,260+130,0,360,10);	
						puthz(40+90,260+130+20,"前右车轮",16,16,GREEN);
						break;
					}				
					case 3: 
					{
						putbmp(40,260,"./bmp/c.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+380,260+100,0,360,10);
						puthz(40+380,260+100+40,"前车擎盖",16,16,GREEN);
						pieslice(40+190,260+100,0,360,10);
						puthz(40+190,260+100+30,"车顶",16,16,GREEN);
						break;
					}
					case 4:
					{
						putbmp(40,260,"./bmp/d.bmp");
						putbmp(270,260,"./bmp/e.bmp");
						setcolor(GREEN);
						setfillstyle(1,GREEN);
						pieslice(40+105,260+40,0,360,10);
						puthz(40+105+30,260+40,"前玻璃",16,16,GREEN);
						pieslice(40+110,260+100,0,360,10);
						puthz(40+110,260+100+30,"前保险杠",16,16,GREEN);
						pieslice(270+110,260+45,0,360,10);
						puthz(270+110+30,260+45,"后玻璃",16,16,GREEN);
						pieslice(270+110,260+110,0,360,10);
						puthz(270+110,260+110+30,"后保险杠",16,16,GREEN);
						break;
					}		
				}
				judge = 0;
				break;
			}
			case 1:
			{
				return -1;
			}
			case 2:
			{
				sdje = m[0]*1000+m[1]*689+m[2]*702+m[3]*493;
				ltoa(sdje,mstr,10);
				/*
				提示函数
				*/
				drawwaiting("理赔核算中");
				setfillstyle(1,WHITE);
				bar(140+15+5,110+15+5,500-15-5,370-15-5);
				if(m[4]==0)
				{
					puthz(200,160,"您没有选择车损部位",32,30,GREEN);
				}
				else 
				{
					puthz(220,160,"核算结果为",32,40,GREEN);
					puthz(210,200,"您的爱车修理所需的金额为",16,20,GREEN);
					settextstyle(2,0,6);
					setcolor(CYAN);
					outtextxy(300,230,mstr);
					puthz(300,260,"元",32,40,GREEN);
				}
				setfillstyle(1,CYAN);
				bar(270,300,370,340);
				puthz(280,310,"我已知晓",16,20,WHITE);
				judge = 4;
				break;
				//return -1;
			}
			case 3:
			{
				clrmous(MouseX,MouseY);
				judge  =choosepla( policy,350,130,pcity,plate,pinpai);
				break;
			}
		}
	}
}
/***********************************************
Function :drawchesun()
Attention:
Description:绘制车损函数 
Return :无 
***************************************************/
void drawchesun()
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setlinestyle(SOLID_LINE,0,1);
	line(50,10,20,30);
	line(20,30,50,50);
	puthz(200,10,"车损测算",32,50,DARKGRAY);
	line(0,60,640,60);
	setlinestyle(SOLID_LINE,0,3);
	line(40,70,600,70);
	line(20,80,20,180);
	line(40,190,600,190);
	line(620,80,620,180);
	ellipse(40,80,90,180,20,10);
	ellipse(600,80,0,90,20,10);
	ellipse(40,180,180,270,20,10);
	ellipse(600,180,270,360,20,10);	
	puthz(40,85,"测损车辆：",16,20,LIGHTGRAY);
	puthz(40,115,"品牌：",16,20,LIGHTGRAY);
	button(400,110,100,40,CYAN,CYAN,0);
	puthz(350,100,"测测其他车辆",16,16,CYAN);
	setcolor(GREEN);
	settextstyle(2,0,6);
	//puthz(140,85,policy[0].pcity,16,20,GREEN);
	//outtextxy(160,85,policy[0].plate);
	//puthz(100,115,policy[0].pinpai,16,20,GREEN);
	outtextxy(40,150,"Tips:");
	puthz(85,153,"不同车型的车维修价格也不同哦",16,20,LIGHTGRAY);
	puthz(40,200,"请依次点击您车损部位 若无则选择无即可",16,20,GREEN);
	setcolor(BLACK);
	line(40,250,470,250);
	line(20,260,20,435);
	line(40,445,470,445);
	line(490,260,490,435);
	ellipse(40,260,90,180,20,10);
	ellipse(40,435,180,270,20,10);
	ellipse(470,435,270,360,20,10);
	ellipse(470,260,0,90,20,10);
	
	//图像大小450*175  (40,260,490,435)
	puthz(520,250,"第  步",16,20,BLACK);
	puthz(520,280,"共 步",16,30,BLACK);
	
	outtextxy(540,278,"4");
	Barshadow(530,300,630,340,CYAN,LIGHTGRAY);
	puthz(540,310,"下一步",16,20,WHITE);
	Barshadow(530,360,630,400,CYAN,LIGHTGRAY);
	puthz(540,370,"无车损",16,20,WHITE);
	Barshadow(530,420,630,460,LIGHTGRAY,CYAN);
	puthz(540,430,"完成测损",16,20,WHITE);
	
}
int choosepla(struct POLICY policy[10],int x,int y,char pcity[3],char plate[7],char pinpai[15])
{
	int i=0,j=0,k=0;
	setfillstyle(1,WHITE);
	for(i=0;i<10;i++)
	{
		if(policy[i].p==1)
		{
			j++;
		}
	}
	bar(x,y,x+200,y+j*40);
	rectangle(x,y,x+200,y+j*40);
	j=0;
	for(i=0;i<10;i++)
	{
		if(policy[i].p==1)
		{
			puthz(x+10,y+10+i*40,policy[i].pcity,16,16,GREEN);
			outtextxy(x+40,y+10+i*40,policy[i].plate);
			line(x,y+40+i*40,x+200,y+40+i*40);
			j++;
		}
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=x &&MouseX <=x+200 &&MouseY >= y &&MouseY <= y+j*40&&press)
		{
			k = (MouseY-y)/40;
			strcpy(pcity,policy[k].pcity);
			strcpy(plate,policy[k].plate);
			strcpy(pinpai,policy[k].pinpai);
			return -2;
		}
	}
}
void drawwaiting(char *item)
{
	int x,y,i,t;
	setfillstyle(1,WHITE);
	bar(120,90,520,390);//400*300
	setcolor(CYAN);
	setlinestyle(SOLID_LINE,0,3);
	rectangle(140-15,110-15,140+15,110+15);
	rectangle(140-15,370-15,140+15,370+15);
	rectangle(500-15,110-15,500+15,110+15);
	rectangle(500-15,370-15,500+15,370+15);
	rectangle(145,115,495,365);
	line(140-5,110+15+5,140-5,370-15-5);
	line(500+5,110+15+5,500+5,370-15-5);
	line(140+15+5,110-5,500-15-5,110-5);
	line(140+15+5,370+5,500-15-5,370+5);
	x = 170;
	y = 340;
	i = 0;
	//(170,340,470,346);
	setfillstyle(1,BLACK);
	bar(168,338,472,348);
	setfillstyle(1,WHITE);
	bar(170,340,470,346);
	puthz(220,160,item,32,40,GREEN);
	outtextxy(330,200,"waiting...");
	setlinestyle(SOLID_LINE,0,1);
	setcolor(BLACK);
	rectangle(120,90,520,390);
	
	for(i=0;x<=465;i++)
	{
		if(i%5==0)
		{
			t=(i/5)%5;
			switch(t)
			{
				case 0:setfillstyle(1, LIGHTCYAN);
				       break;
				case 1:setfillstyle(1, CYAN);
				       break;
				case 2:setfillstyle(1, LIGHTBLUE);
				       break;
				case 3:setfillstyle(1, CYAN);
				       break;
				case 4:setfillstyle(1, LIGHTGREEN);
				       break;
			}
			bar(x,y,x+5,y+6);
			x+=5;
		}
		delay(5);
	}
	delay(50);
	return ;
}
