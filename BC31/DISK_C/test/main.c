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
Description:程序主函数
Attention:无
Return：无
***************************************/
void main()
{
	int judge = 1;//用于控制页面的变化
	int flag = 1;//用于控制保单画面
	int driver = VGA;
	int mode = VGAHI;
	setuser person;    //表示当前用户的变量
	setuser *head = NULL;    //用户链表的头节点
	person.accounts[0] = '\0';//初始化
	person.code[0] = '\0';//初始化	
	initgraph(&driver, &mode, "C:\\test\\BGI");
	cleardevice();
	if ((head = (setuser *)malloc(sizeof(setuser))) == NULL)
	{
	    closegraph();
		printf("\nout of memory");
		return ;
	}
	createuserlist(head);//创建用户链表，记得要释放
	while(1)
	{
		/*根据judge的值判断需要调用界面和其后台函数*/
	   newmouse(&MouseX,&MouseY,&press);
	   switch(judge)
	   {
		    case 1://进入主登录界面
		    {	
			    drawmainlogin();
				mouseinit();
				judge=mainlogin();
				break;
		    }
		    case 2://进入用户登录界面
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
			case 3://进入管理员登录界面
			{
				draw_managerlogin();
				judge= manage_login(head,person.accounts,person.code);
				break;
			}
		    case 4://退出程序
			{
				clrmous(MouseX,MouseY);
				press = 0;
				freeuserlist(&head);//释放用户链表
			    closegraph();
				//return ;
			}
			case 5://进入管理员界面
			{
				clrmous(MouseX,MouseY);
				draw_manage_page();
				judge=manage_page();
				
				break;
			}
			case 6://用户登录后
			{
				
				clrmous(MouseX,MouseY);
				delay(60);
				//登录后的首页
				drawusermain();
				judge = usermain(head,&person);
				//将用户信息存入链表
				saveinftolist(head,&person);
				break;
			}
			case 7://进入注册界面
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
