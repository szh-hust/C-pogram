#include "common.h"
#include "lipei1.h"
#include "lipei2.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "draw.h"
/****************************************
Function : lipeimain(setuser *person,struct POLICY policy[10],struct CLAIM claim[10],int cn)
Description:理赔界面主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int lipeimain(setuser *person,struct POLICY policy[10],struct CLAIM claim[10],int cn)
{
	int judge = 0;
	int t;//用于表示某个被选择的保单,即policy[t]
	int g[4]={0,0,0,0};
	int i=0;
	int press,MouseX,MouseY;
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		switch(judge)
		{
			case -1:
			{
				return -1;
			}
			case 0:
			{
				clrmous(MouseX,MouseY);
				drawchoosepolicy(policy);
				judge = choosepolicy(policy,&t);
                strcpy(claim[cn].bdh,policy[t].bdh);
				strcpy(claim[cn].dianhua,policy[t].dianhua);
				break;
			}
			case 1:
			{
				clrmous(MouseX,MouseY);
				drawlipei(policy,t,g);
				judge = lipei(policy,t,g,claim,cn);
				break;
			}
			case 2:
			{
				clrmous(MouseX,MouseY);
				drawxzlpfs();
				judge = xzlpfs(policy,t,claim,cn);
				break;
			}
			case 3:
			{
				clrmous(MouseX,MouseY);
				drawzzlp();
				judge=zzlp(policy,t,claim,cn);
				break;
			}
			case 4:
			{
				clrmous(MouseX,MouseY);
				drawrgfw();
				judge=rgfw(policy,t,claim,cn);
				break;
			}
			case 5:
			{
				claim[cn].p=1;
				policy[t].zt = 1;
				strcpy(claim[cn].ybe,policy[t].money_str[5]);
				putclaim(person,claim,cn);
				changepolicy(t,1);
				return -1;
			}
		}
	}
}
/****************************************
Function :changepolicy(int i,int j)
Description:修改保单状态函数
Attention:该用户的第i个保单状态修改为j；
Return：上一个界面的judge值
***************************************/
int changepolicy(int i,int j)
{
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p1=NULL;   //指向需要接收字符的地址的指针变量
	int judge=-1;
	int m=0;
	char j_str[2]={'\0','\0'};
	j_str[0]=48+j;
	p1= j_str;
	if ((fp = fopen("./t_file/user/policy.txt", "r+")) == NULL)
	{
		closegraph();
		printf("Can't open policy.txt");
		getchar();
		exit(1);
	}
    while (!feof(fp))
	{
		cha = fgetc(fp);
		if(cha=='/')//'/'默认为账户名的开始
		{
			judge++;
		}
		if(judge==i&&cha=='#')
		{
			m++;
		}
		if(m==22&&cha=='#')
		{
			fseek(fp,0,SEEK_CUR);
			fputs("1",fp);
			//putc(*p1,fp);
			fclose(fp);
			puthz(100,100,"修改成功",16,16,BLACK);
			break;
		}
	}
}
/****************************************
Function :drawchoosepolicy(struct POLICY policy[10])
Description:画选择保单界面函数
Attention:无
Return：无
***************************************/
void drawchoosepolicy(struct POLICY policy[10])
{
	int i=0,k=0;//i用于决定policy
	settextstyle(2,0,6);
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(578,80,"？",32,40,LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(LIGHTGRAY);
	circle(590,98,20);
	puthz(10,10,"平安好车主",32,30,WHITE);
	puthz(170,30,"车损理赔",16,20,WHITE);
	puthz(270,30,"保单选择",16,16,WHITE);
	puthz(10,60,"您拥有的保单如下 ",16,20,GREEN);
	puthz(10,95,"请选择您想要理赔的保单",16,20,GREEN);
	setfillstyle(1,GREEN);
	for(i=0;i<4;i++)
	{
		bar(0,130+i*80,640,170+i*80);
	}
	puthz(10,140,"保单编号",16,20,WHITE);
	puthz(120,140,"车牌号",16,20,WHITE);
	puthz(250,140,"保额（元）",16,20,WHITE);
	puthz(380,140,"保费（元）",16,20,WHITE);
	i=0;
	setfillstyle(1,LIGHTGRAY);
	bar(0,440,100,480);
	bar(540,440,640,480);
	puthz(20,450,"返回",16,25,WHITE);
	puthz(560,450,"下一页",16,25,WHITE);
	
}
/****************************************
Function :shoumyy(struct POLICY policy[10],int yema)
Description:
Attention:
Return：
***************************************/
int  shoumyy(struct POLICY policy[10],int yema)
{
	int i=0;
	int k=0;
	setfillstyle(1,WHITE);
	bar(0,170,640,410);
	setfillstyle(1,GREEN);
	for(i=0;i<3;i++)
	{
		bar(0,210+i*80,640,250+i*80);
	}
	i=0;
	settextstyle(2,0,5);
	for(k=0;k<10;k++)
	{
		if(yema == 0&&policy[k].p==1)
		{
			if(i==0||i==2||i==4)
			{
				setcolor(GREEN);
				puthz(120,180+i*40,policy[k].pcity,16,16,GREEN);
				puthz(560,180+i*40,"确认选择",16,16,GREEN);
			}
			else if(i==1||i==3||i==5) 
			{
				setcolor(WHITE);
				puthz(120,180+i*40,policy[k].pcity,16,16,WHITE);
				puthz(560,180+i*40,"确认选择",16,16,WHITE);
			}
			outtextxy(10,180+i*40,policy[k].bdh);
			outtextxy(145,180+i*40,policy[k].plate);
			outtextxy(250,180+i*40,policy[k].money_str[5]);
			outtextxy(380,180+i*40,policy[k].baofei[5]);	
			i++;
		}
		if(yema == 0&&i==6) break;  
		if(yema == 1&&policy[k].p==1)
		{
			if(i==6||i==8)
			{
				setcolor(GREEN);
				puthz(120,180+(i-6)*40,policy[k].pcity,16,16,GREEN);
				puthz(560,180+(i-6)*40,"确认选择",16,16,GREEN);
				outtextxy(10,180+(i-6)*40,policy[k].bdh);
				outtextxy(145,180+(i-6)*40,policy[k].plate);
				outtextxy(250,180+(i-6)*40,policy[k].money_str[5]);
				outtextxy(380,180+(i-6)*40,policy[k].baofei[5]);
			}
			else if(i==7||i==9) 
			{
				setcolor(WHITE);
				puthz(120,180+(i-6)*40,policy[k].pcity,16,16,WHITE);
				puthz(560,180+(i-6)*40,"确认选择",16,16,WHITE);
				outtextxy(10,180+(i-6)*40,policy[k].bdh);
				outtextxy(145,180+(i-6)*40,policy[k].plate);
				outtextxy(250,180+(i-6)*40,policy[k].money_str[5]);
				outtextxy(380,180+(i-6)*40,policy[k].baofei[5]);
			}
			i++;
		}
	}
	if(i<=6)  return (i-1);
	else return (i-7);
}
/****************************************
Function :choosepolicy(struct POLICY policy[10],int *t)
Description:选择保单主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int choosepolicy(struct POLICY policy[10],int *t)
{
	int yema=0;
	int i=0,k=0;//k用于决定policy
	int judge = 0;
	int press,MouseX,MouseY;
	int f = 0;
	int ynum = 0;
	ynum=shoumyy(policy,yema);
	/*
	settextstyle(2,0,5);
	for(k=0;k<6;k++)
	{
		
		if(policy[k].p==1)
		{
			if(i==0||i==2||i==4||i==6)
			{
				setcolor(GREEN);
				puthz(120,180+i*40,policy[k].pcity,16,16,GREEN);
				puthz(560,180+i*40,"确认选择",16,16,GREEN);
			}
			else if(i==1||i==3||i==5) 
			{
				setcolor(WHITE);
				puthz(120,180+i*40,policy[k].pcity,16,16,WHITE);
				puthz(560,180+i*40,"确认选择",16,16,WHITE);
			}
			outtextxy(10,180+i*40,policy[k].bdh);
			outtextxy(145,180+i*40,policy[k].plate);
			outtextxy(250,180+i*40,policy[k].money_str[5]);
			outtextxy(380,180+i*40,policy[k].baofei[5]);
			
			i++;
		}
	}*/
	delay(100);
	//save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>=0 && MouseX<=100 && MouseY >=440 && MouseY<=480 && press)
		{
			return -1;
		}
		if(MouseX>=570 && MouseX<=610 && MouseY >=78 && MouseY<=118 )
		{
			if(f==0)
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(560,75,610,120);
				puthz(578,80-5,"？",32,40,LIGHTGRAY);
				setlinestyle(SOLID_LINE,0,3);
				setcolor(LIGHTGRAY);
				circle(590,98-5,20);
				save_bk_mou(MouseX,MouseY);
				f=1;
			}
			if(press)
			{
				judge = 1;
			}
		}
		else if(f==1 && !(MouseX>=570 && MouseX<=610 && MouseY >=78 && MouseY<=118 ))
		{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(560,75-5,610,120-5);
				puthz(578,80,"？",32,40,LIGHTGRAY);
				setlinestyle(SOLID_LINE,0,3);
				setcolor(LIGHTGRAY);
				circle(590,98,20);
				save_bk_mou(MouseX,MouseY);
				f=0;
		}
		//点击所有的确认选择
		if(MouseX>=560 && MouseX<=640 && MouseY >=170 && MouseY<=170+(ynum+1)*40 && press)
		{
			*t=(MouseY-170)/40+yema * 6;
			judge = 2;
		}
		if(yema == 0&&MouseX>=540 && MouseX<=640 && MouseY >=440 && MouseY<=480 && press)
		{
			judge = 3;
		}
		if(yema == 1&&MouseX>=540 && MouseX<=640 && MouseY >=440 && MouseY<=480 && press)
		{
			judge = 4;
		}
		switch(judge)
		{
			case -1:
			{
				drawchoosepolicy(policy);
				shoumyy(policy,yema);
				/*i=0;
				for(k=0;k<10;k++)
				{
					if(policy[k].p==1)
					{
						if(i!=1)
						{
							setcolor(GREEN);
							puthz(120,180+i*40,policy[k].pcity,16,16,GREEN);
							puthz(560,180+i*40,"确认选择",16,16,GREEN);
						}
						else if(i==1) 
						{
							setcolor(WHITE);
							puthz(120,180+i*40,policy[k].pcity,16,16,WHITE);
							puthz(560,180+i*40,"确认选择",16,16,WHITE);
						}
							outtextxy(10,180+i*40,policy[k].bdh);
							outtextxy(145,180+i*40,policy[k].plate);
							outtextxy(250,180+i*40,policy[k].money_str[5]);
							outtextxy(380,180+i*40,policy[k].baofei[5]);
							i++;
					}
				}*/
				save_bk_mou(MouseX,MouseY);
				judge = 0;
				delay(100);
				break;
			}
			case 1:
			{
				judge = shuoming();
				break;
			}
			case 2:
			{
				if(policy[*t].zt == 1)
				{
					clrmous(MouseX,MouseY);
					delay(100); 
					judge = queren("该保单已被理赔",195,170,32,35,-1);
					break;
				}
				else 
				{
					clrmous(MouseX,MouseY);
					delay(100); 
					judge = jueding("选此保单？",5);
					break;
				}
			}
			case 3:
			{
				yema = 1;
				ynum = shoumyy(policy,yema);
				setfillstyle(1,LIGHTGRAY);
				bar(540,440,640,480);
				puthz(560,450,"上一页",16,25,WHITE);
				judge = 0;
				delay(100);
				break;
			}
			case 4:
			{
				judge = 0;
				yema = 0 ;
				ynum = shoumyy(policy,yema);
				setfillstyle(1,LIGHTGRAY);
				bar(540,440,640,480);
				puthz(560,450,"下一页",16,25,WHITE);
				delay(100);
				break;
			}
			case 5:
				{
					return 1;
				}
		}
	}
}
/****************************************
Function :drawlipei(struct POLICY policy[10],int t,int *g)
Description:画理赔界面函数
Attention:无
Return：无
***************************************/
void drawlipei(struct POLICY policy[10],int t,int *g)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"平安好车主",32,35,WHITE);
	puthz(200,30,"车损理赔",16,20,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,455,"上一步",16,20,WHITE);
	setcolor(LIGHTGRAY);
	/*setfillstyle(1,LIGHTGRAY);
	bar(15,55,98,83);*/
	/*puthz(20,60,"确认信息",16,20,RED);
	line(100,70,275,70);
	
	puthz(280,60,"进行理赔",16,20,GREEN);
	line(370,70,525,70);
	puthz(530,60,"获取赔款",16,20,GREEN);*/
	puthz(280,60,"确认信息",16,20,GREEN);
	line(120,100,540,100);
	puthz(140,110,"是否有人受伤",16,16,BLACK);
	circle(270,120,10);
	puthz(290,110,"无人伤",16,16,BLACK);
	circle(400,120,10);
	puthz(420,110,"有人伤",16,16,BLACK);
	line(120,135,540,135);
	puthz(140,145,"车是否能开",16,16,BLACK);
	circle(270,155,10);
	puthz(290,145,"能开",16,16,BLACK);
	circle(400,155,10);
	puthz(420,145,"不能开",16,16,BLACK);
	line(120,170,540,170);
	puthz(140,180,"是否在现场",16,16,BLACK);
	circle(270,190,10);
	puthz(290,180,"还在现场",16,16,BLACK);
	circle(400,190,10);
	puthz(420,180,"已经撤离",16,16,BLACK);
	line(120,205,540,205);
	puthz(140,215,"报案电话",16,16,BLACK);
						
	line(120,240,540,240);
	puthz(140,250,"事故发生时间",16,20,BLACK);
	//line(520,242,530,257);
	//line(520,273,530,257);
	line(120,275,540,275);
	puthz(140,280,"事故拍照",16,20,BLACK);
	setcolor(CYAN);
	rectangle(180,300,480,415);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	puthz(190,310,"请上传一张事故现场照片",16,20,LIGHTGRAY);
	line(120,430,540,430);
	line(540,100,540,430);
	line(120,100,120,430);
	fillellipse(330,370,40,40);
	setcolor(WHITE);
	line(310,360,320,360);
	line(200+120,360,200+120,348);
	line(200+120,348,220+120,348);
	line(220+120,348,220+120,360);
	line(220+120,360,230+120,360);
	line(230+120,360,230+120,388);
	line(230+120,388,190+120,388);
	line(190+120,388,190+120,360);
	setfillstyle(1,WHITE);
	floodfill(210+120,370,LIGHTGRAY);
	setcolor(WHITE);
	circle(210+120,370,10);
	circle(210+120,370,9);
	button(330,455,200,40,LIGHTGREEN,CYAN,1);
	puthz(290,445,"下一步",16,30,WHITE);
	showtime();
				if(g[0]==1) 
					fillellipse(270,120,10,10);
				else if(g[0]==2) 
					fillellipse(400,120,10,10);
				if(g[1]==1) 
					fillellipse(270,155,10,10);
				else if(g[1]==2) 
					fillellipse(400,155,10,10);
				if(g[2]==1) 
					fillellipse(270,190,10,10);
				else if(g[2]==2) 
					fillellipse(400,190,10,10);
	setcolor(GREEN);
	settextstyle(2,0,6);
		outtextxy(260,215,policy[t].dianhua);
	
}
/****************************************
Function : lipei(struct POLICY policy[10],int t,int *g,struct CLAIM claim[10],int cn)
Description:理赔界面主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int lipei(struct POLICY policy[10],int t,int *g,struct CLAIM claim[10],int cn)
{
	int judge = 0;
	int press,MouseX,MouseY;
	int i=0;
	char tel[12];
	*tel = '\0';
	g[3]=0;
	delay(100);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=140+120 &&MouseX <=160+120 &&MouseY >= 110&&MouseY <=130 &&press && g[0]!=1)
		{
			g[0] = 1;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(280+120,120,10,10);
			setfillstyle(1,CYAN);
			fillellipse(150+120,120,10,10);
		}
		if(MouseX >=270+120 &&MouseX <=290+120 &&MouseY >= 110&&MouseY <=130 &&press && g[0]!=2)
		{
			g[0] = 2;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(150+120,120,10,10);
			setfillstyle(1,CYAN);
			fillellipse(280+120,120,10,10);
		}	
		if(MouseX >=140+120 &&MouseX <=160+120 &&MouseY >= 145&&MouseY <=165 &&press && g[1]!=1)
		{
			g[1] = 1;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(280+120,155,10,10);
			setfillstyle(1,CYAN);
			fillellipse(150+120,155,10,10);
		}	
		if(MouseX >=270+120 &&MouseX <=290+120 &&MouseY >= 145&&MouseY <=165 &&press && g[1]!=2)
		{
			g[1] = 2;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(150+120,155,10,10);
			setfillstyle(1,CYAN);
			fillellipse(280+120,155,10,10);
		}
		if(MouseX >=140+120 &&MouseX <=160+120 &&MouseY >= 180&&MouseY <=200 &&press && g[2]!=1)
		{
			g[2] = 1;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(280+120,190,10,10);
			setfillstyle(1,CYAN);
			fillellipse(150+120,190,10,10);
		}
		if(MouseX >=270+120 &&MouseX <=290+120 &&MouseY >= 180&&MouseY <=200 &&press && g[2]!=2)
		{
			g[2] = 2;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(150+120,190,10,10);
			setfillstyle(1,CYAN);
			fillellipse(280+120,190,10,10);
		}
		if(MouseX>= 210 && MouseX<=450 && MouseY >=425 && MouseY<=475 && press)
		{
			judge = 1;
		}
		if(MouseX>=0 && MouseX<=100 && MouseY >=445 && MouseY<=480 && press)
		{
			judge = 2;	
		}
		if(MouseX>= 290&& MouseX<=370 && MouseY >=330 && MouseY<=410 && press&&g[3]==0)
		{
			judge = 3;
		}
		switch(judge)
		{
			case -1:
			{
				drawlipei(policy,t,g);
				if(g[3]==1)
				{
					setfillstyle(1,WHITE);
					bar(190,302,420,360);
					putbmp(220,300,"./bmp/1.bmp");
				}
				if(g[3]==2)
				{
					setfillstyle(1,WHITE);
					bar(190,302,420,360);
					putbmp(200,300,"./bmp/2.bmp");
				}
				save_bk_mou(MouseX,MouseY);
				judge  = 0;
				delay(100);
				break;
			}
			case 1:
			{
				if(g[0]==0)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("您还未选择是否有人受伤",210,170,16,20,-1);
				}
				else if(g[1]==0)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("您还未选择车是否能开",220,170,16,20,-1);
				}
				else if(g[2]==0)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("您还未选择是否在现场",220,170,16,20,-1);
				}
				else if(g[2]==1&&g[3]==0)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("您仍在现场但未上传现场照片",190,170,16,20,-1);
				}
				else 
				{
					return 2;
				}
				break;
			}
			case 2:
			{
				return 0;
			}
			case 3:
			{
				clrmous(MouseX,MouseY);
				judge =scbmp(g);
				break;
			}
		}
	}
}
/*******************************************
Function   :cintel
Attention  :注意传入鼠标的坐标指针
Destrcption:
***********************************************
int cintel(int *MouseX,int *MouseY,char *tel)
{
	int judge = 0;
	int key;     //表示 键值 的变量
	int i= 0;    //用于计算已经输入的字符 数目的变量
	char *p = tel;  //输入字符的中间指针变量
	char ch;     //用于临时 储存键值所对应的字符变量
	int press;   //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	AddFrame(*MouseX, *MouseY,250,205,540,240, GREEN);
	while (1)
	{
		newmouse(MouseX,MouseY,&press);
		//重置键值并得到新键值
		key = 0;
		if(!(MouseX >=250 && MouseX<=540 && MouseY >=205 &&MouseY <=240) &&press)
		{
			return ;
		}
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		 //如果按了删除键
		if(key == 0xe08)
		{
			if(p != code)
			{
				setfillstyle(1,WHITE);
				bar(247+i*11,215,258+i*11,235);
				backgroundChange(*MouseX, *MouseY,427+i*11,334,438+i*11,350);
				p--;
				i--;
			}
			*p = '\0';
		}
		/*将按键对应的字符存入code数组中
		ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			/*将字符显示出来
			setfillstyle(1, WHITE);
			bar(438 + i * 11, 334, 449 + i * 11, 350);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BROWN);
			outtextxy(438 + i * 11, 334, temp);
			backgroundChange(*MouseX, *MouseY, 438 + i * 11, 334, 449 + i * 11, 350);

			/*将字符存入数组中
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
}
*************************/
/****************************************
Function :scbmp(int *g)
Description:上传事故照片
Attention:无
Return：上一个界面的judge值
***************************************/
int scbmp(int *g)
{
	int press;
	int MouseX,MouseY;
	setfillstyle(1,LIGHTGRAY);
	bar(170,130,470,360);
	setfillstyle(1,WHITE);
	bar(180,140,460,350);
	puthz(215,160,"可供上传的照片如下",16,20,BLACK);
	outtextxy(215,200,"bmp>1.bmp");
	outtextxy(215,240,"bmp>2.bmp");
	//outtextxy(215,180,"DISK_C>tezt>bmp>3.bmp");
	setfillstyle(1,CYAN);
	bar(400,200,440,230);
	puthz(407,205,"选择",16,16,WHITE);
	bar(400,240,440,270);
	puthz(407,245,"选择",16,16,WHITE);
	clrmous(MouseX,MouseY);
	delay(100);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=400 && MouseX <= 440 && MouseY >= 200 && MouseY <= 230 && press)
		{
			g[3]=1;
			return -1;
		}
		if(MouseX >=400 && MouseX <= 440 && MouseY >= 240 && MouseY <= 270 && press)
		{
			g[3]=2;
			return -1;
		}
		if(!(MouseX >=170 && MouseX <= 470 && MouseY >= 130 && MouseY <= 160)&& press)
		{
			delay(100);
			return -1;
		}
	}
}
/****************************************
Function :showtime(void)
Description:显示当前时间
Attention:无
Return：无
***************************************/
void showtime(void)
{
	char a[10];
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	settextstyle(2,0,5);
	setcolor(GREEN);
	itoa(1900+p->tm_year,a,10);
	outtextxy(270,250,a);
	puthz(310,250,"年",16,16,GREEN);
	itoa(1+p->tm_mon,a,10);
	outtextxy(330,250,a);
	puthz(340,250,"月",16,16,GREEN);
	itoa(p->tm_mday,a,10);
	outtextxy(360,250,a);
	puthz(380,250,"日",16,20,GREEN);
	itoa(p->tm_hour-4,a,10);
	outtextxy(400,250,a);
	puthz(420,250,"时",16,20,GREEN);
	itoa(p->tm_min,a,10);
	outtextxy(440,250,a);
	puthz(460,250,"分",16,20,GREEN);
}
/****************************************
Function :shuoming(void)
Description:说明保单相关问题
Attention:无
Return：无
***************************************/
int shuoming(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	settextstyle(1,0,3);
	puthz(20,20,"关于保单选择的相关问题",32,35,BLACK);
	setcolor(GREEN);
	outtextxy(30,60,"Q1");
	puthz(60,65,"为什么没有保单具体信息",16,20,BLACK);
	outtextxy(30,100,"Answer:");
	puthz(40,130,"用户保单具体信息可以在用户个人中心的“我的保单”界面查看，本处只用于用户根据保单编号及个人车牌进行理赔保单的选择，故不做赘述",16,20,BLACK);
	outtextxy(30,200,"Q2");
	puthz(60,205,"车险理赔有哪些流程？",16,20,BLACK);
	outtextxy(30,240,"Answer:");
	puthz(40,270,"车险理赔流程如下：",16,20,BLACK);
	puthz(40,300,"通过首页— ",16,20,BLACK);
	puthz(140,300,"办理赔",16,20,GREEN);
	puthz(200,300,"—保单选择—理赔方式选择—管理员审核—领取赔",16,20,BLACK);
	puthz(40,330,"款即可获得赔款",16,20,BLACK);
	setfillstyle(1,CYAN);
	bar(540,440,640,480);
	puthz(550,450,"返回",16,20,WHITE);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>=540 && MouseX<=640 && MouseY >=440 && MouseY<=480 && press)
		{
			
		}
		if(MouseX>=540 && MouseX<=640 && MouseY >=440 && MouseY<=480 && press)
		{
			return -1;
		}
	}
}
