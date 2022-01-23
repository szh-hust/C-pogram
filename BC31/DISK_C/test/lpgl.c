#include "common.h"
#include "lpgl.h"
#include "duqu.h"
/*********************************************
存放管理员 审批用户申请的理赔的相关函数
Function List :
				lpguanli         理赔管理主函数
				drawlpguanli     绘制理赔管理部分界面
				showlp           选出未受理的理赔并显示
				gldulp           管理员读取理赔
*************************************************/
int lpguanli()
{
	int press,MouseX,MouseY;
	int driver = VGA;
	int mode = VGAHI;
	int judge = 0;
	int k=0; // k 表示 要展示的第几个
	struct CLAIM claimall[50];
	struct CLAIM claimu [50]; 
	int num = 0;//num使用形参 表示 待审批的个数
	int i=0,j=0;
	int flagok=0;
	int gaibian;//claimall中改变的第几个
	long  fanhuan;
	long  yuanmoney;
	for(i=0;i<50;i++)
	{
		j=duqulpgly(i,claimall);
	}
	jisuan(claimall,claimu,&num);
	if(num ==0)
	{
		judge = 3;
	}
	else {
		showlp(claimu, k,num);
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if(flagok !=1&&MouseX>=180&&MouseX<=200&&MouseY>=320&&MouseY<=340&&press)
		{
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(190,370,10,10);
			setfillstyle(1,CYAN);
			fillellipse(190,330,10,10);
			bar(540,445,640,480);
			puthz(560,455,"确认",16,30,WHITE);
			claimu[k].zhuangtai = 1;
			flagok = 1;
			delay(100);
		}
		if(flagok !=2&&MouseX>=180&&MouseX<=200&&MouseY>=360&&MouseY<=380&&press)
		{
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGRAY);
			setfillstyle(1,WHITE);
			fillellipse(190,330,10,10);
			setfillstyle(1,CYAN);
			fillellipse(190,370,10,10);
			bar(540,445,640,480);
			puthz(560,455,"确认",16,30,WHITE);
			claimu[k].zhuangtai = 2;
			flagok = 2;
			delay(100);
		}
		if(MouseX>=0&&MouseX<=100&&MouseY>=455&&MouseY<=480&&press)
		{
			judge = 2;
		}
		if((flagok ==1||flagok == 2)&&MouseX>=540&&MouseX<=640&&MouseY>=455&&MouseY<=480&&press)
		{
			judge = 1;
		}
		if(k!=0 && MouseX>= 145 && MouseX <= 185&&MouseY>=395&&MouseY<=420&&press)
		{
			k=0;
			judge = -1;
			delay(100);
		}
		if(k!=0 && MouseX>= 195 && MouseX <= 255&MouseY>=395&&MouseY<=420&&press)
		{
			k = k-1;
			judge = -1;
			delay(100);
		}
		if((k +1)!= num && MouseX>= 265 && MouseX <= 325&MouseY>=395&&MouseY<=420&&press)
		{
			k = k+1;
			judge = -1;
			delay(100);
		}
		if((k +1) != num && MouseX>=335 && MouseX <= 375&MouseY>=395&&MouseY<=420&&press)
		{
			k = num-1;
			judge = -1;
			delay(100);
		}
		switch(judge)
		{
			case -1:
			{
				clrmous(MouseX,MouseY);
				delay(100);
				drawlpguanli();
				jisuan(claimall,claimu,&num);
				if(num == 0)
				{
					judge = 3;
				}
				else 
				{
					showlp(claimu, k,num);
					judge = 0;
				}
				break;
			}
			case 1:
			{
				for(i=0;i<50;i++)
				{
					if(strcmp(claimall[i].bdh,claimu[k].bdh)==0)
					{
						gaibian = i;
						i=0;
						break;
					}
				}
				changezt(gaibian,flagok);
				if(flagok ==1)
				{
					fanhuan = atol(claimall[i].claimmoney);
					dumoney(claimall[i].accounts,&yuanmoney);
					fanhuan += yuanmoney;
					changemoney(claimall[i].accounts,fanhuan);
				}
				clrmous(MouseX,MouseY);
				judge = queren("处理成功！",230,180,32,30,-1);
				gaibian = 0;
				k=0;
				flagok = 0;
				delay(200);
				return judge;	
			}
			case 2:
			{
				clrmous(MouseX,MouseY);
				delay(100);
				return -1;
			}
			case 3:
			{
				clrmous(MouseX,MouseY);
				delay(100);
				judge = wulipei();
				break;
			}			
		}
	}
}
int wulipei()
{
	//cleardevice();
	//setbkcolor(BLACK);
	//setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(120,90,520,390);//400*300
	setcolor(CYAN);
	setlinestyle(SOLID_LINE,0,3);
	rectangle(140-15,110-15,140+15,110+15);
	rectangle(140-15,370-15,140+15,370+15);
	rectangle(500-15,110-15,500+15,110+15);
	rectangle(500-15,370-15,500+15,370+15);
	rectangle(145,115,495,365);
	line(140-5,110+15+5,140-5,370-15-5);
	line(500+5,110+15+5,500+5,370-15-5);
	line(140+15+5,110-5,500-15-5,110-5);
	line(140+15+5,370+5,500-15-5,370+5);
	setlinestyle(SOLID_LINE,0,1);
	setcolor(BLACK);
	rectangle(120,90,520,390);
	//Drawbeautiful();
	puthz(230,160,"暂无可以处理的理赔",16,16,CYAN);
	setfillstyle(1,CYAN);
	bar(270,350,370,380);
	puthz(300,360,"返回",16,20,WHITE);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>=270&&MouseX<=370&&MouseY>=350&&MouseY<=380&&press)
		{
			return 2;
		}
	}
}
void drawlpguanli()
{
	cleardevice();
	setbkcolor(BLACK);
	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,60);
	puthz(220,10,"理赔管理",32,50,WHITE);
	puthz(20,80,"您可审核的理赔如下",16,20,GREEN);
	//puthz(20,110,"点击下一页可翻页",16,20,BLACK);
	setcolor(LIGHTGRAY);
	rectangle(20,110,620,430);
	puthz(30,115,"保单号",16,20,BLACK);
	line(20,150,620,150);
	puthz(30,155,"原保额",16,20,BLACK);
	line(20,190,620,190);
	puthz(30,200,"申请理赔金额",16,20,BLACK);
	line(20,230,620,230);
	puthz(30,240,"申请账号",16,20,BLACK);
	line(20,270,620,270);
	puthz(30,280,"联系电话",16,20,BLACK);
	line(20,310,620,310);
	puthz(40,330,"审批",32,40,BLACK);
	line(170,110,170,390);
	circle(190,330,10);
	puthz(210,325,"审批通过",16,20,BLACK);
	line(170,350,620,350);
	
	circle(190,370,10);
	puthz(210,365,"审核不通过",16,20,BLACK);
	line(20,390,620,390);
	
	puthz(150,400,"首页",16,16,LIGHTGRAY);
	rectangle(145,395,185,420);
	puthz(200,400,"上一页",16,16,LIGHTGRAY);
	rectangle(195,395,255,420);
	puthz(270,400,"下一页",16,16,LIGHTGRAY);
	rectangle(265,395,325,420);
	puthz(340,400,"尾页",16,16,LIGHTGRAY);
	rectangle(335,395,375,420);
	puthz(400,400,"第 页，共 页",16,20,LIGHTGRAY);
	setfillstyle(1,CYAN);
	bar(0,445,100,480);
	puthz(20,455,"返回",16,30,WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(540,445,640,480);
	puthz(560,455,"确认",16,30,WHITE);
	
}
void jisuan(struct CLAIM claimall[50],struct CLAIM claimu[50],int *num)
{
	int i=0,j = 0;
	char kstr[2] = {'\0','\0'};
	char numstr[2]= {'\0','\0'};
	for(i=0;i<50;i++)
	{
		if(claimall[i].flag==1&&claimall[i].zhuangtai==0)
		{
			strcpy(claimu[j].accounts,claimall[i].accounts);
			strcpy(claimu[j].bdh,claimall[i].bdh);
			strcpy(claimu[j].ybe,claimall[i].ybe);
			strcpy(claimu[j].claimmoney,claimall[i].claimmoney);
			strcpy(claimu[j].dianhua,claimall[i].dianhua);
			claimu[j].flag = claimall[i].flag;
			claimu[j].zhuangtai = claimall[i].zhuangtai;
			strcpy(claimu[j].dianhua,claimall[i].dianhua);
			j = j + 1;
		}
	}
	*num = j;
}
void showlp(struct CLAIM claimu[50],int k,int num)
{
	char kstr[2] = {'\0','\0'};
	char numstr[2]= {'\0','\0'};
	setcolor(BLACK);
	outtextxy(190,115,claimu[k].bdh);
	outtextxy(190,155,claimu[k].ybe);
	outtextxy(190,195,claimu[k].claimmoney);
	outtextxy(190,235,claimu[k].accounts);
	outtextxy(190,275,claimu[k].dianhua);
	if(k==0)
	{
		clrmous(MouseX,MouseY);
		setfillstyle(1,LIGHTGRAY);
		bar(145,395,185,420);
		puthz(150,400,"首页",16,16,WHITE);
		bar(195,395,255,420);
		puthz(200,400,"上一页",16,16,WHITE);
	}
	if((k+1)==num)
	{
		clrmous(MouseX,MouseY);
		setfillstyle(1,LIGHTGRAY);
		bar(265,395,325,420);
		bar(335,395,375,420);
		puthz(270,400,"下一页",16,16,WHITE);
		puthz(340,400,"尾页",16,16,WHITE);	
	}
	kstr[0] = k +1+ '0';
	numstr[0] = num +'0';
	outtextxy(418,398,kstr);
	outtextxy(500,398,numstr);
}
/*****************************************************
Function ：
******************************************************/
int duqulpgly(int i,struct CLAIM claim[50])
{
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p1=NULL;   //指向需要接收字符的地址的指针变量
	char accounts[11]={'\0'};
	char bdh[9]={'\0'};
	char ybe[10]={'\0'};
	char claimmoney[10]={'\0'};
	char dianhua[12]={'\0'};
	char  zhuangtai[2]={'\0','\0'};
	/*zhuangtai==0表示未使用  zhuangtai==1表示管理员已同意 zhuangtai==2 表示管理员不同意*/
	char flagstr[2]={'\0','\0'};
	int zt=0;
	int f=0;
	int flag=0;
	int judge = -1;
	int m = 0;
	/*标志人工理赔 1 还是自助理赔 2 的变量*/
	if ((fp = fopen("./t_file/user/claim.txt", "r+")) == NULL)
	{
		closegraph();
		printf("Can't open claim.txt");
		getchar();
		exit(1);
	}
	///fseek(fp,0L,SEEK_SET);
	while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	{
		cha=fgetc(fp);//读取一个字符
		if(cha=='/')//'/'默认为账户名的开始
		{
			judge++;
			flag=1;
			p1=accounts;
			m=0;
		}
		else if(cha=='#'&&flag==1&&judge==i)
		{
			flag=2;
		    m++;
		}
		else if(cha=='#'&&flag==2)
		{
			m++;
		}
		else if(cha!='\0'&&judge==i)
		{
			*p1=cha;
			 p1++;
		}
		if(m==1&&cha=='#')
		{
			p1=bdh;
		}
		   if(m==2&&cha=='#')
		  {
			  p1=claimmoney;
		  }
		   if(m==3&&cha=='#')
		  {
			  p1=zhuangtai;
		  }
		   if(m==4&&cha=='#')
		  {
			  p1=ybe;
		  }
		   if(m==5&&cha=='#')
		  {
			  p1=dianhua;
		  }
		   if(m==6&&cha=='#')
		  {
			  p1=flagstr;
		  }
	}
	strcpy(claim[i].accounts,accounts);
	f=atoi(flagstr);
	zt=atoi(zhuangtai);
	strcpy(claim[i].bdh,bdh);
	strcpy(claim[i].claimmoney,claimmoney);
	claim[i].zhuangtai=zt;
	strcpy(claim[i].ybe,ybe);
	strcpy(claim[i].dianhua,dianhua);
    claim[i].flag=f;
	fclose(fp);
	return (judge +1);
}
/*************************
Function ：i是第几个 j是要改变的值
***************************/
int changezt(int i,int j)
{
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p1=NULL;   //指向需要接收字符的地址的指针变量
	int judge=-1;
	int m=0;
	char j_str[2]={'\0','\0'};
	j_str[0]=48+j;
	p1=&j_str;
	if ((fp = fopen("./t_file/user/claim.txt", "r+")) == NULL)
	{
		closegraph();
		printf("Can't open claim.txt");
		getchar();
		exit(1);
	}
    while (!feof(fp))
	{
		cha = fgetc(fp);
		if(cha=='/')//'/'默认为账户名的开始
		{
			judge++;
		}
		if(judge==i&&cha=='#')
		{
			m++;
		}
		if(m==3&&cha=='#')
		{
			fseek(fp,0,SEEK_CUR);
			fputs(j_str,fp);
			//putc(*p1,fp);
			fclose(fp);
			break;
		}
	}
}
