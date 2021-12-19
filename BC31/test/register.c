/*
用于进行注册的功能
可分为:registercinaccounts  注册时账号输入函数
       registercincode      注册时密码输入函数
       registersecondcode     注册时第二次密码输入函数
	   addnew                 将新注册用户添加至文件和链表
	   draw_register
	   userregister           注册界面的后台函数  
*/
#include "common.h"
#include "register.h"
#include "userll.h"
#include "dlogin.h"
/*************************************************
Function: registercinaccounts(char *accounts, int *MouseX, int *MouseY)
Descration:输入注册时的账号
Attention:
账号只能是大小写字母与数字且只能输入1到10位
鼠标位置参数必须要以指针形式传递过来！
***************************************************/
int registercinaccounts(char *accounts, int *MouseX, int *MouseY)
{
	char *p = accounts;   //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int press;    //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	int key;    //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	//画点开后的框框
	setcolor(RED);
	rectangle(300,150,500,180);
	setcolor(BLACK);
	rectangle(300,215,500,245);
	rectangle(300,275,500,305);
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if (key == 0x1c0d || key == 0x5000||(*MouseX >=300  && *MouseX <=500 && *MouseY >= 215 && *MouseY <= 245 && press) )
		{//如果按了一次enter键或鼠标点击*密码输入*或按了一次下方向键，返回2表示调用registerinputcode函数
			return 2; 
		}

		if (*MouseX >= 300 && *MouseX <= 500 && *MouseY >= 275 && *MouseY <= 305 && press)
		{//如果鼠标点击*再次输入密码*，返回3表示调用registersecondcode函数
			return 3;       
		}

		if (*MouseX >= 300 && *MouseX <= 500 && *MouseY >= 320 && *MouseY <= 360 && press)
		{//如果鼠标点击*确认*（完成注册），返回4
			return 4;       
		}
		if (*MouseX >= 0 && *MouseX <= 100 && *MouseY >=440 && *MouseY <= 480 && press)
		{//如果鼠标点击*返回*，返回5表示返回登录界面
			return 5;       
		}
		
		 if (*MouseX >= 540 && *MouseX <= 640 && *MouseY >= 440&& *MouseY <= 480 && press) 
		{//如果鼠标点击*退出系统*
			return 6;
		}
		//如果按了回删键 
		if (key == 0xe08)
		{
			if (p != accounts)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297 + i * 11, 152, 308 + i * 11, 178);
			//	backgroundChange(*MouseX, *MouseY, 297 + i * 11, 152, 308 + i * 11, 178);
				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入accounts数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(308 + i * 11, 152, 319 + i * 11, 178);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(308+ i * 11, 155, temp);
			//backgroundChange(*MouseX, *MouseY, 308 + i * 11, 152, 319 + i * 11, 178);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/*************************************************
Function: registercincode (char *code ,int *MouseX,int *MouseY)
Descration:输入注册时的第一次密码
Attention:
账号只能是大小写字母与数字且只能输入1到10位
鼠标位置参数必须要以指针形式传递过来！
***************************************************/
int registercincode (char *code ,int *MouseX,int *MouseY)
{
    char *p = code;   //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int press;    //鼠标的参数变量
	int key;    //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	setcolor(RED);
	rectangle(300,215,500,245);
	setcolor(BLACK);
	rectangle(300,150,500,180);
	rectangle(300,275,500,305);
	
	while (1)
	{
		newmouse(MouseX,MouseY,&press);

		//重置键值并得到新键值
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 150 && *MouseY <= 180 && press || key == 0x4800)
		{//如果鼠标点击*账号输入*或按了一次上方向键，返回1表示调用registerinputaccounts函数
			return 1; 
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 275 && *MouseY <= 305 && press|| key == 0x5000 || key == 0x1c0d)
		{//如果鼠标点击*再次输入密码*或按了enter键或下方键，返回3表示调用registersecondcode函数
			return 3;       
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 320 && *MouseY <= 360 && press)
		{//如果鼠标点击*确认*（完成注册），返回4
			return 4;       
		}

		if (*MouseX >=  0  && *MouseX <=100 && *MouseY >= 440 && *MouseY <= 480 && press)
		{//如果鼠标点击*返回*，返回5表示返回登录界面
			return 5;       
		}
		
		if (*MouseX >= 540 && *MouseX <= 640 && *MouseY >= 440&& *MouseY <= 480 && press) 
		{//如果鼠标点击*退出系统*
			return 6;
		}
		
        /*如果按了回删键*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297 + i * 11, 217, 308 + i * 11, 243);

			//	backgroundChange(*MouseX, *MouseY, 297 + i * 11, 215, 308 + i * 11, 245);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入code数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;

			/*画一个圆*/
			setfillstyle(1, WHITE);
			bar(297 + i * 11, 217, 308 + i * 11, 243);
			setcolor(BROWN);//如果没有这个，下面画圆就会有缺陷
			setfillstyle(1, BLACK);
			clrmous(*MouseX,*MouseY); 
			pieslice(301 + i * 11, 230, 0, 360, 3);
			//backgroundChange(*MouseX, *MouseY, 297 + i * 11, 217, 308 + i * 11, 243);
		}   		
	}
}

