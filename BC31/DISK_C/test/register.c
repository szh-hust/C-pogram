/*
���ڽ���ע��Ĺ���
�ɷ�Ϊ:registercinaccounts  ע��ʱ�˺����뺯��
       registercincode      ע��ʱ�������뺯��
       registersecondcode     ע��ʱ�ڶ����������뺯��
	   addnew                 ����ע���û�������ļ�������
	   draw_register
	   userregister           ע�����ĺ�̨����  
*/
#include "common.h"
#include "register.h"
#include "userll.h"
#include "dlogin.h"
/*************************************************
Function: registercinaccounts(char *accounts, int *MouseX, int *MouseY)
Descration:����ע��ʱ���˺�
Attention:
�˺�ֻ���Ǵ�Сд��ĸ��������ֻ������1��10λ
���λ�ò�������Ҫ��ָ����ʽ���ݹ�����
***************************************************/
int registercinaccounts(char *accounts, int *MouseX, int *MouseY)
{
	char *p = accounts;   //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int press;    //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	int key;    //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	while (*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	//���㿪��Ŀ��
	setcolor(RED);
	rectangle(300,150,500,180);
	setcolor(BLACK);
	rectangle(300,215,500,245);
	rectangle(300,275,500,305);
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if (key == 0x1c0d || key == 0x5000||(*MouseX >=300  && *MouseX <=500 && *MouseY >= 215 && *MouseY <= 245 && press) )
		{//�������һ��enter���������*��������*����һ���·����������2��ʾ����registerinputcode����
			return 2; 
		}

		if (*MouseX >= 300 && *MouseX <= 500 && *MouseY >= 275 && *MouseY <= 305 && press)
		{//��������*�ٴ���������*������3��ʾ����registersecondcode����
			return 3;       
		}

		if (*MouseX >= 300 && *MouseX <= 500 && *MouseY >= 320 && *MouseY <= 360 && press)
		{//��������*ȷ��*�����ע�ᣩ������4
			return 4;       
		}
		if (*MouseX >= 0 && *MouseX <= 100 && *MouseY >=440 && *MouseY <= 480 && press)
		{//��������*����*������5��ʾ���ص�¼����
			return 5;       
		}
		
		 if (*MouseX >= 540 && *MouseX <= 640 && *MouseY >= 440&& *MouseY <= 480 && press) 
		{//��������*�˳�ϵͳ*
			return 6;
		}
		//������˻�ɾ�� 
		if (key == 0xe08)
		{
			if (p != accounts)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297 + i * 11, 152, 308 + i * 11, 178);
			//	backgroundChange(*MouseX, *MouseY, 297 + i * 11, 152, 308 + i * 11, 178);
				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����accounts������*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(308 + i * 11, 152, 319 + i * 11, 178);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(308+ i * 11, 155, temp);
			//backgroundChange(*MouseX, *MouseY, 308 + i * 11, 152, 319 + i * 11, 178);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/*************************************************
Function: registercincode (char *code ,int *MouseX,int *MouseY)
Descration:����ע��ʱ�ĵ�һ������
Attention:
�˺�ֻ���Ǵ�Сд��ĸ��������ֻ������1��10λ
���λ�ò�������Ҫ��ָ����ʽ���ݹ�����
***************************************************/
int registercincode (char *code ,int *MouseX,int *MouseY)
{
    char *p = code;   //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int press;    //���Ĳ�������
	int key;    //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	while (*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	setcolor(RED);
	rectangle(300,215,500,245);
	setcolor(BLACK);
	rectangle(300,150,500,180);
	rectangle(300,275,500,305);
	
	while (1)
	{
		newmouse(MouseX,MouseY,&press);

		//���ü�ֵ���õ��¼�ֵ
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 150 && *MouseY <= 180 && press || key == 0x4800)
		{//��������*�˺�����*����һ���Ϸ����������1��ʾ����registerinputaccounts����
			return 1; 
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 275 && *MouseY <= 305 && press|| key == 0x5000 || key == 0x1c0d)
		{//��������*�ٴ���������*����enter�����·���������3��ʾ����registersecondcode����
			return 3;       
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 320 && *MouseY <= 360 && press)
		{//��������*ȷ��*�����ע�ᣩ������4
			return 4;       
		}

		if (*MouseX >=  0  && *MouseX <=100 && *MouseY >= 440 && *MouseY <= 480 && press)
		{//��������*����*������5��ʾ���ص�¼����
			return 5;       
		}
		
		if (*MouseX >= 540 && *MouseX <= 640 && *MouseY >= 440&& *MouseY <= 480 && press) 
		{//��������*�˳�ϵͳ*
			return 6;
		}
		
        /*������˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297 + i * 11, 217, 308 + i * 11, 243);

			//	backgroundChange(*MouseX, *MouseY, 297 + i * 11, 215, 308 + i * 11, 245);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����code������*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;

			/*��һ��Բ*/
			setfillstyle(1, WHITE);
			bar(297 + i * 11, 217, 308 + i * 11, 243);
			setcolor(BROWN);//���û����������滭Բ�ͻ���ȱ��
			setfillstyle(1, BLACK);
			clrmous(*MouseX,*MouseY); 
			pieslice(301 + i * 11, 230, 0, 360, 3);
			//backgroundChange(*MouseX, *MouseY, 297 + i * 11, 217, 308 + i * 11, 243);
		}   		
	}
}

