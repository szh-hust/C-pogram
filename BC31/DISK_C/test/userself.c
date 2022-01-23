/************************************************************************
Function list:      userself   �û���������������
					userpolicy �û���������->�ҵı���*���湦��
					usercar	   �û���������->������*���湦��
					aboutus    �û���������->��������*���湦��
					problem    �û���������->��������*���湦��
*******************************************************************/
#include "common.h"
#include "userself.h"
#include "userll.h"
#include "ccode.h"
#include "chzh.h"
#include "draw.h"
/****************************************
Function : userself (setuser *head,setuser *person,struct POLICY policy[10])
Description: �û��������ĺ�̨����
Attention:��һ�����ܺ�����user.c->int usermain(setuser *head,setuser *person)
return ��usermian������judgeֵ 
***************************************/
int userself(setuser *head,setuser *person,struct POLICY policy[10])
{
	int judge = 0;
	int press,MouseX,MouseY;
	int i=0;
	int k=0;
	struct CLAIM claim[10];
	delay(100);
	puthz(280,150,"���ã�",32,50,CYAN);
	setcolor(GREEN);
	settextstyle(DEFAULT_FONT,0,3);
	outtextxy(400,160,(*person).accounts);
	save_bk_mou(MouseX,MouseY);
	for(i=0;i<10;i++)
	{
		k=duqulp(person,claim,i);
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//�����ҵı���
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
		{
			judge = 1;
		}
		//�����ҵ�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
		{
			judge = 2;
		}
		//���밮������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 &&MouseY <= 170 && press)
		{
			judge = 3;
		}
		//�����޸�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 &&MouseY <= 210 && press)
		{
			judge = 4;
		}
		//�����ҵ�Ǯ��
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
		{
			judge = 5;
		}
		//�����������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 &&MouseY <= 290 && press)
		{
			judge = 6;
		}
		//���볣������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 &&MouseY <= 330 && press)
		{
			judge = 7;
		}
		//���������ҳ(505,10,590,40)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
		{
			judge = 8;
		}
		switch(judge)
		{
			case 1://�����ҵı���
			{
				drawuserpolicy(person);
				judge = userpolicy(person,policy);
				break;
			}
			//�ҵ����� 
			case 2:
			{
				drawmyclaim();
				judge=myclaim(claim,k);
				break;
			}
			case 3://���밮������
			{
				drawmycar(person);
				judge = usercar(person,policy);
				break;
			}
			case 4:
			{
				drawchangecode();
				judge = changecode(head,person);
				break;
			}
			case 5:
			{
				drawmymoney(person);
				judge = usermoney(head,person);
				break;
			}
			case 6:
			{
				drawaboutus(person);
				judge = aboutus(person);
				break;
			}
			case 7:
			{
				drawproblem(person);
				judge = problem(person);
				break;
			}
			case 8://������ذ�ť��������ҳ
			{
				return -1;
			}
		}
	}
}
/****************************************
Function : userself (void)
Description: �û��������ĺ�̨��ͼ����
Attention:��
return: 
***************************************/
void drawuserself(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,40+10);
	puthz(10,10,"ƽ���ó���",32,40,WHITE);
	puthz(230,30,"��������",16,30,RED);
	setfillstyle(1,CYAN);
	bar(20,420,120,460);
	puthz(30,430,"������ҳ",16,20,WHITE);
	
	setfillstyle(1,LIGHTGRAY);
	bar(170,50,180,480);
	
	setcolor(BLACK);
	line(0,50,640,50);
	
	//line(0,50,150,50);
	line(0,50,0,330);
	line(150,50,150,330);
	line(0,290,150,290);
	line(0,90,150,90);
	line(0,130,150,130);
	line(0,170,150,170);
	line(0,210,150,210);
	line(0,250,150,250);
	line(0,290,150,290);
	line(0,330,150,330);
	puthz(10,60,"�ҵı���",16,30,BLACK);
	puthz(10,100,"�ҵ�����",16,30,BLACK);
	puthz(10,140,"��������",16,30,BLACK);
	puthz(10,180,"�޸�����",16,30,BLACK);
	puthz(10,220,"�ҵ�Ǯ��",16,30,BLACK);
	puthz(10,260,"��������",16,30,BLACK);
	puthz(10,300,"��������",16,30,BLACK);
	
}


