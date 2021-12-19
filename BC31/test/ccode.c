/********************************

*************************************/
#include "common.h"
#include "userll.h"

/****************************************
Function :putinoldcode(char *old_code, int *MouseX, int *MouseY)
Description:输入原密码
Attention:无
Return：上一个界面的judge值
***************************************/
int putinoldcode(char *old_code, int *MouseX, int *MouseY)
{
	char *p = old_code;   //输入字符的中间指针变量
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
	setcolor(RED);
	rectangle(400-50,130,550,170);
	setcolor(BLACK);
	rectangle(400-50,220,550,260);
	rectangle(400-50,310,550,350);
	/*//画点开后的框框
	AddFrame(*MouseX,*MouseY,400-50,130,550,170,RED);//账号框变红
	AddFrame(*MouseX,*MouseY,400-50,220,550,260,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,310,550,350,BLACK);*/
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if (key == 0x1c0d || key == 0x5000||(*MouseX >=350  && *MouseX <=550 && *MouseY >= 220 && *MouseY <= 260 && press) )
		{//如果按了一次enter键或鼠标点击*密码输入*或按了一次下方向键，返回9表示调用putinnewcode函数
			return 9; 
		}

		if (*MouseX >= 350 && *MouseX <= 550 && *MouseY >= 310 && *MouseY <= 350 && press)
		{//如果鼠标点击*再次输入密码*，返回10表示调用putinjudgecode函数
			return 10;       
		}

		if (*MouseX >= 400 && *MouseX <= 500 && *MouseY >= 380 && *MouseY <= 420 && press)
		{//如果鼠标点击*确认*（完成注册），返回11
			return 11;       
		}
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 50 && *MouseY <= 90 && press)
			return 1;
		//进入我的理赔
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 90 && *MouseY <= 130 && press)
			return 2;
		//进入爱车管理
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 130 && *MouseY <= 170 && press)
			return 3;
		//进入我的钱包
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 210 && *MouseY <= 250 && press)
			return 5;
		//进入关于我们
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 250 && *MouseY <= 290 && press)
			return 6;	
		//进入常见问题
		if(*MouseX >=0  && *MouseX <= 150 &&* MouseY >= 290 && *MouseY <= 330 && press)
			return 7;
		//点击返回主页(20,420,120,460)
		if(*MouseX >=20  && *MouseX <= 120 && *MouseY >= 420 &&*MouseY <= 460 && press)
			return 8;
		//如果按了回删键 
		if (key == 0xe08)
		{
			if (p != old_code)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(344 + i * 11, 132, 355 + i * 11, 168);
			//	backgroundChange(*MouseX, *MouseY, 344 + i * 11, 130, 355 + i * 11, 170);
				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入old_code数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(355 + i * 11, 132, 366 + i * 11, 168);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(355+ i * 11, 135, temp);
		//	backgroundChange(*MouseX, *MouseY, 355 + i * 11, 130, 366 + i * 11, 170);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :putinnewcode (char *code ,int *MouseX,int *MouseY)
Description:输入新密码
Attention:无
Return：上一个界面的judge值
***************************************/
int putinnewcode (char *code ,int *MouseX,int *MouseY)
{
    char *p = code;   //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	int press;    //鼠标的参数变量
	int key;    //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
	setcolor(RED);
	rectangle(400-50,220,550,260);
	setcolor(BLACK);
	rectangle(400-50,130,550,170);
	rectangle(400-50,310,550,350);
	
	/*AddFrame(*MouseX,*MouseY,400-50,130,550,170,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,220,550,260,RED);
	AddFrame(*MouseX,*MouseY,400-50,310,550,350,BLACK);*/
	
	while (1)
	{
		newmouse(MouseX,MouseY,&press);

		//重置键值并得到新键值
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 130 && *MouseY <= 170 && press || key == 0x4800)
		{//如果鼠标点击*账号输入*或按了一次上方向键，返回1表示调用registerinputaccounts函数
			return 12; 
		}

		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 310 && *MouseY <= 350 && press|| key == 0x5000 || key == 0x1c0d)
		{//如果鼠标点击*再次输入密码*或按了enter键或下方键，返回3表示调用registersecondcode函数
			return 10;       
		}

		if (*MouseX >= 400 && *MouseX <= 500 && *MouseY >= 380 && *MouseY <= 420 && press)
		{//如果鼠标点击*确认*（完成注册），返回11
			return 11;       
		}
		
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 50 && *MouseY <= 90 && press)
			return 1;
		//进入我的理赔
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 90 && *MouseY <= 130 && press)
			return 2;
		//进入爱车管理
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 130 && *MouseY <= 170 && press)
			return 3;
		//进入我的钱包
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 210 && *MouseY <= 250 && press)
			return 5;
		//进入关于我们
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 250 && *MouseY <= 290 && press)
			return 6;	
		//进入常见问题
		if(*MouseX >=0  && *MouseX <= 150 &&* MouseY >= 290 && *MouseY <= 330 && press)
			return 7;
		//点击返回主页(20,420,120,460)
		if(*MouseX >=20  && *MouseX <= 120 && *MouseY >= 420 &&*MouseY <= 460 && press)
			return 8;
        /*如果按了回删键*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(344 + i * 11, 132+90, 355 + i * 11, 168+90);

				//backgroundChange(*MouseX, *MouseY, 355 + i * 11, 220, 366 + i * 11, 260);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入new_code数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(355 + i * 11, 132+90, 366 + i * 11, 168+90);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(355+ i * 11, 135+90, temp);
		//	backgroundChange(*MouseX, *MouseY, 355 + i * 11, 130+90, 366 + i * 11, 170+90);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++; 
		}   		
	}
}
/****************************************
Function :putinjudgecode(char *tcode ,int *MouseX, int *MouseY)
Description:输入确认密码
Attention:无
Return：上一个界面的judge值
***************************************/
int putinjudgecode(char *tcode ,int *MouseX, int *MouseY)
{
	
	char *p = tcode;//用于输入字符
	char ch;//用于临时储存键值所对应字符的变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组
	int press=0;//鼠标的参数变量	
	int key;//表示键值的变量
	int i = 0;//用于计算已输入的字符数目的变量
	while (*p != '\0')//使p指向'\0',i表示当前字符数
	{
		i++;
		p++;
	}
    setcolor(RED);
	rectangle(400-50,310,550,350);
	setcolor(BLACK);
	rectangle(400-50,130,550,170);
	rectangle(400-50,220,550,260);
	/*
	AddFrame(*MouseX,*MouseY,400-50,130,550,170,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,220,550,260,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,310,550,350,RED);*/
	while (1)
	{
		newmouse(MouseX, MouseY, &press);

		//重置键值并得到新键值
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 130 && *MouseY <= 170&& press )
		{//如果鼠标点击*原密码输入*，返回1表示调用putinoldcode函数
		    
			return 12; 
		}

		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 220 && *MouseY <= 260 && press|| key == 0x4800)
		{//如果鼠标点击*新密码输入*，返回2表示调用putinnewcode函数
		    
			return 9;       
		}

		if (*MouseX >= 400 && *MouseX <= 500 && *MouseY >= 380 && *MouseY <= 420 && press)
		{//如果鼠标点击*确认*（完成修改），返回11
			return 11;       
		}
		
		//进入我的保单
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 50 && *MouseY <= 90 && press)
			return 1;
		//进入我的理赔
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 90 && *MouseY <= 130 && press)
			return 2;
		//进入爱车管理
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 130 && *MouseY <= 170 && press)
			return 3;
		//进入我的钱包
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 210 && *MouseY <= 250 && press)
			return 5;
		//进入关于我们
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 250 && *MouseY <= 290 && press)
			return 6;	
		//进入常见问题
		if(*MouseX >=0  && *MouseX <= 150 &&* MouseY >= 290 && *MouseY <= 330 && press)
			return 7;
		//点击返回主页(20,420,120,460)
		if(*MouseX >=20  && *MouseX <= 120 && *MouseY >= 420 &&*MouseY <= 460 && press)
			return 8;
		/*如果按了回删键*/
		if (key == 0xe08)
		{
			if (p != tcode)
			{
				setfillstyle(1, WHITE);
				
				clrmous(*MouseX,*MouseY); 
				bar(344 + i * 11, 132+90+90, 355 + i * 11, 168+90+90);

				//backgroundChange(*MouseX, *MouseY,  355 + i * 11, 220+90, 366 + i * 11, 260+90);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入jud_code数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(355 + i * 11, 132+90+90, 366 + i * 11, 168+90+90);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(355+ i * 11, 135+90+90, temp);
			//backgroundChange(*MouseX, *MouseY, 355 + i * 11, 130+90+90, 366 + i * 11, 170+90+90);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++; 
		}   		
	}
}
/****************************************
Function :changecode(setuser *head,setuser *person)
Description:修改密码主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int changecode(setuser *head,setuser *person)
{
	FILE *fp = NULL;   
	char ch = '\0';
	char CurrentAccounts[11];
	char *p = NULL;
	int length =0;
	int i;
	//int mark = 0;
	int judge = 0;
	int press,MouseX,MouseY;
	//int driver = VGA;
	//int mode = VGAHI;
    	char old_code[11]="\0";
	char new_code[11]="\0";
	char jud_code[11]="\0";
	char *rightcode=NULL;
	rightcode = searchaccounts(head,(*person).accounts);
	strcpy(CurrentAccounts,rightcode);
                delay(100);
                save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
		{
			judge = 1;
		}
		//进入我的理赔
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
		{
			judge = 2;
		}
		//进入爱车管理
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 &&MouseY <= 170 && press)
		{
			judge = 3;
		}
		//进入修改密码
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 &&MouseY <= 210 && press)
		{
			judge = 4;
		}
		//进入我的钱包
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
		{
			judge = 5;
		}
		//进入关于我们
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 &&MouseY <= 290 && press)
		{
			judge = 6;
		}
		//进入常见问题
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 &&MouseY <= 330 && press)
		{
			judge = 7;
		}
		//点击返回主页(505,10,590,40)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
		{
			judge = 8;
		}
		if(MouseX >=350  && MouseX <= 550 && MouseY >= 130 && MouseY <= 170 && press)
		{
			judge = 12;
		}
		if(MouseX >=350  && MouseX <= 550 && MouseY >= 220 && MouseY <= 260 && press)
		{
			judge = 9;
		}
		if(MouseX >=350  && MouseX <= 550 && MouseY >= 310 && MouseY <= 350 && press)
		{
			judge = 10;
		}
		if(MouseX >=400  && MouseX <= 500 && MouseY >= 380 && MouseY <= 420 && press)
		{
			judge = 11;
		}
		switch(judge)
		{
			case 1:
		    {
				return 1;
			}
			case 2:
		    {
				return 2;
			}
			case 3:
		    {
				return 3;
			}
			case 4:
		    {
				return 4;
			}
			case 5:
		    {
				return 5;
			}
			case 6:
		    {
				return 6;
			}
			case 7:
		    {
				return 7;
			}
			case 8:
			{
				return 8;
			}
			case 12://点击原密码框
			{
				clrmous(MouseX,MouseY);
				judge =putinoldcode(old_code,&MouseX,&MouseY);
				break;
			}
			case 9://点击新密码框
			{
				clrmous(MouseX,MouseY);
				judge=putinnewcode(new_code,&MouseX,&MouseY);
				break;
			}
			case 10://点击确认密码框
			{
				clrmous(MouseX,MouseY);
				judge=putinjudgecode(jud_code,&MouseX,&MouseY);
				break;
			}
			case 11://点击确认按钮
			{ 
				setfillstyle(1,LIGHTGRAY);
				if(strcmp(new_code,"\0")!=0)//新密码不为空
				{
					if(strcmp(old_code,(*person).code)==0)
					{
						if(strcmp(old_code,new_code)==0)
						{
							bar(300,360,550,379);
							puthz(300,360,"新旧密码相同",16,30,BLACK);
							judge=9;
						}
						else
						{
							if(strcmp(jud_code,new_code)!=0)
							{
								bar(300,360,550,379);
								puthz(300,360,"两次新密码不相同",16,30,BLACK);
								judge=10;
							}
							else
							{
								bar(300,360,550,379);
								strcpy(person->code,new_code);
								puthz(300,360,"修改成功",16,30,BLACK);
								changenewcode(&head,person);
								//saveinftolist(head,person);
								length = strlen(new_code);
	if ((fp = fopen("./t_file/user/accandco.txt", "r+")) == NULL)
	{
		closegraph();
		printf("Can't open accandco.txt");
		getchar();
		exit(1);
	}
    while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '#')
		{
			ch = fgetc(fp);
			for (p = CurrentAccounts;ch != '*';ch = fgetc(fp))
			{
				*p = ch;
				*(p + 1) = '\0';
				p++;
			}
			if (strcmp(CurrentAccounts, (*person).accounts) == 0)
			{
				p = new_code;
				fseek(fp, 0, SEEK_CUR);
				fputs(new_code, fp);
				for (i = 0;i < 10 - length;i++)
				putc(' ', fp);
			    fclose(fp);
				break;
			}
		}
	}
						 fclose(fp);
						delay(1000);
						return 4;
					   }

					}
				}
				else
				{bar(300,360,550,379);
					puthz(300,360,"原密码错误",16,30,BLACK);
					judge=8;
				}
			}
			else
			{bar(300,360,550,379);
				puthz(300,360,"新密码为空",16,30,BLACK);
				judge=9;
				//fclose(fp);
				//DestroyUList(&UL);
			}
			}
		}
	}
}
//绘制*个人中心——修改密码*界面的绘制
/****************************************
Function :drawchangecode(void)
Description:画修改密码界面
Attention:无
Return：无
***************************************/
void drawchangecode(void)
{
	drawuserself();
	setfillstyle(1,RED);
	bar(170,130+40,180,170+40);
	setfillstyle(1,LIGHTGRAY);
	bar(230,110,570,440);
	
	setfillstyle(1,WHITE);
	bar(400-50,130,550,170);//原密码框
	bar(400-50,210+10,550,250+10);//新密码框
	bar(400-50,290+20,550,330+20);//确认密码框
	
	setfillstyle(1,CYAN);
	bar(400,380,500,420);//确认框
	setcolor(BLACK);
	puthz(250,140,"原密码",16,25,BLACK);
	puthz(250,230,"新密码",16,25,BLACK);
	puthz(250,320,"确认密码",16,25,BLACK);
	puthz(420,390,"确认",16,35,WHITE);
	rectangle(400-50,130,550,170);
	rectangle(400-50,210+10,550,250+10);
	rectangle(400-50,290+20,550,330+20);
}
