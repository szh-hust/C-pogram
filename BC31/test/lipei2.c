#include "common.h"
#include "lipei1.h"
#include "lipei2.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "draw.h"
/****************************************
Function :xzlpfs(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
Description:ѡ�����ⷽʽ������
Attention:��
Return����һ�������judgeֵ
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
Description:��ѡ�����ⷽʽ���溯��
Attention:��
Return����
***************************************/
void drawxzlpfs(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"ƽ���ó���",32,30,WHITE);
	puthz(170,30,"��������",16,20,WHITE);
	//puthz(270,30,"�¹���Ϣȷ��",16,16,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"����",16,20,WHITE);
	
	setcolor(LIGHTGRAY);
	/*puthz(20,60,"ȷ����Ϣ",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"��������",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"��ȡ���",16,20,GREEN);
	*/
	puthz(280,60,"��������",16,20,GREEN);
	puthz(200,90,"���ⷽʽѡ��",32,40,BLACK);
	setfillstyle(1,CYAN);
	bar(75,160,275,210);
	bar(365,160,565,210);
	puthz(85,170,"��������",32,40,WHITE);
	puthz(375,170,"�˹�����",32,40,WHITE);
	
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,3);
	rectangle(50,140,300,420);
	rectangle(340,140,590,420);
	puthz(80,240,"�����ϴ���ʧ��Ƭ",16,20,LIGHTGRAY);
	puthz(80,270,"������ȡ��ʧ���",16,20,LIGHTGRAY);
	puthz(370,240,"������Ա�ֳ�����",16,20,LIGHTGRAY);
	puthz(370,270,"������ȡ��ʧ���",16,20,LIGHTGRAY);
	drawlittlecar(85,290,CYAN,6);
	drawlittlecar(375,290,CYAN,6);
}
/****************************************
Function : zzlp(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
Description:��������������
Attention:��
Return����һ�������judgeֵ
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
				puthz(410,360,"��������ȷ�ı���",16,20,RED);
				judge=0;
				break;
			}
			else if(money1>=money2)
			{
				strcpy(claim[cn].claimmoney,lpje);
				clrmous(MouseX,MouseY);
				strcpy(claim[cn].claimmoney,lpje);
				judge=bingo(220,300,"����ɹ�");
				break;
				
			}
			else
			{
				puthz(410,360,"��������ȷ�ı���",16,20,RED);
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
Description:������������溯��
Attention:��
Return����
***************************************/
void drawzzlp(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"ƽ���ó���",32,30,WHITE);
	puthz(170,30,"��������",16,20,WHITE);
	//puthz(270,30,"�¹���Ϣȷ��",16,16,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"����",16,20,WHITE);
	puthz(120,90,"�����ڽ��������������",32,35,BLACK);
	puthz(120,140,"���ı���Ϊ��",16,20,BLACK);
	puthz(50,190,"����������Ҫ����Ľ��",16,20,BLACK);
	puthz(570,190,"Ԫ",16,20,BLACK);
	setcolor(LIGHTGRAY);
	/*puthz(20,60,"ȷ����Ϣ",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"��������",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"��ȡ���",16,20,GREEN);*/
	puthz(270,60,"��ȡ���",16,20,RED);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,3);
	rectangle(40,170,600,420);
	line(40,230,600,230);
	setcolor(BLACK);
	rectangle(300,185,560,215);
	puthz(60,240,"ע�⣺",16,20,RED);
	puthz(60,260,"һ��������ó��������ı��",16,20,BLACK);
	puthz(60,280,"���������辭������Ա��������ĵȴ���",16,20,BLACK);
	puthz(60,300,"�����������ʵ���ⲻ��������⡣",16,20,BLACK);
	setfillstyle(1,CYAN);
	bar(240,350,400,400);
	puthz(250,360,"��������",32,35,WHITE);
}