/****************************************
Function : userpolicy(setuser *person,struct POLICY policy[10])
Description:�û���������->�ҵı���*���湦��
Attention:
***************************************/
int userpolicy(setuser *person,struct POLICY policy[10])
{
	int judge = 0;
	int i,k=0,t;
	char ch[3]={'\0'};
	int press,MouseX,MouseY;

	for(i=0;i<10;i++)
	{
		if(policy[i].p==1)
		{
			settextstyle(2,0,6);
			setcolor(BLACK);
			outtextxy(240,100+k*40,policy[i].bdh);
			puthz(350,100+k*40,policy[i].pcity,16,16,BLACK);
			outtextxy(370,100+k*40,policy[i].plate);
			outtextxy(460,100+k*40,policy[i].baofei[5]);
			puthz(560,100+k*40,"�鿴����",16,16,BLACK);
			if(k==9) 
		    {
		    	strcpy(ch,"10");
			}
			else
			{
				ch[0] = k+'1';
			} 
			outtextxy(190,100+(k)*40,ch);
			k++;
		}
	}
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//�����ҵ�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
			return 2;
		//���밮������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 && MouseY <= 170 && press)
			return 3;
		//�����޸�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 && MouseY <= 210 && press)
			return 4;
		//�����ҵ�Ǯ��
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
			return 5;
		//�����������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 && MouseY <= 290 && press)
			return 6;	
		//���볣������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 && MouseY <= 330 && press)
			return 7;
		//���������ҳ(20,420,120,460)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
			return 8;
		if(MouseX>=560 && MouseX<=640 && MouseY>=90 && MouseY<=90+k*40 && press)
		{
			judge = 1;
			t = (MouseY-90)/40;
		}
		switch(judge)
		{
			case -1:
			{
				drawuserpolicy(person);
				k=0;
				for(i=0;i<10;i++)
				{
					if(policy[i].p==1)
					{
						outtextxy(240,100+k*40,policy[i].bdh);
						puthz(350,100+k*40,policy[i].pcity,16,16,BLACK);
						outtextxy(370,100+k*40,policy[i].plate);
						outtextxy(460,100+k*40,policy[i].baofei[5]);
						puthz(560,100+k*40,"�鿴����",16,16,BLACK);
						settextstyle(2,0,6);
						setcolor(BLACK);
						if(k==9) 
		   				{
		    				strcmp(ch,"10");
						}
						else
						{
							ch[0] = k+'1';
						} 
						outtextxy(190,100+(k)*40,ch);
						k++;
					}
				}
				save_bk_mou(MouseX,MouseY);
				judge = 0;
				break;
			}
			case 1:
			{
				clrmous(MouseX,MouseY);
				judge = chakan(policy,t);
				break;
			}
			case 2:
			{
				//clrmous(MouseX,MouseY);
				judge = shanchu(person,policy,t);
				//clrmous(MouseX,MouseY);
				if(judge == 3)
				{
					clrmous(MouseX,MouseY);
					judge = sccg();
					break;
				}
			}
		}
	}
}
int  sccg()
{
	int press;
	int MouseX,MouseY;
	setfillstyle(1,LIGHTGRAY);
	bar(155,115,485,365);
	setfillstyle(1,WHITE);
	bar(160,120,480,360);//320*240
	Drawbeautiful(160,120,0.5);
	puthz(220,170,"ɾ���ɹ���",16,20,GREEN);
	setcolor(CYAN);
	outtextxy(300,200,"70%");
	puthz(200,200,"�ѽ����ѵ�  �������",16,20,GREEN);
	setfillstyle(1,CYAN);
	bar(260,300,380,340);
	puthz(300,310,"�õ�",16,25,WHITE);
	clrmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=260 && MouseX <= 380 && MouseY >= 300 && MouseY <= 360 && press)
			return -1;
	}
}
/**************************
Function :drawuserpolicy(setuser *person)
Description:
Attention:
****************************************/
void drawuserpolicy(setuser *person)
{
	int i;
	drawuserself();
	setfillstyle(1,RED);
	bar(170,50,180,90);
	setfillstyle(1,CYAN);
	bar(180,50,640,90);
	puthz(185,60,"���",16,16,WHITE);
	puthz(240,60,"�������",16,16,WHITE);
	puthz(350,60,"������Ϣ",16,16,WHITE);
	puthz(460,60,"���ѣ�Ԫ��",16,16,WHITE);
	//puthz(550,60,"�鿴����",16,16,WHITE);
	for(i=0;i<7;i++)
	{
		setfillstyle(1,LIGHTGRAY);
		bar(180,90+i*80,640,130+i*80);
	}
	for(i=0;i<6;i++)
	{
		setfillstyle(1,WHITE);
		bar(180,130+i*80,640,170+i*80);
	}
}
/****************************************
Function :chakan(struct POLICY policy[10],int t)
Description:
Attention:���뱣������Ҫ�鿴�ı������ 
return: -1/2 
***************************************/
int chakan(struct POLICY policy[10],int t)
{
	int j=0;
	int judge = 0;
	char name[5][10]={"��ǿ��","������","������","˾����","�˿���"};
	int p =0;
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	bar(185,215,635,435);
	setfillstyle(1,WHITE);
	bar(190,220,630,430);
	puthz(195,230,"���ƺţ�",16,16,LIGHTGRAY);
	puthz(280,230,policy[t].pcity,16,16,LIGHTGRAY);
	outtextxy(300,230,policy[t].plate);
	puthz(195,260,"Ʒ�ƣ�",16,16,LIGHTGRAY);
	puthz(280,260,policy[t].pinpai,16,16,LIGHTGRAY);
	puthz(195,290,"��ϵ�绰��",16,16,LIGHTGRAY);
	outtextxy(280,290,policy[t].dianhua);
	puthz(195,320,"�����ţ�",16,16,LIGHTGRAY);
	outtextxy(280,320,policy[t].bdh);
	puthz(195,350,"�ϼƱ���",16,16,LIGHTGRAY);
	outtextxy(280,350,policy[t].money_str[5]);
	puthz(195,380,"�ϼƱ���",16,16,LIGHTGRAY);
	outtextxy(280,380,policy[t].baofei[5]);
	line(440,225,440,425);
	puthz(455,230,"֧��״̬��",16,16,LIGHTGRAY);
	puthz(545,230,"��֧��",16,16,LIGHTGRAY);
	puthz(455,260,"����״̬��",16,16,LIGHTGRAY);
	if(policy[t].zt == 1)
	{
		puthz(545,260,"������",16,16,LIGHTGRAY);
	}
	else 
	{
		puthz(545,260,"δ����",16,16,LIGHTGRAY);
		puthz(500,400,"ɾ��",16,16,LIGHTGRAY);
	}
	puthz(580,400,"��һҳ",16,16,LIGHTGRAY);
	
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(p == 0 && MouseX>=580 && MouseX<=630 && MouseY>=400 && MouseY<=430 && press)
		{
			judge = 1;
		}
		if(MouseX>=0 && MouseX<=640 && MouseY>=0 && MouseY<=480)
		{
			if(!(MouseX>=190 && MouseX<=630 && MouseY>=220 && MouseY<=430) && press)
			{
				judge = 2;
			}
		}
		if(policy[t].zt != 1&&MouseX>=500 && MouseX<=550 && MouseY>=400 && MouseY<=430 && press)
		{
			judge = 3;
		}
		switch(judge)
		{
			case 1:
			{
				p = 1;
				setfillstyle(1,WHITE);
				bar(190,220,630,430);
				puthz(195,230,"��������",16,20,LIGHTGRAY);
				puthz(295,230,"���Ԫ��",16,20,LIGHTGRAY);
				puthz(455,230,"����",16,20,LIGHTGRAY);
				for(j=0;j<5;j++)
				{
						puthz(195,260+j*30,name[j],16,20,LIGHTGRAY);
						setcolor(LIGHTGRAY);
						outtextxy(295,260+30*j,policy[t].money_str[j]);
						outtextxy(455,260+30*j,policy[t].baofei[j]);
						//p++;
				}
				//p=0;
				judge = 0;
				save_bk_mou(MouseX,MouseY);
				break;
			}
			case 2:
			{
				return -1;
			}
			case 3:
				{
					clrmous(MouseX,MouseY);
					return 2;
				}
		}
	}
}
/*****************************************
Function :shanchu(setuser *person,struct POLICY policy [10],int number)
Description:ɾ���û����еı��� 
Attention: �Ѿ�����ı�������ɾ�� 
return: 3
**************************************/ 
int shanchu(setuser *person,struct POLICY policy [10],int number)
{
	int i,num;
    long bao = 0;
	long money=0;
	dumoney(person->accounts,&money);
	bao = atol(policy[num-1].baofei[5]);
	money = money+ bao*0.7;
	changemoney(person->accounts,money);
	shanchubd(person,number);
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
		return 3;
}
/*****************************************
Function : shanchubd(setuser *person,int i)
Description:������ص��ı����� 
Attention:
return: �� 
**************************************/ 
void shanchubd(setuser *person,int i)
{
	int j,k;
	int flag=0;
	int judge=0;
	FILE *fp=NULL; //���ļ���ָ��
	char cha;    //���ڽ��ղ������ļ��ڲ��ַ����м����
    char *p1=NULL;   //ָ����Ҫ�����ַ��ĵ�ַ��ָ�����
	//char **p2=NULL;
	char accounts[11]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

	if ((fp = fopen("./t_file/user/policy.txt","r+")) == NULL)//�Զ�д�ķ�ʽ��
    {
	  closegraph();
	  printf("Can't open policy.txt");
	  //getchar();
	  exit(1);
    }
	//return judge ;
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
		}
		else if(cha=='#'&&flag==1)
		{
			flag=2;
			if(strcmp(accounts,person->accounts)==0)
		    judge++;
		}
		else if(cha!='\0'&&flag==1)
		{
			*p1=cha;
			 p1++;
		}
		if(cha=='/'&&judge==i)
		{
			fseek(fp,-1l,SEEK_CUR);
			fputc('$',fp);
			//putc(*p1,fp);
			fclose(fp);
			break;
		}
	}
}
/****************************************
Function : usercar
Description:�û���������->������*���湦��
Attention:
return ����һ��������judge 
***************************************/
int usercar(setuser *person,struct POLICY policy[10])
{
	int judge = 0;
	int i;
	int press,MouseX,MouseY;
	char ch[3]={'\0'};
	int k=0;
	delay(100);
    save_bk_mou(MouseX,MouseY);
	for(i=0;i<10;i++)
	{
		if(policy[i].p==1)
		{
			settextstyle(2,0,6);
		    setcolor(BLACK);
		    if(i==9)
		    {
		    	strcmp(ch,"10");
			}
			else
			{
				ch[0] = i+'1';
			} 
		    outtextxy(190,100+k*40,ch);
			outtextxy(385,100+k*40,policy[i].chejia);
			puthz(260,100+k*40,policy[i].pcity,16,16,BLACK);
			outtextxy(280,100+k*40,policy[i].plate);
			puthz(560,100+k*40,policy[i].pinpai,16,16,BLACK);
			k++;
		}
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//�����ҵı���
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
			return 1;
		//�����ҵ�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
			return 2;
		//�����޸�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 && MouseY <= 210 && press)
			return 4;
		//�����ҵ�Ǯ��
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
			return 5;
		//�����������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 && MouseY <= 290 && press)
			return 6;	
		//���볣������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 && MouseY <= 330 && press)
			return 7;
		//���������ҳ(20,420,120,460)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
			return 8;
	}
}
/****************************************
Function : drawmycar
Description:�����û���������->������*����
Attention:��һ��������judge 
***************************************/
void drawmycar(setuser *person)
{
	int i;
	//char size[3];
	//char pla[7];
	drawuserself();
	setfillstyle(1,RED);
	bar(170,130,180,170);
	setfillstyle(1,CYAN);
	bar(182,51,640,90);
    setlinestyle(SOLID_LINE,0,1);
	puthz(195,60,"���",16,20,RED);
	setcolor(WHITE);
	line(240,51,240,90);
	puthz(270,60,"���ƺ�",16,30,RED);
	line(370,51,370,90);
	puthz(385,60,"���ܺ�",16,30,BLACK);
	line(520,51,520,90);
	puthz(530,60,"����Ʒ��",16,30,BLACK);
	settextstyle(SMALL_FONT,HORIZ_DIR,6);
	setcolor(RED);
	for(i=0;i<7;i++)
	{
		setfillstyle(1,LIGHTGRAY);
		bar(180,90+i*80,640,130+i*80);
	}
	for(i=0;i<6;i++)
	{
		setfillstyle(1,WHITE);
		bar(180,130+i*80,640,170+i*80);
	}
}
/****************************************
Function : aboutus
Description:�û���������->��������*���湦��
Attention:��һ��������judge 
***************************************/
int aboutus()
{
	int judge = 0;
	int press,MouseX,MouseY;
	int driver =VGA;
	int mode = VGAHI;
	//clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//�����ҵı���
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
			return 1;
		//�����ҵ�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
			return 2;
		//���밮������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 && MouseY <= 170 && press)
			return 3;
		//�����޸�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 && MouseY <= 210 && press)
			return 4;
		//�����ҵ�Ǯ��
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
			return 5;	
		//���볣������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 && MouseY <= 330 && press)
			return 7;
		//���������ҳ(20,420,120,460)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
			return 8;
		//����������
		if(MouseX >=350  && MouseX <= 450 &&MouseY >= 250+50 &&MouseY <= 290+50 && press)
			judge = 1;
		switch(judge)
		{
			case 1:
			{
			    drawadvice();
				delay(100);
				judge=advice();
				break;
			}
			case 2:
			{
				return 6; 
			} 
		}
	}
}
/****************************************
Function : drawaboutus
Description:�����û���������->��������*����
Attention:
***************************************/
void drawaboutus(setuser *person)
{

	drawuserself();
	setfillstyle(1,RED);
	bar(170,250,180,290);
	setfillstyle(1,CYAN);
	bar(300+50,250+50,400+50,290+50);
	puthz(310+50,260+50,"�������",16,20,WHITE);
	puthz(190,60,"Ӧ�ý���",32,30,BLACK);
	puthz(220,110,"�ó��������ó����ְ�ȫ�ܼҡ���",16,16,BLACK);
	puthz(190,140,"ƽ���ó�����ƽ������Ϥ�Ĵ����һվʽ����ƽ̨���������Գ�",16,16,BLACK);
	puthz(190,170,"������Ϊ�������ṩ�������񡢳����ա�����������ų�����",16,16,BLACK);
	puthz(190,200,"���߼�ֵ���գ������������������������������ͣ���ɷѡ��������ա�Υ�²�ѯ�������⡢�鱣������·��Ԯ�����߷���",16,16,BLACK);
	settextstyle(SMALL_FONT,0,7);
	setcolor(RED);
	
	outtextxy(400,420,"Author");
	puthz(500,430,"���ں� ��٥��",16,16,BLACK);
	puthz(400,455,"��ϵ����",16,16,RED);
	setcolor(BLACK);
	outtextxy(500,455,"1578899003");
}
/****************************************
Function : problem
Description:�û���������->��������*���湦��
Attention:��һ��������judge 
***************************************/
int problem()
{
	int judge = 0;
	int press,MouseX,MouseY;
	int driver =VGA;
	int mode = VGAHI;
	//clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//�����ҵı���
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
			return 1;
		//�����ҵ�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
			return 2;
		//���밮������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 && MouseY <= 170 && press)
			return 3;
		//�����޸�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 && MouseY <= 210 && press)
			return 4;
		//�����ҵ�Ǯ��
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
			return 5;
		//�����������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 && MouseY <= 290 && press)
			return 6;	
		//���������ҳ(20,420,120,460)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
			return 8;
		if(MouseX >=190  && MouseX <= 370 && MouseY >= 120 &&MouseY <= 170 && press)
		{
			judge = 1;
		}
		if(MouseX >=190  && MouseX <= 370 && MouseY >= 170 &&MouseY <= 220 && press)
		{
			judge = 2;
		}
		if(MouseX >=190  && MouseX <= 370 && MouseY >= 220 &&MouseY <= 270 && press)
		{
			judge = 3;
		}
		if(MouseX >=190  && MouseX <= 370 && MouseY >= 270 &&MouseY <= 320 && press)
		{
			judge =4;
		}
		if(MouseX >=190  && MouseX <= 370 && MouseY >= 320 &&MouseY <= 370 && press)
		{
			judge = 5;
		}
		switch(judge)
		{
			case 1:
			{
				setfillstyle(1,WHITE);
				bar(380,130,635,460);
				setfillstyle(1,CYAN);
	            bar(360,120,370,470);
				setfillstyle(1,RED);
				bar(360,120,370,170);
				puthz(380,130,"�������������ڡ��ҵ�Ǯ�������Ƚ��г�ֵ��ȥ���ѡ�",16,20,BLACK);
				judge = 0;
				break;
			}
			case 2:
			{
				setfillstyle(1,WHITE);
				bar(380,130,635,460);
				setfillstyle(1,CYAN);
	            bar(360,120,370,470);
				setfillstyle(1,RED);
				bar(360,120+50,370,170+50);
				puthz(380,130,"������Ϣ���ܷ����������޹�����Ա������ϵ��������ϵ����������Ա��",16,20,BLACK);
				judge = 0;
				break;
			}
			case 3:
			{
				setfillstyle(1,WHITE);
				bar(380,130,635,460);
				setfillstyle(1,CYAN);
	            bar(360,120,370,470);
				setfillstyle(1,RED);
				bar(360,170+50,370,220+50);
				puthz(380,130,"���������п���ѡ�񰮳�������λ���г���Ԥ������Ҳ���������˹������ֳ�Ԥ������",16,20,BLACK);
				judge = 0;
				break;
			}
			case 4:
			{
				setfillstyle(1,WHITE);
				bar(380,130,635,460);
				setfillstyle(1,CYAN);
	            bar(360,120,370,470);
				setfillstyle(1,RED);
				bar(360,220+50,370,270+50);
				puthz(380,130,"���Բο�����˵���鿴��ϸ���������������ѡ��",16,20,BLACK);
				judge = 0;
				break;
			}
			case 5:
			{
				setfillstyle(1,WHITE);
				bar(380,130,635,460);
				setfillstyle(1,CYAN);
	            bar(360,120,370,470);
				setfillstyle(1,RED);
				bar(360,270+50,370,320+50);
				puthz(380,130,"�������������ǡ��ҵ��ҵ�������Ա�绰����ϵ������Ա��",16,20,BLACK);
				judge = 0;
				break;
			}
		}
	}
}
/*****************************************
Function :drawproblem(setuser *person)
Description:�����û����� 
Attention:
return: �� 
**************************************/ 
void drawproblem(setuser *person)
{

	drawuserself();
	setfillstyle(1,RED);
	bar(170,290,180,330);
	setfillstyle(1,CYAN);
	bar(360,120,370,470);
	puthz(190,70,"��������",32,40,RED);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(CYAN);
	line(190,120,638,120);
	line(190,120,190,470);
	line(638,120,638,470);
	line(190,470,638,470);
	line(190,170,370,170);
	line(190,220,370,220);
	line(190,270,370,270);
	line(190,320,370,320);
	line(190,370,370,370);
	puthz(200,130,"�޷�����",16,15,BLACK);
	puthz(200,130+50,"�˻�������",16,15,BLACK);
	puthz(200,130+100,"�����Ӱ���",16,15,BLACK);
	puthz(200,130+150,"ѡ����ʱ���",16,15,BLACK);
	puthz(200,130+200,"��������",16,15,BLACK);
}
/****************************************
Function : advice
Description:�û���������->�������*���湦��
Attention:
***************************************/
int advice(void)
{
	int flag = 0;
	int judge = 0;
	int press,MouseX,MouseY;
	int driver =VGA;
	int mode = VGAHI;
	//clrmous(MouseX,MouseY);
	//delay(100);
	//save_bk_mou(MouseX,MouseY);
	newmouse(&MouseX,&MouseY,&press);
	setfillstyle(1,WHITE);
	bar(20,20,80,80);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=540  && MouseX <= 640 && MouseY >= 0 && MouseY <= 40 && press)//������ذ�ť
			return 2;
		else if(MouseX >=80  && MouseX <= 280 && MouseY >= 100 && MouseY <= 150&&flag!=1)//���ϴ����ť
		{
			yy();
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
	        bar(84,151,284,154);
	        bar(281,104,284,154);
			save_bk_mou(MouseX,MouseY);
			flag=1;
		}
		else if(MouseX >=80  && MouseX <= 280 && MouseY >= 100 && MouseY <= 150 && press)//���������ť
		{
			judge = 1;
		}
		else if(MouseX >=360  && MouseX <= 560 && MouseY >= 100 && MouseY <= 150 &&flag!=2)//���������ť
		{
			yy();
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
	        bar(84+280,151,284+280,154);
	        bar(281+280,104,284+280,154);
			save_bk_mou(MouseX,MouseY);
			flag=2;
		}
		else if(MouseX >=360  && MouseX <= 560 && MouseY >= 100 && MouseY <= 150 && press)//���������ť
		{
			judge = 1;
		}
		else if(MouseX >=80  && MouseX <= 280 && MouseY >= 200 && MouseY <= 250 &&flag!=3)//���������ť
		{
			yy();
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
	        bar(84,251,284,254);
	        bar(281,204,284,254);
			save_bk_mou(MouseX,MouseY);
			flag=3;
		}
		else if(MouseX >=80  && MouseX <= 280 && MouseY >= 200 && MouseY <= 250 && press)//���������ť
		{
			judge = 1;
		}
		else if(MouseX >=360  && MouseX <= 560 && MouseY >= 200 && MouseY <= 250 &&flag!=4)//���������ť
		{
			yy();
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
	        bar(84+280,251,284+280,254);
	        bar(281+280,204,284+280,254);
			save_bk_mou(MouseX,MouseY);
			flag=4;
		}
		else if(MouseX >=360  && MouseX <= 560 && MouseY >= 200 && MouseY <= 250 && press)//���������ť
		{
			judge = 1;
		}
		else if(MouseX >=80  && MouseX <= 280 && MouseY >= 300 && MouseY <= 350 &&flag!=5)//���������ť
		{
			yy();
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
	       bar(84,351,284,354);
	        bar(281,304,284,354);
			save_bk_mou(MouseX,MouseY);
			flag=5;
		}
		else if(MouseX >=80  && MouseX <= 280 && MouseY >= 300 && MouseY <= 350 && press)//���������ť
		{
			judge = 1;
		}
		else if(MouseX >=360  && MouseX <= 560 && MouseY >= 300 && MouseY <= 350 &&flag!=6)//���������ť
		{
			yy();
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
            bar(84+280,351,284+280,354);
	        bar(281+280,304,284+280,354);
			save_bk_mou(MouseX,MouseY);
			flag=6;
		}
		else if(MouseX >=360  && MouseX <= 560 && MouseY >= 300 && MouseY <= 350 && press)//���������ť
		{
			judge = 1;
		}
		switch (judge)
		{
			case 1:
			{
				judge = sure();
				break;
			}
			case 2:
			{
				return 1;
			}
		}
	}

}

