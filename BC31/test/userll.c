/*************************************************************
用户的链表/       个人中心->修改密码    /     用户个人中心主函数
Function list:    createuserlist	构造用户链表（前提：传入一个头指针，根
                                   据C>test>t_file>user>accandco.txt文件中
								   的信息构建用户链若accandco.txt文件被清
								   空，要在其开头用记事本加上#号才能正常创
								   建链表！并且首尾两指针无数据）
				  freeuserlist     释放用户链表，把用户链表的头指针置为NULL
				  searchaccounts   根据用户链表头指针和账户名，搜索密码
				  saveinftolist    将person的信息存入链表中
				  changenewcode    修改用户在链表中的密码
***************************************************************/
#include "common.h"
#include "userll.h"
#include "userself.h"
/**************************************
创建用户链表
*****************************************/
void createuserlist(setuser *head)
{
	 FILE *fp=NULL; //打开文件的指针
	 setuser *now=NULL;
	 char cha;    //用于接收并传送文件内部字符的中间变量
     char *p=NULL;   //指向需要接收字符的地址的指针变量

	 
	 now=head;//now指向表头
	 p=head->accounts;
	 strcpy(head->code," ");//将密码初始化
	 
	if ((fp = fopen("./t_file/user/accandco.txt", "r+")) == NULL)//以读写的方式打开
    {
	  closegraph();
	  printf("Can't open accandco.txt");
	  //getchar();
	  exit(1);
    }

	 while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	 {
		 cha=fgetc(fp);//读取一个字符
		 
		 if(cha=='#')//#默认为账户名的开始和密码串的结束
		 {
	        if((now->next=(setuser*)malloc(sizeof(setuser)))==NULL)
			{
				closegraph();
				printf("\n OUT OF MEMORY!");
		       // getchar();
		        exit(1);
		    }
            now=now->next;

	        *p='\0';
	        p=now->accounts;
	     }
	     else if(cha=='*')      //表示账户串的结束，密码串的开始
	        {
	           *p='\0';           
	           p=now->code;
	        }
	     else if(cha!=' '&&cha!='\n')       //将对应的账户串或密码串装入链表中
	        {
	            *p=cha;
	            p++;
	        }
     }

     strcpy(now->code, "   "); //密码初始化
     now->next=NULL;
     fclose(fp);
}
/****************************************
 freeuserlist
释放链表的内存空间并将头指针置为NULL
文件必须按要求格式化书写;
一定要把指针的地址传过来
*****************************************/
void freeuserlist(setuser **head)
{
   setuser *per= *head;
   setuser *cur=(*head)->next;
   if(*head==NULL)return ;
   
   
   while(cur!=NULL)
   {
     free(per);
	 per=cur;
	 cur=cur->next;
   }
	free(per);
	*head=NULL;
}
/********************************************************
Function: saveinftolist
Description: 将person的账号、密码信息存入链表中

*********************************************************/
void saveinftolist(setuser **head,setuser *person)
{
   setuser *per= *head;
   setuser *cur=(*head)->next;
   if(head==NULL)return ;
   while(strcmp(cur->accounts,person->accounts)!=0)
   {
	 if(cur==NULL)return;
	 per=cur;
	 cur=cur->next;
   }
   if(strcmp(cur->accounts,person->accounts)==0)
   {
	  strcpy(cur->code,person->code);
      //cur->money=person->money;
      //cur->spend=person->spend;
	  //strcpy(cur->plate,person->plate);
	 // strcpy(cur->size,person->size);
   }
}
/***********************************************************
Function: searchaccounts
Description: 根据传进函数的账户字符串，
             在建立的用户链表中，搜索相应密码，如果
			 找到了返回其对应的密码字符串（地址），否则返回NULL。
Attention: 传入用户链表的头指针和账户字符串
*************************************************************/
char *searchaccounts(setuser *head, char *str)
{
   setuser *cur=head;
   while((cur!=NULL)&&( strcmp(cur->accounts,str)!=0))
   {
      cur=cur->next;
	}
   if(strcmp(cur->accounts,str)==0)
    {
      return cur->code;
	}
     else 
	 {
	   return NULL;
	 }
} 
/*************************
Function:changenewcode
Description:修改用户在链表中的密码
***************************/
void changenewcode(setuser **head ,setuser *person)
{
	  setuser *per= *head;
   setuser *cur=(*head)->next;
   if(head==NULL)return ;
   while(strcmp(cur->accounts,person->accounts)!=0)
   {
	 if(cur==NULL)return;
	 per=cur;
	 cur=cur->next;
   }
   if(strcmp(cur->accounts,person->accounts)==0)
   {
	  strcpy(cur->code,person->code);
   }
}
