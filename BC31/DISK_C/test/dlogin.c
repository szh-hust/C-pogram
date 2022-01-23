#include "common.h"
#include "dlogin.h"

/*绘制用户登录界面*/
/****************************************
Function : draw_userlogin(void)
Description:绘制用户登录界面
Attention:无
Return：无
***************************************/
void draw_userlogin(void)
{
	cleardevice();
	setbkcolor(BLACK);
	
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,660,480);
	drawlittlecar(0,130+30+30,LIGHTCYAN,13);
	setfillstyle(1,LIGHTGRAY);
	bar(280,100,520,350);
	puthz(10,10,"平安好车主",32,40,GREEN);
	puthz(130,50,"保险服务系统",32,40,GREEN);
	
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
	outtextxy(10,20+50+30+20,"H U S T");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(85,110+50+30+30,"A I A");
	//drawlittlecar(10,150,BROWN,10);
	setfillstyle(1,LIGHTGRAY);
	bar(280,100,520,350);
	setfillstyle(1,WHITE);
	puthz(300,130,"账号",16,25,WHITE);
	bar(300,150,500,180);
	//puthz(10,10,"H",16,16,BLUE);
	//puthz(100,10,"U",16,16,BLUE);
	puthz(300,195,"密码",16,25,WHITE);   
	bar(300,215,500,245);
	setcolor(BLACK);
	rectangle(300,150,500,180);
	rectangle(300,215,500,245);
	setfillstyle(1,CYAN);
	bar(300,270,500,300);
	puthz(370,278,"登录",16,50,WHITE);   
	//bar(410,270,500,300);
	//puthz(420,280,"注册",16,50,WHITE);
	puthz(300,310,"注册好车主账号",16,16,LIGHTBLUE);
	setcolor(LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,1);
	line(415,310,415+8,310+8);
	line(415+8,310+8,415,310+16);
	//(300,310,423,326);
	puthz(280,360,"使用好平安好车主 即表示您同",16,16,LIGHTGRAY);
	puthz(280,385,"意",16,16,LIGHTGRAY);
	puthz(301,385,"使用条款",16,16,CYAN);
	puthz(365,385,"和",16,16,LIGHTGRAY);
	puthz(382,385,"隐私政策" ,16,16,CYAN);
	setfillstyle(1,CYAN);
	Barshadow(540,430,640,470,CYAN,LIGHTGRAY);
	puthz(550,440,"退出",16,50,WHITE);
	Barshadow(0,430,90,470,CYAN,LIGHTGRAY);
	puthz(10,440,"返回首页",16,20,WHITE);
	drawhaochezhu(540,10,BLACK,LIGHTRED,60);

}


/*绘制管理员登录界面*/
/****************************************
Function : draw_managerlogin(void)
Description:绘制管理员登录界面
Attention:无
Return：无
***************************************/
void draw_managerlogin(void)
{
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	drawlittlecar(0,130+30+30,LIGHTBLUE,13);
	setfillstyle(1,LIGHTGRAY);
	bar(280,100,520,350);
	puthz(10,10,"平安好车主",32,40,GREEN);
	puthz(130,50,"保险服务系统",32,40,GREEN);
	
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
	outtextxy(10,20+50+30+20,"H U S T");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(85,110+50+30+30,"A I A");
	setfillstyle(1,WHITE);
	puthz(300,130,"账号",16,50,WHITE);
	bar(300,150,500,180);
	
	puthz(300,195,"密码",16,50,WHITE);   
	bar(300,215,500,245);
	
	setfillstyle(1,CYAN);
	bar(300,270,500,305);
	puthz(350,280 ,"登录",16,50,WHITE);   

	   
	setfillstyle(1,CYAN);
	Barshadow(540,430,640,470,CYAN,LIGHTGRAY);
	puthz(555,440,"退出",16,30,WHITE);
	Barshadow(0,430,90,470,CYAN,LIGHTGRAY);
	puthz(10,440,"返回",16,20,WHITE);
	setcolor(BLACK);
	rectangle(300,150,500,180);
	rectangle(300,215,500,245);
	drawhaochezhu(540,10,BLACK,LIGHTRED,60);
}

/*绘制用户注册界面*/
/****************************************
Function : draw_register(void)
Description:绘制用户注册界面
Attention:无
Return：无
***************************************/
void draw_register(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,660,480);
	setfillstyle(1,LIGHTGRAY);
	bar(280,100,520,380);
	drawlittlecar(0,130+30+30,LIGHTBLUE,13);
	setfillstyle(1,LIGHTGRAY);
	bar(280,100,520,350);
	puthz(10,10,"平安好车主",32,40,GREEN);
	puthz(130,50,"保险服务系统",32,40,GREEN);
	
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
	outtextxy(10,20+50+30+20,"H U S T");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(85,110+50+30+30,"A I A");
	setfillstyle(1,WHITE);
	puthz(300,130,"账号",16,30,BLACK);
	bar(300,150,500,180);
	
	puthz(300,195,"密码",16,30,BLACK);   
	bar(300,215,500,245);
	
	puthz(300,255,"确认密码",16,30,BLACK);
	bar(300,275,500,305);
    	setcolor(BLACK);
		rectangle(300,150,500,180);
		rectangle(300,215,500,245);
		rectangle(300,275,500,305);
	setfillstyle(1,CYAN);	
	bar(300,325,500,355);
	puthz(370,335,"确认",16,50,WHITE);
	setfillstyle(1,CYAN);
	Barshadow(540,430,640,470,CYAN,LIGHTGRAY);
	puthz(550,440,"退出",16,50,WHITE);
	Barshadow(0,430,90,470,CYAN,LIGHTGRAY);
	puthz(10,440,"返回登录",16,20,WHITE);
	puthz(280,385,"注册平安好车主账号表示你",16,16,LIGHTGRAY);
	puthz(280,410,"同意",16,16,LIGHTGRAY);
	puthz(312,410,"最终用户协议",16,16,CYAN);
}