/*****************************************
Function :drawadvice(void)
Description:���Ƹ�������->����������� 
Attention:
return: �� 
**************************************/ 
void drawadvice(void)
{
	cleardevice();
	setbkcolor(BLACK);
	
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(220,10,420,60);
	puthz(230,20,"�������",32,50,WHITE);
	
	setfillstyle(1,CYAN);
	bar(540,0,640,40);
	puthz(550,10,"����",16,50,BLACK);
	bar(80,100,280,150);
	puthz(90,110,"ϴ������",32,50,WHITE);
	bar(360,100,560,150);
	puthz(370,110,"��������",32,50,WHITE);
	bar(80,200,280,250);
	puthz(90,210,"��������",32,50,WHITE);
	bar(360,200,560,250);
	puthz(370,210,"Ӧ������",32,50,WHITE);
	bar(360,300,560,350);
	puthz(370,310,"��������",32,50,WHITE);
	bar(80,300,280,350);
	puthz(90,310,"��ֵ����",32,50,WHITE);
	
}
/*****************************************
Function :yy(void)
Description��������Ӱ���� 
Attention:
return: �� 
**************************************/ 
void yy(void)
{
	setfillstyle(1,WHITE);
			bar(84,151,284,154);
	        bar(281,104,284,154);
			bar(84+280,151,284+280,154);
	        bar(281+280,104,284+280,154);
			bar(84,251,284,254);
	        bar(281,204,284,254);
			bar(84+280,251,284+280,254);
	        bar(281+280,204,284+280,254);
			bar(84,351,284,354);
	        bar(281,304,284,354);
			bar(84+280,351,284+280,354);
	        bar(281+280,304,284+280,354);
}
/*****************************************
Function :drawmyclaim()
Description:���Ƹ�������->�ҵ����⺯�� 
Attention:��������� 
return: �� 
**************************************/ 
void drawmyclaim()
{
	int i=0;
	drawuserself();
	setfillstyle(1,RED);
	bar(170,90,180,130);
	setfillstyle(1,CYAN);
	bar(180,50,640,90);
	puthz(185,60,"���",16,16,WHITE);
	puthz(240,60,"�������",16,16,WHITE);
	puthz(350,60,"���뱣��",16,16,WHITE);
	puthz(460,60,"���ⷽʽ",16,16,WHITE);
	puthz(550,60,"״̬",16,16,WHITE);
	//puthz(550,60,"�鿴����",16,16,WHITE);
	for(i=0;i<7;i++)
	{
		setfillstyle(1,LIGHTGRAY);
		bar(180,90+i*80,640,130+i*80);
	}
	for(i=0;i<6;i++)
	{
		setfillstyle(1,WHITE);
		bar(180,130+i*80,640,170+i*80);
	}
	
}
/*****************************************
Function :myclaim(struct CLAIM claim[10],int k)
Description:��������ṹ�����Լ�ӵ�е�������� 
Attention:
return: useself�е�judgeֵ 
**************************************/ 
int myclaim(struct CLAIM claim[10],int k)
{
		int judge = 0;
	int press,MouseX,MouseY;
	int driver =VGA;
	int mode = VGAHI;
	char ch[3]={'\0'};
	int i=0;
	//clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	for(i=0;i<k;i++)
	{
		settextstyle(2,0,6);
		setcolor(BLACK);
		if(i==9)
		    {
		    	strcmp(ch,"10");
			}
			else
			{
				ch[0] = i+'1';
			} 
		outtextxy(190,100+(i)*40,ch);
	}
	settextstyle(2,0,6);
		setcolor(BLACK);
	for(i=0;i<k;i++)
	{
			outtextxy(240,100+i*40,claim[i].bdh);
			if(claim[i].flag==1)
			{
			puthz(460,100+i*40,"��������",16,16,BLACK);
			outtextxy(350,100+i*40,claim[i].claimmoney);
			}
	        else if(claim[i].flag==2)
			{
				puthz(460,100+i*40,"�˹�����",16,16,BLACK);
				puthz(350,100+i*40,"���޽��",16,16,BLACK); 
			}
			if(claim[i].zhuangtai==0)
			{
				puthz(550,100+i*40,"δ����",16,16,BLACK);
			}
			else if(claim[i].zhuangtai==1)
			{
				puthz(550,100+i*40,"��ͨ��",16,16,BLACK);
			}
			else if(claim[i].zhuangtai==2)
			{
				puthz(550,100+i*40,"δͨ��",16,16,BLACK);
			}
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//�����ҵı���
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
			return 1;
	//�����������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 && MouseY <= 290 && press)
			return 6;	
		//���밮������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 && MouseY <= 170 && press)
			return 3;
		//�����޸�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 && MouseY <= 210 && press)
			return 4;
		//�����ҵ�Ǯ��
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
			return 5;	
		//���볣������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 && MouseY <= 330 && press)
			return 7;
		//���������ҳ(20,420,120,460)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
			return 8;
	}
}
