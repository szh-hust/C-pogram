#include"draw.h"
#include "common.h"
#include "time.h"

/****************************************
Function : queren(char *item,int x,int y,int sizehanzi,int jianju,int returnnum)
Description:确认框函数
Attention:无
Return：上一个界面的judge值
***************************************/
int queren(char *item,int x,int y,int sizehanzi,int jianju,int returnnum)
{
	int press;
	int MouseX,MouseY;
	
	setfillstyle(1,LIGHTGRAY);
	bar(155,115,485,365);
	setfillstyle(1,WHITE);
	bar(160,120,480,360);//320*240
	Drawbeautiful(160,120,0.5);
	puthz(x,y,item, sizehanzi,jianju,BLACK);
	setfillstyle(1,CYAN);
	bar(260,300,380,340);
	puthz(300,310,"好的",16,25,WHITE);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=260 && MouseX <= 380 && MouseY >= 300 && MouseY <= 360 && press)
			return returnnum;
	}
}
/****************************************
Function : jueding(char *item,int returnnum)
Description:决定框函数
Attention:无
Return：上一个界面的judge值
***************************************/
int jueding(char *item,int returnnum)
{
	int press;
	int MouseX,MouseY;
	
	setfillstyle(1,LIGHTGRAY);
	bar(155,115,485,365);
	setfillstyle(1,WHITE);
	bar(160,120,480,360);//320*240
	Drawbeautiful(160,120,0.5);
	puthz(250,170,item,32,35,GREEN);
	setfillstyle(1,CYAN);
	bar(210,280,270,320);
	bar(370,280,430,320);
	puthz(230,290,"是",16,16,WHITE);
	puthz(390,290,"否",16,20,WHITE);
	delay(100);
	clrmous(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=370 && MouseX <= 430 && MouseY >=280 && MouseY <= 320 && press)
			return -1;	
		if(MouseX >=210 && MouseX <= 270 && MouseY >=280 && MouseY <= 320 && press)
			return returnnum;
	}
}
/*钝型按钮
x，y表示矩形中心坐标
*/
/****************************************
Function : button(int x,int y,int length,int wide,int color,int fillcolor,int i)
Description:钝型按钮
Attention:无
Return：无
***************************************/
void  button(int x,int y,int length,int wide,int color,int fillcolor,int i)
{
	setcolor(color);
	line(x-length/2,y-wide/2,x+length/2,y-wide/2);
	line(x-length/2,y+wide/2,x+length/2,y+wide/2);
	ellipse(x-length/2,y,90,270,wide/2,wide/2);
	ellipse(x+length/2,y,270,90,wide/2,wide/2);
	if(i==1)
	{
		setfillstyle(1,fillcolor);
		floodfill(x,y,color);
	}
}
/*
作用：矩形加阴影
	Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
					对角坐标               矩形颜色                  阴影颜色
调用：无
返回：无
*/
/****************************************
Function : Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
Description:矩形加阴影
Attention:无
Return：无
***************************************/
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
{
	setfillstyle(1,shacolor);
	bar( x1+5, y1+5, x2+5, y2+5);
	setfillstyle(1,precolor);
	bar( x1, y1, x2, y2);
	return;
}
int putbmp(int x, int y, char *s)
{
    FILE *fp;
    long begin, w, h;
    unsigned char k;
    unsigned char color[256], R, G, B;
    unsigned int i, j, bit;
    if ((fp = fopen(s, "rb")) == NULL)
    {
        printf("not open");
        return 1;
    }
    fseek(fp, 10l, 0);
    fread(&begin, 4, 1, fp);
    fseek(fp, 18l, 0);
    fread(&w, 4, 1, fp);
    fread(&h, 4, 1, fp);
    fseek(fp, 28l, 0);
    fread(&bit, 2, 1, fp);
    if (bit != 8)
    {
        fclose(fp);
        printf("bit:%d,not 8", bit);
        return 2;
    }
    fseek(fp, 54l, 0);
    for (i = 0; i < 256; i++)
    {
        fread(&B, 1, 1, fp);
        fread(&G, 1, 1, fp);
        fread(&R, 1, 1, fp);
        if (R < 42)
        {

            color[i] = (B > 84) + 2 * (G > 84);
        }
        else if (R < 126)
        {
            color[i] = 8 + (B > 168) + 2 * (G > 168);
        }
        else if (R < 210)
        {
            color[i] = 4 + (B > 84) + 2 * (G > 60);
        }
        else
        {
            color[i] = 12 + (B > 168) + 2 * (G > 168);
        }

        fseek(fp, 1, 1);
    }
    for (i = 0; i < h; i++)
    {

        fseek(fp, begin + (w + 3) / 4 * i * 4, 0);

        for (j = 0; j < w; j++)
        {

            fread(&k, 1, 1, fp);
            putpixel(x + j, y + h - i - 1, color[k]);
        }
    }
    fclose(fp);
    return 0;
}
/****************************************
Function : sure(void)
Description:反馈确认框函数
Attention:无
Return：上一个界面的judge值
***************************************/
int sure(void)
{
	int judge = 0;
	int press,MouseX,MouseY;
	int driver =VGA;
	int mode = VGAHI;
	//clrmous(MouseX,MouseY);
	setfillstyle(1,LIGHTGRAY);
	bar(170,130,470,360);
	setfillstyle(1,WHITE);
	bar(180,140,460,350);
	puthz(215,160,"感谢您的反馈，我们会在",16,20,BLACK);
	puthz(215,180,"第一时间联系您！",16,20,BLACK);
	setfillstyle(1,CYAN);
	bar(250,290,390,330);
	puthz(270,300,"确认",16,50,WHITE);
	
	delay(100);
	save_bk_mou(MouseX,MouseY);

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=250  && MouseX <= 390 && MouseY >= 290 && MouseY <= 330 && press)
			return 2;
	}
}
/****************************************
Function :Drawbeautiful(int x,int y,double size) 
Description:画界面边框
Attention:无
Return：无
***************************************/

