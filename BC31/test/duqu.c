#include "common.h"
#include "duqu.h"
#include <string.h>
/****************************************
Function : duqu(setuser *person,struct POLICY policy[10],int i)
Description:读取保单信息
Attention:无
Return：该用户保单总数
***************************************/
int duqu(setuser *person,struct POLICY policy[10],int i)
{
	int j,k;
	int z,x;
	int flag=0;
	int judge=-1;
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p1=NULL;   //指向需要接收字符的地址的指针变量
	//char **p2=NULL;
	char accounts[11]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char pcity[3]={'\0'};//车牌地区
	char plate[7]={'\0'};//车牌
	char pinpai[15]={'\0'};
	char sfzh[19]={'\0'};//身份证号
	char dianhua[12]={'\0'};//电话
	char chejia[9]={'\0'};//车架号
	char fdjh[9]={'\0'};//发动机号
	char time[2]={'\0'};//日期
	char money_str[6][10]={{'0'},{'0'},{'0'},{'0'},{'0'},{'0'}};
	char baofei[6][10]={{'0'},{'0'},{'0'},{'0'},{'0'},{'0'}};
	char flagnewstr[6]={'\0'};
	int flagnew[6];
	char bdh[9]={'\0'};
	char ztstr[2]={'0'};
	int m=0;
	z=0;
	x=0;
	if ((fp = fopen("./t_file/user/policy.txt","r+")) == NULL)//以读写的方式打开
    {
	  closegraph();
	  printf("Can't open policy.txt");
	  //getchar();
	  exit(1);
    }
	//return judge ;
	while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	{
		cha=fgetc(fp);//读取一个字符
		if(cha=='/')//'/'默认为账户名的开始
		{
			for(k=0;k<11;k++)
	    	{
				 accounts[k]='\0';
			}
			flag=1;
			p1=accounts;
			m=0;
		}
		else if(cha=='#'&&flag==1)
		{
			flag=2;
			if(strcmp(accounts,person->accounts)==0)
		    judge++;
		    m++;
		}
		else if(cha=='#'&&flag!=1)
		{
			m++;
		}
		else if(cha!='\0'&&flag==1)
		{
			*p1=cha;
			 p1++;
		}
		else if(cha!='\0'&&flag==2&&judge==i&&(m<4||(m>15&&m<=22)))
		{
			*p1=cha;
			p1++;
		}
		else if(cha!='\0'&&flag==2&&judge==i&&m>=4&&m<=9)
		{
				money_str[z][x]=cha;
				x++;
		}
		else if(cha!='\0'&&flag==2&&judge==i&&m>=10&&m<=15)
		{
			   baofei[z][x]=cha;
			   x++;
		}
		if(flag==2&&judge==i&&m==1&&cha=='#')
		{
			p1=pcity;
		}
		   if(flag==2&&judge==i&&m==2&&cha=='#')
		  {
			  p1=plate;
		  }
		    if(flag==2&&judge==i&&m==3&&cha=='#')
		  {
			  p1=pinpai;
		  }
		    if(flag==2&&judge==i&&m==4&&cha=='#')
		  {
			  z=0;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==5&&cha=='#')
		  {
			  z=1;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==6&&cha=='#')
		  {
			  z=2;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==7&&cha=='#')
		  {
			  z=3;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==8&&cha=='#')
		  {
			 
			  z=4;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==9&&cha=='#')
		  {
			  z=5;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==10&&cha=='#')
		  {
			  z=0;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==11&&cha=='#')
		  {
			  z=1;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==12&&cha=='#')
		  {
			  z=2;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==13&&cha=='#')
		  {
			  z=3;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==14&&cha=='#')
		  {
			  z=4;
			  x=0;
		  }
		    if(flag==2&&judge==i&&m==15&&cha=='#')
		  {
			  z=5;
			  x=0;
		  } 
		    if(flag==2&&judge==i&&m==16&&cha=='#')
		  {
			  p1=flagnewstr;
		  }  
		    if(flag==2&&judge==i&&m==17&&cha=='#')
		  {
			  p1=chejia;
		  }  
		    if(flag==2&&judge==i&&m==18&&cha=='#')
		  {
			  p1=fdjh;
		  }
		   if(flag==2&&judge==i&&m==19&&cha=='#')
		  {
			  p1=sfzh;
		  }
		   if(flag==2&&judge==i&&m==20&&cha=='#')
		  {
			  p1=dianhua;
		  }
		   if(flag==2&&judge==i&&m==21&&cha=='#')
		  {
			  p1=bdh;
		  }
		   if(flag==2&&judge==i&&m==22&&cha=='#')
		  {
			  p1=ztstr;
		  }
	}
			policy[i].zt = atoi(ztstr);
	     //strcpy(policy[i].accounts,person->accounts);
		  strcpy(policy[i].pcity,pcity);
		  strcpy(policy[i].plate,plate);
		  strcpy(policy[i].pinpai,pinpai);
		  strcpy(policy[i].sfzh,sfzh);
		  strcpy(policy[i].bdh,bdh);
		  strcpy(policy[i].dianhua,dianhua);
		  strcpy(policy[i].chejia,chejia);
		  for(j=0;j<6;j++)
		  {
		  strcpy(policy[i].money_str[j],money_str[j]);
		  }
		   for(j=0;j<6;j++)
		  {
		  strcpy(policy[i].baofei[j],baofei[j]);
		  }
		   for(j=0;j<6;j++)
		  {
				flagnew[j]=atoi(&flagnewstr[j]);
				policy[i].flagnew[j]=flagnew[j];
		  }	  
		  fclose(fp);
	return judge+1 ; 
}
/****************************************
Function : duqulp(setuser *person,struct CLAIM claim[10],int cn)
Description:读取理赔信息函数
Attention:无
Return：该用户理赔总数
***************************************/
int duqulp(setuser *person,struct CLAIM claim[10],int cn)
{
	int j,k;
	int z,x;
	int m=0;
	int flag=0;
	int judge=-1;
	FILE *fp=NULL; //打开文件的指针
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p1=NULL;   //指向需要接收字符的地址的指针变量
	char accounts[11]={'\0'};
	char bdh[9]={'\0'};
	char ybe[10]={'\0'};
	char claimmoney[10]={'\0'};
	char dianhua[12]={'\0'};
	char  zhuangtai[2]={'\0'};
	/*zhuangtai==0表示未使用  zhuangtai==1表示管理员已同意 zhuangtai==2 表示管理员不同意*/
	char flagstr[2]={'\0'};
	int zt=0;
	int f=0;
	/*标志人工理赔 1 还是自助理赔 2 的变量*/
	if ((fp = fopen("./t_file/user/claim.txt","r+")) == NULL)//以读写的方式打开
    {
	  closegraph();
	  printf("Can't open claim.txt");
	  //getchar();
	  exit(1);
    }
	while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	{
		cha=fgetc(fp);//读取一个字符
		if(cha=='/')//'/'默认为账户名的开始
		{
			for(k=0;k<11;k++)
	    	{
				 accounts[k]='\0';
			}
			flag=1;
			p1=accounts;
			m=0;
		}
		else if(cha=='#'&&flag==1)
		{
			flag=2;
			if(strcmp(accounts,person->accounts)==0)
		    judge++;
		    if(judge==cn)
		    m++;
		}
		else if(cha=='#'&&flag==2&&judge==cn)
		{
			m++;
		}
		else if(cha!='\0'&&flag==1)
		{
			*p1=cha;
			 p1++;
		}
		else if(cha!='\0'&&flag==2&&judge==cn)
		{
			*p1=cha;
			 p1++;
		}
		if(flag==2&&judge==cn&&m==1&&cha=='#')
		{
			p1=bdh;
		}
		   if(flag==2&&judge==cn&&m==2&&cha=='#')
		  {
			  p1=claimmoney;
		  }
		   if(flag==2&&judge==cn&&m==3&&cha=='#')
		  {
			  p1=zhuangtai;
		  }
		   if(flag==2&&judge==cn&&m==4&&cha=='#')
		  {
			  p1=ybe;
		  }
		   if(flag==2&&judge==cn&&m==5&&cha=='#')
		  {
			  p1=dianhua;
		  }
		   if(flag==2&&judge==cn&&m==6&&cha=='#')
		  {
			  p1=flagstr;
		  }
	}
	f=atoi(flagstr);
	zt=atoi(zhuangtai);
	strcpy(claim[cn].bdh,bdh);
	strcpy(claim[cn].claimmoney,claimmoney);
	claim[cn].zhuangtai=zt;
	strcpy(claim[cn].ybe,ybe);
	strcpy(claim[cn].dianhua,dianhua);
    claim[cn].flag=f;
	strcpy(claim[cn].accounts,person->accounts);
	fclose(fp);
		return (judge+1);  
}

