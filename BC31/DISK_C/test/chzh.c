#include "common.h"
#include "chzh.h"
/****************************************
Function :drawmymoney(setuser *person)
Description:画我的钱包界面
Attention:无
Return：无
***************************************/
void drawmymoney(setuser *person)
{
	drawuserself();
	setfillstyle(1,RED);
	bar(170,170+40,180,210+40);
	puthz(325,65,"账户充值",32,35,GREEN);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,3);
	line(180,100,640,100);
	puthz(200,115,"账号",16,20,BLACK);
	settextstyle(2,0,6);
	outtextxy(500,115,person->accounts);
	setlinestyle(SOLID_LINE,0,1);
	line(180,140,640,140);
	puthz(200,155,"余额",16,20,BLACK);
	line(180,180,640,180);
	setcolor(LIGHTGRAY);
	rectangle(205,200,325,240);
	rectangle(350,200,470,240);
	rectangle(495,200,615,240);
	
	rectangle(205,260,325,300);
	rectangle(350,260,470,300);
	rectangle(495,260,615,300);
	
	setcolor(BLACK);
	outtextxy(235,210,"20");
	puthz(260,213,"元",16,20,BLACK);
	outtextxy(380,210,"50");
	puthz(405,213,"元",16,20,BLACK);
	outtextxy(525,210,"100");
	puthz(553,213,"元",16,20,BLACK);
	outtextxy(235,270,"200");
	puthz(268,273,"元",16,20,BLACK);
	outtextxy(380,270,"500");
	puthz(408,273,"元",16,20,BLACK);
	puthz(515,270,"其他金额",16,20,BLACK);
	line(180,320,640,320);
	puthz(200,330,"账号密码",16,20,BLACK);
	//puthz(440,330,"请输入账号密码",16,16,LIGHTGRAY);
	rectangle(430,325,630,355);
	line(180,360,640,360);
	setfillstyle(1,CYAN);
	bar(210,420,610,460);
	puthz(360,430,"确认充值",16,20,WHITE);
}
/****************************************
Function : usermoney(setuser *head,setuser *person)
Description:用户个人中心->我的钱包*界面功能
Attention:无
Return：上一个界面的judge值
***************************************/
int usermoney(setuser *head,setuser *person)
{
	char code[10];
	int k=0;
	char chongzhi[4];//表示充值的金额
	long cz=0;
	int judge = 0;
	int press,MouseX,MouseY;
	char money[10];
	int p = 0 ;
	char ys[5][4]={"20","50","100","200","500"};
	*code='\0';
	delay(100);
	save_bk_mou(MouseX,MouseY);
	setfillstyle(1,WHITE);
	dumoney(person->accounts,&person->money);
	ltoa(person->money,money,10);
	setcolor(RED);
	outtextxy(500,155,money);
	settextstyle(SMALL_FONT,0,8);
	puthz(600,155,"元",16,20,BLACK);
	//puthz(405,213,"元",16,20,BLACK);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
			return 1;
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
			return 2;
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 && MouseY <= 170 && press)
			return 3;
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 && MouseY <= 210 && press)
			return 4;
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 && MouseY <= 290 && press)
			return 6;	
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 && MouseY <= 330 && press)
			return 7;
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
			{
				judge = 4;
			}
		
		//20元
		if(MouseX >=205  && MouseX <= 325 && MouseY >= 200 &&MouseY <= 240 && press)
		{
			clrmous(MouseX,MouseY);
			//drawm();
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(205+1,200+1,325-1,240-1);
			setcolor(WHITE);
			outtextxy(235,210,ys[0]);
			puthz(260,213,"元",16,20,WHITE);
			cz = 20;
			k=0;
			p = 1;
		}
		//50元
		if(MouseX >=350  && MouseX <= 470 && MouseY >= 200 &&MouseY <= 240 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(350+1,200+1,470-1,240-1);
			setcolor(WHITE);
			outtextxy(380,210,ys[1]);
			puthz(405,213,"元",16,20,WHITE);
			cz = 50;
			k=0;
			p =2;
			
		}
		//100元
		if(MouseX >=495  && MouseX <= 615 && MouseY >= 200 &&MouseY <= 240 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(495+1,200+1,615-1,240-1);
			setcolor(WHITE);
			outtextxy(525,210,ys[2]);
			puthz(553,213,"元",16,20,WHITE);
			cz = 100;
			k=0;
			p =3;
		}
		//200元
		if(MouseX >=205  && MouseX <= 325 && MouseY >= 260 &&MouseY <= 300 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(205+1,260+1,325-1,300-1);
			setcolor(WHITE);
			outtextxy(235,270,ys[3]);
			puthz(265,273,"元",16,20,WHITE);
			cz = 200;
			k=0;
			p =4;
		}
		//500元
		if(MouseX >=350  && MouseX <= 470 && MouseY >= 260 &&MouseY <= 300 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(350+1,260+1,470-1,300-1);
			setcolor(WHITE);
			outtextxy(380,270,ys[4]);
			puthz(410,273,"元",16,20,WHITE);
			cz = 500;
			k=0;
			p= 5;
		}
		//点击其他金额
		if(MouseX >=495  && MouseX <= 615 && MouseY >= 260 &&MouseY <= 300 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			setfillstyle(1,CYAN);
			bar(495+1,260+1,615-1,300-1);
			puthz(515,270,"其他金额",16,20,WHITE);
			setcolor(DARKGRAY);
			line(180,410,640,410);
			puthz(200,380,"金额",16,20,BLACK);
			rectangle(430,370,630,400);
			*chongzhi ='\0';
			cz = 0;
			k=1;
			p=6;
		}
		if(k==1&&MouseX >=500  && MouseX <= 630 && MouseY >= 370 &&MouseY <= 400 && press)
		{
			judge = 1;
		}
		if(MouseX >=430  && MouseX <= 630 && MouseY >= 325 &&MouseY <= 355 && press)
		{
			judge = 2;
		}
		if(MouseX >=210  && MouseX <= 610 && MouseY >= 410 &&MouseY <= 460 && press)
		{
			judge = 3;
		}
		switch (judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY);
				drawmymoney(person);
				ltoa(person->money,money,10);
				setcolor(RED);
				outtextxy(500,155,money);
				settextstyle(SMALL_FONT,0,8);
				puthz(600,155,"元",16,20,BLACK);
				cz  = 0;
				*chongzhi = '\0';
				*code='\0';
				judge = 0;
				break;
			}
			case 1:
			{	
				clrmous(MouseX,MouseY);
				delay(100);
				judge = cinmoney(chongzhi,&MouseX,&MouseY);
				cz = atoi(chongzhi);
				break;
			}
			case 2:
			{
				clrmous(MouseX,MouseY);
				delay(100); 
				judge = cincode(code,&MouseX,&MouseY,k);
				break;
			}
			case 3:
			{
				if(cz==0)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("未选择您要充值的钱数！",220,150,16,20,-1);
					break;
				}
				else if( strcmp(code, (*person).code) != 0)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("密码不正确！",225,150,32,35,-1);
					break;
				}
				else 
				{
					(person->money)+=cz;
					if(person->money >= 1000000)
					{
						person->money = 1000000;
						clrmous(MouseX,MouseY);
						delay(100);
						judge = queren("账户余额不能再多了！",240,150,16,20,-1);
						ltoa(person->money,money,10);
						changemoney(person->accounts,person->money);
						break; 
					}
					ltoa(person->money,money,10);
					changemoney(person->accounts,person->money);
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("充值成功！",240,150,32,35,-1);
					delay(300);
					break;
				}
				case 4:
					{
						return 8;
					}
			}
		}
				
	}
}
/****************************************
Function :fugai(int a)
Description:覆盖金额
Attention:无
Return：无
***************************************/
void fugai(int a)
{
	setfillstyle(1,WHITE);
	setcolor(BLACK); 
	switch(a)
	{
		case 1:
		{
			bar(205+1,200+1,325-1,240-1);
			outtextxy(235,210,"20");
			puthz(260,213,"元",16,20,BLACK);
			break;
		}
		case 2:
		{
			bar(350+1,200+1,470-1,240-1);
			outtextxy(380,210,"50");
			puthz(405,213,"元",16,20,BLACK);
			break;
		}
		case 3:
		{
			bar(495+1,200+1,615-1,240-1);
			outtextxy(525,210,"100");
			puthz(553,213,"元",16,20,BLACK);
			break;
		}
		case 4:
		{
			bar(205+1,260+1,325-1,300-1);
			outtextxy(235,270,"200");
			puthz(268,273,"元",16,20,BLACK);
			break;
		}
		case 5:
		{
			bar(350+1,260+1,470-1,300-1);
			outtextxy(380,270,"500");
			puthz(408,273,"元",16,20,BLACK);
			break;
		}
		case 6:
		{
			bar(495+1,260+1,615-1,300-1);
			puthz(515,270,"其他金额",16,20,BLACK);
			bar(181,365,640,415);
			break;
		}
	}
}
/*void drawm(void)
{
	settextstyle(2,0,6);
	setfillstyle(1,WHITE);
	bar(200,190,620,310);
	setcolor(LIGHTGRAY);
	rectangle(205,200,325,240);
	rectangle(350,200,470,240);
	rectangle(495,200,615,240);
	
	rectangle(205,260,325,300);
	rectangle(350,260,470,300);
	rectangle(495,260,615,300);
	
	setcolor(BLACK);
	outtextxy(235,210,"20");
	outtextxy(380,210,"50");
	outtextxy(525,210,"100");
	outtextxy(235,270,"200");
	outtextxy(380,270,"500");
	//puthz(100,100,"元",16,16,CYAN);
	//puthz(553,213,"元",16,20,CYAN);
	/*puthz(405,213,"元",16,20,BLACK);
	puthz(260,213,"元",16,20,BLACK);
	puthz(268,273,"元",16,20,BLACK);
	puthz(408,273,"元",16,20,BLACK);
	puthz(515,270,"其他金额",16,20,BLACK);
	setfillstyle(1,WHITE);
	bar(181,365,640,415);
}*/
/****************************************
Function :cincode(char *code,int *MouseX,int *MouseY,int k) 
Description:输入密码
Attention:无
Return：上一个函数的judge值
***************************************/
int cincode(char *code,int *MouseX,int *MouseY,int k)
{
	int key;     //表示 键值 的变量
	int i= 0;    //用于计算已经输入的字符 数目的变量
	char *p = code;  //输入字符的中间指针变量
	char ch;     //用于临时 储存键值所对应的字符变量
	int press;   //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	setcolor(GREEN);
	rectangle(430,325,630,355);
	if(k==1)
	{
			setcolor(BLACK);
	rectangle(430,370,630,400) ;
	}

/*	AddFrame(*MouseX, *MouseY,430,325,630,355, GREEN);
	if(k==1)
	{
		AddFrame(*MouseX, *MouseY,430,370,630,400, BLACK);
	}*/
	
	while (1)
	{
		newmouse(MouseX,MouseY,&press);
		//重置键值并得到新键值
		key = 0;
		if(k==1&&MouseX >=430  && MouseX <= 630 && MouseY >= 370 &&MouseY <= 400)
		{
			return 1;
		}
		if(!(MouseX >=430  && MouseX <= 630 && MouseY >= 325 &&MouseY <= 355)&&press)
		{
			setcolor(BLACK);
			rectangle(430,325,630,355);
			return 0;
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
				clrmous(*MouseX,*MouseY); 
				bar(427+i*11,334,438+i*11,350);
			///	backgroundChange(*MouseX, *MouseY,427+i*11,334,438+i*11,350);
				p--;
				i--;
			}
			*p = '\0';
		}
		/*将按键对应的字符存入code数组中*/
		ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(438 + i * 11, 334, 449 + i * 11, 350);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(438 + i * 11, 334, temp);
		//	backgroundChange(*MouseX, *MouseY, 438 + i * 11, 334, 449 + i * 11, 350);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :cinmoney(char * chongzhi,int *MouseX,int *MouseY)
Description:输入需要充值的金额
Attention:无
Return：上一个函数的judge值
***************************************/
int cinmoney(char * chongzhi,int *MouseX,int *MouseY)
{
	int key;     //表示 键值 的变量
	int i= 0;    //用于计算已经输入的字符 数目的变量
	char *p = chongzhi;  //输入字符的中间指针变量
	char ch;     //用于临时 储存键值所对应的字符变量
	int press;   //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	while(*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	setcolor(GREEN);
	rectangle(430,370,630,400);
	setcolor(BLACK);
	rectangle(430,325,630,355) ;
	/* 
	AddFrame(*MouseX, *MouseY,430,325,630,355, BLACK);
	AddFrame(*MouseX, *MouseY,430,370,630,400, GREEN);*/
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;   //重置键值并得到新键值
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		if(!(*MouseX >=430  && *MouseX <= 630 && *MouseY >= 365 && *MouseY <= 405) && press)
		{
			return 0;
		}
		//如果按了删除键
		if(key == 0xe08)
		{
			if(p != chongzhi)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(427 + i * 11, 379, 438 + i * 11, 395);
			//	backgroundChange(*MouseX, *MouseY,427 + i * 11, 379, 438 + i * 11, 395);
				p--;
				i--;
			}
			*p= '\0';
		}
		/*将按键对应的字符存入chongzhi数组中*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<4)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(438 + i * 11, 379, 449 + i * 11,395);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(438 + i * 11,379, temp);
			//backgroundChange(*MouseX, *MouseY, 438 + i * 11, 379, 449 + i * 11, 395);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :putmoney(char *accounts,long money)
Description:将充值后的金额存入文件
Attention:无
Return：无
***************************************/
void putmoney(char *accounts,long money)
{
	int t=0;
	char *p;
	int i=0;
	char  moneystr[10];
	FILE *fp;
	ltoa(money,moneystr,10);
	if((fp=fopen("./t_file/user/money.txt","r+"))==NULL)
	{
		closegraph();
		printf("can't open money.txt");
		//getchar();
		exit(1);
	}
	fseek(fp,0L,2);
	
	putc('/',fp);
	p=accounts;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	p=moneystr;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
		i++;
	}
	for(;i<10;i++)
	{
		putc(' ',fp);
	}
	putc('#',fp);
	fclose(fp);
}
/****************************************
Function :dumoney(char *acccountsperson,long *money)
Description:读取该用户的余额
Attention:无
Return：该用户的余额
***************************************/
int dumoney(char *acccountsperson,long *money)
{
	int m =0 ;
	int j,k;
	int flag=0;
	int judge=-1;
	char accounts[11]={'\0'};
	char moneystr[10]={'\0'};
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p1=NULL;   //指向需要接收字符的地址的指针变量
	if ((fp = fopen("./t_file/user/money.txt","r+")) == NULL)//以读写的方式打开
    {
	  closegraph();
	  printf("Can't open money.txt");
	  //getchar();
	  exit(1);
    }
	while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	{
		cha=fgetc(fp);//读取一个字符
		if(cha=='/')//'/'默认为账户名的开始
		{
			for(k=0;k<11;k++)
	    	{
				 accounts[k]='\0';
			}
			flag=1;
			p1=accounts;
			m=0;
		}
		else if(cha=='#'&&flag==1)
		{
			flag=2;
			if(strcmp(accounts,acccountsperson)==0)
			{
				judge = 1;
				p1 = moneystr;
			}
		}
		else if(cha!='\0'&&flag==1)
		{
			*p1=cha;
			 p1++;
		}
		else if(cha!='\0'&&flag==2&&judge==1)
		{
			*p1=cha;
			 p1++;
		}
	}
	* money = atol(moneystr);
	fclose(fp);
}
/****************************************
Function :changemoney(char *accountsperson,long money) 
Description:
Attention:
Return：
***************************************/
void changemoney(char *accountsperson,long money)
{
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p1=NULL;   //指向需要接收字符的地址的指针变量
	int judge=-1;
	int m=0;
	int k=0;
	int flag = 0;
	char moneystr[10]={'\0'};
	char accounts[11]={'\0'};
	ltoa(money,moneystr,10);
	if ((fp = fopen("./t_file/user/money.txt", "r+")) == NULL)
	{
		closegraph();
		printf("Can't open money.txt");
		getchar();
		exit(1);
	}
    while (!feof(fp))
	{
		cha = fgetc(fp);
		if(cha=='/')//'/'默认为账户名的开始
		{
			for(k=0;k<11;k++)
	    	{
				 accounts[k]='\0';
			}
			flag=1;
			p1=accounts;
			m=0;
		}
		else if(cha=='#'&&flag==1)
		{
			flag=2;
			if(strcmp(accounts,accountsperson)==0)
			{
				judge = 1;
				p1 = moneystr;
			}
		}
		else if(cha!='\0'&&flag==1)
		{
			*p1=cha;
			 p1++;
		}
		else if(flag==2&&judge==1)
		{
			fseek(fp,-1L,SEEK_CUR);
			fputs(p1,fp);
			break;
		}
	}
	fclose(fp);
}
/****************************************
Function : zhifu(char *item,int money,setuser *person)
Description:支付界面
Attention:无
Return：上一个界面的judge值
***************************************/
int zhifu(char *item,int money,setuser *person,int xiangxiang)
{
	int judge = 0;
	int press,MouseX,MouseY;
	char moneystr[8]={'\0'};
	int k;
	itoa(money,moneystr,10);
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	Drawbeautiful(0,0,1);
	puthz(150,50,"您正在进行支付环节",32,40,CYAN);
	puthz(50,130,"您的支付项目为",16,20,LIGHTGRAY);
	puthz(240,130,item,16,16,CYAN);
	puthz(50,170,"您所需支付金额为",16,20,LIGHTGRAY);
	outtextxy(240,170,moneystr);
	puthz(300,170,"元",16,16,LIGHTGRAY);
	puthz(50,210,"您可以选择的支付方式有",16,20,LIGHTGRAY);
	setfillstyle(1,LIGHTBLUE);
	bar(50,250,100,300);
	
	puthz(57,257,"支",32,30,WHITE);
	setfillstyle(1,LIGHTGREEN);
	bar(150,250,200,300);
	setfillstyle(1,WHITE);
	setcolor(WHITE);
	fillellipse(150+20,250+23,12,10);
	line(200-38,250+35,200-36,250+29);
	line(200-38,250+35,200-32,250+30);
	fillellipse(150+35,250+30,10,6);
	line(150+42,250+40,150+36,250+36);
	line(150+42,250+40,150+39,250+35);
	setfillstyle(1,LIGHTGREEN);
	fillellipse(150+18-1,250+18+3,2,2);
	fillellipse(150+25-1,250+18+3,2,2);
	fillellipse(150+29+1,250+26+2,2,2);
	fillellipse(150+37+1,250+26+2,2,2);
	setcolor(LIGHTGREEN);
	ellipse(150+35,250+30,0,360,10,6);
	setfillstyle(1,CYAN);
	bar(250,250,400,300);
	puthz(260,257,"余额支付",32,30,WHITE);
	if((person->money - money)>=100)
	{
		puthz(240,290,"荐",16,16,RED);
	}
	else if((person->money - money) >= 0)
	{
		puthz(410,255,"您的余额较少，支付后",16,16,LIGHTGRAY);
		puthz(410,280,"可能无法进行其他操作",16,16,LIGHTGRAY);
	}
	else if((person->money - money) <= 0)
	{
		setfillstyle(1,LIGHTGRAY);
		bar(250,250,400,300);
		puthz(260,257,"余额支付",32,30,WHITE);
		puthz(410,255,"余额不足",16,16,LIGHTGRAY);
		k = 0;
	}
	puthz(50,320,"支付宝或微信支付不会花费账户余额",16,16,LIGHTGRAY);
	setfillstyle(1,CYAN);
	bar(270,400,370,440);
	puthz(285,410,"我再想想",16,20,WHITE);
	puthz(80,450,"平安好车主只有此一个支付界面 请用户认真辨别",16,20,LIGHTGRAY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=270 && MouseX <= 370&& MouseY >= 400&& MouseY <= 440 &&press )
		{
			return xiangxiang;
		}
		if(MouseX >=50 && MouseX <= 100&& MouseY >= 250&& MouseY <= 300 &&press )
		{
			puthz(50,350,"支付成功！",16,20,RED);
			puthz(50,380,"三秒后自动返回",16,16,RED);
			outtextxy(300,380,"3");
			delay(1000);
			setfillstyle(1,WHITE);
			bar(300,380,330,400);
			outtextxy(300,380,"2");
			delay(1000);
			setfillstyle(1,WHITE);
			bar(300,380,330,400);
			outtextxy(300,380,"1");
			delay(1000);
			return -1;
		}
		if(MouseX >=150 && MouseX <= 200&& MouseY >= 250&& MouseY <= 300 &&press ) 
		{
			puthz(50,350,"支付成功！",16,20,RED);
			puthz(50,380,"三秒后自动返回",16,16,RED);
			outtextxy(300,380,"3");
			delay(1000);
			setfillstyle(1,WHITE);
			bar(300,380,330,400);
			outtextxy(300,380,"2");
			delay(1000);
			setfillstyle(1,WHITE);
			bar(300,380,330,400);
			outtextxy(300,380,"1");
			delay(1000);
			return -1;
		}
		if(k!=0&&MouseX >=250 && MouseX <= 400&& MouseY >= 250&& MouseY <= 300 &&press )
		{
			person->money -= money;
			changemoney(person->accounts,person ->money);
			puthz(50,350,"支付成功！",16,20,RED);
			puthz(50,380,"三秒后自动返回",16,16,RED);
			outtextxy(300,380,"3");
			delay(1000);
			setfillstyle(1,WHITE);
			bar(300,380,330,397);
			outtextxy(300,380,"2");
			delay(1000);
			setfillstyle(1,WHITE);
			bar(300,380,330,397);
			outtextxy(300,380,"1");
			delay(1000);
			return -1;
		}
	}
	
}
