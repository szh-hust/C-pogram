#include "common.h"
#include "service.h"
#include "daolu.h"
/***********************************************
Function :daolujiuyuan(struct POLICY policy[10]) 
Attention:���뱣���ṹ���� 
Description:
Return :
***************************************************/
int daolujiuyuan(struct POLICY policy[10])
{
	int judge = 0;
	int flag = 0;
	int m=0;
	int press,MouseX,MouseY;
	char didian[20]={'\0'};
		delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=20 &&MouseX <=50 &&MouseY >= 10 &&MouseY <= 50 &&press)
		{
			return -1;
		}
		//���ѡ��ص�
		if(MouseX >=500 &&MouseX <=550 &&MouseY >= 170 &&MouseY <= 210 &&press)
		{
			judge=1;
		}
		if(MouseX >=220 &&MouseX <=420 &&MouseY >= 240 &&MouseY <= 290 &&press)
		{
			judge=2;
		}
		if(MouseX >=80 &&MouseX <=180 &&MouseY >= 120 &&MouseY <= 160 &&press)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,CYAN);
	        bar(80,120,180,160);
	        bar(210,120,310,160);
	        bar(340,120,440,160);
	        bar(470,120,570,160);
			puthz(90,130,"�ӵ�",16,40,RED);
	        puthz(220,130,"��̥",16,40,WHITE);
	        puthz(350,130,"�����ϳ�",16,20,WHITE);
	        puthz(480,130,"��������",16,20,WHITE);
			flag=1;
		}
		if(MouseX >=210 &&MouseX <=310 &&MouseY >= 120 &&MouseY <= 160 &&press)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,CYAN);
	        bar(80,120,180,160);
	        bar(210,120,310,160);
	        bar(340,120,440,160);
	        bar(470,120,570,160);
			puthz(90,130,"�ӵ�",16,40,WHITE);
	        puthz(220,130,"��̥",16,40,RED);
	        puthz(350,130,"�����ϳ�",16,20,WHITE);
	        puthz(480,130,"��������",16,20,WHITE);
			flag=2;
		}
		if(MouseX >=340 &&MouseX <=440 &&MouseY >= 120 &&MouseY <= 160 &&press)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,CYAN);
	        bar(80,120,180,160);
	        bar(210,120,310,160);
	        bar(340,120,440,160);
	        bar(470,120,570,160);
			puthz(90,130,"�ӵ�",16,40,WHITE);
	        puthz(220,130,"��̥",16,40,WHITE);
	        puthz(350,130,"�����ϳ�",16,20,RED);
	        puthz(480,130,"��������",16,20,WHITE);
			flag=3;
		}
		if(MouseX >=470 &&MouseX <=570 &&MouseY >= 120 &&MouseY <= 160 &&press)
		{
			clrmous(MouseX,MouseY);
			setfillstyle(1,CYAN);
	        bar(80,120,180,160);
	        bar(210,120,310,160);
	        bar(340,120,440,160);
	        bar(470,120,570,160);
			puthz(90,130,"�ӵ�",16,40,WHITE);
	        puthz(220,130,"��̥",16,40,WHITE);
	        puthz(350,130,"�����ϳ�",16,20,WHITE);
	        puthz(480,130,"��������",16,20,RED);
			flag=4;
		}
		if(MouseX >=100 &&MouseX <=250 &&MouseY >= 350 &&MouseY <= 390 &&press)
		{
			m=1;
			judge=3;
		}
		if(MouseX >=370 &&MouseX <=520 &&MouseY >= 350 &&MouseY <= 390 &&press)
		{
			m=2;
			judge=3;
		}
		if(MouseX >=100 &&MouseX <=250 &&MouseY >= 420 &&MouseY <= 460 &&press)
		{
			m=3;
			judge=3;
		}
		if(MouseX >=370 &&MouseX <=520 &&MouseY >= 420 &&MouseY <= 460 &&press)
		{
			m=4;
			judge=3;
		}
		switch(judge)
		{
			case -2:
			{
				return -1;
			}
			case -1:
			{
				clrmous(MouseX,MouseY);
				drawdaolujiuyuan();
				if(flag==1)
					puthz(90,130,"�ӵ�",16,40,RED);
				else if(flag==2)
					puthz(220,130,"��̥",16,40,RED);
				else if(flag==3)
					puthz(350,130,"�����ϳ�",16,20,RED);
				else if(flag==4)
					puthz(480,130,"��������",16,20,RED);
				setfillstyle(1,WHITE);
				bar(180,180,480,205);
				puthz(180,180,didian,16,20,BLACK);
				judge=0;
				delay(100);
				break;
			}
			case 1:
			{
				clrmous(MouseX,MouseY);
				drawxunzedidian();
				judge=xunzedidian(didian);
				break;
			}
			case 2:
			{
				if(flag==0)
				{
					puthz(250,90,"��ѡ���Ԯ��Ŀ��",16,20,RED);
					judge=0;
					break;
				}
				else if(strlen(didian)==0)
				{
					puthz(180,180,"��ѡ��ص㣡",16,20,RED);
					judge=0;
					break;
				}
				
				else
				{
					clrmous(MouseX,MouseY);
					drawxiayibu();
					judge=xiayibu(policy);
					break;
				}
			}
			case 3:
			{
				clrmous(MouseX,MouseY);
				judge=zhiyin(m,&MouseX,&MouseY);
				break;
			}
		}
		
	}
}
/***********************************************
Function :drawdaolujiuyuan()
Attention:
Description:���Ƶ�·��Ԯ 
Return :�� 
***************************************************/
void drawdaolujiuyuan()
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setlinestyle(SOLID_LINE,0,3);
	line(50,10,20,30);
	line(20,30,50,50);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,1);
	line(0,60,585,60);
	puthz(200,10,"��·��Ԯ",32,50,DARKGRAY);
	
	setlinestyle(SOLID_LINE,0,3);
	setcolor(LIGHTGRAY);
	rectangle(50,80,590,300);
	rectangle(50,310,590,470);
	setcolor(BLACK);
	rectangle(90,170,550,210);
	puthz(100,180,"�ص㣺",16,20,BLACK);
	line(170,170,170,210);
	line(500,170,500,210);
	line(505,175,545,190);
	line(505,205,545,190);
	
	puthz(60,90,"��ѡ���Ԯ��Ŀ��",16,20,BLACK);
	setfillstyle(1,CYAN);
	bar(80,120,180,160);
	bar(210,120,310,160);
	bar(340,120,440,160);
	bar(470,120,570,160);
	
	bar(100,350,250,390);
	bar(370,350,520,390);
	bar(100,420,250,460);
	bar(370,420,520,460);
	puthz(90,130,"�ӵ�",16,40,WHITE);
	puthz(220,130,"��̥",16,40,WHITE);
	puthz(350,130,"�����ϳ�",16,20,WHITE);
	puthz(480,130,"��������",16,20,WHITE);
	puthz(110,360,"�ӵ����ָ��",16,20,WHITE);
	puthz(380,360,"��̥����ָ��",16,20,WHITE);
	puthz(110,430,"�����ϳ�����ָ��",16,15,WHITE);
	puthz(380,430,"������������ָ��",16,15,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(220,240,420,290);
	puthz(260,260,"��һ��",16,40,WHITE);
	puthz(60,320,"��Ԯָ��",16,20,BLACK);
	
}