/*************************************************
Function: registersecondcode(char *tcode ,int *MouseX, int *MouseY)
Descration:输入注册时的第二次密码
Attention:
账号只能是大小写字母与数字且只能输入1到10位
鼠标位置参数必须要以指针形式传递过来！
***************************************************/
int registersecondcode(char *tcode ,int *MouseX, int *MouseY)
{
	
	char *p = tcode;//用于输入字符
	char ch;//用于临时储存键值所对应字符的变量
	int press=0;//鼠标的参数变量	
	int key;//表示键值的变量
	int i = 0;//用于计算已输入的字符数目的变量
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	setcolor(RED);
	rectangle(300,275,500,305);
	setcolor(BLACK);
	rectangle(300,150,500,180);
	rectangle(300,215,500,245);
	while (1)
	{
		newmouse(MouseX, MouseY, &press);

		//重置键值并得到新键值
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 150 && *MouseY <= 180 && press )
		{//如果鼠标点击*账号输入*，返回1表示调用registercinaccounts函数
		    
			return 1; 
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 215 && *MouseY <= 245 && press|| key == 0x4800)
		{//如果鼠标点击*密码输入*，返回2表示调用registercincode函数
		    
			return 2;       
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 320 && *MouseY <= 360 && press|| key == 0x1c0d)
		{//如果鼠标点击*确认*（完成注册）或按了enter键，返回4
		    
			return 4;       
		}

		if (*MouseX >=   0 && *MouseX <= 100 && *MouseY >= 440 && *MouseY <= 480 && press)
		{//如果鼠标点击*返回*，返回5表示返回登录界面
			return 5;       
		}
		
		if (*MouseX >= 540 && *MouseX <=640 && *MouseY >= 440&& *MouseY <= 480 && press) 
		{//如果鼠标点击*退出系统*
			return 6;
		}
		
		/*如果按了回删键*/
		if (key == 0xe08)
		{
			if (p != tcode)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297 + i * 11, 277, 308 + i * 11, 303);

			//	backgroundChange(*MouseX, *MouseY, 297 + i * 11, 277, 308 + i * 11, 303);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入tcode数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;

			/*画一个圆*/
			setfillstyle(1, WHITE);
			bar(297 + i * 11, 277, 308 + i * 11, 303);
			setcolor(BROWN);//如果没有这个，下面画圆就会有缺陷
			setfillstyle(1, BLACK);
			clrmous(*MouseX,*MouseY); 
			pieslice(301 + i * 11, 290, 0, 360, 3);
			//backgroundChange(*MouseX, *MouseY, 297 + i * 11, 277, 308 + i * 11, 303);
		}   		
	}
}
/************************************************************************
  将注册好的用户的账号和密码加入到用户链表中，并添加进文件
              C>test>t_file>user>accandco.txt中
 新用户的链表节点直接插入到头节点之后
***********************************************************************/
int addnew(setuser *head,char *accounts,char *code)	
{
	FILE *fp;
	char *p;
	int i=0;
	setuser *newnode=(setuser *)malloc(sizeof(setuser));
	if(newnode==NULL)
	{
		closegraph();
		printf("no enough memory!!!");
		//getchar();
		exit(1);
	}
	//新节点存放注册好的用户的信息
	strcpy(newnode->accounts,accounts);
	strcpy(newnode->code,code);
	//将新节点插到头节点head之后
	newnode->next=head->next;//注意先连接后断开，否则链表后面的节点都将丢失
	head->next=newnode;
	
	//以下部分将注册好的用户信息写入文件中
	if((fp=fopen("./t_file/user/accandco.txt","r+"))==NULL)
	{
		closegraph();
		printf("can't open accandco.txt");
		//getchar();
		exit(1);
	}
	fseek(fp,0L,2);//把文件内部指针指到文件末端0偏移的地方
	p=accounts;
	 while(*p!='\0')
     {
	     putc(*p,fp);
	     p++;
     }
      putc('*',fp);
      p=code;
     while(*p!='\0')
     {
	     putc(*p,fp);
	     p++;
     }
     for (i = 0;i < 10 - strlen(code);i++)
	 {
	    putc(' ', fp);
	 }
     putc('#',fp);

     fclose(fp);
	 return 0;
}
/*************************************************
Function:userregister(setuser *head,char *accounts,char *code)
Descration:注册主函数 
Attention:
***************************************************/
int userregister(setuser *head,char *accounts,char *code)
{
	long money =500; 
    int judge=0;   
    int huanchong;//用于吸收键盘缓冲区的变量
    int press,MouseX,MouseY;//鼠标相关变量
    int driver=VGA;
    int mode=VGAHI;
    char *rightcode=NULL;//指向正确密码的指针
    char tcode[11]={'\0'};//放入第二次输入的密码，密码最多10个字符
    int flagone=0,flagtwo=0,flagthree=0;//标志三个输入框内是否有提醒字
    *accounts = '\0';
    *code = '\0';
    while(1)
    {
	    newmouse(&MouseX,&MouseY,&press);
	    if (kbhit() != 0)
	    {//吸收键盘缓冲区域数据
	    	 huanchong = bioskey(0);      
	    }
	    if (MouseX >= 300 && MouseX <= 500 && MouseY >= 150 && MouseY <= 180 && press)
		{//鼠标点击账号输入框
			 judge=1;
		}
		if (MouseX >=300  && MouseX <= 500 && MouseY >= 215 && MouseY <= 245 && press)
		{//鼠标点密码输入框
			judge=2;
		}
		if (MouseX >=300  && MouseX <= 500 && MouseY >= 275 && MouseY <= 305 && press)
		{//鼠标点击再次密码输入框
			judge=3;
		}
		if (MouseX >= 300 && MouseX <= 500 && MouseY >= 320 && MouseY <= 360 && press)
		{//鼠标点击确认（完成注册）
			judge=4;
		}
		if (MouseX >=   0 && MouseX <= 100 && MouseY >= 440 && MouseY <= 480 && press)
		{//鼠标点击返回
			judge=5;
		}
        if (MouseX >= 540 && MouseX <= 640 && MouseY >= 440&& MouseY <= 480 && press) 
		{//如果鼠标点击*退出*
			judge=6;
		}
		 switch(judge)
		{
		    case -1:
			    {
					return 2;	
		        }
		    case 1://如果点击了*账号输入框*
		        {
					clrmous(MouseX,MouseY);
					if(flagone==1)//判断输入框内是否有提示字，如有则覆盖掉
					{
						setfillstyle(1, WHITE);
						bar(300,150,500,180);
						// backgroundChange(MouseX,MouseY, 300,150,500,180);
						flagone=0;
					}
					judge=registercinaccounts(accounts,&MouseX,&MouseY);
					break;
				}
		    case 2://如果点击了*新密码输入*
		    {
			    clrmous(MouseX,MouseY);
			    if(flagtwo==1)//判断输入框内是否有提示字，如有则覆盖掉
				{
					setfillstyle(1, WHITE);
			        bar(300,215,500,245);
					flagtwo=0;
				 }
		        judge=registercincode(code,&MouseX,&MouseY);
				break;
		    }
		    case 3://如果点击了*再次输入密码*
			{
				clrmous(MouseX,MouseY);
				if(flagthree==1)//判断输入框内是否有提示字，如有则覆盖掉
				{
					setfillstyle(1, WHITE);
			        bar(300,275,500,305);
					flagthree=0;
				}
		        judge=registersecondcode(tcode,&MouseX,&MouseY);
				break;
			}		 
		    case 4://如果鼠标点击*确认*（完成注册）
		    {
				if(strlen(accounts)<6)//如果账号长度少于6
				 {
					 flagone=1;
					 setfillstyle(1, WHITE);
			         bar(300,150,500,180);
				     puthz(305,155,"账号不得少于六位！",16,16,LIGHTGRAY);
					 setcolor(BLACK);
					rectangle(300,150,500,180);
					// backgroundChange(MouseX, MouseY,300,150,500,180);
					 *accounts = '\0';//将已输入的密码字符串清除
					 judge=0;
					 break;
				 } 
				else if(searchaccounts(head,accounts)!=NULL)//如果输入的账号名能在用户链表中找到
				 {
					 flagone=1;
					 setfillstyle(1, WHITE);
			         bar(300,150,500,180);
				     puthz(305,155,"该账号已注册！",16,16,LIGHTGRAY);
					 setcolor(BLACK);
					rectangle(300,150,500,180);
					// backgroundChange(MouseX,MouseY,300,150,500,180);
					 *accounts = '\0';//将已输入的账号字符串清除
					 delay(100);
					 judge=0;
					 break;
				 }
				else if(strlen(code)<6)//如果密码长度少于6
				 {
					 flagtwo=1; 
					 setfillstyle(1, WHITE);
			         bar(300,215,500,245);
				     puthz(305,220,"密码不得少于六位！",16,16,LIGHTGRAY);
					 setcolor(BLACK);
					rectangle(300,215,500,245);
					// backgroundChange(MouseX, MouseY,300,150,500,180);
					 *code = '\0';//将已输入的密码字符串清除
					 judge=0;
					 break;
				 } 	 
				 else if(strcmp(code, tcode) != 0)//如果密码和第二次输入的密码不一致
				 {
					flagthree=1;
					setfillstyle(1, WHITE);
			        bar(300,275,500,305);
				    puthz(305,280,"两次输入的密码不同！",16,16,LIGHTGRAY);
					setcolor(BLACK);
					rectangle(300,275,500,305);
					//backgroundChange(MouseX, MouseY,300,275,500,305);
					*tcode = '\0';//将已输入的第二次密码字符串清除
					judge=0;
					break;
				 }	  
				else
				{
					putmoney(accounts,money);
					addnew(head, accounts, code);//将注册好的用户的账号和密码加入到用户链表中，并添加进文件中									 
					
					judge = queren("即将进入登录界面！",240,170,16,20,-1);
					*accounts = '\0';//重新初始化，防止输入异常
                    *code = '\0';
				    *tcode='\0';
					//return 1;//注册成功后进入登录界面
				}
		  }
			case 5://点击返回
			{
				 *accounts = '\0';
	             *code = '\0';
				 *tcode='\0';
				 return 2;
			}
			case 6://点击退出
			{
				*accounts = '\0';//由注册返回到登录应重新初始化，防止输入异常！！！
	             *code = '\0';
				 *tcode='\0';
				 return 4;
			}
		}
  }
}
