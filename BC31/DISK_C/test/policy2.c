#include "common.h"
#include "policy1.h"
#include "policy2.h"
#include "draw.h"
#include "gpolicy.h"
/****************************************
Function :xinxiluru(char *sfzh,char *dianhua,char *chejia,char *fdj,char *time,setuser *person)
Description:��Ϣ¼�����������
Attention:��
Return����һ�������judgeֵ
***************************************/
int  xinxiluru(char *sfzh,char *dianhua,char *chejia,char *fdj,char *time,setuser *person)
{
	
	int judge = 0;
	int press,MouseX,MouseY;
	int flag1=0;
	int flag2=0;
	int i=0;
	int j=0;
	char *p;
	long num=0;
	char k[9]={'\0'};
	char k1[5]={'\0'};
	char k2[3]={'\0'};
	char k3[3]={'\0'};
	char m[9]={'\0'};
	char h[2]={'\0'};
	char time1[2]={'1','\0'};
	char time2[2]={'2','\0'};
	char time3[2]={'3','\0'};
	delay(100);
	save_bk_mou(MouseX,MouseY);
	if(strlen(chejia)!=0)
	{
	setfillstyle(1,WHITE);
	bar(365,55,585,85);
	bar(365,55+80,585,85+80);
	bar(365,55+250,585,85+250);
	bar(365,55+330,585,85+330);
	setcolor(BLACK);
	i=0;
	p=chejia;
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=chejia[j];
		outtextxy(368 + j * 11, 60, h);
	}
	i=0;
	p=fdj;
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=fdj[j];
		outtextxy(368 + j * 11, 60+80, h);
	}
	i=0;
	p=sfzh;
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=sfzh[j];
		outtextxy(368 + j * 11, 60+250, h);
	}
	i=0;
	p=dianhua;
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=dianhua[j];
		outtextxy(368 + j * 11, 60+330, h);
	}
	}
	setlinestyle(SOLID_LINE,0,3);
	setcolor(RED);
	
	if(strcmp(time,time1)==0)
	{
	line(565-140-14,225,575-140-14,240);
	line(585-140-14,220,575-140-14,240);	
	}
	if(strcmp(time,time2)==0)
	{
	line(565-70-7,225,575-70-7,240);
	line(585-70-7,220,575-70-7,240);
	}
	if(strcmp(time,time3)==0)
	{
	line(565,225,575,240);
	line(585,220,575,240);
	}
	i=0;
	while(1)
	{
		

		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=540 &&MouseX <=640 &&MouseY >= 445 &&MouseY <= 480 &&press)
		{
			judge = -2;
		}
		if(MouseX >=0 &&MouseX <=100 &&MouseY >= 445 &&MouseY <= 480 &&press)
		{
			judge = -1;
		}	
	    if(MouseX >=360 &&MouseX <=590 &&MouseY >= 50 &&MouseY <= 90 &&press)
		{
			judge = 1;
		}		
	   if(MouseX >=360 &&MouseX <=590 &&MouseY >= 130 &&MouseY <= 170 &&press)
		{
			judge = 2;
		}		
	   if(MouseX >=360 &&MouseX <=590 &&MouseY >= 300 &&MouseY <= 340 &&press)
		{
			judge = 3;
		}		
	  if(MouseX >=360 &&MouseX <=590 &&MouseY >= 380 &&MouseY <= 420 &&press)
		{
			judge = 4;
		}
      if(MouseX >=565-140-14 &&MouseX <=585-140-14 &&MouseY >= 220 &&MouseY <= 240 &&press)		
	  {
		  judge = 5;
	  }
	   if(MouseX >=565-70-7 &&MouseX <=585-70-7 &&MouseY >= 220 &&MouseY <= 240 &&press)
	   {
		   judge = 6;
	   }
	    if(MouseX >=565 &&MouseX <=585 &&MouseY >= 220 &&MouseY <= 240 &&press)
		{
			judge = 7;
		}
	
	switch(judge)
	{
		case -1:
		{
			strcpy(chejia,"");
			strcpy(fdj,"");
			strcpy(sfzh,"");
			strcpy(dianhua,"");
			strcpy(time,"");
		 return 0;
		 break;
		}
		case -2:
		{
			setfillstyle(1,WHITE);
			bar(365,100,585,120);
			bar(365,180,585,200);
			bar(365,260,585,280);
			bar(365,350,585,370);
			//bar(365,385,585,415);
			flag1=0;
			flag2=0;
			for(i=0;i<11;i++)
			{
				if(dianhua[i]<'0'||dianhua[i]>'9')
					flag1=1;
			}
			for(i=0;i<3;i++)
			{
				m[i]=dianhua[i];
			}
			num=atoi(m);
			if(num!=133&&num!=149&&num!=153&&num!=173&&num!=177&&num!=180&&num!=181&&num!=189&&num!=199&&num!=130&&num!=131&&num!=132&&num!=145&&num!=155&&num!=156&&num!=166&&num!=171&&num!=175&&num!=176&&num!=185&&num!=186&&num!=166&&num!=134&&num!=135&&num!=136&&num!=137&&num!=138&&num!=139&&num!=147&&num!=150&&num!=151&&num!=152&&num!=157&&num!=158&&num!=159&&num!=172&&num!=178&&num!=182&&num!=183&&num!=184&&num!=187&&num!=188&&num!=198)
			{
				flag1=1;
			}
			for(i=0;i<17;i++)
			{
				if(sfzh[i]<'0'||sfzh[i]>'9')
					flag2=1;
			}
			for(i=6;i<14;i++)
			{
				k[i-6]=sfzh[i];
			}
			num=atol(k);
			if(num<19200101||num>20210421)
			{
				flag2=1;
			}
			for(i=6;i<10;i++)
			{
				k1[i-6]=sfzh[i];
			}
			num=atol(k1);
			if(num<1920||num>2021)
			{
				flag2=1;
			}
			for(i=10;i<12;i++)
			{
				k2[i-10]=sfzh[i];
			}
			num=atol(k2);
			if(num<1||num>12)
			{
				flag2=1;
			}
			for(i=12;i<14;i++)
			{
				k3[i-12]=sfzh[i];
			}
			num=atol(k3);
			if(num<1||num>31)
			{
				flag2=1;
			}
			if(strlen(chejia)!=8)
			{
				puthz(370,100,"��������ȷ�ĳ��ܺ�",16,20,RED);
				judge=1;
			}
			else if(strlen(fdj)!=8)
			{
				puthz(370,180,"��������ȷ�ķ�������",16,20,RED);
				judge=2;
			}
			else if(strlen(time)!=1)
			{
				puthz(370,260,"��ѡ����ȷ��ע��ʱ��",16,20,RED);
				judge=0;
			}
			else if(strlen(sfzh)!=18||flag2==1)
			{
				puthz(370,350,"��������ȷ�����֤�ź�",16,20,RED);
				judge=3;
			}
			else if(strlen(dianhua)!=11||flag1==1)
			{
				puthz(370,430,"��������ȷ���ֻ���",16,20,RED);
				judge=4;
			}
			else
			{
		 return 2;
			}
		 break;
		}
		case 1:
		{
			clrmous(MouseX,MouseY);
			judge = cincjh(chejia,&MouseX,&MouseY,person);
			break;
		}
		case 2:
		{
			clrmous(MouseX,MouseY);
			judge = cinfdj(fdj,&MouseX,&MouseY,person);
			break;
		}
		case 3:
		{
			clrmous(MouseX,MouseY);
			judge = cinsfzh(sfzh,&MouseX,&MouseY,person);
			break;
		}
		case 4:
		{
			clrmous(MouseX,MouseY);
			judge = cindianhua(dianhua,&MouseX,&MouseY,person);
			break;
		}
		case 5:
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(409,220,433,242);
			bar(486,220,510,242);
			bar(563,220,587,242);
			setlinestyle(SOLID_LINE,0,3);
	setcolor(CYAN);
	rectangle(565,220,585,240);
	rectangle(565-77,220,585-77,240);
	rectangle(565-154,220,585-154,240);
	setcolor(RED);
	line(565-140-14,225,575-140-14,240);
	line(585-140-14,220,575-140-14,240);
	/*line(565,220,585,220);
	line(565,220,575,240);
	line(585,220,575,240);
	line(565-70-7,220,585-70-7,220);
	line(565-70-7,220,575-70-7,240);
	line(585-70-7,220,575-70-7,240);
	line(565-140-14,220,585-140-14,220);
	line(565-140-14,220,575-140-14,240);
	line(585-140-14,220,575-140-14,240);
	setfillstyle(1,CYAN);
	floodfill(418,225,CYAN);*/
	time[0]='1';
	judge=0;
			break;
		}
		case 6:
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(409,220,433,242);
			bar(486,220,510,242);
			bar(563,220,587,242);
			setlinestyle(SOLID_LINE,0,3);
	setcolor(CYAN);
	rectangle(565,220,585,240);
	rectangle(565-77,220,585-77,240);
	rectangle(565-154,220,585-154,240);
	setcolor(RED);
	line(565-70-7,225,575-70-7,240);
	line(585-70-7,220,575-70-7,240);
	/*line(565,220,585,220);
	line(565,220,575,240);
	line(585,220,575,240);
	line(565-70-7,220,585-70-7,220);
	line(565-70-7,220,575-70-7,240);
	line(585-70-7,220,575-70-7,240);
	line(565-140-14,220,585-140-14,220);
	line(565-140-14,220,575-140-14,240);
	line(585-140-14,220,575-140-14,240);
	setfillstyle(1,CYAN);
	floodfill(500,225,CYAN);*/
	time[0]='2';
	judge=0;
			break;
		}
		case 7:
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(409,220,433,242);
			bar(486,220,510,242);
			bar(563,220,587,242);
			setlinestyle(SOLID_LINE,0,3);
	setcolor(CYAN);
	rectangle(565,220,585,240);
	rectangle(565-77,220,585-77,240);
	rectangle(565-154,220,585-154,240);
	setcolor(RED);
	line(565,225,575,240);
	line(585,220,575,240);
	/*line(565,220,585,220);
	line(565,220,575,240);
	line(585,220,575,240);
	line(565-70-7,220,585-70-7,220);
	line(565-70-7,220,575-70-7,240);
	line(585-70-7,220,575-70-7,240);
	line(565-140-14,220,585-140-14,220);
	line(565-140-14,220,575-140-14,240);
	line(585-140-14,220,575-140-14,240);
	setfillstyle(1,CYAN);
	floodfill(570,225,CYAN);*/
	time[0]='3';
	judge=0;
			break;
		}
	}
	}
}
/****************************************
Function :drawxinxiluru(void)
Description:����Ϣ¼����溯��
Attention:��
Return����
***************************************/
void drawxinxiluru(void)
{
	cleardevice();
	setbkcolor(BLACK);
	
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,660,480);
	
	setcolor(CYAN);
	setlinestyle(SOLID_LINE,0,1);
	line(20,20,20,440);
	line(20,20,620,20);
	line(20,440,620,440);
	line(620,20,620,440);
	line(190,20,190,440);
	line(20,270,190,270);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE,0,3);
	line(406,210,406,250);
	line(436,210,436,250);
	line(483,210,483,250);
	line(513,210,513,250);
	line(560,210,560,250);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(CYAN);
	rectangle(565,220,585,240);
	rectangle(565-77,220,585-77,240);
	rectangle(565-154,220,585-154,240);
	/*line(565,220,585,220);
	line(565,220,575,240);
	line(585,220,575,240);
	line(565-70-7,220,585-70-7,220);
	line(565-70-7,220,575-70-7,240);
	line(585-70-7,220,575-70-7,240);
	line(565-140-14,220,585-140-14,220);
	line(565-140-14,220,575-140-14,240);
	line(585-140-14,220,575-140-14,240);*/
	setlinestyle(SOLID_LINE,0,3);
	setcolor(BLACK);
	rectangle(360,50,590,90);
	rectangle(360,130,590,170);
	rectangle(360,210,590,250);
	rectangle(360,300,590,340);
	rectangle(360,380,590,420);
	setfillstyle(1,LIGHTGRAY);
	bar(540,445,640,480);
	bar(0,445,100,480);

	
	setfillstyle(1,CYAN);
	
	setcolor(LIGHTGRAY);
	outtextxy(365,220,"0-5");
	outtextxy(441,220,"5-10");
	outtextxy(518,220,">10");
	
	setfillstyle(1,WHITE);
	
	puthz(30,100,"������",32,50,BLACK);
	puthz(30,150,"Ϣ¼��",32,50,BLACK);
	puthz(30,300,"������",32,50,BLACK);
	puthz(30,350,"Ϣ¼��",32,50,BLACK);
	puthz(200,60,"���ܺ�",16,30,BLACK);
	puthz(200,140,"��������",16,30,BLACK);
	puthz(200,220,"ʹ�����",16,30,BLACK);
	puthz(200,310,"���֤��",16,30,BLACK);
	puthz(200,390,"��ϵ�绰",16,30,BLACK);
	puthz(550,455,"��һ��",16,30,WHITE);
	puthz(10,455,"������ҳ",16,22,WHITE);
	puthz(370,60,"�������λ���ܺ�",16,15,LIGHTGRAY);
	puthz(370,140,"�������λ��������",16,15,LIGHTGRAY);
	puthz(370,310,"������ʮ��λ���֤��",16,15,LIGHTGRAY);
	puthz(370,390,"������ʮһλ��ϵ�绰",16,15,LIGHTGRAY);
	
}


