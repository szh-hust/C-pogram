/*************************************************************
�û�������/       ��������->�޸�����    /     �û���������������
Function list:    createuserlist	�����û�����ǰ�᣺����һ��ͷָ�룬��
                                   ��C>test>t_file>user>accandco.txt�ļ���
								   ����Ϣ�����û�����accandco.txt�ļ�����
								   �գ�Ҫ���俪ͷ�ü��±�����#�Ų���������
								   ������������β��ָ�������ݣ�
				  freeuserlist     �ͷ��û��������û������ͷָ����ΪNULL
				  searchaccounts   �����û�����ͷָ����˻�������������
				  saveinftolist    ��person����Ϣ����������
				  changenewcode    �޸��û��������е�����
***************************************************************/
#include "common.h"
#include "userll.h"
#include "userself.h"
/**************************************
�����û�����
*****************************************/
void createuserlist(setuser *head)
{
	 FILE *fp=NULL; //���ļ���ָ��
	 setuser *now=NULL;
	 char cha;    //���ڽ��ղ������ļ��ڲ��ַ����м����
     char *p=NULL;   //ָ����Ҫ�����ַ��ĵ�ַ��ָ�����

	 
	 now=head;//nowָ���ͷ
	 p=head->accounts;
	 strcpy(head->code," ");//�������ʼ��
	 
	if ((fp = fopen("./t_file/user/accandco.txt", "r+")) == NULL)//�Զ�д�ķ�ʽ��
    {
	  closegraph();
	  printf("Can't open accandco.txt");
	  //getchar();
	  exit(1);
    }

	 while(!feof(fp))//�ļ���ȡ����������ļ���������ֵ��1������Ϊ0
	 {
		 cha=fgetc(fp);//��ȡһ���ַ�
		 
		 if(cha=='#')//#Ĭ��Ϊ�˻����Ŀ�ʼ�����봮�Ľ���
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
	     else if(cha=='*')      //��ʾ�˻����Ľ��������봮�Ŀ�ʼ
	        {
	           *p='\0';           
	           p=now->code;
	        }
	     else if(cha!=' '&&cha!='\n')       //����Ӧ���˻��������봮װ��������
	        {
	            *p=cha;
	            p++;
	        }
     }

     strcpy(now->code, "   "); //�����ʼ��
     now->next=NULL;
     fclose(fp);
}
/****************************************
 freeuserlist
�ͷ�������ڴ�ռ䲢��ͷָ����ΪNULL
�ļ����밴Ҫ���ʽ����д;
һ��Ҫ��ָ��ĵ�ַ������
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
Description: ��person���˺š�������Ϣ����������

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
Description: ���ݴ����������˻��ַ�����
             �ڽ������û������У�������Ӧ���룬���
			 �ҵ��˷������Ӧ�������ַ�������ַ�������򷵻�NULL��
Attention: �����û������ͷָ����˻��ַ���
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
Description:�޸��û��������е�����
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
