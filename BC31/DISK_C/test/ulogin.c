#include "common.h"
#include "ulogin.h"
#include "dlogin.h"
#include "userll.h"
#include "register.h"
/***************************************************
function:�û���¼������˺����뺯��
Attention:��Сд��ĸ������
          1��10λ
Description:*x��*y�������λ�ã�����ָ�����ʽ����
return :userlogin������judge 
***************************************************/
int cinloginaccouhts(char *accounts,int *MouseX,int *MouseY)
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
	rectangle(300,215,500,245);
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
		if((*MouseX >= 300 && *MouseX <= 500 && *MouseY >= 215 && *MouseY <= 245 && press)||key == 0x1c0d || key == 0x5000) 
		{
			
			return 2;
		}
		//�����¼��ť
		if(*MouseX >= 300 && *MouseX <= 500 && *MouseY >= 270 && *MouseY <= 300 && press)
		{
			return 3;
		}
		//���ע�ᰴť
		if(*MouseX>=300&&*MouseX<=423&&*MouseY>=310&&*MouseY<=326&&press)
		{
			return 4;
		}
		//����˳���ť  �˳�����
		if(*MouseX >= 540 && *MouseX <= 640 && *MouseY >= 440 && *MouseY <= 480 && press)
		{
			return 6;
		}
		//������ذ�ť   ��������¼����
		if(*MouseX >= 0 && *MouseX <= 100 && *MouseY >= 440 && *MouseY <= 480 && press)
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
			outtextxy(308 + i * 11, 158, temp);
			//backgroundChange(*MouseX, *MouseY, 308 + i * 11, 159, 319 + i * 11, 171);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}		
	}
}


/***************************************************
function:�û���¼������������뺯��
Attention:��Сд��ĸ������
          1��10λ
Description:*x��*y�������λ�ã�����ָ�����ʽ����
return :userlogin������judge 
***************************************************/
int cinlogincode(char *code , int *MouseX,int *MouseY)
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
		//����1����cinloginaccounts����
		if((*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 150 && *MouseY <= 180&&press)|| key == 0x4800)
		{
			return 1;
		}
		//�����¼��ť
		if(*MouseX >= 300 && *MouseX <= 500 && *MouseY >= 270 && *MouseY <= 300 && press)
		{
			
			return 3;
		}
		//���ע�ᰴť
		if(*MouseX>=300&&*MouseX<=423&&*MouseY>=310&&*MouseY<=326&&press)
		{
			return 4;
		}
		//����˳���ť  �˳�����
		if(*MouseX >= 540 && *MouseX <= 640 && *MouseY >= 440 && *MouseY <= 480 && press)
		{
			return 6;
		}
		//������ذ�ť   ��������¼����
		if(*MouseX >= 0 && *MouseX <= 100 && *MouseY >= 440 && *MouseY <= 480 && press)
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
				bar(297+i*11,219,308+i*11,235);
				//backgroundChange(*MouseX, *MouseY,308+i*11,219,319+i*11,231);
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
			bar(308+i*11,219,319+i*11,231);
			setcolor(BLACK);//���û����������滭Բ�ͻ���ȱ��
			setfillstyle(1, BLACK);
			clrmous(*MouseX,*MouseY); 
			pieslice(315+i*11, 230, 0, 360, 3);
			//backgroundChange(*MouseX, *MouseY,308+i*11,219,319+i*11,231);

			 /*���ַ�����������*/
			 *p = ch;
			 p++;
			 *p = '\0';
			 i++;
		}
	}
	
}

/***************************************************
function:�û���¼���������� 
Attention:��Сд��ĸ������
          1��10λ
Description:*x��*y�������λ�ã�����ָ�����ʽ����
return :4��6��-1��7 
***************************************************/
int user_login(setuser *head,char *accounts,char *code)
{
	int judge = 0;
	int huanchong ;//�������ռ��̻������ı���
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	char * rightcode = NULL;//ָ����ȷ�����ָ��
	*accounts ='\0';
	*code = '\0';
	clrmous(MouseX,MouseY);
	delay(100);
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
		
		//���ע�ᰴť
		//(300,310,423,326);
		if(MouseX>=300&&MouseX<=423&&MouseY>=310&&MouseY<=326&&press)   judge=4;
		
		//������ذ�ť
		if(MouseX>=0  &&MouseX<=100&&MouseY>=440&&MouseY<=480&&press)   judge=5;
		
		//����˳���ť
		if(MouseX>=540&&MouseX<=640&&MouseY>=430&&MouseY<=480&&press)   judge=6;
		
		switch(judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY);
				draw_userlogin();
				*accounts ='\0';
				*code = '\0';
				judge = 0;
				break;
			}
			case 1://����˻���
			{
				clrmous(MouseX,MouseY);
				judge = cinloginaccouhts(accounts,&MouseX,&MouseY);
				break;
			}
			case 2://��������
			{
				clrmous(MouseX,MouseY);
				judge = cinlogincode(code,&MouseX,&MouseY);
				break;
			}
			case 3://�����¼��ť
			{
				rightcode = searchaccounts(head,accounts);
				if(rightcode != NULL && strcmp(rightcode, code) == 0)
				{
					//Drawjiazaitiao();
					//ȥ���н��û�����Ϣ��������
					return 6;
				}
				else 
				{
					puthz(300,410, "�˺����������������", 16, 16,RED);
				    break;
				}	
			}
			case 4://���ע�ᰴť
			{
				delay(100);
				return 7;
			}
			case 5://������ذ�ť
			{
				return -1;
			}
			case 6://����˳���ť
			{
				clrmous(MouseX,MouseY);
				judge = jueding("�˳�����",7);
				delay(100);
				break;
			}
			case 7:
			{
				return 4;
			}
		}
		
	}	
	
}