/****************************************
Function :cincjh(char *chejia,int *MouseX,int *MouseY,setuser *person)
Description:���복�ܺ�
Attention:��
Return����һ��������judgeֵ
***************************************/
//���복�ܺ�
int cincjh(char *chejia,int *MouseX,int *MouseY,setuser *person)
{
	int key;     //��ʾ ��ֵ �ı���
	int i= 0;    //���ڼ����Ѿ�������ַ� ��Ŀ�ı���
	char *p ;  //�����ַ����м�ָ�����
	char ch;     //������ʱ �����ֵ����Ӧ���ַ�����
	int press;   //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	int j=0;
	char h[2]= { '\0','\0' };
	p=chejia;
		delay(100);
	//save_bk_mou(MouseX,MouseY);
	setfillstyle(1,WHITE);
	bar(365,55,585,85);
	settextstyle(2, 0, 6);
			setcolor(BLACK);	
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=chejia[j];
		outtextxy(368 + j * 11, 60, h);
	}
	setlinestyle(SOLID_LINE,0,3);
	setcolor(BLACK);
	rectangle(360,130,590,170);
	rectangle(360,300,590,340);
	rectangle(360,380,590,420);
	setcolor(RED);
	rectangle(360,50,590,90);
	
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;   //���ü�ֵ���õ��¼�ֵ
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		if((*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 130 &&*MouseY <= 170 &&press)||key == 0x1c0d || key == 0x5000) 
		{
			
			return 2;
		}
		//���
		if(*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 300 &&*MouseY <= 340 &&press)
		{
			return 3;
		}
		//���
		if(*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 380 &&*MouseY <= 420 &&press)
		{
			return 4;
		}
		//�����һҳ
		if(*MouseX >=540 &&*MouseX <=640 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return 0;
		}
		//�������
		if(*MouseX >=0 &&*MouseX <=100 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return -1;
		}
		 if(*MouseX >=565-140-14 &&*MouseX <=585-140-14 &&*MouseY >= 220 &&*MouseY <= 240 &&press)		
	  {
		  return 5;
	  }
	   if(*MouseX >=565-70-7 &&*MouseX <=585-70-7 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
	   {
		   return 6;
	   }
	    if(*MouseX >=565 &&*MouseX <=585 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
		{
			return 7;
		}
		//�������ɾ����
		if(key == 0xe08)
		{
			if(p != chejia)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(357 + i * 11, 60, 368 + i * 11, 80);
			//	backgroundChange(*MouseX, *MouseY,368 + i * 11, 60, 379 + i * 11, 80);
				p--;
				i--;
			}
			*p= '\0';
		}
		

		/*��������Ӧ���ַ�����chejia������*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<8)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(368 + i * 11, 60, 379 + i * 11, 80);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(368 + i * 11, 60, temp);
		//	backgroundChange(*MouseX, *MouseY, 368 + i * 11, 60, 379 + i * 11, 80);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}		
	}
}
/****************************************
Function :cinfdj(char *fdj,int *MouseX,int *MouseY,setuser *person)
Description:���뷢������
Attention:��
Return����һ��������judgeֵ
***************************************/
//���뷢������
int cinfdj(char *fdj,int *MouseX,int *MouseY,setuser *person)
{
	int key;     //��ʾ ��ֵ �ı���
	int i= 0;    //���ڼ����Ѿ�������ַ� ��Ŀ�ı���
	char *p ;  //�����ַ����м�ָ�����
	char ch;     //������ʱ �����ֵ����Ӧ���ַ�����
	int press;   //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	char h[2]= { '\0','\0' };
	int j=0;
	p=fdj;
		delay(100);
	//save_bk_mou(*MouseX,MouseY);
	setfillstyle(1,WHITE);
	bar(365,55+80,585,85+80);
	settextstyle(2, 0, 6);
			setcolor(BLACK);
	//outtextxy(368,140,fdj);
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=fdj[j];
		outtextxy(368 + j * 11, 60+80, h);
	}
	setlinestyle(SOLID_LINE,0,3);
	setcolor(BLACK);
	rectangle(360,130,590,170);
	rectangle(360,50,590,90);
	rectangle(360,300,590,340);
	rectangle(360,380,590,420);
	setcolor(RED);
	rectangle(360,130,590,170);
	
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;   //���ü�ֵ���õ��¼�ֵ
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		if((*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 300 &&*MouseY <= 340 &&press)||key == 0x1c0d || key == 0x5000) 
		{
			
			return 3;
		}
		//���
		if((*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 50 &&*MouseY <= 90 &&press)|| key == 0x4800)
		{
			return 1;
		}
		//���
		if(*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 380 &&*MouseY <= 420 &&press)
		{
			return 4;
		}
		//�����һҳ
		if(*MouseX >=540 &&*MouseX <=640 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return 0;
		}
		//�������
		if(*MouseX >=0 &&*MouseX <=100 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return -1;
		}
		 if(*MouseX >=565-140-14 &&*MouseX <=585-140-14 &&*MouseY >= 220 &&*MouseY <= 240 &&press)		
	  {
		  return 5;
	  }
	   if(*MouseX >=565-70-7 &&*MouseX <=585-70-7 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
	   {
		   return 6;
	   }
	    if(*MouseX >=565 &&*MouseX <=585 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
		{
			return 7;
		}
		//�������ɾ����
		if(key == 0xe08)
		{
			if(p != fdj)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(357 + i * 11, 60+80, 368+ i * 11, 80+80);
			//	backgroundChange(*MouseX, *MouseY,368 + i * 11, 60+80, 379+ i * 11, 80+80);
				p--;
				i--;
			}
			*p= '\0';
		}
		

		/*��������Ӧ���ַ�����chejia������*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<8)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(368+ i * 11, 60+80, 379+ i * 11, 80+80);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(368 + i * 11, 60+80, temp);
		//	backgroundChange(*MouseX, *MouseY, 368 + i * 11, 60+80, 379+ i * 11, 80+80);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}		
	}
}
//�������֤��
/****************************************
Function :cinsfzh(char *sfzh,int *MouseX,int *MouseY,setuser *person)
Description:�������֤��
Attention:��
Return����һ��������judgeֵ
***************************************/
int cinsfzh(char *sfzh,int *MouseX,int *MouseY,setuser *person)
{
	int key;     //��ʾ ��ֵ �ı���
	int i= 0;    //���ڼ����Ѿ�������ַ� ��Ŀ�ı���
	char *p ;  //�����ַ����м�ָ�����
	char ch;     //������ʱ �����ֵ����Ӧ���ַ�����
	int press;   //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	char h[2]= { '\0','\0' };
	int j=0;
	p=sfzh;
		delay(100);
	//save_bk_mou(MouseX,MouseY);
	setfillstyle(1,WHITE);
	bar(365,55+250,585,85+250);
	settextstyle(2, 0, 6);
	setcolor(BLACK);
	//outtextxy(368,310,sfzh);
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=sfzh[j];
		outtextxy(368 + j * 11, 60+250, h);
	}
	setlinestyle(SOLID_LINE,0,3);
	setcolor(BLACK);
	rectangle(360,50,590,90);
	rectangle(360,130,590,170);
	rectangle(360,300,590,340);
	rectangle(360,380,590,420);
	setcolor(RED);
	rectangle(360,300,590,340);
	
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;   //���ü�ֵ���õ��¼�ֵ
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		if((*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 130 &&*MouseY <= 170 &&press)|| key == 0x4800) 
		{
			
			return 2;
		}
		//���
		if(*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 50 &&*MouseY <= 90 &&press)
		{
			return 1;
		}
		//���
		if((*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 380 &&*MouseY <= 420 &&press)||key == 0x1c0d || key == 0x5000)
		{
			return 4;
		}
		//�����һҳ
		if(*MouseX >=540 &&*MouseX <=640 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return 0;
		}
		//�������
		if(*MouseX >=0 &&*MouseX <=100 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return -1;
		}
		 if(*MouseX >=565-140-14 &&*MouseX <=585-140-7 &&*MouseY >= 220 &&*MouseY <= 240 &&press)		
	  {
		  return 5;
	  }
	   if(*MouseX >=565-70-7 &&*MouseX <=585-70-7 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
	   {
		   return 6;
	   }
	    if(*MouseX >=565 &&*MouseX <=585 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
		{
			return 7;
		}
		//�������ɾ����
		if(key == 0xe08)
		{
			if(p != sfzh)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(357 + i * 11, 60+250, 368 + i * 11, 80+250);
				//backgroundChange(*MouseX, *MouseY,368 + i * 11, 60+250, 379 + i * 11, 80+250);
				p--;
				i--;
			}
			*p= '\0';
		}
		

		/*��������Ӧ���ַ�����chejia������*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<18)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(368 + i * 11, 60+250, 379 + i * 11, 80+250);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(368+ i * 11, 60+250, temp);
		//	backgroundChange(*MouseX, *MouseY, 368 + i * 11, 60+250, 379 + i * 11, 80+250);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}		
	}
}
//����绰����
/****************************************
Function :cindianhua(char *dianhua,int *MouseX,int *MouseY,setuser *person)
Description:����绰����
Attention:��
Return����һ��������judgeֵ
***************************************/
int cindianhua(char *dianhua,int *MouseX,int *MouseY,setuser *person)
{
	int key;     //��ʾ ��ֵ �ı���
	int i= 0;    //���ڼ����Ѿ�������ַ� ��Ŀ�ı���
	char *p ;  //�����ַ����м�ָ�����
	char ch;     //������ʱ �����ֵ����Ӧ���ַ�����
	int press;   //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	char h[2]= { '\0','\0' };
	int j=0;
	p=dianhua;
		delay(100);
	//save_bk_mou(MouseX,MouseY);
	setfillstyle(1,WHITE);
	bar(365,55+330,585,85+330);
	settextstyle(2, 0, 6);
			setcolor(BLACK);
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	for(j=0;j<=i;j++)
	{
		h[0]=dianhua[j];
		outtextxy(368 + j * 11, 60+330, h);
	}
	setlinestyle(SOLID_LINE,0,3);
	setcolor(BLACK);
	rectangle(360,50,590,90);
	rectangle(360,130,590,170);
	rectangle(360,300,590,340);
	rectangle(360,380,590,420);
	setcolor(RED);
	rectangle(360,380,590,420);
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;   //���ü�ֵ���õ��¼�ֵ
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		if(*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 130 &&*MouseY <= 170 &&press) 
		{
			
			return 2;
		}
		//���
		if((*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 300 &&*MouseY <= 340 &&press)|| key == 0x4800)
		{
			return 3;
		}
		//���
		if(*MouseX >=360 &&*MouseX <=590 &&*MouseY >= 50 &&*MouseY <= 90 &&press)
		{
			return 1;
		}
		//�����һҳ
		if(*MouseX >=540 &&*MouseX <=640 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return 0;
		}
		//�������
		if(*MouseX >=0 &&*MouseX <=100 &&*MouseY >= 445 &&*MouseY <= 480 &&press)
		{
			return -1;
		}
		 if(*MouseX >=565-140-14 &&*MouseX <=585-140-14 &&*MouseY >= 220 &&*MouseY <= 240 &&press)		
	  {
		  return 5;
	  }
	   if(*MouseX >=565-70-7 &&*MouseX <=585-70-7 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
	   {
		   return 6;
	   }
	    if(*MouseX >=565 &&*MouseX <=585 &&*MouseY >= 220 &&*MouseY <= 240 &&press)
		{
			return 7;
		}
		//�������ɾ����
		if(key == 0xe08)
		{
			if(p != dianhua)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(357 + i * 11, 60+330, 368 + i * 11, 80+330);
			//	backgroundChange(*MouseX, *MouseY,368 + i * 11, 60+330, 379 + i * 11, 80+330);
				p--;
				i--;
			}
			*p= '\0';
		}
		

		/*��������Ӧ���ַ�����chejia������*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<11)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(368 + i * 11, 60+330, 379 + i * 11, 80+330);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(368 + i * 11, 60+330, temp);
		//	backgroundChange(*MouseX, *MouseY, 368 + i * 11, 60+330, 379+ i * 11, 80+330);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}		
	}
}
/*int nianfen(char *time)
{
	int judge = 0;
	int press,MouseX,MouseY;
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	}
}
int yuefen(char *time)
{
	int judge = 0;
	int press,MouseX,MouseY;
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	}
}
int riqi(char *time)
{
	int judge = 0;
	int press,MouseX,MouseY;
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	}
}*/
/****************************************
Function :drawbdpage(void)
Description:����������������
Attention:��
Return����
***************************************/
void drawbdpage(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	
	setlinestyle(SOLID_LINE,0,1);
	setcolor(CYAN);
	line(20,100,620,100);
	line(320,50,320,440);
	rectangle(20,50,620,440);
	
	setfillstyle(1,LIGHTGRAY);
	bar(240,445,400,475);
	bar(490,0,640,40);
	bar(0,0,150,40);
	
	puthz(260,10,"��������",32,40,BLACK);
	puthz(250,455,"ȷ��֧��",16,40,BLACK);
	puthz(70,60,"Ͷ����Ϣ",32,40,BLACK);
	puthz(30,110,"�û�����",16,20,BLACK);
	puthz(30,150,"��ϵ�绰��",16,20,BLACK);
	puthz(30,190,"���ƺţ�",16,20,BLACK);
	puthz(30,240,"Ʒ�Ƴ��ͣ�",16,20,BLACK);
	puthz(30,290,"���ܺţ�",16,20,BLACK);
	puthz(30,340,"�����ţ�",16,20,BLACK);
	puthz(30,390,"�ϼƱ��ѣ�Ԫ����",16,20,BLACK);
	puthz(370,60,"��������",32,40,BLACK);
	puthz(340,110,"������Ŀ",16,20,LIGHTGRAY);
	puthz(450,110,"���Ԫ��",16,15,LIGHTGRAY);
	puthz(550,110,"���ѣ�Ԫ��",16,15,LIGHTGRAY);
	puthz(500,10,"������ҳ",16,30,BLACK);
	puthz(10,10,"������ҳ",16,30,BLACK);
	settextstyle(2, 0, 6);
	setcolor(BLACK);
}
/****************************************
Function :bdpage(setuser *person,char *dianhua,char *plate,char *pinpai,char *chejia,int *flagnew,char money_str[][10],char baofei[][10],char *pcity,char *bdh)
Description:��������������
Attention:��
Return����һ�������judgeֵ
***************************************/
 int bdpage(setuser *person,char *dianhua,char *plate,char *pinpai,char *chejia,int *flagnew,char money_str[][10],char baofei[][10],char *pcity,char *bdh)
 {
	 int judge = 0;
	int press,MouseX,MouseY;
	int i,j;
	long n=0;
	char temp;
	//char bdh[9]={'\0'};
	int k=0;
	char bd[6][20];
	delay(100);
	
	//save_bk_mou(MouseX,MouseY);
	strcpy(bd[0],"��ǿ��");
	strcpy(bd[1],"������");
	strcpy(bd[2],"������");
	strcpy(bd[3],"˾����");
	strcpy(bd[4],"�˿���");

	setfillstyle(1,WHITE);
	bar(0,50,0,50);
	bdh[0]='1';
	bdh[1]='0';
	bdh[2]='3';
	n=suijishu(5);
	if(n<0)
	{
		n=-n;
	}
	for(i=3;i<=7;i++)
	{
		j=n-(n/10)*10;
		temp='0'+j;
		bdh[i]=temp;
		n=n/10;
	}
	
	settextstyle(2, 0, 6);
	setcolor(BLACK);
	outtextxy(180,340,bdh);
	outtextxy(180,110,person->accounts);
	outtextxy(180,150,dianhua);
	if(strlen(plate)==0)
	{
		puthz(180,190,"���޳���",16,20,BLACK);
	}
	else
	{
	    puthz(180,190,pcity,16,15,BLACK);
	    outtextxy(210,190,plate);
	}
	puthz(180,240,pinpai,16,20,BLACK);
	outtextxy(180,290,chejia);
	outtextxy(220,390,baofei[5]);
	k=0;
	for(i=0;i<=4;i++)
	{
		if(flagnew[i]==1)
		{
			puthz(340,130+k*40,bd[i],16,20,BLACK);
			outtextxy(550,130+k*40,baofei[i]);
			outtextxy(450,130+k*40,money_str[i]);
			k++;
		}
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=240 &&MouseX <=440 &&MouseY >= 445 &&MouseY <= 475 &&press)
		{
			/*i=atoi(baofei[5]);
			j=person->money;
			j=j-i;
			person->money=j;*/
			return 5;
		}
		if(MouseX >=0 &&MouseX <=150 &&MouseY >= 0 &&MouseY <= 40 &&press)
		{
			return 2;
		}
		if(MouseX >=490 &&MouseX <=640 &&MouseY >= 0 &&MouseY <= 40 &&press)
		{
			judge = 1;
			}	
		switch(judge)
		{
			case 1:
				{
					clrmous(MouseX,MouseY);
					delay(100);
					judge=jueding("������ҳ",-2);
					break;
				}
			case -2:{
				return -1; 
			}
			case -1:
			{
				return 3;
			}
		}
		
	}
 }