/***********************************************
Function :drawxunzedidian()
Attention:����ѡ��ص㺯�� 
Description:
Return :�� 
***************************************************/
void drawxunzedidian(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setlinestyle(SOLID_LINE,0,3);
	line(50,10,20,30);
	line(20,30,50,50);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,1);
	line(0,60,640,60);
	//puthz(200,10,"��·��Ԯ",32,50,DARKGRAY);
	//putbmp(0,70,"./bmp/xiche.bmp");
	drawdt();
	line(0,380,640,380);
	puthz(150,10,"��ѡ����µص㣡",32,50,BLACK);
	puthz(150,400,"�������λ�ò�����Ҳ����ѡ�����ɶ�λ��",16,20,CYAN);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,CYAN);
	bar(250,430,390,470);
	puthz(280,440,"������λ",16,20,WHITE);
	
	/*setcolor(RED);
	setfillstyle(1,LIGHTRED);
	circle(200,22+70,10);//���Ƹ�С
	floodfill(200,22+70,RED);
	circle(395,94+70,10);//����ѧԺ
	floodfill(395,94+70,RED);
	circle(590,118+70,10);//����ѧԺ
	floodfill(590,118+70,RED);
	circle(223,203+70,10);//�о���������
	floodfill(223,203+70,RED);
	circle(135,120+70,10);//�����׶�԰
	floodfill(135,120+70,RED);
	circle(135,260+70,10);//��������
	floodfill(135,260+70,RED);
	circle(437,255+70,10);//��ͩ����ѧ����
	floodfill(437,255+70,RED);*/
	
}
/***********************************************
Function :xunzedidian(char *didian)
Attention:
Description:
Return :-1 
***************************************************/
int xunzedidian(char *didian)
{
	int judge = 0;
	int flag = 0;
	int press,MouseX,MouseY;
		delay(100);
	//save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=20 &&MouseX <=50 &&MouseY >= 10 &&MouseY <= 50&&press)
		{
			return -1;
		}
		// ѡ��ϴ���껪�Ƹ�С
		if(MouseX >=50 && MouseX <= 70&& MouseY >= 170&& MouseY <= 190 &&press)
		{
			judge = 1;
		}
		//ѡ��ϴ���껪���׶�԰
		if(MouseX >=290 && MouseX <= 310&& MouseY >= 170&& MouseY <= 190 &&press)
		{
			judge = 2;
		}
		//ѡ���о���������
		if(MouseX >=90 && MouseX <= 110&& MouseY >= 340&& MouseY <= 360 &&press)
		{
			judge = 3;
		}
		//ѡ������
		if(MouseX >=260 && MouseX <= 280&& MouseY >= 310&& MouseY <= 330 &&press)
		{
			judge = 4;
		}
		//ѡ����ͩ��
		if(MouseX >=545 && MouseX <= 565&& MouseY >= 210&& MouseY <= 230&&press)
		{
			judge = 5;
		}
		//ѡ�񾭼�ѧԺ
		if(MouseX >=530 && MouseX <= 550&& MouseY >= 120&& MouseY <= 140 &&press)
		{
			judge = 6;
		}
		if(MouseX >=250 && MouseX <= 390&& MouseY >= 430&& MouseY <= 470 &&press)
		{
			judge = 7;
		}
		
		switch(judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY); 
				drawxunzedidian();
				judge=0;
				break;
			}
			case 1:
			{
				strcpy(didian,"���Ƹ�С");
				return -1;
			}
			case 2:
			{
				strcpy(didian,"����ѧԺ");
				return -1;
			}
			case 3:
			{
				strcpy(didian,"����ѧԺ");
				return -1;
			}
			case 4:
			{
				strcpy(didian,"�о���������");
				return -1;
			}
			case 5:
			{
				strcpy(didian,"�����׶�԰");
				return -1;
			}
			
			case 6:
			{
				strcpy(didian,"��ͩ����ѧ����");
				return -1;
			}
			case 7:
			{
				clrmous(MouseX,MouseY);
				judge=zizhudw();
				break;
			}
			case 8:
			{
			strcpy(didian,"��������λ");
				return -1;
			}
			
		}
	}
}
/***********************************************
Function :zizhudw()
Attention:
Description:������λ���� 
Return :-1 
***************************************************/
int zizhudw()
{
	int judge = 0;
	int flag = 0;
	int press,MouseX,MouseY;
	drawxunzedidian();
	setfillstyle(1,WHITE);
	bar(0,400,640,480);
	setfillstyle(1,CYAN);
	bar(220,430,420,470);
	puthz(270,440,"ȷ��",16,50,WHITE);
	puthz(40,410,"�뽫���ʮ���ƶ�������λ�ò����£�ȷ���������ȷ��",16,20,CYAN);
		while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=20 &&MouseX <=50 &&MouseY >= 10 &&MouseY <= 50&&press)
		{
			return -1;
		}
		if( MouseY >= 60 &&MouseY <= 380&&flag==0)
		{
			MouseS=3;
			flag=1;
		}
		if(flag==1&&( MouseY < 60 ||MouseY > 380))
		{
			MouseS=0;
			flag=0;
		}
		if(MouseY >= 70 &&MouseY <= 370&&press)
		{
		    judge=1;
		}
		if(MouseX >=220 &&MouseX <=420 &&MouseY >= 430 &&MouseY <= 470&&press)
		{
			return 8;
		}
		switch(judge)
		{
			case 1:
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(0,62,640,378);
				drawdt();
				setfillstyle(1,RED);
				fillellipse(MouseX,MouseY,10,10);
				judge=0;
				break;
			}
			
		}
	}
}
/***********************************************
Function :zhiyin(int m,int *MouseX,int *MouseY)
Attention:������������������ָ����ʽ���� 
Description:
Return :-1 
***************************************************/
int zhiyin(int m,int *MouseX,int *MouseY)
{
	int press;
	setfillstyle(1,WHITE);
	bar(50,200,590,460);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(CYAN);
	rectangle(50,200,590,460);
	line(70,330,570,330);
	setfillstyle(1,LIGHTGRAY);
	bar(575,205,585,215);
	setcolor(WHITE);
	line(575,205,585,215);
	line(575,215,585,205);
	puthz(60,210,"��Ԯ����",16,20,BLACK);
	puthz(60,340,"ע������",16,20,BLACK);
	if(m==1)
	{
		puthz(60,240,"���������ؿ���������ɳ����޷���������Ԯ�����ṩ���ش�����",16,15,BLACK);
		puthz(60,270,"һ�������޷���������",16,15,BLACK);
		puthz(60,300,"�������Ȳ��죬Կ��ת�����������Ʋ�����",16,15,BLACK);
		puthz(60,370,"һ���������С��ƿ������Ҫ�ӵ�ģ��ɰ��Žӵ紦��",16,15,BLACK);
		puthz(60,400,"�������������ˮ������£��޷��ṩ������",16,15,BLACK);
		puthz(60,430,"������������ڸ���·������������������ײ������ʹ�õ�·��Ԯ����",16,15,BLACK);
	}
	else if(m==2)
	{
		puthz(60,240,"������̥�����𻵣���ҪЭ��������̥��",16,15,BLACK);
		puthz(60,270,"һ��������ʻʱ������һ��ƫת",16,15,BLACK);
		puthz(60,300,"������̥����ʯ�Ӷ��ӵȼ������",16,15,BLACK);
		puthz(60,370,"һ����̥ʱ����Ӧ����Ϩ��״̬��������ɲ����ֹ��̥ʱ�ﳵ��",16,15,BLACK);
		puthz(60,400,"�������ñ�̥��Ӧ���Ƴ��ٲ����쵽�ͽ������޵�ά�޻������̥��",16,15,BLACK);
		
	}
	else if(m==3)
	{
		puthz(60,240,"�����������ڲ����ϣ�����ײ��ʧ���޷�������ʻ�����ϳ����ͽ�����㡣",16,15,BLACK);
		puthz(60,270,"һ���������������ϵ�����",16,15,BLACK);
		puthz(60,300,"���������޷�������ʻ��",16,15,BLACK);
		puthz(60,370,"һ���˷�����޹����ϳ���������ĳ���������ײ������רҵ�¹��ϳ���",16,15,BLACK);
		puthz(60,400,"���������������ϲ���������ʻʱӦ��������ͣ����",16,15,BLACK);
	}
	else if(m==4)
	{
		puthz(60,240,"������ʻ�����в�����������������ײ��ʧ�����Ԯ����Э������������",16,15,BLACK);
		puthz(60,270,"һ������������Ţ�޷�����",16,15,BLACK);
		puthz(60,300,"������������ˮΧ����",16,15,BLACK);
		puthz(60,370,"һ���˷��������Э������������",16,15,BLACK);
		puthz(60,400,"�������������������ʱ����������ʧ������޷�������ʻ���뱨������",16,15,BLACK);
	}
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		if(*MouseX >=575 &&*MouseX <=585 &&*MouseY >= 205 &&*MouseY <= 215 &&press)
		{
			return -1;
		}
	}
}
/***********************************************
Function :choosepla1(struct POLICY policy[10],int x,int y,char pcity[3],char plate[7],char pinpai[15],char dianhua[12])
Attention:
Description:ѡ�� ���� 
Return :-1 
***************************************************/
int choosepla1(struct POLICY policy[10],int x,int y,char pcity[3],char plate[7],char pinpai[15],char dianhua[12])
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
			strcpy(dianhua,policy[k].dianhua);
			return -1;
		}
	}
}
/***********************************************
Function :drawxiayibu(void)
Attention:������һ�� 
Description:
Return :�� 
***************************************************/
void drawxiayibu(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setlinestyle(SOLID_LINE,0,3);
	line(50,10,20,30);
	line(20,30,50,50);
	setcolor(LIGHTGRAY);
	rectangle(60,100,540,290);
	line(60,180,540,180);
	line(60,240,540,240);
	setlinestyle(SOLID_LINE,0,1);
	line(0,60,585,60);
	puthz(200,10,"��·��Ԯ",32,50,DARKGRAY);
	puthz(100,125,"��ѡ�����ĳ��ƣ�",16,20,BLACK);
    puthz(100,205,"��ϵ�绰��",16,20,BLACK);
	puthz(100,255,"Ʒ�ƣ�",16,20,BLACK);
	setfillstyle(1,LIGHTGRAY);
	bar(220,320,420,360);
	puthz(250,335,"ȷ������",16,40,WHITE);
	puthz(20,380,"��ܰ��ʾ����������󣬾�Ԯ��Ӧ�̻������绰��ϵȷ����Ϣ��������û��ھ�Ԯ��ɺ����ֳ���ȡ��",16,15,CYAN);


	setlinestyle(SOLID_LINE,0,3);
	setcolor(BLACK);
	rectangle(280,120,520,160);
	line(480,120,480,160);
	line(485,125,500,155);
	line(500,155,515,125);
}
/***********************************************
Function :xiayibu(struct POLICY policy[10])
Attention:
Description:��һ���������ܺ��� 
Return :-2 
***************************************************/
int xiayibu(struct POLICY policy[10])
{
	int judge = 0;
	int flag = 0;
	int press,MouseX,MouseY;
	char pcity[3]={'\0'};
	char plate[7]={'\0'};
	char pinpai[15]={'\0'};
	char dianhua[12]={'\0'};
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=20 &&MouseX <=50 &&MouseY >= 10+70 &&MouseY <= 50+70 &&press)
		{
			return -1;
		}
		if(MouseX >=480 &&MouseX <=520 &&MouseY >= 120 &&MouseY <= 160 &&press)
		{
			judge=1;
		}
		if(MouseX >=220 &&MouseX <=420 &&MouseY >= 320 &&MouseY <= 360 &&press)
		{
			judge=2;
		}
		switch(judge)
		{
			case -2:
			{
				return -2;
			}
			case -1:
			{
				clrmous(MouseX,MouseY);
				drawxiayibu();
				puthz(290,125,pcity,16,20,BLACK);
				outtextxy(310,125,"-");
				outtextxy(320,125,plate);
				outtextxy(290,205,dianhua);
				puthz(290,255,pinpai,16,20,BLACK);
				judge=0;
				break;
				
			}
			case 1:
			{
				clrmous(MouseX,MouseY);
				judge=choosepla1(policy,280,161.5,pcity,plate,pinpai,dianhua);
				break;
			}
			case 2:
			{
				clrmous(MouseX,MouseY);
				judge=bingo(220,300,"����ɹ�");
			}
		}
	}
	
}