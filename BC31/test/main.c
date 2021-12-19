#include "common.h"
#include"draw.h"
#include"nmouse.h"
#include"mouse.h"
#include "HZ.H"
#include "keyboard.h"
#include "struct.h"
#include "dlogin.h"
#include "mlogin.h"
#include "register.h"
#include "user.h"
#include "userll.h"
#include "ulogin.h"
#include "malog.h"
#include "manage.h"
#include "register.h"
#include "userself.h"
#include "ccode.h"
#include "lipei1.h"
#include "lipei2.h"
#include "lpgl.h"
#include "daolu.h"
#include "policy1.h"
#include "policy2.h"
#include "gpolicy.h" 
/****************************************
Function :main()
Description:����������
Attention:��
Return����
***************************************/
void main()
{
	int judge = 1;//���ڿ���ҳ��ı仯
	int flag = 1;//���ڿ��Ʊ�������
	int driver = VGA;
	int mode = VGAHI;
	setuser person;    //��ʾ��ǰ�û��ı���
	setuser *head = NULL;    //�û������ͷ�ڵ�
	person.accounts[0] = '\0';//��ʼ��
	person.code[0] = '\0';//��ʼ��	
	initgraph(&driver, &mode, "C:\\test\\BGI");
	cleardevice();
	if ((head = (setuser *)malloc(sizeof(setuser))) == NULL)
	{
	    closegraph();
		printf("\nout of memory");
		return ;
	}
	createuserlist(head);//�����û������ǵ�Ҫ�ͷ�
	while(1)
	{
		/*����judge��ֵ�ж���Ҫ���ý�������̨����*/
	   newmouse(&MouseX,&MouseY,&press);
	   switch(judge)
	   {
		    case 1://��������¼����
		    {	
			    drawmainlogin();
				mouseinit();
				judge=mainlogin();
				break;
		    }
		    case 2://�����û���¼����
		    {
				person.accounts[0] = '\0';
				person.code [0]= '\0';
				mouseinit();
			    draw_userlogin();
				//mouseinit();
			    judge=user_login(head, person.accounts, person.code);
			    clrmous(MouseX,MouseY); 
			    break;
		    }
			case 3://�������Ա��¼����
			{
				draw_managerlogin();
				judge= manage_login(head,person.accounts,person.code);
				break;
			}
		    case 4://�˳�����
			{
				clrmous(MouseX,MouseY);
				press = 0;
				freeuserlist(&head);//�ͷ��û�����
			    closegraph();
				//return ;
			}
			case 5://�������Ա����
			{
				clrmous(MouseX,MouseY);
				draw_manage_page();
				judge=manage_page();
				
				break;
			}
			case 6://�û���¼��
			{
				
				clrmous(MouseX,MouseY);
				delay(60);
				//��¼�����ҳ
				drawusermain();
				judge = usermain(head,&person);
				//���û���Ϣ��������
				saveinftolist(head,&person);
				break;
			}
			case 7://����ע�����
			{
				draw_register();
			    judge=userregister(head, person.accounts, person.code);
				break;
			}
			case -1:
			{
				judge = 1;
				break;
			}
	   }
	}	
}
