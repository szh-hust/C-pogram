#include "common.h"
#include "malog.h"
/***************************************************
用户登录界面的账号输入函数
大小写字母与数字
1到10位
*x与*y传递鼠标位置，且以指针的形式传入
***************************************************/
/****************************************
Function :mcinloginaccouhts(char *accounts,int *MouseX,int *MouseY)
Description:输入管理员账户函数
Attention:无
Return：上一个界面的judge值
***************************************/
int mcinloginaccouhts(char *accounts,int *MouseX,int *MouseY)
{
	int key;     //表示 键值 的变量
	int i= 0;    //用于计算已经输入的字符 数目的变量
	char *p = accounts;  //输入字符的中间指针变量
	char ch;     //用于临时 储存键值所对应的字符变量
	int press;   //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	
	
	while(*p != '\0')//使p指向'\0',i表示当前字符数
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
		key = 0;   //重置键值并得到新键值
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		//点击密码框 或者回车  或者按下方向键
		//返回2调用密码输入cinloginmode函数
		if((*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 215 && *MouseY <= 245&&press)||key == 0x1c0d || key == 0x5000) 
		{
			return 2;
		}
		//点击登录按钮
		if(*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 270 && *MouseY <= 300&&press)
		{
			return 3;
		}
		
		//点击退出按钮  退出程序
		if(*MouseX >= 540&& *MouseX <= 640 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 6;
		}
		//点击返回按钮   进入主登录界面
		if(*MouseX >= 0&& *MouseX <= 100 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 5;
		}
		//如果按了删除键
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
		

		/*将按键对应的字符存入accounts数组中*/
        ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(308 + i * 11, 159, 319 + i * 11, 171);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(308 + i * 11, 155, temp);
			//backgroundChange(*MouseX, *MouseY, 308 + i * 11, 159, 319 + i * 11, 171);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}		
	}
}


/****************************************
Function :mcinlogincode(char *code , int *MouseX,int *MouseY)
Description:输入管理员密码函数
Attention:无
Return：上一个界面的judge值
***************************************/


int mcinlogincode(char *code , int *MouseX,int *MouseY)
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
		
		//重置键值并得到新键值
		key = 0;
		
		if(kbhit()!=0)
		{
			key = bioskey(0);
		}
		//如果点击账号框或者按上方向键
		//返回1调用mcinloginaccounts函数
		if((*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 150 && *MouseY <= 180&&press)|| key == 0x4800)
		{
			return 1;
		}
		//如果点击退出键
		if(*MouseX >=540 && *MouseX <= 640 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 6;
		}
		//点击登录按钮
		if(*MouseX >= 300&& *MouseX <= 500 && *MouseY >= 270 && *MouseY <= 300&&press)
		{
			return 3;
		}
		//如果按了返回键
		if(*MouseX >=  0 && *MouseX <= 100 && *MouseY >= 430 && *MouseY <= 480&&press)
		{
			return 5;
		}
	    //如果按了删除键
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
		/*将按键对应的字符存入code数组中*/
		ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			/*画一个圆*/
			setfillstyle(1, WHITE);
			bar(308+i*11,224,319+i*11,236);
			setcolor(BLACK);//如果没有这个，下面画圆就会有缺陷
			setfillstyle(1, BLACK);
			clrmous(*MouseX,*MouseY); 
			pieslice(315+i*11, 230, 0, 360, 3);
		//	backgroundChange(*MouseX, *MouseY,308+i*11,219,319+i*11,231);

			 /*将字符存入数组中*/
			 *p = ch;
			 p++;
			 *p = '\0';
			 i++;
		}
	}
	
}
/*判断管理员账户密码是否正确*/
/****************************************
Function mastercmp (char *a , char *c)
Description:判断管理员账户密码是否正确
Attention:无
Return：上一个函数的judge值
***************************************/
int  mastercmp (char *a , char *c)
{
	if(strcmp(a,"gly")==0&&strcmp(c,"abc")==0)
	{	
	return 7;
	}
	else
	{
		puthz(345,310,"用户名或密码错误",16,20,BLACK);
		return 0;
	}
}


/****************************************
Function :manage_login(setuser *head,char *accounts,char *code)
Description:管理员登录主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int manage_login(setuser *head,char *accounts,char *code)
{
	int judge = 0;
	int huanchong ;//用于吸收键盘缓冲区的变量
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	char * rightcode = NULL;//指向正确密码的指针
	char mima[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char yhm[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	*accounts ='\0';
	*code = '\0';
	//mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		/*吸收键盘缓冲区域数据*/
		if (kbhit() != 0)
		{
			huanchong = bioskey(0);
		}
		//点击账户框
		if(MouseX>=300&&MouseX<=500&&MouseY>=150&&MouseY<=180&&press)   judge=1;
		//点击密码框
		if(MouseX>=300&&MouseX<=500&&MouseY>=215&&MouseY<=245&&press)   judge=2;
	    //点击登录按钮
		if(MouseX>=300&&MouseX<=500&&MouseY>=270&&MouseY<=300&&press)   judge=3;
		//点击返回按钮
		if(MouseX>=0  &&MouseX<=100&&MouseY>=440&&MouseY<=480&&press)   judge=5;
		//点击退出按钮
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
			case 1://点击账户框
			{
				clrmous(MouseX,MouseY);
				judge = mcinloginaccouhts(yhm,&MouseX,&MouseY);
				break;
			}
			case 2://点击密码框
			{
					clrmous(MouseX,MouseY);
				judge = mcinlogincode(mima,&MouseX,&MouseY);
				break;
			}
			case 3://点击登录按钮
			{
				
				judge = mastercmp(yhm,mima);
				break;
			}
			case 5://点击账户框
			{
				return 1;
			}
			case 6://点击退出按钮
			{
				clrmous(MouseX,MouseY);
				judge = jueding("退出程序",8);
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
