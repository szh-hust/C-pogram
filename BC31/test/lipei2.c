#include "common.h"
#include "lipei1.h"
#include "lipei2.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "draw.h"
/****************************************
Function :xzlpfs(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
Description:选择理赔方式主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int xzlpfs(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
{
	int flag=0;
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	delay(100);
	clrmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>=75&&MouseX<=275&&MouseY>=160&&MouseY<=210&&press)
		{
			claim[cn].flag = 1;
			return 3;
		}
		if(MouseX>=75&&MouseX<=275&&MouseY>=160&&MouseY<=210&&flag!=1)
		{
			flag=1;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			 bar(368,211,568,214);
	        bar(566,163,569,214);
			setfillstyle(1,LIGHTGRAY);
			bar(78,211,278,214);
			bar(276,163,279,214);
			//save_bk_mou(MouseX,MouseY);
		}
		if(MouseX>=365&&MouseX<=565&&MouseY>=160&&MouseY<=210&&press)
		{
			claim[cn].flag = 2;
			return 4;
		}
		if(MouseX>=365&&MouseX<=565&&MouseY>=160&&MouseY<=210&&flag!=2)
		{
			flag=2;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(78,211,278,214);
			bar(276,163,279,214);
			setfillstyle(1,LIGHTGRAY);
	        bar(368,211,568,214);
	        bar(566,163,569,214);
			//save_bk_mou(MouseX,MouseY);
		}
		if(((MouseX<=75||MouseX>=275)&&(MouseY<=160||MouseY>=210))&&((MouseX<=365||MouseX>=565)&&(MouseY<=160||MouseY>=210))&&flag!=0)
		{
			flag=0;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(78,211,278,214);
			bar(276,163,279,214);
			  bar(368,211,568,214);
	        bar(566,163,569,214);
			//save_bk_mou(MouseX,MouseY);
		}
		if(MouseX>=0 && MouseX<=100 && MouseY >=445 && MouseY<=480 && press)
		{
			return 1;
		}
	}
}
/****************************************
Function :drawxzlpfs(void)
Description:画选择理赔方式界面函数
Attention:无
Return：无
***************************************/
void drawxzlpfs(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"平安好车主",32,30,WHITE);
	puthz(170,30,"车损理赔",16,20,WHITE);
	//puthz(270,30,"事故信息确认",16,16,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"返回",16,20,WHITE);
	
	setcolor(LIGHTGRAY);
	/*puthz(20,60,"确认信息",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"进行理赔",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"获取赔款",16,20,GREEN);
	*/
	puthz(280,60,"进行理赔",16,20,GREEN);
	puthz(200,90,"理赔方式选择",32,40,BLACK);
	setfillstyle(1,CYAN);
	bar(75,160,275,210);
	bar(365,160,565,210);
	puthz(85,170,"自主理赔",32,40,WHITE);
	puthz(375,170,"人工服务",32,40,WHITE);
	
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,3);
	rectangle(50,140,300,420);
	rectangle(340,140,590,420);
	puthz(80,240,"自助上传损失照片",16,20,LIGHTGRAY);
	puthz(80,270,"在线领取损失赔款",16,20,LIGHTGRAY);
	puthz(370,240,"工作人员现场服务",16,20,LIGHTGRAY);
	puthz(370,270,"当面领取损失赔款",16,20,LIGHTGRAY);
	drawlittlecar(85,290,CYAN,6);
	drawlittlecar(375,290,CYAN,6);
}
/****************************************
Function : zzlp(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
Description:自主理赔主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int zzlp(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
{
	int judge=0;
	int press,MouseX,MouseY,i;
	int driver = VGA;
	int mode = VGAHI;
	char lpje[10]={'\0'};
	long money1;
	long money2;
	int flag=0;
	
	delay(100);
	clrmous(MouseX,MouseY);
	outtextxy(250,140,policy[t].money_str[5]);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	if(MouseX>=0&&MouseX<=100&&MouseY>=445&&MouseY<=480&&press)
			return 2;
	if(MouseX>=240&&MouseX<=400&&MouseY>=350&&MouseY<=400&&press)
		judge=1;
	if(MouseX>=300&&MouseX<=560&&MouseY>=185&&MouseY<=215&&press)
		judge=2;
	if((!(MouseX>=300&&MouseX<=560&&MouseY>=185&&MouseY<=215))&&press)
	{
		setlinestyle(SOLID_LINE,0,3);
		setcolor(BLACK);
	    rectangle(300,185,560,215);
	}
	switch(judge)	
	{
		case -1:
		{
			return 2;
		}
		case -2:
		{
			return 5;
		}
		case 1:
		{
			money1=atol(policy[t].money_str[5]);
			money2=atol(lpje);
			flag=0;
			for(i=0;lpje[i]!='\0';i++)
			{
				if(lpje[i]<'0'||lpje[i]>'9')
					flag=1;
			}
			if(flag==1)
			{
				puthz(410,360,"请输入正确的保额",16,20,RED);
				judge=0;
				break;
			}
			else if(money1>=money2)
			{
				strcpy(claim[cn].claimmoney,lpje);
				clrmous(MouseX,MouseY);
				strcpy(claim[cn].claimmoney,lpje);
				judge=bingo(220,300,"申请成功");
				break;
				
			}
			else
			{
				puthz(410,360,"请输入正确的保额",16,20,RED);
				judge=0;
				break;
			}
		}
		case 2:
		{
			judge=cinlpje(lpje,&MouseX,&MouseY);
			break;
		}
	}
		
	}
}
/****************************************
Function :drawzzlp(void)
Description:画自主理赔界面函数
Attention:无
Return：无
***************************************/
void drawzzlp(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"平安好车主",32,30,WHITE);
	puthz(170,30,"车损理赔",16,20,WHITE);
	//puthz(270,30,"事故信息确认",16,16,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"返回",16,20,WHITE);
	puthz(120,90,"您正在进行自主理赔服务",32,35,BLACK);
	puthz(120,140,"您的保额为：",16,20,BLACK);
	puthz(50,190,"请输入您想要理赔的金额",16,20,BLACK);
	puthz(570,190,"元",16,20,BLACK);
	setcolor(LIGHTGRAY);
	/*puthz(20,60,"确认信息",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"进行理赔",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"获取赔款",16,20,GREEN);*/
	puthz(270,60,"获取赔款",16,20,RED);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,3);
	rectangle(40,170,600,420);
	line(40,230,600,230);
	setcolor(BLACK);
	rectangle(300,185,560,215);
	puthz(60,240,"注意：",16,20,RED);
	puthz(60,260,"一、索赔金额不得超过保单的保额。",16,20,BLACK);
	puthz(60,280,"二、理赔需经过管理员审核请耐心等待。",16,20,BLACK);
	puthz(60,300,"三、请根据事实理赔不得虚假理赔。",16,20,BLACK);
	setfillstyle(1,CYAN);
	bar(240,350,400,400);
	puthz(250,360,"申请理赔",32,35,WHITE);
}