/*************************************************
Function: registersecondcode(char *tcode ,int *MouseX, int *MouseY)
Descration:����ע��ʱ�ĵڶ�������
Attention:
�˺�ֻ���Ǵ�Сд��ĸ��������ֻ������1��10λ
���λ�ò�������Ҫ��ָ����ʽ���ݹ�����
***************************************************/
int registersecondcode(char *tcode ,int *MouseX, int *MouseY)
{
	
	char *p = tcode;//���������ַ�
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	int press=0;//���Ĳ�������	
	int key;//��ʾ��ֵ�ı���
	int i = 0;//���ڼ�����������ַ���Ŀ�ı���
	while (*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	setcolor(RED);
	rectangle(300,275,500,305);
	setcolor(BLACK);
	rectangle(300,150,500,180);
	rectangle(300,215,500,245);
	while (1)
	{
		newmouse(MouseX, MouseY, &press);

		//���ü�ֵ���õ��¼�ֵ
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 150 && *MouseY <= 180 && press )
		{//��������*�˺�����*������1��ʾ����registercinaccounts����
		    
			return 1; 
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 215 && *MouseY <= 245 && press|| key == 0x4800)
		{//��������*��������*������2��ʾ����registercincode����
		    
			return 2;       
		}

		if (*MouseX >=300  && *MouseX <=500 && *MouseY >= 320 && *MouseY <= 360 && press|| key == 0x1c0d)
		{//��������*ȷ��*�����ע�ᣩ����enter��������4
		    
			return 4;       
		}

		if (*MouseX >=   0 && *MouseX <= 100 && *MouseY >= 440 && *MouseY <= 480 && press)
		{//��������*����*������5��ʾ���ص�¼����
			return 5;       
		}
		
		if (*MouseX >= 540 && *MouseX <=640 && *MouseY >= 440&& *MouseY <= 480 && press) 
		{//��������*�˳�ϵͳ*
			return 6;
		}
		
		/*������˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != tcode)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(297 + i * 11, 277, 308 + i * 11, 303);

			//	backgroundChange(*MouseX, *MouseY, 297 + i * 11, 277, 308 + i * 11, 303);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����tcode������*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;

			/*��һ��Բ*/
			setfillstyle(1, WHITE);
			bar(297 + i * 11, 277, 308 + i * 11, 303);
			setcolor(BROWN);//���û����������滭Բ�ͻ���ȱ��
			setfillstyle(1, BLACK);
			clrmous(*MouseX,*MouseY); 
			pieslice(301 + i * 11, 290, 0, 360, 3);
			//backgroundChange(*MouseX, *MouseY, 297 + i * 11, 277, 308 + i * 11, 303);
		}   		
	}
}
/************************************************************************
  ��ע��õ��û����˺ź�������뵽�û������У�����ӽ��ļ�
              C>test>t_file>user>accandco.txt��
 ���û�������ڵ�ֱ�Ӳ��뵽ͷ�ڵ�֮��
***********************************************************************/
int addnew(setuser *head,char *accounts,char *code)	
{
	FILE *fp;
	char *p;
	int i=0;
	setuser *newnode=(setuser *)malloc(sizeof(setuser));
	if(newnode==NULL)
	{
		closegraph();
		printf("no enough memory!!!");
		//getchar();
		exit(1);
	}
	//�½ڵ���ע��õ��û�����Ϣ
	strcpy(newnode->accounts,accounts);
	strcpy(newnode->code,code);
	//���½ڵ�嵽ͷ�ڵ�head֮��
	newnode->next=head->next;//ע�������Ӻ�Ͽ��������������Ľڵ㶼����ʧ
	head->next=newnode;
	
	//���²��ֽ�ע��õ��û���Ϣд���ļ���
	if((fp=fopen("./t_file/user/accandco.txt","r+"))==NULL)
	{
		closegraph();
		printf("can't open accandco.txt");
		//getchar();
		exit(1);
	}
	fseek(fp,0L,2);//���ļ��ڲ�ָ��ָ���ļ�ĩ��0ƫ�Ƶĵط�
	p=accounts;
	 while(*p!='\0')
     {
	     putc(*p,fp);
	     p++;
     }
      putc('*',fp);
      p=code;
     while(*p!='\0')
     {
	     putc(*p,fp);
	     p++;
     }
     for (i = 0;i < 10 - strlen(code);i++)
	 {
	    putc(' ', fp);
	 }
     putc('#',fp);

     fclose(fp);
	 return 0;
}
/*************************************************
Function:userregister(setuser *head,char *accounts,char *code)
Descration:ע�������� 
Attention:
***************************************************/
int userregister(setuser *head,char *accounts,char *code)
{
	long money =500; 
    int judge=0;   
    int huanchong;//�������ռ��̻������ı���
    int press,MouseX,MouseY;//�����ر���
    int driver=VGA;
    int mode=VGAHI;
    char *rightcode=NULL;//ָ����ȷ�����ָ��
    char tcode[11]={'\0'};//����ڶ�����������룬�������10���ַ�
    int flagone=0,flagtwo=0,flagthree=0;//��־������������Ƿ���������
    *accounts = '\0';
    *code = '\0';
    while(1)
    {
	    newmouse(&MouseX,&MouseY,&press);
	    if (kbhit() != 0)
	    {//���ռ��̻�����������
	    	 huanchong = bioskey(0);      
	    }
	    if (MouseX >= 300 && MouseX <= 500 && MouseY >= 150 && MouseY <= 180 && press)
		{//������˺������
			 judge=1;
		}
		if (MouseX >=300  && MouseX <= 500 && MouseY >= 215 && MouseY <= 245 && press)
		{//�������������
			judge=2;
		}
		if (MouseX >=300  && MouseX <= 500 && MouseY >= 275 && MouseY <= 305 && press)
		{//������ٴ����������
			judge=3;
		}
		if (MouseX >= 300 && MouseX <= 500 && MouseY >= 320 && MouseY <= 360 && press)
		{//�����ȷ�ϣ����ע�ᣩ
			judge=4;
		}
		if (MouseX >=   0 && MouseX <= 100 && MouseY >= 440 && MouseY <= 480 && press)
		{//���������
			judge=5;
		}
        if (MouseX >= 540 && MouseX <= 640 && MouseY >= 440&& MouseY <= 480 && press) 
		{//��������*�˳�*
			judge=6;
		}
		 switch(judge)
		{
		    case -1:
			    {
					return 2;	
		        }
		    case 1://��������*�˺������*
		        {
					clrmous(MouseX,MouseY);
					if(flagone==1)//�ж���������Ƿ�����ʾ�֣������򸲸ǵ�
					{
						setfillstyle(1, WHITE);
						bar(300,150,500,180);
						// backgroundChange(MouseX,MouseY, 300,150,500,180);
						flagone=0;
					}
					judge=registercinaccounts(accounts,&MouseX,&MouseY);
					break;
				}
		    case 2://��������*����������*
		    {
			    clrmous(MouseX,MouseY);
			    if(flagtwo==1)//�ж���������Ƿ�����ʾ�֣������򸲸ǵ�
				{
					setfillstyle(1, WHITE);
			        bar(300,215,500,245);
					flagtwo=0;
				 }
		        judge=registercincode(code,&MouseX,&MouseY);
				break;
		    }
		    case 3://��������*�ٴ���������*
			{
				clrmous(MouseX,MouseY);
				if(flagthree==1)//�ж���������Ƿ�����ʾ�֣������򸲸ǵ�
				{
					setfillstyle(1, WHITE);
			        bar(300,275,500,305);
					flagthree=0;
				}
		        judge=registersecondcode(tcode,&MouseX,&MouseY);
				break;
			}		 
		    case 4://��������*ȷ��*�����ע�ᣩ
		    {
				if(strlen(accounts)<6)//����˺ų�������6
				 {
					 flagone=1;
					 setfillstyle(1, WHITE);
			         bar(300,150,500,180);
				     puthz(305,155,"�˺Ų���������λ��",16,16,LIGHTGRAY);
					 setcolor(BLACK);
					rectangle(300,150,500,180);
					// backgroundChange(MouseX, MouseY,300,150,500,180);
					 *accounts = '\0';//��������������ַ������
					 judge=0;
					 break;
				 } 
				else if(searchaccounts(head,accounts)!=NULL)//���������˺��������û��������ҵ�
				 {
					 flagone=1;
					 setfillstyle(1, WHITE);
			         bar(300,150,500,180);
				     puthz(305,155,"���˺���ע�ᣡ",16,16,LIGHTGRAY);
					 setcolor(BLACK);
					rectangle(300,150,500,180);
					// backgroundChange(MouseX,MouseY,300,150,500,180);
					 *accounts = '\0';//����������˺��ַ������
					 delay(100);
					 judge=0;
					 break;
				 }
				else if(strlen(code)<6)//������볤������6
				 {
					 flagtwo=1; 
					 setfillstyle(1, WHITE);
			         bar(300,215,500,245);
				     puthz(305,220,"���벻��������λ��",16,16,LIGHTGRAY);
					 setcolor(BLACK);
					rectangle(300,215,500,245);
					// backgroundChange(MouseX, MouseY,300,150,500,180);
					 *code = '\0';//��������������ַ������
					 judge=0;
					 break;
				 } 	 
				 else if(strcmp(code, tcode) != 0)//�������͵ڶ�����������벻һ��
				 {
					flagthree=1;
					setfillstyle(1, WHITE);
			        bar(300,275,500,305);
				    puthz(305,280,"������������벻ͬ��",16,16,LIGHTGRAY);
					setcolor(BLACK);
					rectangle(300,275,500,305);
					//backgroundChange(MouseX, MouseY,300,275,500,305);
					*tcode = '\0';//��������ĵڶ��������ַ������
					judge=0;
					break;
				 }	  
				else
				{
					putmoney(accounts,money);
					addnew(head, accounts, code);//��ע��õ��û����˺ź�������뵽�û������У�����ӽ��ļ���									 
					
					judge = queren("���������¼���棡",240,170,16,20,-1);
					*accounts = '\0';//���³�ʼ������ֹ�����쳣
                    *code = '\0';
				    *tcode='\0';
					//return 1;//ע��ɹ�������¼����
				}
		  }
			case 5://�������
			{
				 *accounts = '\0';
	             *code = '\0';
				 *tcode='\0';
				 return 2;
			}
			case 6://����˳�
			{
				*accounts = '\0';//��ע�᷵�ص���¼Ӧ���³�ʼ������ֹ�����쳣������
	             *code = '\0';
				 *tcode='\0';
				 return 4;
			}
		}
  }
}
