#include "common.h"
#include <string.h>
#include "policy1.h"
#include "policy2.h"
#include "duqu.h"
#include "gpolicy.h"
/****************************************
Function :policymain(setuser *person,struct POLICY policy[10],int j)
Description:投保主界面
Attention:无
Return：上一个界面的judge值
***************************************/
int policymain(setuser *person,struct POLICY policy[10],int j)
{
	int i,k=0;
	int judge = 0;
	int flag[4]={0,0,0,0};/*注意0不使用,用于标记车的投保状态*/
	char pcity[3]={"鄂"};//车牌地区
	char plate[7]={'\0'};//车牌
	char pinpai[15]={'\0'};
	char sfzh[19]={'\0'};//身份证号
	char dianhua[12]={'\0'};//电话
	char chejia[9]={'\0'};//车架号
	char fdjh[9]={'\0'};//发动机号
	char time[2]={'\0'};//日期
	//money[0]代表交强险金额，money[5]代表总金额
	char money_str[6][10]={{'0'},{'0'},{'0'},{'0'},{'0'},{'0'}};
	long  money[6]={0,0,0,0,0,0};
	int flagnew[6]={0,0,0,0,0,0};//标记各种保险是否已买
	char baofei[6][10]={{'0'},{'0'},{'0'},{'0'},{'0'},{'0'}};
	int  baofeii=0,baofeisum=0;
	char bdh[9]={'\0'};//保单号
	int press,MouseX,MouseY;
	delay(100);
	clrmous(MouseX,MouseY);
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		switch(judge)
		{
			case -1:
			{
				return -1;
			}
			case 0:
			{
				clrmous(MouseX,MouseY);
				delay(100);
				drawpolicyone(flag,plate,pinpai,pcity);
			    judge = policyone(flag,plate,pinpai,pcity,policy);
			    break;
			}
			case 1:
			{
				drawxinxiluru();
				judge = xinxiluru(sfzh,dianhua,chejia,fdjh,time,person);
				break;
			}
			case 2:
			{
				drawgetpolicy(money_str,flagnew,plate,pinpai,baofei,flag);
				//传入的是标记各种保险是否已买的变量
				judge = getpolicy(money_str,flagnew,plate,pinpai,baofei,flag,time);
				break;
			}
			case 3:
			{
				clrmous(MouseX,MouseY);
				drawbdpage();
				judge=bdpage(person,dianhua,plate,pinpai,chejia,flagnew,money_str,baofei,pcity,bdh);
				delay(300); 
				break;
			}
			case 4://完成投保
			{
				putpolicy(person,pcity,flag,plate,pinpai,money_str,baofei,flagnew,chejia,sfzh,fdjh,dianhua,bdh);
				strcpy(policy[j].pcity,pcity);
					for(i=0;i<4;i++)
					{
						policy[j].flag[i]=flag[i];
					}
					strcpy(policy[j].plate,plate);
					strcpy(policy[j].pinpai,pinpai);
					for(i=0;i<6;i++)
					{
						strcpy(policy[j].money_str[i],money_str[i]);
					}
					for(i=0;i<6;i++)
					{
						strcpy(policy[j].baofei[i],baofei[i]);
					}
					strcpy(policy[j].chejia,chejia);
					strcpy(policy[j].fdjh,fdjh);
					strcpy(policy[j].sfzh,sfzh);
					strcpy(policy[j].dianhua,dianhua);
					strcpy(policy[j].bdh,bdh);
					for(i=0;i<6;i++)
					{
						policy[j].flagnew[i]=flagnew[i];
					}
					policy[j].p=1;
				return -1;
			}
			case 5:
			{
				clrmous(MouseX,MouseY);
				baofeisum = atoi(baofei[5]);
				judge = zhifu("购买保险",baofeisum,person,3);
				if(judge == -1)
				{
					judge = 4;
				}
				break;
			}
		}
	}
}
/*写入文本*/
/****************************************
Function putpolicy(setuser *person,char *pcity,int *flag,char *plate,char *pinpai ,char money_str[6][10],char baofei[][10],int *flagnew,char *chejia,char *sfzh,char *fdjh,char *dianhua,char *bdh)
Description:将保单信息写入文本
Attention:无
Return：上一个界面的judge值
***************************************/
int putpolicy(setuser *person,char *pcity,int *flag,char *plate,char *pinpai ,char money_str[6][10],char baofei[][10],int *flagnew,char *chejia,char *sfzh,char *fdjh,char *dianhua,char *bdh)
{
    char *p;
	int i=0,j=0;
	char flagstr[3],flagnewstr[6];
	char *m={"无\0"};
	FILE *fp;
	for(i=0;i<3;i++)
	{
		flagstr[i]=flag[i+1]+'0';
	}
	for(i=0;i<6;i++)
	{
		flagnewstr[i]=flagnew[i]+'0';
	}
	if((fp=fopen("./t_file/user/policy.txt","r+"))==NULL)
	{
		closegraph();
		printf("can't open policy.txt");
		//getchar();
		exit(1);
	}
	fseek(fp,0L,2);
	
	 putc('/',fp);
	p=person->accounts;
		while(*p!='\0')
		{
			putc(*p,fp);
			p++;
		}
	putc('#',fp);
	
	if(flag[3]==1)
	{
		while(*m!='\0')
		{
			putc(*m,fp);
			m++;
		}
		putc('#',fp);
	}
	else {
		p=pcity;
		while(*p!='\0')
		{
			putc(*p,fp);
			p++;
		}
		putc('#',fp);
		p=plate;
		while(*p!='\0')
		{
			putc(*p,fp);
			p++;
		}
	}
	putc('#',fp);
	p=pinpai;
	while(*p!='\0')
    {
	     putc(*p,fp);
	     p++;
    }
	putc('#',fp);
	for(i=0;i<6;i++)
	{
		p=money_str[i];
		while(*p!='\0')
		{
			putc(*p,fp);
			p++;
		}
		putc('#',fp);
	}
	//putc('-',fp);
	for(i=0;i<6;i++)
	{
		p=baofei[i];
		while(*p!='\0')
		{
			putc(*p,fp);
			p++;
		}
		putc('#',fp);
	}
	p=flagnewstr;
	i=0;
	while(i!=7)
    {
	     putc(*p,fp);
	     p++;
		 i++;
    }
	putc('#',fp);
	
	p=chejia;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	
	p=fdjh;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	
	p=sfzh;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	
	p=dianhua;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	
	p=bdh;
	while(*p!='\0')
	{
		putc(*p,fp);
		p++;
	}
	putc('#',fp);
	putc('0',fp);
	putc('#',fp);
	fclose(fp);
	/*for(i =0;i<5;i++)
	 {
		 putc(' ', fp);
	 }*/
	 //putc('/',fp);

}
/****************************************
Function :drawpolicyone(int *flag,char *plate,char *pinpai,char *pcity)
Description:画第一个投保界面函数
Attention:无
Return：无
***************************************/
void drawpolicyone(int *flag,char *plate,char *pinpai,char *pcity)
{
	char temp[2]={'\0','\0'};
	int k=0;
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setlinestyle(SOLID_LINE,0,3);
	line(50,10,20,30);
	line(20,30,50,50);
	puthz(200,10,"平安车险",32,50,DARKGRAY);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,1);
	line(0,60,585,60);
	line(0,80,420,80);
	puthz(10,100,"投保城市",16,20,BLACK);
	puthz(160,100,"湖北省武汉市",16,16,LIGHTGRAY);
	line(0,130,420,130);
	puthz(10,140,"车牌号码",16,20,BLACK);
	setfillstyle(1,WHITE);
	bar(150,140,170,160);
	puthz(150,140,pcity,16,16,BLACK);
	line(195,140,175,140);
	line(185,155,195,140);//(175,140,200,160)
	line(185,155,175,140);
	rectangle(200,130,420,170);
	//puthz(210,140,"请输入您的车牌号",16,16,LIGHTGRAY);
	line(0,170,420,170);
	
	puthz(10,180,"过户车续保",16,16,BLACK);
	circle(200,190,10);
	puthz(215,185,"是",16,16,LIGHTGRAY);
	circle(300,190,10);
	puthz(315,185,"否",16,16,LIGHTGRAY);
	
	line(0,210,420,210);
	puthz(10,220,"发生过交通事故",16,16,BLACK);
	circle(200,230,10);
	puthz(215,225,"是",16,16,LIGHTGRAY);
	circle(300,230,10);
	puthz(315,225,"否",16,16,LIGHTGRAY);
	
	line(0,250,420,250);
	puthz(10,260,"新车未上牌",16,16,BLACK);
	circle(200,270,10);
	puthz(215,265,"是",16,16,LIGHTGRAY);
	circle(300,270,10);
	puthz(315,265,"否",16,16,LIGHTGRAY);
	line(0,290,420,290);
	puthz(10,300,"品牌车型",16,20,BLACK);
	puthz(160,300,"请选择您的车辆型号",16,16,LIGHTGRAY);
	line(400,295,410,310);
	line(410,310,400,325);
	
	line(0,330,420,330);
	
    line(0,400,420,400);
    line(420,80,420,400);

    setcolor(CYAN);
	rectangle(110,350,310,390);
	puthz(150,360,"立即报价",16,30,CYAN);
	
	setfillstyle(1,CYAN);
	setcolor(LIGHTGRAY);
	if(flag[1]==1) fillellipse(200,190,10,10);
	    else if(flag[1]==2) fillellipse(300,190,10,10);
	if(flag[2]==1) fillellipse(200,230,10,10);
		else if(flag[2]==2) fillellipse(300,230,10,10);
	if(flag[3]==1) 
	{
		fillellipse(200,270,10,10);
		puthz(210,140,"您还没有车牌号",16,20,LIGHTGRAY);
	}
	else if(flag[3]==2) 
	{
		fillellipse(300,270,10,10);
	}
	if(pinpai[0]!='\0')
	{
		setfillstyle(1,WHITE);
		bar(155,295,390,325);
	    puthz(210,300,pinpai,16,30,BLACK);
	}
	setcolor(BLACK);
	settextstyle(2, 0, 6);
	if(plate[0]!='\0'&&flag[3]!=1)
	{
		for(k=0;k<6;k++)
		{
			temp[0] = plate[k];
			outtextxy(208+ k * 11, 137, temp);
		}
	}
	setcolor(CYAN);
	puthz(30,440,"为什么在好车主购车险？",16,16,CYAN);
	line(30,460,200,460);
	puthz(600,30,"车",32,30,DARKGRAY);
	puthz(600,65,"险",32,30,DARKGRAY);
	puthz(600,100,"投",32,30,DARKGRAY);
	puthz(600,135,"保",32,30,DARKGRAY);
	puthz(600,170,"就",32,30,DARKGRAY);
	puthz(600,205,"三",32,30,CYAN);
	puthz(600,240,"步",32,30,CYAN);
	puthz(550,60,"报",32,30,DARKGRAY);
	puthz(550,95,"价",32,30,DARKGRAY);
	puthz(550,130,"支",32,30,DARKGRAY);
	puthz(550,165,"付",32,30,DARKGRAY);
	puthz(550,200,"享",32,30,CYAN);
	puthz(550,235,"服",32,30,CYAN);
	puthz(550,270,"务",32,30,CYAN);
	
}
/****************************************
Function :policyone(int *flag,char *plate,char *pinpai,char *pcity,struct POLICY policy[10])
Description:第一投保界面主函数
Attention:无
Return：上一个界面的judge值
***************************************/
int policyone(int *flag,char *plate,char *pinpai,char *pcity,struct POLICY policy[10])
{
	int judge  = 0;
	int press,MouseX,MouseY;
	int i;//用于实现新车未上牌
	char temp[2]={'\0','\0'};
	int panding=0;
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		/*返回上一页*/
		if(MouseX >=20 &&MouseX <=50 &&MouseY >= 10 &&MouseY <= 50 &&press)
		{
			judge = 1;
		}
		/*选择过户车续保*/
		if(MouseX >=190 &&MouseX <=210 &&MouseY >= 180 &&MouseY <= 200 &&press)
		{
			flag[1]=1;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(300,190,10,10);
			bar(428,368,632,472);
			setfillstyle(1,CYAN);
			fillellipse(200,190,10,10);
		}
		if(MouseX >=290 &&MouseX <=310 &&MouseY >= 180 &&MouseY <= 200 &&press)
		{
			flag[1]=2;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(200,190,10,10);
			bar(428,368,632,472);
			setfillstyle(1,CYAN);
			fillellipse(300,190,10,10);
			//save_bk_mou(MouseX,MouseY);
		}
			/*发生过交通事故*/
		if(MouseX >=190 &&MouseX <=210 &&MouseY >= 220 &&MouseY <= 240 &&press)
		{
			flag[2]=1;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(300,230,10,10);
			bar(428,368,632,472);
			setfillstyle(1,CYAN);
			fillellipse(200,230,10,10);
		}
		/*未发生过交通事故*/
		if(MouseX >=290 &&MouseX <=310 &&MouseY >= 220 &&MouseY <= 240 &&press)
		{
			flag[2]=2;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(200,230,10,10);
			bar(428,368,632,472);
			setfillstyle(1,CYAN);
			fillellipse(300,230,10,10);
		}
		/*新车无车牌*/
		if(MouseX >=190 &&MouseX <=210 &&MouseY >= 260 &&MouseY <= 280 &&press)
		{
			flag[3]=1;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(300,270,10,10);
			bar(428,368,632,472);
			bar(202,132,418,168);
			puthz(210,140,"您还没有车牌号",16,20,LIGHTGRAY);
			
			setfillstyle(1,CYAN);
			fillellipse(200,270,10,10);
		}
		if(MouseX >=290 &&MouseX <=310 &&MouseY >= 260 &&MouseY <= 280 &&press)
		{
			flag[3]=2;
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(200,270,10,10);
			bar(428,368,632,472);
			bar(202,132,418,168);
			//puthz(210,140,"请输入您的车牌号",16,20,LIGHTGRAY);
			setcolor(BLACK);
			settextstyle(2, 0, 6);
			for(i=0;i<6;i++)
			{
				temp[0] = plate[i];
				outtextxy(208+ i * 11, 137, temp);
			}
			setcolor(LIGHTGRAY);
			setfillstyle(1,CYAN);
			fillellipse(300,270,10,10);
		}
		/*立即报价*/
		if(MouseX >=110 &&MouseX <=310 &&MouseY >= 350 &&MouseY <= 390 &&press)
		{
			judge = 2;
		}
		/*输入车牌*/
		if(MouseX >=200 &&MouseX <=420 &&MouseY >=130  &&MouseY <= 170 &&press&&flag[3]!=1)
		{
			judge = 3;
		}
		/*品牌车型*/
		if(MouseX >=400 &&MouseX <=420 &&MouseY >=295  &&MouseY <= 325 &&press)
		{
			judge = 4;
		}
		/*车牌城市*/
		if(MouseX >=175 &&MouseX <=195 &&MouseY >=140  &&MouseY <= 155 &&press&&flag[3]!=1)
		{
			judge = 5;
		}
		if(MouseX >=30 &&MouseX <=200 &&MouseY >=440  &&MouseY <= 460 &&press)
		{
			judge = 6;
		}
		switch(judge)
		{
			case -1:
			{
				drawpolicyone(flag,plate,pinpai,pcity);
				save_bk_mou(MouseX,MouseY);
				judge = 0;
				break;
			}
			case 1:
			{
				return -1;
			}
		case 2:
			{
				/*if(flag[2] != 1)
				{
					for(i=0;i<10;i++)
					{
						if(strcmp(plate,policy[i].plate)==0 && strcmp(pcity,policy[i].pcity)==0)
						{
							panding = 1;
						}
					}
				}
				if(flag[2]==1)
				{
					for(i=0;i<10;i++)
					{
						if(strcmp(plate,policy[i].plate)==0 && strcmp(pcity,policy[i].pcity)==0)
						{
							panding = 2;
							break;
						}
					}
				}*/
				if(flag[1]==0||flag[2]==0||flag[3]==0)
				{
					setlinestyle(DOTTED_LINE,0,3);
					setcolor(CYAN);
					rectangle(430,370,630,470);
					puthz(490,390,"请选择",16,16,BLACK);
					puthz(460,420,"您的投保状态！",16,16,RED);
					judge = 0;
					break;
				}
				else if(flag[3]==2&&( 
				         !(plate[0]>='A'&&plate[0]<='Z')||
					     !((plate[1]>='1'&&plate[1]<='9')||(plate[1]>='A'&&plate[1]<='Z'))||
					     !((plate[2]>='1'&&plate[2]<='9')||(plate[2]>='A'&&plate[2]<='Z'))||
						 !((plate[3]>='1'&&plate[3]<='9')||(plate[3]>='A'&&plate[3]<='Z'))||
						 !((plate[4]>='1'&&plate[4]<='9')||(plate[4]>='A'&&plate[4]<='Z'))||
						 !((plate[5]>='1'&&plate[5]<='9')||(plate[5]>='A'&&plate[5]<='Z'))
				                    ))
					{
						setlinestyle(DOTTED_LINE,0,3);
						setcolor(CYAN);
						rectangle(430,370,630,470);
						puthz(490,390,"请正确",16,16,BLACK);
						puthz(460,420,"输入您的车牌号！",16,16,RED);
						judge = 0;
						break;	   
					}
				else if (pinpai[0]=='\0')
				{
					setlinestyle(DOTTED_LINE,0,3);
					setcolor(CYAN);
					rectangle(430,370,630,470);
					puthz(490,390,"请选择",16,16,BLACK);
					puthz(460,420,"输入您的车辆品牌型号！",16,16,RED);
					judge = 0;
					break;	   
				}
			/*	else if(pinpai!=2&&flag[2]==1)
				{
					setlinestyle(DOTTED_LINE,0,3);
					setcolor(CYAN);
					rectangle(430,370,630,470);
					puthz(480,390,"以前未投保",16,16,BLACK);
					puthz(470,420,"无法重新投保",16,16,RED);
					judge = 0;
					break;	
				}
				else if(panding == 1)
				{
					setlinestyle(DOTTED_LINE,0,3);
					setcolor(CYAN);
					rectangle(430,370,630,470);
					puthz(490,390,"该车辆",16,16,BLACK);
					puthz(460,420,"已经进行过投保",16,16,RED);
					judge = 0;
					break;	
				}*/
				else 
				{
					return 1;
				}
			}
			case 3:
			{
				clrmous(MouseX,MouseY);
				setfillstyle(1,WHITE);
				bar(428,368,632,472);
				//save_bk_mou(MouseX,MouseY);
				judge = cinplate(plate,&MouseX,&MouseY);
				break;
			}
			case 4:
			{
				delay(100);
				clrmous(MouseX,MouseY);
				judge = carleixing(pinpai);
				break;
			}
			case 5:
			{
				delay(100);
				//save_bk_mou(MouseX,MouseY);
				clrmous(MouseX,MouseY);
				judge = choosepcity(pcity);
				break;
			}
			case 6:
			{
				clrmous(MouseX,MouseY);
				delay(100);
				judge = why();
				break;
			}
		}
	}
}
/****************************************
Function :why(void)
Description:为什么在好车主购车险？
Attention:无
Return：上一个界面的judge值
***************************************/
int why(void)
{
	int judge  = 0;
	int press,MouseX,MouseY;
	setfillstyle(1,WHITE);
	bar(120,90,520,390);
	setcolor(CYAN);
	rectangle(120,90,520,390);
	setcolor(GREEN);
	outtextxy(130,100,"Q1");
	puthz(160,100,"为什么在好车主购车险？",16,20,GREEN);
	outtextxy(130,130,"Answer");
	puthz(130,160,"价格透明",16,16,BROWN);
	puthz(140,185,"无中间环节 ",16,16,LIGHTGRAY);
	puthz(130,210,"操作便捷",16,20,BROWN);
	puthz(140,235,"一键查报价 自助便捷",16,16,LIGHTGRAY);
	puthz(130,260,"养车更省钱",16,20,BROWN);
	puthz(140,285,"平安自营 服务有保障",16,20,LIGHTGRAY);
	puthz(130,310,"理赔及时",16,20,BROWN);
	puthz(140,335,"管理员处理及时",16,20,LIGHTGRAY);
	setfillstyle(1,CYAN);
	bar(270,355,370,385);
	puthz(280,363,"我知道了",16,20,WHITE);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >= 270 && MouseX  <=370 && MouseY >= 355 && MouseY <= 385&& press)
		{
			return -1;
		}
	}
}
/****************************************
Function :choosepcity(char *pcity)
Description:选择省份函数
Attention:无
Return：上一个界面的judge值
***************************************/
int choosepcity(char *pcity)
{
	int judge=0;
	int i=0,j=0,p=0;
	char name[35][3]={"京","津","沪","渝","冀",
				  "豫","云","辽","黑","湘",
				 "皖","鲁","新","苏","浙",
				 "赣","鄂","桂","甘","晋",
				 "蒙","陕","吉","闽","贵",
				 "粤","青","藏","川","宁",
				 "琼","台","港","澳"};
	setfillstyle(1,LIGHTGRAY);
	bar(145,175,455,355);
	setfillstyle(1,WHITE);
	bar(150,180,450,350);
	puthz(160,190,"请选择您的车牌省份",16,20,BLACK);
	setcolor(LIGHTGRAY);
	line(150,220,450,220);
	line(150,250,450,250);
	line(150,280,450,280);
	line(150,310,450,310);
	
	line(150,340,270,340);
	line(180,220,180,340);
	line(210,220,210,340);
	line(240,220,240,340);
	line(270,220,270,340);
	line(300,220,300,310);
	line(330,220,330,310);
	line(360,220,360,310);
	line(390,220,390,310);
	line(420,220,420,310);
	for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
		{
			p=i*10+j;
			puthz(160+j*30,230+i*30,name[p],16,20,LIGHTGRAY);
			if(p==34) break;
		}
	}
	setfillstyle(1,CYAN);
	bar(350,315,450,350);
	puthz(360,325,"取消",16,30,WHITE);
	i=0,j=0,p=0;
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>=150 &&MouseX<=450&&MouseY>= 180&&MouseY<= 350&&press)
		{
			if(MouseX>=350 &&MouseX<=450&&MouseY>= 315&&MouseY<= 350&&press)
			{
				return -1;
			}
			else if(!(MouseX>=270 &&MouseX<=350&&MouseY>= 310&&MouseY<= 350&&press))
			{
				i=(MouseY-220)/30;
				j=(MouseX-150)/30;
				p=i*10+j;
				strcpy(pcity,name[p]);
				delay(100);
				return -1;
			}
		}
	}
}
/****************************************
Function :cinplate(char *plate,int *MouseX,int *MouseY)
Description:输入车牌函数
Attention:无
Return：上一个界面的judge值
***************************************/
int cinplate(char *plate,int *MouseX,int *MouseY)
{
	char *p = plate;   //输入字符的中间指针变量
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
	rectangle(200,130,420,170);
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(!(*MouseX >= 200 && *MouseX <= 400 && *MouseY >= 130 && *MouseY <= 170) && press)
		{
			setcolor(LIGHTGRAY);
			rectangle(200,130,420,170);
			return ;
		}
		//如果按了回删键 
		if (key == 0xe08)
		{
			if (p != plate)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(197 + i * 11, 132, 208 + i * 11, 168);
				//backgroundChange(*MouseX, *MouseY, 197 + i * 11, 132, 208 + i * 11, 168);
				p--;
				i--;
			}
			*p = '\0';
		}
		setcolor(LIGHTGRAY);
		/*将按键对应的字符存入plate数组中*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<6)
		{
			/*将字符显示出来*/
			setfillstyle(1, WHITE);
			bar(208 + i * 11, 132, 219 + i * 11, 168);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(208+ i * 11, 137, temp);
			//backgroundChange(*MouseX, *MouseY, 208 + i * 11, 132, 219 + i * 11, 168);

			/*将字符存入数组中*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :carleixing (char *pinpai)
Description:选择车辆品牌函数
Attention:无
Return：上一个界面的judge值
***************************************/
int carleixing (char *pinpai)
{
	char name[15][10]={"奥迪","宝马","别克","比亚迪","长安",
	                 "雪弗兰","保时捷","福特","长城","本田"	,				
					 "现代","起亚","日产","丰田","大众"
	};
	int i1=0,j1=0, p1=0;
	int i2,j2,p2;
	setfillstyle(1,LIGHTGRAY);
	bar(115,145,525,435);
	setfillstyle(1,WHITE);
	bar(120,150,520,430);
	
	setfillstyle(1,CYAN);
	bar(480,150,520,180);
	setcolor(RED);
	line(490,155,510,175);
	line(510,155,490,175);
	setcolor(LIGHTGRAY);
	line(120,200,520,200);
	line(120,250,520,250);
	line(120,300,520,300);
	line(120,350,520,350);
	line(200,200,200,350);
	line(280,200,280,350);
	line(360,200,360,350);
	line(440,200,440,350);
	line(520,200,520,350);
	for(i1=0;i1<3;i1++)
	{
		for(j1=0;j1<5;j1++)
		{
			puthz(140+j1*80,215+i1*50,&name[p1],16,20,BLACK);
			p1++;
		}
	}
	puthz(130,400,"没有您的品牌，请点击这里",16,20,CYAN);
	setcolor(CYAN);
	line(130,420,370,420);
	save_bk_mou(MouseX,MouseY);
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=480 &&MouseX <=520 &&MouseY >=150  &&MouseY <= 180 &&press)
		{
			return -1;
		}
		if(MouseX >=120 &&MouseX <=520 &&MouseY >=150  &&MouseY <= 350 &&press)
		{
			i2=(MouseY-150)/50;
			j2=(MouseX-120)/80;
			p2=(i2-1)*5+j2;
			strcpy(pinpai,name[p2]);
			delay(100);
			return -1;
		}
		if(MouseX >=130 &&MouseX <=370 &&MouseY >=400  &&MouseY <= 420 &&press)
		{
			strcpy(pinpai,"其他");
			delay(100);
			return -1;
		}
	}
	
}
/****************************************
Function :nopolicy(setuser *person)
Description:保单数过多提示函数
Attention:无
Return：上一个界面的judge值
***************************************/
int  nopolicy(setuser *person)
{
	cleardevice();
	setbkcolor(BLACK);
	
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,660,480);
	setcolor(CYAN);
	puthz(20,20,"尊敬的",32,35,GREEN);
	settextstyle(DEFAULT_FONT,0,3);
	outtextxy(130,23,person->accounts);
	puthz(280,20,"用户",32,35,GREEN);
	puthz(40,70,"我们很抱歉地通知您，由于您的账户已经申请过多保险，您已经无法申请新的保险，我们非常理解您的感受",16,20,BLACK);
	puthz(40,120,"如果您仍需申请保单，您可以人工办理或者联系好车主的客服进行申诉",16,20,BLACK);
	puthz(40,170,"您的满意始终是我们的第一服务宗旨",16,20,BLACK);
	puthz(40,220,"同时非常感谢您的理解与支持",16,20,BLACK);
	settextstyle(2,0,6);
	setcolor(BLACK);
	puthz(30,400,"申诉电话",16,20,BLACK);
	outtextxy(180,400,"888-88888");
	puthz(30,430,"客服联系方式",16,20,BLACK);
	outtextxy(180,430,"16868686868");
	setfillstyle(1,CYAN);
	bar(540,445,640,480);
	puthz(550,455,"返回",16,30,WHITE);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=540 &&MouseX <=640 &&MouseY >=445  &&MouseY <= 480 &&press)
		{
			return -1;
		}
	}
}
