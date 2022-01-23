#include "common.h"
#include "chzh.h"
/****************************************
Function :drawmymoney(setuser *person)
Description:���ҵ�Ǯ������
Attention:��
Return����
***************************************/
void drawmymoney(setuser *person)
{
	drawuserself();
	setfillstyle(1,RED);
	bar(170,170+40,180,210+40);
	puthz(325,65,"�˻���ֵ",32,35,GREEN);
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,3);
	line(180,100,640,100);
	puthz(200,115,"�˺�",16,20,BLACK);
	settextstyle(2,0,6);
	outtextxy(500,115,person->accounts);
	setlinestyle(SOLID_LINE,0,1);
	line(180,140,640,140);
	puthz(200,155,"���",16,20,BLACK);
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
	puthz(260,213,"Ԫ",16,20,BLACK);
	outtextxy(380,210,"50");
	puthz(405,213,"Ԫ",16,20,BLACK);
	outtextxy(525,210,"100");
	puthz(553,213,"Ԫ",16,20,BLACK);
	outtextxy(235,270,"200");
	puthz(268,273,"Ԫ",16,20,BLACK);
	outtextxy(380,270,"500");
	puthz(408,273,"Ԫ",16,20,BLACK);
	puthz(515,270,"�������",16,20,BLACK);
	line(180,320,640,320);
	puthz(200,330,"�˺�����",16,20,BLACK);
	//puthz(440,330,"�������˺�����",16,16,LIGHTGRAY);
	rectangle(430,325,630,355);
	line(180,360,640,360);
	setfillstyle(1,CYAN);
	bar(210,420,610,460);
	puthz(360,430,"ȷ�ϳ�ֵ",16,20,WHITE);
}
/****************************************
Function : usermoney(setuser *head,setuser *person)
Description:�û���������->�ҵ�Ǯ��*���湦��
Attention:��
Return����һ�������judgeֵ
***************************************/
int usermoney(setuser *head,setuser *person)
{
	char code[10];
	int k=0;
	char chongzhi[4];//��ʾ��ֵ�Ľ��
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
	puthz(600,155,"Ԫ",16,20,BLACK);
	//puthz(405,213,"Ԫ",16,20,BLACK);
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
		
		//20Ԫ
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
			puthz(260,213,"Ԫ",16,20,WHITE);
			cz = 20;
			k=0;
			p = 1;
		}
		//50Ԫ
		if(MouseX >=350  && MouseX <= 470 && MouseY >= 200 &&MouseY <= 240 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(350+1,200+1,470-1,240-1);
			setcolor(WHITE);
			outtextxy(380,210,ys[1]);
			puthz(405,213,"Ԫ",16,20,WHITE);
			cz = 50;
			k=0;
			p =2;
			
		}
		//100Ԫ
		if(MouseX >=495  && MouseX <= 615 && MouseY >= 200 &&MouseY <= 240 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(495+1,200+1,615-1,240-1);
			setcolor(WHITE);
			outtextxy(525,210,ys[2]);
			puthz(553,213,"Ԫ",16,20,WHITE);
			cz = 100;
			k=0;
			p =3;
		}
		//200Ԫ
		if(MouseX >=205  && MouseX <= 325 && MouseY >= 260 &&MouseY <= 300 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(205+1,260+1,325-1,300-1);
			setcolor(WHITE);
			outtextxy(235,270,ys[3]);
			puthz(265,273,"Ԫ",16,20,WHITE);
			cz = 200;
			k=0;
			p =4;
		}
		//500Ԫ
		if(MouseX >=350  && MouseX <= 470 && MouseY >= 260 &&MouseY <= 300 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			settextstyle(2,0,6);
			setfillstyle(1,CYAN);
			bar(350+1,260+1,470-1,300-1);
			setcolor(WHITE);
			outtextxy(380,270,ys[4]);
			puthz(410,273,"Ԫ",16,20,WHITE);
			cz = 500;
			k=0;
			p= 5;
		}
		//����������
		if(MouseX >=495  && MouseX <= 615 && MouseY >= 260 &&MouseY <= 300 && press)
		{
			clrmous(MouseX,MouseY);
			fugai(p);
			setfillstyle(1,CYAN);
			bar(495+1,260+1,615-1,300-1);
			puthz(515,270,"�������",16,20,WHITE);
			setcolor(DARKGRAY);
			line(180,410,640,410);
			puthz(200,380,"���",16,20,BLACK);
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
				puthz(600,155,"Ԫ",16,20,BLACK);
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
					judge = queren("δѡ����Ҫ��ֵ��Ǯ����",220,150,16,20,-1);
					break;
				}
				else if( strcmp(code, (*person).code) != 0)
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("���벻��ȷ��",225,150,32,35,-1);
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
						judge = queren("�˻������ٶ��ˣ�",240,150,16,20,-1);
						ltoa(person->money,money,10);
						changemoney(person->accounts,person->money);
						break; 
					}
					ltoa(person->money,money,10);
					changemoney(person->accounts,person->money);
					clrmous(MouseX,MouseY);
					delay(100);
					judge = queren("��ֵ�ɹ���",240,150,32,35,-1);
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
Description:���ǽ��
Attention:��
Return����
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
			puthz(260,213,"Ԫ",16,20,BLACK);
			break;
		}
		case 2:
		{
			bar(350+1,200+1,470-1,240-1);
			outtextxy(380,210,"50");
			puthz(405,213,"Ԫ",16,20,BLACK);
			break;
		}
		case 3:
		{
			bar(495+1,200+1,615-1,240-1);
			outtextxy(525,210,"100");
			puthz(553,213,"Ԫ",16,20,BLACK);
			break;
		}
		case 4:
		{
			bar(205+1,260+1,325-1,300-1);
			outtextxy(235,270,"200");
			puthz(268,273,"Ԫ",16,20,BLACK);
			break;
		}
		case 5:
		{
			bar(350+1,260+1,470-1,300-1);
			outtextxy(380,270,"500");
			puthz(408,273,"Ԫ",16,20,BLACK);
			break;
		}
		case 6:
		{
			bar(495+1,260+1,615-1,300-1);
			puthz(515,270,"�������",16,20,BLACK);
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
	//puthz(100,100,"Ԫ",16,16,CYAN);
	//puthz(553,213,"Ԫ",16,20,CYAN);
	/*puthz(405,213,"Ԫ",16,20,BLACK);
	puthz(260,213,"Ԫ",16,20,BLACK);
	puthz(268,273,"Ԫ",16,20,BLACK);
	puthz(408,273,"Ԫ",16,20,BLACK);
	puthz(515,270,"�������",16,20,BLACK);
	setfillstyle(1,WHITE);
	bar(181,365,640,415);
}*/
/****************************************
Function :cincode(char *code,int *MouseX,int *MouseY,int k) 
Description:��������
Attention:��
Return����һ��������judgeֵ
***************************************/
int cincode(char *code,int *MouseX,int *MouseY,int k)
{
	int key;     //��ʾ ��ֵ �ı���
	int i= 0;    //���ڼ����Ѿ�������ַ� ��Ŀ�ı���
	char *p = code;  //�����ַ����м�ָ�����
	char ch;     //������ʱ �����ֵ����Ӧ���ַ�����
	int press;   //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	while (*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
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
		//���ü�ֵ���õ��¼�ֵ
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
		 //�������ɾ����
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
		/*��������Ӧ���ַ�����code������*/
		ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(438 + i * 11, 334, 449 + i * 11, 350);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(438 + i * 11, 334, temp);
		//	backgroundChange(*MouseX, *MouseY, 438 + i * 11, 334, 449 + i * 11, 350);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :cinmoney(char * chongzhi,int *MouseX,int *MouseY)
Description:������Ҫ��ֵ�Ľ��
Attention:��
Return����һ��������judgeֵ
***************************************/
int cinmoney(char * chongzhi,int *MouseX,int *MouseY)
{
	int key;     //��ʾ ��ֵ �ı���
	int i= 0;    //���ڼ����Ѿ�������ַ� ��Ŀ�ı���
	char *p = chongzhi;  //�����ַ����м�ָ�����
	char ch;     //������ʱ �����ֵ����Ӧ���ַ�����
	int press;   //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
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
		key = 0;   //���ü�ֵ���õ��¼�ֵ
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		if(!(*MouseX >=430  && *MouseX <= 630 && *MouseY >= 365 && *MouseY <= 405) && press)
		{
			return 0;
		}
		//�������ɾ����
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
		/*��������Ӧ���ַ�����chongzhi������*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<4)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(438 + i * 11, 379, 449 + i * 11,395);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(438 + i * 11,379, temp);
			//backgroundChange(*MouseX, *MouseY, 438 + i * 11, 379, 449 + i * 11, 395);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :putmoney(char *accounts,long money)
Description:����ֵ��Ľ������ļ�
Attention:��
Return����
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
Description:��ȡ���û������
Attention:��
Return�����û������
***************************************/
int dumoney(char *acccountsperson,long *money)
{
	int m =0 ;
	int j,k;
	int flag=0;
	int judge=-1;
	char accounts[11]={'\0'};
	char moneystr[10]={'\0'};
	FILE *fp=NULL; //���ļ���ָ��
	char cha;    //���ڽ��ղ������ļ��ڲ��ַ����м����
    char *p1=NULL;   //ָ����Ҫ�����ַ��ĵ�ַ��ָ�����
	if ((fp = fopen("./t_file/user/money.txt","r+")) == NULL)//�Զ�д�ķ�ʽ��
    {
	  closegraph();
	  printf("Can't open money.txt");
	  //getchar();
	  exit(1);
    }
	while(!feof(fp))//�ļ���ȡ����������ļ���������ֵ��1������Ϊ0
	{
		cha=fgetc(fp);//��ȡһ���ַ�
		if(cha=='/')//'/'Ĭ��Ϊ�˻����Ŀ�ʼ
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
Return��
***************************************/
void changemoney(char *accountsperson,long money)
{
	FILE *fp=NULL; //���ļ���ָ��
	char cha;    //���ڽ��ղ������ļ��ڲ��ַ����м����
    char *p1=NULL;   //ָ����Ҫ�����ַ��ĵ�ַ��ָ�����
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
		if(cha=='/')//'/'Ĭ��Ϊ�˻����Ŀ�ʼ
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
Description:֧������
Attention:��
Return����һ�������judgeֵ
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
	puthz(150,50,"�����ڽ���֧������",32,40,CYAN);
	puthz(50,130,"����֧����ĿΪ",16,20,LIGHTGRAY);
	puthz(240,130,item,16,16,CYAN);
	puthz(50,170,"������֧�����Ϊ",16,20,LIGHTGRAY);
	outtextxy(240,170,moneystr);
	puthz(300,170,"Ԫ",16,16,LIGHTGRAY);
	puthz(50,210,"������ѡ���֧����ʽ��",16,20,LIGHTGRAY);
	setfillstyle(1,LIGHTBLUE);
	bar(50,250,100,300);
	
	puthz(57,257,"֧",32,30,WHITE);
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
	puthz(260,257,"���֧��",32,30,WHITE);
	if((person->money - money)>=100)
	{
		puthz(240,290,"��",16,16,RED);
	}
	else if((person->money - money) >= 0)
	{
		puthz(410,255,"���������٣�֧����",16,16,LIGHTGRAY);
		puthz(410,280,"�����޷�������������",16,16,LIGHTGRAY);
	}
	else if((person->money - money) <= 0)
	{
		setfillstyle(1,LIGHTGRAY);
		bar(250,250,400,300);
		puthz(260,257,"���֧��",32,30,WHITE);
		puthz(410,255,"����",16,16,LIGHTGRAY);
		k = 0;
	}
	puthz(50,320,"֧������΢��֧�����Ứ���˻����",16,16,LIGHTGRAY);
	setfillstyle(1,CYAN);
	bar(270,400,370,440);
	puthz(285,410,"��������",16,20,WHITE);
	puthz(80,450,"ƽ���ó���ֻ�д�һ��֧������ ���û�������",16,20,LIGHTGRAY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=270 && MouseX <= 370&& MouseY >= 400&& MouseY <= 440 &&press )
		{
			return xiangxiang;
		}
		if(MouseX >=50 && MouseX <= 100&& MouseY >= 250&& MouseY <= 300 &&press )
		{
			puthz(50,350,"֧���ɹ���",16,20,RED);
			puthz(50,380,"������Զ�����",16,16,RED);
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
			puthz(50,350,"֧���ɹ���",16,20,RED);
			puthz(50,380,"������Զ�����",16,16,RED);
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
			puthz(50,350,"֧���ɹ���",16,20,RED);
			puthz(50,380,"������Զ�����",16,16,RED);
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
