#include "common.h"
#include "manage.h"
#include "dlogin.h"
#include "lpgl.h"
/*绘制管理员界面*/
void draw_manage_page()
{
	cleardevice();
	setbkcolor(BLACK);
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	
	Drawbeautiful(0,0,1);
	setcolor(CYAN);
	setlinestyle(0, 0, 1);
	line(24,380,190,380);
	line(190,380,190,420);
	line(190,420,150,420);
	line(150,420,150,400);
	line(150,400,220,400);
	line(220,400,220,440);
	line(220,440,150,440);
	line(150,440,150,468);
	
	line(24,380-4,190+4,380-4);
	line(190+4,380-4,190+4,420+4);
	line(190+4,420+4,150-4,420+4);
	line(150-4,420+4,150-4,400-4);
	line(150-4,400-4,220+4,400-4);
	line(220+4,400-4,220+4,440+4);
	line(220+4,440+4,150+4,440+4);
	line(150+4,440+4,150+4,468);
	
	line(640-24,380,640-190,380);
	line(640-190,380,640-190,420);
	line(640-190,420,640-150,420);
	line(640-150,420,640-150,400);
	line(640-150,400,640-220,400);
	line(640-220,400,640-220,440);
	line(640-220,440,640-150,440);
	line(640-150,440,640-150,468);
	
	line(640-24,380-4,640-(190+4),380-4);
	line(640-(190+4),380-4,640-(190+4),420+4);
	line(640-(190+4),420+4,640-(150-4),420+4);
	line(640-(150-4),420+4,640-(150-4),400-4);
	line(640-(150-4),400-4,640-(220+4),400-4);
	line(640-(220+4),400-4,640-(220+4),440+4);
	line(640-(220+4),440+4,640-(150+4),440+4);
	line(640-(150+4),440+4,640-(150+4),468);
	
	line(24,480-380,190,480-380);
	line(190,480-380,190,480-420);
	line(190,480-420,150,480-420);
	line(150,480-420,150,480-400);
	line(150,480-400,220,480-400);
	line(220,480-400,220,480-440);
	line(220,480-440,150,480-440);
	line(150,480-440,150,480-468);
	
	line(24,480-(380-4),190+4,480-(380-4));
	line(190+4,480-(380-4),190+4,480-(420+4));
	line(190+4,480-(420+4),150-4,480-(420+4));
	line(150-4,480-(420+4),150-4,480-(400-4));
	line(150-4,480-(400-4),220+4,480-(400-4));
	line(220+4,480-(400-4),220+4,480-(440+4));
	line(220+4,480-(440+4),150+4,480-(440+4));
	line(150+4,480-(440+4),150+4,480-468);
	
	line(640-24,480-380,640-190,480-380);
	line(640-190,480-380,640-190,480-420);
	line(640-190,480-420,640-150,480-420);
	line(640-150,480-420,640-150,480-400);
	line(640-150,480-400,640-220,480-400);
	line(640-220,480-400,640-220,480-440);
	line(640-220,480-440,640-150,480-440);
	line(640-150,480-440,640-150,480-468);
	
	line(640-24,480-(380-4),640-(190+4),480-(380-4));
	line(640-(190+4),480-(380-4),640-(190+4),480-(420+4));
	line(640-(190+4),480-(420+4),640-(150-4),480-(420+4));
	line(640-(150-4),480-(420+4),640-(150-4),480-(400-4));
	line(640-(150-4),480-(400-4),640-(220+4),480-(400-4));
	line(640-(220+4),480-(400-4),640-(220+4),480-(440+4));
	line(640-(220+4),480-(440+4),640-(150+4),480-(440+4));
	line(640-(150+4),480-(440+4),640-(150+4),480-468);
	
	setfillstyle(1,CYAN);
	bar(220,220,420,270);
	bar(220,300,420,350);
	//bar(220,380,420,430);
	puthz(230,230,"用户管理",32,40,WHITE);
	puthz(230,310,"理赔管理",32,40,WHITE);
	//puthz(230,390,"服务管理",32,40,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(540,440,640,480);
	puthz(550,450,"退出",16,50,WHITE);
	bar(0,440,100,480);
	puthz(10,450,"返回",16,50,WHITE);
	puthz(220,20,"管理界面",32,50,BLACK);
	drawlittlecar(200,30,7,10);
}
int manage_page()
{
	int flag=0;
	int judge =0;
	int sum=0;
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	clrmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		//点击返回按钮
		if(MouseX>=0  &&MouseX<=100&&MouseY>=440&&MouseY<=480&&press) 
			return 1;
		//点击退出按钮
		if(MouseX>=540&&MouseX<=640&&MouseY>=440&&MouseY<=480&&press)
			return 4;
		if(MouseX>=220&&MouseX<=420&&MouseY>=220&&MouseY<=270&&press)
			judge=1;
		if(MouseX>=220&&MouseX<=420&&MouseY>=220&&MouseY<=270&&flag!=1)
		{
			flag=1;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			 bar(223,351,423,354);
	        bar(421,303,424,354);
			setfillstyle(1,LIGHTGRAY);
			bar(223,271,423,274);
			bar(421,223,424,274);
			save_bk_mou(MouseX,MouseY);
		}
		if(MouseX>=220&&MouseX<=420&&MouseY>=300&&MouseY<=350&&press)
			judge=2;
		if(MouseX>=220&&MouseX<=420&&MouseY>=300&&MouseY<=350&&flag!=2)
		{
			flag=2;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(223,271,423,274);
			bar(421,223,424,274);
			setfillstyle(1,LIGHTGRAY);
	        bar(223,351,423,354);
	        bar(421,303,424,354);
			save_bk_mou(MouseX,MouseY);
		}
		
		if(((MouseX<=220||MouseX>=420)&&(MouseY<=220||MouseY>=270))&&((MouseX<=220||MouseX>=420)&&(MouseY<=300||MouseY>=350))&&flag!=0)
		{
			flag=0;
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			bar(223,271,423,274);
			bar(421,223,424,274);
			 bar(223,351,423,354);
	        bar(421,303,424,354);
			save_bk_mou(MouseX,MouseY);
		}
		switch(judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY);
				draw_manage_page();
				judge = 0;
				break;
			}
			case 1:
			{
				sum=drawyhguanli(1);
				judge=yhguanli(sum);
				break;
			}
			case 2:
			{
				clrmous(MouseX,MouseY);
				delay(100);
				drawlpguanli();
				judge = lpguanli();
				break;
			}
		
		}
	}
}