/****************************************
Function :cinlpje(char * lpje,int *MouseX, int *MouseY)
Description:����������
Attention:��
Return����һ�������judgeֵ
***************************************/
int cinlpje(char * lpje,int *MouseX, int *MouseY)
{
	char *p = lpje;   //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int press;    //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	int key;    //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	while (*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	//���㿪��Ŀ��
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
		{//��������*����*
			return 1;
		}
		 if (*MouseX >= 0 && *MouseX <= 100 && *MouseY >= 445&& *MouseY <= 480 && press) 
		{//��������*����*
			return -1;
		}
		//������˻�ɾ�� 
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

		/*��������Ӧ���ַ�����lpje������*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<6)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(311 + i * 11, 188, 322 + i * 11, 212);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(311+ i * 11, 188, temp);
		//	backgroundChange(*MouseX, *MouseY, 311 + i * 11, 188, 322 + i * 11, 212);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :drawxzdd(void)
Description:��ѡ��ص���溯��
Attention:��
Return����
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
	puthz(10,10,"ƽ���ó���",32,30,WHITE);
	puthz(170,30,"��������",16,20,WHITE);
	//puthz(270,30,"�¹���Ϣȷ��",16,16,WHITE);*/
	puthz(100,30,"�����ڽ����˹���������",32,40,BLACK);
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"����",16,20,WHITE);
	puthz(120,390,"��ѡ�����Ĵ��µص�",32,40,BLACK);
	
	
	/*setcolor(LIGHTGRAY);
	puthz(20,60,"ȷ����Ϣ",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"��������",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"��ȡ���",16,20,GREEN);*/
}
/****************************************
Function :drawrgfw(void)
Description:���˹�������溯��
Attention:��
Return����
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
	puthz(10,10,"ƽ���ó���",32,30,WHITE);
	puthz(170,30,"��������",16,20,WHITE);
	//puthz(270,30,"�¹���Ϣȷ��",16,16,WHITE);*/
	setfillstyle(1,LIGHTGRAY);
	bar(0,445,100,480);
	puthz(20,450,"����",16,20,WHITE);
	
	puthz(100,90,"�����ڽ����˹���������",32,40,BLACK);
	puthz(230,180,"��ѡ�����Ĵ��µص�",16,20,BLACK);
	setcolor(CYAN);
	setfillstyle(1,CYAN);
	setlinestyle(SOLID_LINE,0,3);
	line(40,290,600,290);
	bar(500,220,560,270);
	puthz(510,230,"ѡ��",16,20,WHITE);
	rectangle(40,170,600,420);
	bar(240,350,400,400);
	setcolor(BLACK);
	rectangle(150,220,490,270);
	puthz(250,360,"�������",32,35,WHITE);
	puthz(100,300,"�뱣��������ϵ�绰��",16,20,BLACK);
	puthz(400,320,"��ͨ��",16,20,BLACK);
	//outtextxy(150,330,policy[t].dianhua);
	
	setcolor(LIGHTGRAY);
	puthz(20,60,"ȷ����Ϣ",16,20,GREEN);
	line(100,70,265,70);
	puthz(270,60,"��������",16,20,RED);
	line(360,70,515,70);
	puthz(520,60,"��ȡ���",16,20,GREEN);
}
/****************************************
Function :rgfw(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn)
Description:�˹�����������
Attention:��
Return����һ�������judgeֵ
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
				puthz(160,240,"��ѡ����ʵĵص㣡",16,20,RED);
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
				judge=bingo(170,300,"�������ڸ���");
				break;
			}
		}
	}
	}
}
/****************************************
Function :xzdd(char *didian)
Description:ѡ��ص�������
Attention:��
Return����һ�������judgeֵ
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
			strcpy(didian,"���Ƹ�С");
		    return 2;
		}
		//ѡ��ϴ���껪���׶�԰
		if(MouseX >=290 && MouseX <= 310&& MouseY >= 170&& MouseY <= 190 &&press)
		{
			strcpy(didian,"����ѧԺ");
		    return 2;
		}
		//ѡ���о���������
		if(MouseX >=90 && MouseX <= 110&& MouseY >= 340&& MouseY <= 360 &&press)
		{
			strcpy(didian,"����ѧԺ");
		    return 2;
		}
		//ѡ������
		if(MouseX >=260 && MouseX <= 280&& MouseY >= 310&& MouseY <= 330 &&press)
		{
			strcpy(didian,"�о���������");
		    return 2;
		}
		//ѡ����ͩ��
		if(MouseX >=545 && MouseX <= 565&& MouseY >= 210&& MouseY <= 230&&press)
		{
			strcpy(didian,"�����׶�԰");
		    return 2;
		}
		//ѡ�񾭼�ѧԺ
		if(MouseX >=530 && MouseX <= 550&& MouseY >= 120&& MouseY <= 140 &&press)
		{
			strcpy(didian,"��ͩ����ѧ����");
		    return 2;
		}
	}
}

/*д���ı�*/
/*money_str[5],dianhua,zhuantai,flag */
/****************************************
Function :putclaim(setuser *person,struct CLAIM claim[10],int cn)
Description:��������Ϣд���ļ�
Attention:��
Return����һ�������judgeֵ
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