/****************************************
Function :cinlpje(char * lpje,int *MouseX, int *MouseY)
Description:输入理赔金额
Attention:无
Return：上一个界面的judge值
***************************************/
int cinlpje(char * lpje,int *MouseX, int *MouseY)
{
	char *p = lpje;   //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int press;    //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	int key;    //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	//画点开后的框框
	setlinestyle(SOLID_LINE,0,3);
		setcolor(RED);
	    rectangle(300,185,560,215);
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		if (*MouseX >= 240 && *MouseX <= 400 && *MouseY >= 350&& *MouseY <= 400 && press) 
		{//如果鼠标点击*申请*
			return 1;
		}
		 if (*MouseX >= 0 && *MouseX <= 100 && *MouseY >= 445&& *MouseY <= 480 && press) 
		{//如果鼠标点击*返回*
			return -1;
		}
		//如果按了回删键 
		if (key == 0xe08)
		{
			if (p != lpje)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(300 + i * 11, 188, 311 + i * 11, 212);
			//	backgroundChange(*MouseX, *MouseY, 300 + i * 11, 188, 311 + i * 11, 212);
				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入lpje数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<6)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(311 + i * 11, 188, 322 + i * 11, 212);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(311+ i * 11, 188, temp);
		//	backgroundChange(*MouseX, *MouseY, 311 + i * 11, 188, 322 + i * 11, 212);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :drawxzdd(void)
Description:画选择地点界面函数
Attention:无
Return：无
***************************************/
void drawxzdd(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	drawdt();
	//putbmp(0,0,"./bmp/rengong.bmp");
	/*setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"平安好车主",32,30,WHITE);
	puthz(170,30,"车损理赔",16,20,WHITE);
	//puthz(270,30,"事故信息确认",16,16,WHITE);*/
	puthz(100,30,"您正在进行人工服务申请",32,40,BLACK);
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"返回",16,20,WHITE);
	puthz(120,390,"请选择您的大致地点",32,40,BLACK);
	
	
	/*setcolor(LIGHTGRAY);
	puthz(20,60,"确认信息",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"进行理赔",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"获取赔款",16,20,GREEN);*/
}
/****************************************
Function :drawrgfw(void)
Description:画人工服务界面函数
Attention:无
Return：无
***************************************/
void drawrgfw(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	//putbmp(0,0,"./bmp/rengong.bmp");
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"平安好车主",32,30,WHITE);
	puthz(170,30,"车损理赔",16,20,WHITE);
	//puthz(270,30,"事故信息确认",16,16,WHITE);*/
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"返回",16,20,WHITE);
	
	puthz(100,90,"您正在进行人工服务申请",32,40,BLACK);
	puthz(230,180,"请选择您的大致地点",16,20,BLACK);
	setcolor(CYAN);
	setfillstyle(1,CYAN);
	setlinestyle(SOLID_LINE,0,3);
	line(40,290,600,290);
	bar(500,220,560,270);
	puthz(510,230,"选择",16,20,WHITE);
	rectangle(40,170,600,420);
	bar(240,350,400,400);
	setcolor(BLACK);
	rectangle(150,220,490,270);
	puthz(250,360,"申请服务",32,35,WHITE);
	puthz(100,300,"请保持您的联系电话：",16,20,BLACK);
	puthz(400,320,"畅通！",16,20,BLACK);
	//outtextxy(150,330,policy[t].dianhua);
	
	setcolor(LIGHTGRAY);
	puthz(20,60,"确认信息",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"进行理赔",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"获取赔款",16,20,GREEN);
}
/****************************************
Function :rgfw(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
Description:人工服务主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int rgfw(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
{
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	int judge=0;
	char didian[20]={'\0'};
	int i=0;
	int x,y;
	delay(100);
	clrmous(MouseX,MouseY);
	settextstyle(2, 0, 6);
	outtextxy(250,320,policy[t].dianhua);
	//puthz(160,240,didian,16,20,BLACK);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	if(MouseX>=0&&MouseX<=100&&MouseY>=445&&MouseY<=480&&press)
			return 2;
	if(MouseX>=500&&MouseX<=560&&MouseY>=220&&MouseY<=270&&press)
	{
		judge=1;
	}
	if(MouseX>=240&&MouseX<=400&&MouseY>=350&&MouseY<=400&&press)
	{
		judge=3;
	}
	switch(judge)
	{
		case -2:
		{
			return 5;
		}
		case 1:
		{
			drawxzdd();
			judge=xzdd(didian);
			break;
		}
		case 2:
		{
			clrmous(MouseX,MouseY);
			drawrgfw();
			setfillstyle(1,WHITE);
			bar(155,238,480,265);
			settextstyle(2, 0, 6);
	        outtextxy(250,320,policy[t].dianhua);
			puthz(160,240,didian,16,20,BLACK);
			judge=0;
			delay(100);
			break;
		}
		case 3:
		{
			if(strlen(didian)==0)
			{
				puthz(160,240,"请选择合适的地点！",16,20,RED);
				judge=0;
				break ;
			}
			else
			{
				x=97;
				y=150;
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
				judge=bingo(170,300,"我们正在赶来");
				break;
			}
		}
	}
	}
}
/****************************************
Function :xzdd(char *didian)
Description:选择地点主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int xzdd(char *didian)
{
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	delay(100);
	clrmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	if(MouseX>=0&&MouseX<=100&&MouseY>=445&&MouseY<=480&&press)
	{
		clrmous(MouseX,MouseY);
		drawrgfw();
		return 0;
	}
	
		if(MouseX >=50 && MouseX <= 70&& MouseY >= 170&& MouseY <= 190 &&press)
		{
			strcpy(didian,"华科附小");
		    return 2;
		}
		//选择洗车店华科幼儿园
		if(MouseX >=290 && MouseX <= 310&& MouseY >= 170&& MouseY <= 190 &&press)
		{
			strcpy(didian,"经济学院");
		    return 2;
		}
		//选择研究生工作室
		if(MouseX >=90 && MouseX <= 110&& MouseY >= 340&& MouseY <= 360 &&press)
		{
			strcpy(didian,"公管学院");
		    return 2;
		}
		//选择保卫处
		if(MouseX >=260 && MouseX <= 280&& MouseY >= 310&& MouseY <= 330 &&press)
		{
			strcpy(didian,"研究生工作室");
		    return 2;
		}
		//选择梧桐雨
		if(MouseX >=545 && MouseX <= 565&& MouseY >= 210&& MouseY <= 230&&press)
		{
			strcpy(didian,"华科幼儿园");
		    return 2;
		}
		//选择经济学院
		if(MouseX >=530 && MouseX <= 550&& MouseY >= 120&& MouseY <= 140 &&press)
		{
			strcpy(didian,"梧桐雨问学中心");
		    return 2;
		}
	}
}

/*写入文本*/
/*money_str[5],dianhua,zhuantai,flag */
/****************************************
Function :putclaim(setuser *person,struct CLAIM claim[10],int cn)
Description:将理赔信息写入文件
Attention:无
Return：上一个界面的judge值
***************************************/
int putclaim(setuser *person,struct CLAIM claim[10],int cn)
{
	int t=0;
	char *p;
	FILE *fp;
	char zt[2]={'\0','\0'};
	char flagstr[2]={'\0','\0'};
	zt[0] = claim[cn].zhuangtai+'0';
	flagstr[0]=claim[cn].flag+'0';
	if((fp=fopen("./t_file/user/claim.txt","r+"))==NULL)
	{
		closegraph();
		printf("can't open cliam.txt");
		//getchar();
		exit(1);
	}
	fseek(fp,0L,2);
	
	putc('/',fp);
	p=person->accounts;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	p=claim[cn].bdh;
	while(t!=8)
	{
		putc(*p,fp);
		p++;
		t++;
	}
	putc('#',fp);
	p = claim[cn].claimmoney;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	p = zt;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	p = claim[cn].ybe;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	p = claim[cn].dianhua;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	p = flagstr;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	fclose(fp);
}