int dqyh(int judge)
{
	char accounts[11]={'\0'};
	char mima[11]={'\0'};
	int i=0;
	int j=0;
	int k=0;
	int flag=1;
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p=NULL;   //指向需要接收字符的地址的指针变量
	if ((fp = fopen("./t_file/user/accandco.txt","r+")) == NULL)//以读写的方式打开
    {
	  closegraph();
	  printf("Can't open accandco.txt");
	  //getchar();
	  exit(1);
    }
	p=accounts;
	while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	{
		cha=fgetc(fp);//读取一个字符
		if(cha=='#')//'/'默认为账户名的开始
		{
			j++;
			if((judge-1)*6<=j&&judge*6>j)
			{
		    outtextxy(60,150+40*i,accounts);
			outtextxy(260,150+40*i,mima);
			puthz(500,150+40*i,"正常",16,20,BLUE);
			i++;
			}
			for(k=0;k<11;k++)
	    	{
				 accounts[k]='\0';
			}
			flag=1;
			p=accounts;
		}
	  else if(cha=='*')
		{
			for(k=0;k<11;k++)
	    	{
				 mima[k]='\0';
			}
			flag=2;
			p=mima;
		}
		else 
		{
			*p=cha;
		    p++;
		}
	}
	fclose(fp);
	return j;
}
/*绘制用户管理界面*/
int drawyhguanli(int flag)
{
	int sum=0;
	cleardevice();
	setbkcolor(BLACK);
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	drawlittlecar(0,20,7,30);
	setcolor(BLACK);
	sum=dqyh(flag);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,60);
	puthz(220,10,"用户管理",32,50,WHITE);
	
	setfillstyle(1,CYAN);
	bar(100-50,100,240-50,140);
	bar(300-50,100,440-50,140);
	bar(500-50,100,640-50,140);
	puthz(110-40,110,"用户名",16,20,WHITE);
	puthz(310-20,110,"密码",16,30,WHITE);
	puthz(510-30,110,"账号状态",16,20,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(540,440,640,480);
	bar(0,440,100,480);
	puthz(550,450,"下一页",16,30,WHITE);
	puthz(10,450,"上一页",16,30,WHITE);
	setfillstyle(1,CYAN);
	bar(540,0,640,40);
	puthz(550,10,"返回",16,50,WHITE);
	return sum;
}

/*用户管理界面*/
int yhguanli(int sum)
{
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	int s=0;
	int flag=1;
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	if(MouseX>=540&&MouseX<=640&&MouseY>=440&&MouseY<=480&&press)
	{
		delay(100);
		if(flag>=2)
		{	
		flag--;
		s=drawyhguanli(flag);
		}
		else
		{
			setfillstyle(1,WHITE);
			bar(260,450,420,470);
			puthz(260,450,"已经是第一页了！",16,20,RED);
		}
	}
	if(MouseX>=0&&MouseX<=100&&MouseY>=440&&MouseY<=480&&press)
	{
		delay(100);
		if(flag<sum/6)
		{	
		flag++;
		s=drawyhguanli(flag);
		}
		else
		{
			setfillstyle(1,WHITE);
			bar(260,450,420,470);
			puthz(260,450,"没有下一页了！",16,20,RED);
		}
	}
	if(MouseX>=540&&MouseX<=640&&MouseY>=0&&MouseY<=40&&press)
	{
		delay(100);
		clrmous(MouseX,MouseY);
		draw_manage_page();
		delay(100);
		return 0;
	}
	}
}
