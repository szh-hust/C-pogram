#include "common.h"
#include "malog.h"
/***************************************************
�û���¼������˺����뺯��
��Сд��ĸ������
1��10λ
*x��*y�������λ�ã�����ָ�����ʽ����
***************************************************/
/****************************************
Function :mcinloginaccouhts(char *accounts,int *MouseX,int *MouseY)
Description:�������Ա�˻�����
Attention:��
Return����һ�������judgeֵ
***************************************/
int mcinloginaccouhts(char *accounts,int *MouseX,int *MouseY)
{
	int key;     //��ʾ ��ֵ �ı���
	int i= 0;    //���ڼ����Ѿ�������ַ� ��Ŀ�ı���
	char *p = accounts;  //�����ַ����м�ָ�����
	char ch;     //������ʱ �����ֵ����Ӧ���ַ�����
	int press;   //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	
	
	while(*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	setcolor(RED);
	rectangle(300,150,500,180);
	setcolor(BLACK);
	rectangle( 300,215,500,245);
	/*
	AddFrame(*MouseX, *MouseY, 300,150,500,180, RED);
    AddFrame(*MouseX, *MouseY, 300,215,500,245, BLACK);*/
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;   //���ü�ֵ���õ��¼�ֵ
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		//�������� ���߻س�  ���߰��·����
		//����2������������cinloginmode����
		if((*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 215 && *MouseY <= 245&&press)||key == 0x1c0d || key == 0x5000) 
		{
			return 2;
		}
		//�����¼��ť
		if(*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 270 && *MouseY <= 300&&press)
		{
			return 3;
		}
		
		//����˳���ť  �˳�����
		if(*MouseX >= 540&& *MouseX <= 640 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 6;
		}
		//������ذ�ť   ��������¼����
		if(*MouseX >= 0&& *MouseX <= 100 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 5;
		}
		//�������ɾ����
		if(key == 0xe08)
		{
			if(p != accounts)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297 + i * 11, 159, 308 + i * 11, 175);
			//	backgroundChange(*MouseX, *MouseY,297 + i * 11, 159, 308 + i * 11, 171);
				p--;
				i--;
			}
			*p= '\0';
		}
		

		/*��������Ӧ���ַ�����accounts������*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(308 + i * 11, 159, 319 + i * 11, 171);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(308 + i * 11, 155, temp);
			//backgroundChange(*MouseX, *MouseY, 308 + i * 11, 159, 319 + i * 11, 171);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}		
	}
}


/****************************************
Function :mcinlogincode(char *code , int *MouseX,int *MouseY)
Description:�������Ա���뺯��
Attention:��
Return����һ�������judgeֵ
***************************************/


int mcinlogincode(char *code , int *MouseX,int *MouseY)
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
	setcolor(RED);
	rectangle(300,215,500,245);
	setcolor(BLACK);
	rectangle(300,150,500,180);
	/* 
	AddFrame(*MouseX, *MouseY, 300,215,500,245, RED);
    AddFrame(*MouseX, *MouseY, 300,150,500,180, BLACK);*/
	while (1)
	{
		newmouse(MouseX,MouseY,&press);
		
		//���ü�ֵ���õ��¼�ֵ
		key = 0;
		
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		//�������˺ſ���߰��Ϸ����
		//����1����mcinloginaccounts����
		if((*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 150 && *MouseY <= 180&&press)|| key == 0x4800)
		{
			return 1;
		}
		//�������˳���
		if(*MouseX >=540 && *MouseX <= 640 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 6;
		}
		//�����¼��ť
		if(*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 270 && *MouseY <= 300&&press)
		{
			return 3;
		}
		//������˷��ؼ�
		if(*MouseX >=  0 && *MouseX <= 100 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 5;
		}
	    //�������ɾ����
		if(key == 0xe08)
		{
			if(p != code)
			{
				setfillstyle(1,WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297+i*11,224,308+i*11,236);
			//	backgroundChange(*MouseX, *MouseY,297+i*11,224,308+i*11,236);
				p--;
				i--;
			}
			*p = '\0';
		}
		/*��������Ӧ���ַ�����code������*/
		ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			/*��һ��Բ*/
			setfillstyle(1, WHITE);
			bar(308+i*11,224,319+i*11,236);
			setcolor(BLACK);//���û����������滭Բ�ͻ���ȱ��
			setfillstyle(1, BLACK);
			clrmous(*MouseX,*MouseY); 
			pieslice(315+i*11, 230, 0, 360, 3);
		//	backgroundChange(*MouseX, *MouseY,308+i*11,219,319+i*11,231);

			 /*���ַ�����������*/
			 *p = ch;
			 p++;
			 *p = '\0';
			 i++;
		}
	}
	
}
/*�жϹ���Ա�˻������Ƿ���ȷ*/
/****************************************
Function mastercmp (char *a , char *c)
Description:�жϹ���Ա�˻������Ƿ���ȷ
Attention:��
Return����һ��������judgeֵ
***************************************/
int  mastercmp (char *a , char *c)
{
	if(strcmp(a,"gly")==0&&strcmp(c,"abc")==0)
	{	
	return 7;
	}
	else
	{
		puthz(345,310,"�û������������",16,20,BLACK);
		return 0;
	}
}


/****************************************
Function :manage_login(setuser *head,char *accounts,char *code)
Description:����Ա��¼������
Attention:��
Return����һ�������judgeֵ
***************************************/
int manage_login(setuser *head,char *accounts,char *code)
{
	int judge = 0;
	int huanchong ;//�������ռ��̻������ı���
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	char * rightcode = NULL;//ָ����ȷ�����ָ��
	char mima[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char yhm[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	*accounts ='\0';
	*code = '\0';
	//mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		/*���ռ��̻�����������*/
		if (kbhit() != 0)
		{
			huanchong = bioskey(0);
		}
		//����˻���
		if(MouseX>=300&&MouseX<=500&&MouseY>=150&&MouseY<=180&&press)   judge=1;
		//��������
		if(MouseX>=300&&MouseX<=500&&MouseY>=215&&MouseY<=245&&press)   judge=2;
	    //�����¼��ť
		if(MouseX>=300&&MouseX<=500&&MouseY>=270&&MouseY<=300&&press)   judge=3;
		//������ذ�ť
		if(MouseX>=0  &&MouseX<=100&&MouseY>=440&&MouseY<=480&&press)   judge=5;
		//����˳���ť
		if(MouseX>=540&&MouseX<=640&&MouseY>=430&&MouseY<=480&&press)   judge=6;
		
		switch(judge)
		{
			case -1:
				{
					clrmous(MouseX,MouseY);
					draw_managerlogin();
					strcpy(yhm,"\0");
					strcpy(mima,"\0");
					judge = 0;
					break;
				}
			case 1://����˻���
			{
				clrmous(MouseX,MouseY);
				judge = mcinloginaccouhts(yhm,&MouseX,&MouseY);
				break;
			}
			case 2://��������
			{
					clrmous(MouseX,MouseY);
				judge = mcinlogincode(mima,&MouseX,&MouseY);
				break;
			}
			case 3://�����¼��ť
			{
				
				judge = mastercmp(yhm,mima);
				break;
			}
			case 5://����˻���
			{
				return 1;
			}
			case 6://����˳���ť
			{
				clrmous(MouseX,MouseY);
				judge = jueding("�˳�����",8);
				delay(100);
				break;
			}
			case 7:
			{
				return 5;
			}
			case 8:
				{
					return 4;
				}
		}
		
	}	
	
}