void Drawbeautiful(int x,int y,double size)							//界面边框
{
	setcolor(CYAN);
	setlinestyle(0, 0, 1);
	line(x+40*size, y+8*size, x+600*size, y+8*size);
	line(x+600*size, y+8*size, x+600*size, y+48*size);
	line(x+600*size, y+48*size,x+ 604*size, y+48*size);
	line(x+604*size, y+8*size, x+620*size, y+8*size);
	line(x+604*size, y+8*size, x+604*size, y+48*size);
	line(x+620*size,y+ 8*size, x+620*size, y+24*size);
	line(x+620*size,y+ 24*size, x+588*size, y+24*size);
	line(x+588*size,y+ 24*size, x+588*size, y+32*size);
	line(x+588*size,y+ 32*size, x+620*size, y+32*size);
	line(x+620*size, y+32*size, x+620*size, y+448*size);
	line(x+620*size, y+448*size,x+ 588*size, y+448*size);
	line(x+588*size, y+448*size,x+ 588*size, y+ 456*size);
	line(x+588*size,y+ 456*size, x+620*size, y+456*size);
	line(x+620*size,y+ 456*size, x+620*size, y+472*size);
	line(x+620*size,y+ 472*size, x+604*size, y+472*size);
	line(x+604*size, y+472*size, x+604*size, y+432*size);
	line(x+604*size,y+ 432*size, x+600*size, y+432*size);
	line(x+600*size, y+432*size, x+600*size, y+472*size);
	line(x+600*size, y+472*size, x+40*size, y+472*size);
	line(x+40*size, y+472*size, x+40*size, y+432*size);
	line(x+40*size, y+432*size, x+36*size, y+432*size);
	line(x+36*size, y+432*size, x+36*size, y+472*size);
	line(x+36*size, y+472*size, x+20*size, y+472*size);
	line(x+20*size,y+ 472*size, x+20*size, y+456*size);
	line(x+20*size,y+ 456*size,x+ 52*size, y+456*size);
	line(x+52*size,y+ 456*size,x+ 52*size, y+448*size);
	line(x+52*size,y+ 448*size, x+20*size, y+448*size);
	line(x+20*size,y+ 448*size, x+20*size, y+32*size);
	line(x+20*size,y+ 32*size, x+52*size, y+32*size);
	line(x+52*size,y+ 32*size,x+ 52*size, y+24*size);
	line(x+52*size,y+ 24*size, x+20*size, y+24*size);
	line(x+20*size,y+ 24*size, x+20*size, y+8*size);
	line(x+20*size,y+ 8*size,x+ 36*size, y+8*size);
	line(x+36*size,y+8*size, x+36*size, y+48*size);
	line(x+36*size, y+48*size,x+ 40*size, y+48*size);
	line(x+40*size, y+48*size,x+ 40*size, y+8*size);
	line(x+44*size, y+12*size,x+ 596*size, y+12*size);
	line(x+596*size, y+12*size,x+ 596*size, y+52*size);
	line(x+596*size, y+52*size, x+608*size, y+52*size);
	line(x+608*size, y+52*size, x+608*size, y+12*size);
	line(x+608*size, y+12*size, x+616*size, y+12*size);
	line(x+616*size, y+12*size, x+616*size, y+20*size);
	line(x+616*size, y+20*size, x+584*size, y+20*size);
	line(x+584*size,y+ 20*size, x+584*size, y+36*size);
	line(x+584*size, y+36*size, x+616*size, y+36*size);
	line(x+616*size,y+ 36*size, x+616*size, y+444*size);
	line(x+616*size,y+ 444*size,x+ 584*size, y+444*size);
	line(x+584*size, y+444*size, x+584*size, y+460*size);
	line(x+584*size, y+460*size, x+616*size, y+460*size);
	line(x+616*size, y+460*size, x+616*size, y+468*size);
	line(x+616*size, y+468*size, x+608*size, y+468*size);
	line(x+608*size,y+ 468*size, x+608*size, y+428*size);
	line(x+608*size, y+428*size, x+596*size, y+428*size);
	line(x+596*size, y+428*size, x+596*size, y+468*size);
	line(x+596*size,y+ 468*size,x+ 44*size, y+468*size);
	line(x+44*size, y+468*size, x+44*size, y+428*size);
	line(x+44*size, y+428*size, x+32*size, y+428*size);
	line(x+32*size, y+428*size, x+32*size, y+468*size);
	line(x+32*size, y+468*size, x+24*size, y+468*size);
	line(x+24*size, y+468*size, x+24*size, y+460*size);
	line(x+24*size, y+460*size, x+56*size, y+460*size);
	line(x+56*size, y+460*size,x+ 56*size, y+444*size);
	line(x+56*size, y+444*size,x+ 24*size, y+444*size);
	line(x+24*size, y+444*size,x+ 24*size, y+36*size);
	line(x+24*size, y+36*size,x+ 56*size, y+36*size);
	line(x+56*size, y+36*size,x+ 56*size,y+ 20*size);
	line(x+56*size, y+20*size,x+ 24*size, y+20*size);
	line(x+24*size, y+20*size,x+ 24*size, y+12*size);
	line(x+24*size, y+12*size,x+ 32*size, y+12*size);
	line(x+32*size, y+12*size,x+ 32*size, y+52*size);
	line(x+32*size, y+52*size,x+ 44*size, y+52*size);
	line(x+44*size, y+52*size,x+ 44*size, y+12*size);

}
/****************************************
Function :Drawjiazaitiao() 
Description:画加载条函数
Attention:无
Return：无
***************************************/
void Drawjiazaitiao()
{
	int x,y,i,t;
	x=70;
	y=237;
	i=0;
	cleardevice();
	setbkcolor(WHITE);
	Drawbeautiful(0,0,1);
	setfillstyle(1, DARKGRAY);
	bar(66,234,574,246);
	setfillstyle(1, WHITE);
    bar(70,237,570,243);
	puthz(130,70,"欢迎来到平安好车主保险服务系统！！！",16,16,RED);
	puthz(200,100,"我们将会给您畅快的用车体验！！！",16,16,RED);
	//puthz(530,400,"    ",16,16,DARKGRAY);
	//puthz(530,430,"",16,16,DARKGRAY);
	//puthz(480,400,"",16,16,DARKGRAY);
	for(i=0;x<=565;i++)
	{
		if(i%5==0)
		{
			t=(i/5)%5;
			switch(t)
			{
				case 0:setfillstyle(1, LIGHTCYAN);
				       break;
				case 1:setfillstyle(1, CYAN);
				       break;
				case 2:setfillstyle(1, LIGHTBLUE);
				       break;
				case 3:setfillstyle(1, CYAN);
				       break;
				case 4:setfillstyle(1, LIGHTGREEN);
				       break;
			}
			bar(x,y,x+5,y+6);
			x+=5;
		}
		delay(5);
	}
	delay(50);
}
/****************************************
Function : drawlittlecar(int x,int y,int color,double size)
Description:画小车函数
Attention:无
Return：无
***************************************/
void drawlittlecar(int x,int y,int color,double size)
{
	setlinestyle(SOLID_LINE,0,1);
	setcolor(color);
	ellipse(x+12*size,y+8*size,10,170,6*size,5*size);
	ellipse(x+11.5*size,y+8*size,90,180,4*size,3*size);
	ellipse(x+12.5*size,y+8*size,0,90,4*size,3*size);
	line(x+7.5*size,y+8*size,x+11.5*size,y+8*size);
	line(x+12.5*size,y+8*size,x+16.5*size,y+8*size);
	line(x+11.5*size,y+5*size,x+11.5*size,y+8*size);
	line(x+12.5*size,y+5*size,x+12.5*size,y+8*size);
	line(x+9.75*size,y+8.5*size,x+10.75*size,y+8.5*size);
	line(x+9.75*size,y+9*size,x+10.75*size,y+9*size);
	ellipse(x+9.75*size,y+8.75*size,90,270,0.25*size,0.25*size);
	ellipse(x+10.75*size,y+8.75*size,270,90,0.25*size,0.25*size);
	line(x+14.75*size,y+8.5*size,x+15.75*size,y+8.5*size);
	line(x+14.75*size,y+9*size,x+15.75*size,y+9*size);
	ellipse(x+14.75*size,y+8.75*size,90,270,0.25*size,0.25*size);
	ellipse(x+15.75*size,y+8.75*size,270,90,0.25*size,0.25*size);
	ellipse(x+9.8*size,y+13*size,117,154.8,8*size,6.5*size);
	ellipse(x+2.5*size,y+10.78*size,0,360,0.25*size,0.5*size);
	line(x+2.5*size,y+11.3*size,x+3.25*size,y+11.3*size);
	line(x+2.5*size,y+12.8*size,x+3.25*size,y+12.8*size);
	line(x+3.25*size,y+11.3*size,x+3.25*size,y+12.8*size);
	ellipse(x+2.65*size,y+12.05*size,107,253,0.5*size,0.75*size);
	line(x+3.25*size,y+12.8*size,x+5.25*size,y+12.8*size);
	circle(x+7.25*size,y+12.8*size,2*size);
	circle(x+7.25*size,y+12.8*size,0.8*size);
	line(x+9.25*size,y+12.8*size,x+13.25*size,y+12.8*size);
	circle(x+15.25*size,y+12.8*size,2*size);
	circle(x+15.25*size,y+12.8*size,0.8*size);
	line(x+17.25*size,y+12.8*size,x+19.25*size,y+12.8*size);
	ellipse(x+19.25*size,y+12.55*size,180,270,0.25*size,0.25*size);
	line(x+19.25*size,y+12.8*size,x+19.75*size,y+12.8*size);
	ellipse(x+19.75*size,y+12.55*size,270,360,0.25*size,0.25*size);
	line(x+19*size,y+12.55*size,x+19*size,y+11.55*size);
	ellipse(x+19.25*size,y+11.55*size,90,180,0.25*size,0.25*size);
	line(x+20*size,y+12.55*size,x+20*size,y+11.55*size);
	ellipse(x+19.75*size,y+11.55*size,0,90,0.25*size,0.25*size);
	line(x+19.25*size,y+11.3*size,x+19.75*size,y+11.3*size);
	ellipse(x+11.6*size,y+12.65*size,8.02,38,size*8,size*9);
}
/*n表示随机数位数*/
/****************************************
Function : suijishu(int n)
Description:生成随机数位函数
Attention:无
Return：生成的随机数值
***************************************/
int  suijishu(int n)
{
	int i = 1;
	int k = 1,j = 0;
	int yz = 0;
	//char yz_str[n+1];
	for(i=1;i<n;i++)
	{
		k = k*10;
	}
	j = k*9;
	srand(time(0));//必要的，rand伪随机数
    yz=rand()%(j)+k;
	//itoa(yz,yz_str,10);
	return yz;
}
/****************************************
Function : drawhaochezhu(int x,int y,int color,int fillcolor,double size)
Description:画平安好车主标志
Attention:无
Return：无
***************************************/
void drawhaochezhu(int x,int y,int color,int fillcolor,double size)
{
	setlinestyle(SOLID_LINE,0,1);
	setcolor(color);
	setfillstyle(1,color);
	line(x+size/5,y,x+size*4/5,y);
	line(x+size/5,y+size,x+size*4/5,y+size);
	line(x,y+size/5,x,y+size*4/5);
	line(x+size,y+size/5,x+size,y+size*4/5);
	ellipse(x+size/5,y+size/5,90,180,size/5,size/5);
	ellipse(x+size*4/5,y+size/5,0,90,size/5,size/5);
	ellipse(x+size/5,y+size*4/5,180,270,size/5,size/5);
	ellipse(x+size*4/5,y+size*4/5,270,360,size/5,size/5);
	
	ellipse(x+size/2,y+size/2,0,180,size*30/100,size*30/100);
	line(x+size*20/100,y+size/2,x+size*22/100,y+50*size/100+10*size/100);
	line(x+size-20*size/100,y+size/2,x+size/2+size*28/100,y+60*size/100);
	
	
	
	line(x+size/2,y+90*size/100,x+size*22/100,y+50*size/100+10*size/100);
	line(x+size/2,y+90*size/100,x+size/2+size*28/100,y+60*size/100);
	
	line(x+size/2,y+95*size/100,x,y+75*size/100);
	line(x+size/2,y+95*size/100,x+size,y+75*size/100);
	
	setfillstyle(1,fillcolor);
	floodfill(x+size*23/100,y+50*size/100+49*size/100,color);
	floodfill(x+size/2,y+size/2,color);
	drawlittlecar(x+size*27/100,y+size/100+size*25/100,WHITE,size/100*2);
}
/****************************************
Function : bingo(int x,int y,char *text)
Description:确认框函数
Attention:无
Return：上一个界面的judge值
***************************************/
int bingo(int x,int y,char *text)
{
	int i=0;
	int MouseX,MouseY,press;
	setfillstyle(1,LIGHTGRAY);
	bar(155,115,485,365);
	setfillstyle(1,WHITE);
	bar(160,120,480,360);
	setfillstyle(1,CYAN);
	bar(465,120,480,135);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(WHITE);
	line(466,121,479,134);
	line(466,134,479,121);
	
	setlinestyle(SOLID_LINE,0,3);
	setcolor(CYAN);
	for(i=0;i<6;i++)
	{
		ellipse(320,200,i*60,(i+1)*60,60,60);
		delay(200);
	}
	line(270,200,280,190);
	delay(200);
	line(280,190,320,240);
	delay(200);
	line(320,240,350,160);
	puthz(x,y,text,32,50,BLACK);
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (MouseX >= 465 && MouseX <= 480 && MouseY >= 120&& MouseY <= 135 && press) 
		{
			return -2;
		}
	
	}
}
/****************************************
Function : drawhust(int x,int y,int color,int size)
Description:画hust
Attention:无
Return：无
***************************************/
void drawhust(int x,int y,int color,int size)
{
	int i=0;
setlinestyle(SOLID_LINE,0,1);
setcolor(color);
setfillstyle(1,color);
/*rectangle(x+14*size,y+60*size,x+30*size,y+100*size);
rectangle(x+37*size,y+60*size,x+52*size,y+100*size);
rectangle(x+30*size,y+86*size,x+37*size,y+90*size);
rectangle(x+64*size,y+60*size,x+79*size,y+100*size);
rectangle(x+87*size,y+60*size,x+102*size,y+100*size);
rectangle(x+79*size,y+96*size,x+87*size,y+100*size);*/
line(x+14*size,y+60*size,x+30*size,y+60*size);
line(x+30*size,y+60*size,x+23*size,y+86*size);
line(x+23*size,y+86*size,x+29*size,y+86*size);
line(x+29*size,y+86*size,x+37*size,y+60*size);
line(x+37*size,y+60*size,x+52*size,y+60*size);
line(x+52*size,y+60*size,x+40*size,y+100*size);
line(x+40*size,y+100*size,x+25*size,y+100*size);
line(x+25*size,y+100*size,x+27*size,y+89*size);
line(x+27*size,y+89*size,x+22*size,y+89*size);
line(x+22*size,y+89*size,x+17*size,y+100*size);
line(x+17*size,y+100*size,x+3*size,y+100*size);
line(x+3*size,y+100*size,x+14*size,y+60*size);

line(x+64*size,y+60*size,x+79*size,y+60*size);
line(x+79*size,y+60*size,x+69*size,y+97*size);
line(x+69*size,y+97*size,x+76*size,y+97*size);
line(x+76*size,y+97*size,x+87*size,y+60*size);
line(x+87*size,y+60*size,x+102*size,y+60*size);
line(x+102*size,y+60*size,x+90*size,y+100*size);
line(x+90*size,y+100*size,x+53*size,y+100*size);
line(x+53*size,y+100*size,x+64*size,y+60*size);


line(x+4*size,y+115*size,x+16*size,y+108*size);
line(x+16*size,y+108*size,x+91*size,y+108*size);
line(x+91*size,y+108*size,x+91*size,y+107*size);
line(x+91*size,y+107*size,x+96*size,y+107*size);
line(x+96*size,y+107*size,x+96*size,y+106*size);
line(x+96*size,y+106*size,x+101*size,y+106*size);
line(x+101*size,y+106*size,x+101*size,y+105*size);
line(x+101*size,y+105*size,x+104*size,y+105*size);
line(x+104*size,y+105*size,x+104*size,y+104*size);
line(x+104*size,y+104*size,x+108*size,y+104*size);
line(x+108*size,y+104*size,x+108*size,y+103*size);
line(x+108*size,y+103*size,x+110*size,y+103*size);
line(x+110*size,y+103*size,x+110*size,y+102*size);
line(x+110*size,y+102*size,x+112*size,y+102*size);
line(x+112*size,y+102*size,x+112*size,y+101*size);
line(x+112*size,y+101*size,x+114*size,y+101*size);
line(x+114*size,y+101*size,x+114*size,y+100*size);
line(x+114*size,y+100*size,x+116*size,y+100*size);
line(x+116*size,y+100*size,x+116*size,y+99*size);
line(x+116*size,y+99*size,x+117*size,y+99*size);
line(x+117*size,y+99*size,x+117*size,y+98*size);
line(x+117*size,y+98*size,x+119*size,y+98*size);
line(x+119*size,y+98*size,x+119*size,y+97*size);
line(x+119*size,y+97*size,x+120*size,y+97*size);
line(x+120*size,y+97*size,x+120*size,y+96*size);
line(x+120*size,y+96*size,x+121*size,y+96*size);
line(x+121*size,y+96*size,x+121*size,y+95*size);
line(x+121*size,y+95*size,x+122*size,y+95*size);
line(x+122*size,y+95*size,x+122*size,y+94*size);
line(x+122*size,y+94*size,x+123*size,y+94*size);
line(x+123*size,y+94*size,x+123*size,y+93*size);
line(x+123*size,y+93*size,x+124*size,y+93*size);
line(x+124*size,y+93*size,x+124*size,y+92*size);
line(x+124*size,y+92*size,x+125*size,y+92*size);
line(x+125*size,y+92*size,x+125*size,y+90*size);
line(x+125*size,y+90*size,x+126*size,y+90*size);
line(x+126*size,y+90*size,x+126*size,y+89*size);
line(x+126*size,y+89*size,x+127*size,y+89*size);
line(x+127*size,y+89*size,x+127*size,y+87*size);
line(x+127*size,y+87*size,x+128*size,y+87*size);
line(x+128*size,y+87*size,x+128*size,y+85*size);
line(x+128*size,y+85*size,x+129*size,y+85*size);
line(x+129*size,y+85*size,x+129*size,y+82*size);
line(x+129*size,y+82*size,x+130*size,y+82*size);
line(x+130*size,y+82*size,x+130*size,y+70*size);
line(x+130*size,y+79*size,x+131*size,y+79*size);
line(x+131*size,y+79*size,x+131*size,y+73*size);
line(x+131*size,y+73*size,x+130*size,y+73*size);
line(x+130*size,y+73*size,x+130*size,y+70*size);
line(x+130*size,y+70*size,x+129*size,y+70*size);
line(x+129*size,y+70*size,x+129*size,y+68*size);
line(x+129*size,y+68*size,x+128*size,y+68*size);
line(x+128*size,y+68*size,x+128*size,y+67*size);
line(x+128*size,y+67*size,x+127*size,y+67*size);
line(x+127*size,y+67*size,x+127*size,y+66*size);
line(x+127*size,y+66*size,x+126*size,y+66*size);
line(x+126*size,y+66*size,x+126*size,y+65*size);
line(x+126*size,y+65*size,x+125*size,y+65*size);
line(x+125*size,y+65*size,x+125*size,y+64*size);
line(x+125*size,y+64*size,x+125*size,y+62*size);
line(x+125*size,y+62*size,x+123*size,y+62*size);
line(x+123*size,y+62*size,x+123*size,y+60*size);
line(x+123*size,y+60*size,x+121*size,y+60*size);
line(x+121*size,y+60*size,x+121*size,y+59*size);
line(x+121*size,y+59*size,x+119*size,y+59*size);
line(x+119*size,y+59*size,x+119*size,y+58*size);
line(x+119*size,y+58*size,x+117*size,y+58*size);
line(x+117*size,y+58*size,x+117*size,y+57*size);
line(x+117*size,y+57*size,x+114*size,y+57*size);
line(x+114*size,y+57*size,x+114*size,y+56*size);
line(x+114*size,y+56*size,x+112*size,y+56*size);
line(x+112*size,y+56*size,x+110*size,y+55*size);
line(x+110*size,y+55*size,x+110*size,y+54*size);
line(x+110*size,y+54*size,x+107*size,y+54*size);
line(x+107*size,y+54*size,x+107*size,y+53*size);
line(x+107*size,y+53*size,x+105*size,y+53*size);
line(x+105*size,y+53*size,x+105*size,y+52*size);
line(x+105*size,y+52*size,x+102*size,y+52*size);
line(x+102*size,y+52*size,x+102*size,y+51*size);
line(x+102*size,y+51*size,x+100*size,y+51*size);
line(x+100*size,y+51*size,x+100*size,y+50*size);
line(x+100*size,y+50*size,x+98*size,y+50*size);
line(x+98*size,y+50*size,x+98*size,y+49*size);
line(x+98*size,y+49*size,x+95*size,y+49*size);
line(x+95*size,y+49*size,x+95*size,y+48*size);
line(x+95*size,y+48*size,x+92*size,y+48*size);
line(x+92*size,y+48*size,x+92*size,y+47*size);
line(x+92*size,y+47*size,x+89*size,y+47*size);
line(x+89*size,y+47*size,x+89*size,y+46*size);
line(x+89*size,y+46*size,x+87*size,y+46*size);
line(x+87*size,y+46*size,x+87*size,y+45*size);
line(x+87*size,y+45*size,x+85*size,y+45*size);
line(x+85*size,y+45*size,x+85*size,y+44*size);
line(x+85*size,y+44*size,x+83*size,y+44*size);
line(x+83*size,y+44*size,x+83*size,y+43*size);
line(x+83*size,y+43*size,x+80*size,y+43*size);
line(x+80*size,y+43*size,x+80*size,y+42*size);
line(x+80*size,y+42*size,x+78*size,y+42*size);
line(x+78*size,y+42*size,x+78*size,y+41*size);
line(x+78*size,y+41*size,x+76*size,y+41*size);
line(x+76*size,y+41*size,x+76*size,y+40*size);
line(x+76*size,y+40*size,x+74*size,y+40*size);
line(x+74*size,y+40*size,x+74*size,y+39*size);
line(x+74*size,y+39*size,x+72*size,y+39*size);
line(x+72*size,y+39*size,x+72*size,y+38*size);
line(x+72*size,y+38*size,x+70*size,y+38*size);
line(x+70*size,y+38*size,x+70*size,y+37*size);
line(x+70*size,y+37*size,x+69*size,y+37*size);
line(x+69*size,y+37*size,x+69*size,y+36*size);
line(x+69*size,y+36*size,x+67*size,y+36*size);
line(x+67*size,y+36*size,x+67*size,y+35*size);
line(x+67*size,y+35*size,x+66*size,y+35*size);
line(x+66*size,y+35*size,x+66*size,y+34*size);
line(x+66*size,y+34*size,x+65*size,y+34*size);
line(x+65*size,y+34*size,x+65*size,y+33*size);
line(x+65*size,y+33*size,x+64*size,y+33*size);
line(x+64*size,y+33*size,x+64*size,y+32*size);
line(x+64*size,y+32*size,x+63*size,y+32*size);
line(x+63*size,y+32*size,x+63*size,y+30*size);
line(x+63*size,y+30*size,x+62*size,y+30*size);
line(x+62*size,y+30*size,x+62*size,y+28*size);
line(x+62*size,y+28*size,x+61*size,y+28*size);
line(x+61*size,y+28*size,x+61*size,y+27*size);
line(x+61*size,y+27*size,x+62*size,y+27*size);
line(x+62*size,y+27*size,x+62*size,y+25*size);
line(x+62*size,y+25*size,x+63*size,y+25*size);
line(x+63*size,y+25*size,x+63*size,y+23*size);
line(x+63*size,y+23*size,x+65*size,y+23*size);
line(x+65*size,y+23*size,x+65*size,y+22*size);
line(x+65*size,y+22*size,x+66*size,y+22*size);
line(x+66*size,y+22*size,x+66*size,y+21*size);
line(x+66*size,y+21*size,x+67*size,y+21*size);
line(x+67*size,y+21*size,x+68*size,y+20*size);
line(x+68*size,y+20*size,x+70*size,y+20*size);
line(x+70*size,y+20*size,x+70*size,y+19*size);
line(x+70*size,y+19*size,x+74*size,y+19*size);
line(x+74*size,y+19*size,x+74*size,y+18*size);
line(x+74*size,y+18*size,x+84*size,y+18*size);
line(x+84*size,y+18*size,x+84*size,y+17*size);
line(x+84*size,y+17*size,x+85*size,y+17*size);
line(x+85*size,y+17*size,x+85*size,y+16*size);
line(x+85*size,y+16*size,x+87*size,y+16*size);
line(x+87*size,y+16*size,x+87*size,y+15*size);
line(x+87*size,y+15*size,x+88*size,y+15*size);
line(x+88*size,y+15*size,x+88*size,y+14*size);
line(x+88*size,y+14*size,x+89*size,y+14*size);
line(x+89*size,y+14*size,x+89*size,y+13*size);
line(x+89*size,y+13*size,x+90*size,y+13*size);
line(x+90*size,y+13*size,x+90*size,y+12*size);
line(x+90*size,y+12*size,x+92*size,y+12*size);
line(x+92*size,y+12*size,x+92*size,y+11*size);
line(x+92*size,y+11*size,x+95*size,y+11*size);
line(x+95*size,y+11*size,x+95*size,y+10*size);
line(x+95*size,y+10*size,x+97*size,y+10*size);
line(x+97*size,y+10*size,x+97*size,y+9*size);
line(x+97*size,y+9*size,x+101*size,y+9*size);
line(x+101*size,y+9*size,x+101*size,y+8*size);
line(x+101*size,y+8*size,x+105*size,y+8*size);
line(x+105*size,y+8*size,x+105*size,y+7*size);
line(x+105*size,y+7*size,x+111*size,y+7*size);
line(x+111*size,y+7*size,x+111*size,y+6*size);
line(x+111*size,y+6*size,x+120*size,y+6*size);
line(x+120*size,y+6*size,x+120*size,y+5*size);
line(x+120*size,y+5*size,x+126*size,y+5*size);
line(x+126*size,y+5*size,x+126*size,y+4*size);
line(x+126*size,y+4*size,x+166*size,y+4*size);
line(x+166*size,y+4*size,x+166*size,y+5*size);
line(x+166*size,y+5*size,x+171*size,y+5*size);
line(x+171*size,y+5*size,x+171*size,y+6*size);
line(x+171*size,y+6*size,x+179*size,y+6*size);
line(x+179*size,y+6*size,x+179*size,y+7*size);
line(x+179*size,y+7*size,x+185*size,y+7*size);
line(x+185*size,y+7*size,x+185*size,y+8*size);
line(x+185*size,y+8*size,x+189*size,y+8*size);
line(x+189*size,y+8*size,x+189*size,y+9*size);
line(x+189*size,y+9*size,x+192*size,y+9*size);
line(x+192*size,y+9*size,x+192*size,y+10*size);
line(x+192*size,y+10*size,x+197*size,y+10*size);
line(x+197*size,y+10*size,x+197*size,y+11*size);
line(x+197*size,y+11*size,x+200*size,y+11*size);
line(x+200*size,y+11*size,x+200*size,y+12*size);
line(x+200*size,y+12*size,x+203*size,y+12*size);
line(x+203*size,y+12*size,x+203*size,y+13*size);
line(x+203*size,y+13*size,x+206*size,y+13*size);
line(x+206*size,y+13*size,x+206*size,y+14*size);
line(x+206*size,y+14*size,x+209*size,y+14*size);
line(x+209*size,y+14*size,x+209*size,y+15*size);
line(x+209*size,y+15*size,x+211*size,y+15*size);
line(x+211*size,y+15*size,x+211*size,y+16*size);
line(x+211*size,y+16*size,x+212*size,y+17*size);
line(x+212*size,y+17*size,x+214*size,y+17*size);
line(x+214*size,y+17*size,x+214*size,y+18*size);
line(x+214*size,y+18*size,x+215*size,y+18*size);
line(x+215*size,y+18*size,x+215*size,y+19*size);
line(x+215*size,y+19*size,x+217*size,y+19*size);
line(x+217*size,y+19*size,x+217*size,y+20*size);
line(x+217*size,y+20*size,x+218*size,y+20*size);
line(x+218*size,y+20*size,x+218*size,y+21*size);
line(x+218*size,y+21*size,x+219*size,y+21*size);
line(x+219*size,y+21*size,x+219*size,y+23*size);
line(x+219*size,y+23*size,x+220*size,y+23*size);
line(x+220*size,y+23*size,x+220*size,y+26*size);
line(x+220*size,y+26*size,x+221*size,y+26*size);
line(x+221*size,y+26*size,x+221*size,y+31*size);
line(x+221*size,y+31*size,x+220*size,y+31*size);
line(x+220*size,y+31*size,x+220*size,y+33*size);
line(x+220*size,y+33*size,x+219*size,y+33*size);
line(x+219*size,y+33*size,x+219*size,y+36*size);
line(x+219*size,y+36*size,x+218*size,y+36*size);
line(x+218*size,y+36*size,x+218*size,y+39*size);
line(x+218*size,y+39*size,x+217*size,y+39*size);
line(x+217*size,y+39*size,x+217*size,y+41*size);
for(i=217;i>199;i--)
{
	line(x+i*size,y+(41+217-i)*size,x+(i-1)*size,y+(41+217-i)*size);
	line(x+(i-1)*size,y+(41+217-i)*size,x+(i-1)*size,y+(41+218-i)*size);
}
line(x+199*size,y+59*size,x+199*size,y+60*size);
line(x+199*size,y+60*size,x+186*size,y+60*size);
line(x+186*size,y+60*size,x+170*size,y+114*size);
line(x+170*size,y+114*size,x+151*size,y+114*size);
line(x+151*size,y+114*size,x+167*size,y+60*size);
line(x+167*size,y+60*size,x+149*size,y+60*size);
line(x+149*size,y+60*size,x+159*size,y+49*size);
line(x+159*size,y+49*size,x+200*size,y+49*size);
line(x+200*size,y+49*size,x+200*size,y+48*size);
line(x+200*size,y+48*size,x+202*size,y+48*size);
line(x+202*size,y+48*size,x+202*size,y+45*size);
line(x+202*size,y+45*size,x+201*size,y+45*size);
line(x+201*size,y+45*size,x+201*size,y+44*size);
line(x+201*size,y+44*size,x+199*size,y+44*size);
line(x+199*size,y+44*size,x+199*size,y+43*size);
line(x+199*size,y+43*size,x+198*size,y+43*size);
line(x+198*size,y+43*size,x+198*size,y+42*size);
line(x+198*size,y+42*size,x+196*size,y+42*size);
line(x+196*size,y+42*size,x+196*size,y+41*size);
line(x+196*size,y+41*size,x+194*size,y+41*size);
line(x+194*size,y+41*size,x+195*size,y+40*size);
line(x+195*size,y+40*size,x+194*size,y+40*size);
line(x+194*size,y+40*size,x+194*size,y+39*size);
line(x+194*size,y+39*size,x+191*size,y+39*size);
line(x+191*size,y+39*size,x+189*size,y+39*size);
line(x+189*size,y+39*size,x+189*size,y+38*size);
line(x+189*size,y+38*size,x+186*size,y+38*size);
line(x+186*size,y+38*size,x+186*size,y+37*size);
line(x+186*size,y+37*size,x+183*size,y+37*size);
line(x+183*size,y+37*size,x+183*size,y+36*size);
line(x+183*size,y+36*size,x+181*size,y+36*size);
line(x+181*size,y+36*size,x+181*size,y+35*size);
line(x+181*size,y+35*size,x+178*size,y+35*size);
line(x+178*size,y+35*size,x+175*size,y+34*size);
line(x+175*size,y+34*size,x+175*size,y+33*size);
line(x+175*size,y+33*size,x+172*size,y+33*size);
line(x+172*size,y+33*size,x+172*size,y+32*size);
line(x+172*size,y+32*size,x+170*size,y+32*size);
line(x+170*size,y+32*size,x+170*size,y+31*size);
line(x+170*size,y+31*size,x+166*size,y+31*size);
line(x+166*size,y+31*size,x+166*size,y+30*size);
line(x+166*size,y+30*size,x+162*size,y+30*size);
line(x+162*size,y+30*size,x+162*size,y+29*size);
line(x+162*size,y+29*size,x+159*size,y+29*size);
line(x+159*size,y+29*size,x+159*size,y+28*size);
line(x+159*size,y+28*size,x+154*size,y+28*size);
line(x+154*size,y+28*size,x+154*size,y+27*size);
line(x+154*size,y+27*size,x+150*size,y+27*size);
line(x+150*size,y+27*size,x+150*size,y+26*size);
line(x+150*size,y+26*size,x+145*size,y+26*size);
line(x+145*size,y+26*size,x+145*size,y+25*size);
line(x+145*size,y+25*size,x+142*size,y+25*size);
line(x+142*size,y+25*size,x+142*size,y+24*size);
line(x+142*size,y+24*size,x+136*size,y+24*size);
line(x+136*size,y+24*size,x+136*size,y+23*size);
line(x+136*size,y+23*size,x+130*size,y+23*size);
line(x+130*size,y+23*size,x+130*size,y+22*size);
line(x+130*size,y+22*size,x+126*size,y+22*size);
line(x+126*size,y+22*size,x+126*size,y+21*size);
line(x+126*size,y+21*size,x+119*size,y+21*size);
line(x+119*size,y+21*size,x+119*size,y+20*size);
line(x+119*size,y+20*size,x+111*size,y+20*size);
line(x+111*size,y+20*size,x+111*size,y+19*size);
line(x+111*size,y+19*size,x+104*size,y+19*size);
line(x+104*size,y+19*size,x+104*size,y+18*size);
line(x+104*size,y+18*size,x+86*size,y+18*size);
line(x+86*size,y+18*size,x+86*size,y+19*size);
line(x+86*size,y+19*size,x+84*size,y+19*size);
line(x+84*size,y+19*size,x+84*size,y+20*size);
line(x+84*size,y+20*size,x+83*size,y+21*size);
line(x+83*size,y+21*size,x+82*size,y+21*size);
line(x+82*size,y+21*size,x+82*size,y+28*size);
line(x+82*size,y+28*size,x+83*size,y+28*size);
line(x+83*size,y+28*size,x+83*size,y+29*size);
line(x+83*size,y+29*size,x+85*size,y+29*size);
line(x+85*size,y+29*size,x+85*size,y+30*size);
line(x+85*size,y+30*size,x+86*size,y+30*size);
line(x+86*size,y+30*size,x+86*size,y+31*size);
line(x+86*size,y+31*size,x+87*size,y+32*size);
line(x+87*size,y+32*size,x+90*size,y+32*size);
line(x+90*size,y+32*size,x+90*size,y+34*size);
line(x+90*size,y+34*size,x+92*size,y+34*size);
line(x+92*size,y+34*size,x+92*size,y+35*size);
line(x+92*size,y+35*size,x+93*size,y+35*size);
line(x+93*size,y+35*size,x+93*size,y+36*size);
line(x+93*size,y+36*size,x+94*size,y+36*size);
line(x+94*size,y+36*size,x+94*size,y+37*size);
line(x+94*size,y+37*size,x+95*size,y+37*size);
line(x+95*size,y+37*size,x+95*size,y+38*size);
line(x+95*size,y+38*size,x+97*size,y+38*size);
line(x+97*size,y+38*size,x+97*size,y+39*size);
line(x+97*size,y+39*size,x+99*size,y+39*size);
line(x+99*size,y+39*size,x+99*size,y+40*size);
line(x+99*size,y+40*size,x+100*size,y+40*size);
line(x+100*size,y+40*size,x+100*size,y+41*size);
line(x+100*size,y+41*size,x+102*size,y+41*size);
line(x+102*size,y+41*size,x+102*size,y+42*size);
line(x+102*size,y+42*size,x+103*size,y+42*size);
line(x+103*size,y+42*size,x+103*size,y+43*size);
line(x+103*size,y+43*size,x+105*size,y+43*size);
line(x+105*size,y+43*size,x+105*size,y+44*size);
line(x+105*size,y+44*size,x+106*size,y+44*size);
line(x+106*size,y+44*size,x+106*size,y+45*size);
line(x+106*size,y+45*size,x+108*size,y+45*size);
line(x+108*size,y+45*size,x+108*size,y+46*size);
line(x+108*size,y+46*size,x+109*size,y+46*size);
line(x+109*size,y+46*size,x+109*size,y+47*size);
line(x+109*size,y+47*size,x+111*size,y+47*size);
line(x+111*size,y+47*size,x+111*size,y+48*size);
line(x+111*size,y+48*size,x+112*size,y+48*size);
line(x+112*size,y+48*size,x+112*size,y+49*size);
line(x+112*size,y+49*size,x+114*size,y+49*size);
line(x+114*size,y+49*size,x+114*size,y+50*size);
line(x+114*size,y+50*size,x+116*size,y+50*size);
line(x+116*size,y+50*size,x+116*size,y+51*size);
line(x+116*size,y+51*size,x+117*size,y+51*size);
line(x+117*size,y+51*size,x+117*size,y+52*size);
line(x+117*size,y+52*size,x+119*size,y+52*size);
line(x+119*size,y+52*size,x+119*size,y+53*size);
for(i=119;i<134;i++)
{
	line(x+i*size,y+(53+i-119)*size,x+(i+1)*size,y+(53+i-119)*size);
	line(x+(i+1)*size,y+(53+i-119)*size,x+(i+1)*size,y+(54+i-119)*size);
}
line(x+134*size,y+68*size,x+136*size,y+68*size);
line(x+136*size,y+68*size,x+136*size,y+69*size);
line(x+136*size,y+69*size,x+137*size,y+69*size);
line(x+137*size,y+69*size,x+137*size,y+70*size);
line(x+137*size,y+70*size,x+138*size,y+70*size);
line(x+138*size,y+70*size,x+138*size,y+71*size);
line(x+138*size,y+71*size,x+140*size,y+71*size);
line(x+140*size,y+71*size,x+140*size,y+72*size);
line(x+140*size,y+72*size,x+141*size,y+72*size);
line(x+141*size,y+72*size,x+141*size,y+73*size);
line(x+141*size,y+73*size,x+142*size,y+73*size);
line(x+142*size,y+73*size,x+142*size,y+74*size);
line(x+142*size,y+74*size,x+143*size,y+74*size);
line(x+143*size,y+74*size,x+143*size,y+75*size);
line(x+143*size,y+75*size,x+144*size,y+75*size);
line(x+144*size,y+75*size,x+144*size,y+76*size);
line(x+144*size,y+76*size,x+146*size,y+76*size);
line(x+146*size,y+76*size,x+146*size,y+77*size);
line(x+146*size,y+77*size,x+147*size,y+77*size);
line(x+147*size,y+77*size,x+147*size,y+78*size);
line(x+147*size,y+78*size,x+148*size,y+78*size);
line(x+148*size,y+78*size,x+148*size,y+79*size);
line(x+148*size,y+79*size,x+149*size,y+79*size);
line(x+149*size,y+79*size,x+149*size,y+80*size);
line(x+149*size,y+80*size,x+150*size,y+80*size);
line(x+150*size,y+80*size,x+150*size,y+81*size);
line(x+150*size,y+81*size,x+151*size,y+81*size);
line(x+151*size,y+81*size,x+151*size,y+82*size);
line(x+151*size,y+82*size,x+152*size,y+82*size);
line(x+152*size,y+82*size,x+152*size,y+84*size);
line(x+152*size,y+84*size,x+153*size,y+84*size);
line(x+153*size,y+84*size,x+153*size,y+86*size);
line(x+153*size,y+86*size,x+153*size,y+86*size);
line(x+153*size,y+86*size,x+154*size,y+86*size);
line(x+154*size,y+86*size,x+154*size,y+90*size);
line(x+154*size,y+90*size,x+153*size,y+90*size);
line(x+153*size,y+90*size,x+153*size,y+95*size);
line(x+153*size,y+95*size,x+152*size,y+95*size);
line(x+152*size,y+95*size,x+152*size,y+97*size);
line(x+152*size,y+97*size,x+151*size,y+97*size);
line(x+151*size,y+97*size,x+151*size,y+99*size);
line(x+151*size,y+99*size,x+150*size,y+99*size);
line(x+150*size,y+99*size,x+150*size,y+101*size);
line(x+150*size,y+101*size,x+149*size,y+101*size);
line(x+149*size,y+101*size,x+149*size,y+103*size);
line(x+149*size,y+103*size,x+148*size,y+103*size);
line(x+148*size,y+103*size,x+148*size,y+104*size);
line(x+148*size,y+104*size,x+147*size,y+104*size);
line(x+147*size,y+104*size,x+147*size,y+106*size);
line(x+147*size,y+106*size,x+146*size,y+106*size);
line(x+146*size,y+106*size,x+146*size,y+107*size);
for(i=146;i>=139;i--)
{
	line(x+i*size,y+(107+146-i)*size,x+(i-1)*size,y+(107+146-i)*size);
	line(x+(i-1)*size,y+(107+146-i)*size,x+(i-1)*size,y+(107+146+1-i)*size);
}
line(x+138*size,y+115*size,x+4*size,y+115*size);


}
/****************************************
Function : drawdt(void)
Description:画地图函数
Attention:无
Return：无
***************************************/
void drawdt(void)
{
	setlinestyle(SOLID_LINE,0,3);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	
	line(0,80,585,80);
	line(100,80,100,350);
	line(60,180,400,180);
	line(400,80,400,300);
	line(270,180,270,320);
	line(540,130,540,330);
	line(220,220,555,220);
	fillellipse(60,180,10,10);
	fillellipse(300,180,10,10);
	fillellipse(100,350,10,10);
	fillellipse(270,320,10,10);
	fillellipse(555,220,10,10);
	fillellipse(540,130,10,10);
	puthz(20,145,"华科附小",16,20,RED);
	puthz(260,145,"经济学院",16,20,RED);
	puthz(60,315,"公管学院",16,20,RED);
	puthz(210,285,"研究生工作室",16,20,RED);
	puthz(505,185,"华科幼儿园",16,20,RED);
	puthz(470,95,"梧桐雨问学中心",16,20,RED);
}