#include "common.h"
#include "bywz.h"
#include "service.h"

/***********************************************
Function :drawbaoyang()
Attention:绘制保养界面 
Description:
Return :无 
***************************************************/
void drawbaoyang()
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setlinestyle(SOLID_LINE,0,3);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	bar(0,50,640,60);
	line(560,50,560,10);
	circle(560,30,10);
	line(550,60,550,260);
	circle(550,250,10);
	line(550,200,590,200);
	circle(570,200,10);
	line(550,250,100,250);
	circle(100,250,10);
	line(400,60,400,200);
	circle(400,150,10);
	line(400,150,500,150);
	line(400,200,200,200);
	circle(300,200,10);
	line(200,200,200,100);
	line(200,170,100,170);
	circle(200,170,10);
	line(400,100,100,100);
	circle(100,100,10);
	line(100,100,100,250);
	line(100,200,50,200);
	line(50,60,50,150);
	circle(50,150,10);
	line(20,150,100,150);
	fillellipse(560,30,10,10);
	puthz(570,20,"好车主光谷店",16,16,GREEN);
	fillellipse(550,250,10,10);
	puthz(560,230,"好车主大道店",16,16,GREEN);
	fillellipse(570,200,10,10);
	puthz(555,170,"墨水湖北路店",16,16,GREEN);
	fillellipse(100,250,10,10);
	puthz(10,240,"发展大道店",16,16,GREEN);
	fillellipse(400,150,10,10);
	puthz(410,160,"洪山广场店",16,16,GREEN);
	fillellipse(300,200,10,10);
	puthz(280,220,"常码头店",16,16,GREEN);
	fillellipse(200,170,10,10);
	puthz(220,150,"三里坡店",16,16,GREEN);
	fillellipse(100,100,10,10);
	puthz(110,65,"常乡路店",16,16,GREEN);
	fillellipse(50,150,10,10);
	puthz(10,160,"古田二路店",16,16,GREEN);
	puthz(20,20,"请选择保养店",16,20,GREEN);
	puthz(20,290,"店铺信息如下",16,20,GREEN);
	setcolor(RED);
	setlinestyle(SOLID_LINE,0,1);
	line(0,275,640,275);
	setcolor(LIGHTBLUE);
				setlinestyle(SOLID_LINE,0,3);
				line(120,340,140,320);
				line(140,320,500,320);
				line(500,320,520,340);
				line(520,340,520,440);
				line(520,440,500,460);
				line(500,460,140,460);
				line(140,460,120,440);
				line(120,440,120,340);
				puthz(180,330,"店名：",16,20,BLACK);
				puthz(140,355,"店铺评分：",16,20,BLACK);
				puthz(140,380,"提供服务：",16,20,BLACK);
				
				puthz(140,425,"联系电话：",16,20,BLACK);
	setfillstyle(1,CYAN);
	bar(0,440,100,480);
	puthz(20,450,"返回",16,30,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(540,380,640,420);
	puthz(560,390,"取消",16,30,WHITE);
	bar(540,440,640,480);
	puthz(560,450,"确定",16,30,WHITE);
}
/***********************************************
Function :baoyang(setuser *person)
Attention:
Description:保养的主函数 
Return :service的judge 
***************************************************/
int baoyang(setuser *person)
{
	int judge = 0;
	int flag = 0;//用于判断是否已经选择了保养地点 0 表示未选择
	int k=-1;
	int press,MouseX,MouseY;
	char dianming[9][16]={
		{"古田二路店"},
		{"常乡路店"},
		{"发展大道店"},
		{"三里坡店"},
		{"常码头店"},
		{"洪山广场店"},
		{"好车主大道店"},
		{"好车主光谷店"},
		{"墨水湖北路店"}
	};
	
	char lianxi [9][13]=
	{
		{"037-66666660"},
		{"037-66666661"},
		{"037-66666662"},
		{"037-66666663"},
		{"037-66666664"},
		{"037-66666665"},
		{"037-66666666"},
		{"037-66666667"},
		{"037-66666668"}
	};
	char pingfen[9][5]=
	{
		{"5.0"},
		{"4.9"},
		{"4.8"},
		{"5.0"},
		{"4.9"},
		{"4.9"},
		{"4.8"},
		{"4.7"},
		{"4.6"},
	};
//	clrmous(MouseX,MouseY); 
	delay(100);
	//save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(k!=0&&MouseX>= 50-10 &&MouseX<= 50+10 &&MouseY>= 150-10 &&MouseY<= 150+10 &&press)
			{
				k = 0;
				judge = 4;
			}
			if(k!=1&&MouseX>= 100-10 &&MouseX<= 100+10 &&MouseY>= 100-10 &&MouseY<= 100+10 &&press)
			{
				k = 1;
				judge = 4;
			}
			if(k!=2&&MouseX>= 100-10 &&MouseX<= 100+10 &&MouseY>= 250-10 &&MouseY<= 250+10 &&press)
			{
				k = 2;
				judge = 4;
			}
			if(k!=3&&MouseX>= 200-10 &&MouseX<= 200+10 &&MouseY>= 170-10 &&MouseY<= 170+10 &&press)
			{
				k = 3;
				judge = 4;
			}if(k!=4&&MouseX>= 300-10 &&MouseX<= 300+10 &&MouseY>=200-10 &&MouseY<= 200+10 &&press)
			{
				k = 4;
				judge = 4;
			}if(k!=5&&MouseX>= 400-10 &&MouseX<= 400+10 &&MouseY>= 150-10 &&MouseY<= 150+10 &&press)
			{
				k = 5;
				judge = 4;
			}if(k!=6&&MouseX>= 550-10 &&MouseX<= 550+10 &&MouseY>= 250-10 &&MouseY<= 250+10 &&press)
			{
				k = 6;
				judge = 4;
			}
			if(k!=8&&MouseX>= 560-10 &&MouseX<= 560+10 &&MouseY>= 30-10 &&MouseY<= 30+10 &&press)
			{
				k = 7;
				judge = 4;
			}
			if(k!=8&&MouseX>= 570-10 &&MouseX<= 570+10 &&MouseY>= 200-10 &&MouseY<= 200+10 &&press)
			{
				k = 8;
				judge = 4;
			}
	
		//点击确定
		if(MouseX >=540 && MouseX <= 640&& MouseY >= 440&& MouseY <= 480 &&press && flag == 1)
		{
			judge = 8;
		}
		//点击取消
		if(MouseX >=540 && MouseX <= 640&& MouseY >= 380&& MouseY <= 420 &&press && flag == 1)
		{
			judge = 9;
		}
		//点击返回
		if(MouseX >=0 && MouseX <= 100&& MouseY >= 440&& MouseY <= 480 &&press)
		{
			return -1;
		}	
		switch(judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY);
				drawbaoyang();
				setfillstyle(1,WHITE);
				setcolor(BLACK);
				bar(250,330,250+190,450);
				settextstyle(SMALL_FONT,0,6);
				puthz(250,330,dianming[k],16,16,BLACK);
				outtextxy(250,355,pingfen[k]);
				//outtextxy(250,405,feiyong[k]);
				//puthz(300,405,"元",16,20,BLACK);
				puthz(20,20,"请选择保养店",16,20,GREEN);
				puthz(20,290,"店铺信息如下",16,20,GREEN);
				outtextxy(250,428,lianxi[k]);
				switch(k)
				{
					case 0:
					{
						puthz(250,375+5,"嘉实多保养",16,16,BLACK);
						puthz(250,400+5,"美孚速霸保养",16,16,BLACK);
						break;
					}
					case 1:
					{
						puthz(250,375+5,"小保养",16,16,BLACK);
						puthz(250,400+5,"美孚速霸保养",16,16,BLACK);
							break;
					}
					case 2:
					{
						puthz(250,375+5,"全合成小保养",16,16,BLACK);
						puthz(250,400+5,"半合成小保养",16,16,BLACK);
							break;
					} 
					case 3:
					{
						puthz(250,375+5,"全合成小保养",16,16,BLACK);
						puthz(250,400+5,"空调管路杀菌清洗",16,16,BLACK);
							break;	
					} 
					case 4:
					{
						puthz(250,375+5,"普通保养（含机油机滤）",16,16,BLACK);
						puthz(250,400+5,"空调管路杀菌清洗",16,16,BLACK);
							break;	
					}
					case 5:
					{
						puthz(250,375+5,"好车主汽车保养",16,16,BLACK);
						puthz(250,400+5,"小保养（湖北）",16,16,BLACK);
							break;	
					}
					case 6:
					{
						puthz(250,375+5,"全合成小保养",16,16,BLACK);
						puthz(250,400+5,"小保养（湖北）",16,16,BLACK);
							break;
					 } 
					 case 7:
					{
					 	puthz(250,375+5,"好车主汽车保养",16,16,BLACK);
					 	puthz(250,400+5,"美孚速霸保养",16,16,BLACK);
					 		break;
					}
					case 8:
					{
						puthz(250,375+5,"蒸发箱可视化清洗",16,16,BLACK);
						puthz(250,400+5,"轮胎修复",16,16,BLACK);	
							break;		
					}	
				}
				judge = 0;
				break;
			}
			case 4:
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,CYAN);
				bar(540,380,640,420);
				puthz(560,390,"取消",16,30,WHITE);
				bar(540,440,640,480);
				puthz(560,450,"确定",16,30,WHITE);
				setfillstyle(1,WHITE);
				bar(250,330,250+190,450);
				settextstyle(SMALL_FONT,0,6);
				puthz(250,330,dianming[k],16,16,BLACK);
				outtextxy(250,355,pingfen[k]);
				switch(k)
				{
					case 0:
					{
						puthz(250,375+5,"嘉实多保养",16,16,BLACK);
						puthz(250,400+5,"美孚速霸保养",16,16,BLACK);
						break;
					}
					case 1:
					{
						puthz(250,375+5,"小保养",16,16,BLACK);
						puthz(250,400+5,"美孚速霸保养",16,16,BLACK);
							break;
					}
					case 2:
					{
						puthz(250,375+5,"全合成小保养",16,16,BLACK);
						puthz(250,400+5,"半合成小保养",16,16,BLACK);
							break;
					} 
					case 3:
					{
						puthz(250,375+5,"全合成小保养",16,16,BLACK);
						puthz(250,400+5,"空调管路杀菌清洗",16,16,BLACK);
							break;	
					} 
					case 4:
					{
						puthz(250,375+5,"普通保养（含机油机滤）",16,16,BLACK);
						puthz(250,400+5,"空调管路杀菌清洗",16,16,BLACK);
							break;	
					}
					case 5:
					{
						puthz(250,375+5,"好车主汽车保养",16,16,BLACK);
						puthz(250,400+5,"小保养（湖北）",16,16,BLACK);
							break;	
					}
					case 6:
					{
						puthz(250,375+5,"全合成小保养",16,16,BLACK);
						puthz(250,400+5,"小保养（湖北）",16,16,BLACK);
							break;
					 } 
					 case 7:
					{
					 	puthz(250,375+5,"好车主汽车保养",16,16,BLACK);
					 	puthz(250,400+5,"美孚速霸保养",16,16,BLACK);
					 		break;
					}
					case 8:
					{
						puthz(250,375+5,"蒸发箱可视化清洗",16,16,BLACK);
						puthz(250,400+5,"轮胎修复",16,16,BLACK);	
							break;		
					}		 
				}
				outtextxy(250,427,lianxi[k]);
				flag = 1;
				judge  =0;
				break;
			}
			case 8://点击确定
			{
				clrmous(MouseX,MouseY); 
				judge = zhifu("车保养",30,person,-1);
				flag = 0;
				break;
			}
			case 9://点击取消
			{
				flag = 0;
				k =-1;
				clrmous(MouseX,MouseY);
				setfillstyle(1,LIGHTGRAY);
				bar(540,380,640,420);
				puthz(560,390,"取消",16,30,WHITE);
				bar(540,440,640,480);
				puthz(560,450,"确定",16,30,WHITE);
				setfillstyle(1,WHITE);
				bar(250,330,250+190,450);
				judge = 0;
				break;
			}
		}
	}
}
/***********************************************
Function :weizhang(setuser *person)
Attention:
Description:
Return :-1
***************************************************/
int weizhang(setuser *person)
{
	int judge = 0;
	int press,MouseX,MouseY;
	delay(100);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=270 && MouseX <= 370&& MouseY >= 400&& MouseY <= 440 &&press)
		{
			return -1;
		}	
	}
}
/***********************************************
Function :drawweizhang(setuser *person)
Attention:传入用户结点 
Description:
Return :无 
***************************************************/
void drawweizhang(setuser *person)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);
	puthz(10,10,"平安好车主",32,50,WHITE);
	
	puthz(130,100,"尊敬的",32,30,CYAN);
	settextstyle(DEFAULT_FONT,0,3);
	outtextxy(240,110,(*person).accounts);
	puthz(150,200,"您还没有违章记录！",32,35,RED);
	
	setfillstyle(1,CYAN);
	bar(270,400,370,440);
	puthz(290,410,"返回",16,20,WHITE);
}
