/********************************

*************************************/
#include "common.h"
#include "userll.h"

/****************************************
Function :putinoldcode(char *old_code, int *MouseX, int *MouseY)
Description:����ԭ����
Attention:��
Return����һ�������judgeֵ
***************************************/
int putinoldcode(char *old_code, int *MouseX, int *MouseY)
{
	char *p = old_code;   //�����ַ����м�ָ�����
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
	setcolor(RED);
	rectangle(400-50,130,550,170);
	setcolor(BLACK);
	rectangle(400-50,220,550,260);
	rectangle(400-50,310,550,350);
	/*//���㿪��Ŀ��
	AddFrame(*MouseX,*MouseY,400-50,130,550,170,RED);//�˺ſ���
	AddFrame(*MouseX,*MouseY,400-50,220,550,260,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,310,550,350,BLACK);*/
	while(1)
	{
		newmouse(MouseX,MouseY,&press);
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if (key == 0x1c0d || key == 0x5000||(*MouseX >=350  && *MouseX <=550 && *MouseY >= 220 && *MouseY <= 260 && press) )
		{//�������һ��enter���������*��������*����һ���·����������9��ʾ����putinnewcode����
			return 9; 
		}

		if (*MouseX >= 350 && *MouseX <= 550 && *MouseY >= 310 && *MouseY <= 350 && press)
		{//��������*�ٴ���������*������10��ʾ����putinjudgecode����
			return 10;       
		}

		if (*MouseX >= 400 && *MouseX <= 500 && *MouseY >= 380 && *MouseY <= 420 && press)
		{//��������*ȷ��*�����ע�ᣩ������11
			return 11;       
		}
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 50 && *MouseY <= 90 && press)
			return 1;
		//�����ҵ�����
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 90 && *MouseY <= 130 && press)
			return 2;
		//���밮������
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 130 && *MouseY <= 170 && press)
			return 3;
		//�����ҵ�Ǯ��
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 210 && *MouseY <= 250 && press)
			return 5;
		//�����������
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 250 && *MouseY <= 290 && press)
			return 6;	
		//���볣������
		if(*MouseX >=0  && *MouseX <= 150 &&* MouseY >= 290 && *MouseY <= 330 && press)
			return 7;
		//���������ҳ(20,420,120,460)
		if(*MouseX >=20  && *MouseX <= 120 && *MouseY >= 420 &&*MouseY <= 460 && press)
			return 8;
		//������˻�ɾ�� 
		if (key == 0xe08)
		{
			if (p != old_code)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(344 + i * 11, 132, 355 + i * 11, 168);
			//	backgroundChange(*MouseX, *MouseY, 344 + i * 11, 130, 355 + i * 11, 170);
				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����old_code������*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(355 + i * 11, 132, 366 + i * 11, 168);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(355+ i * 11, 135, temp);
		//	backgroundChange(*MouseX, *MouseY, 355 + i * 11, 130, 366 + i * 11, 170);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++;
		}
	}
}
/****************************************
Function :putinnewcode (char *code ,int *MouseX,int *MouseY)
Description:����������
Attention:��
Return����һ�������judgeֵ
***************************************/
int putinnewcode (char *code ,int *MouseX,int *MouseY)
{
    char *p = code;   //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	int press;    //���Ĳ�������
	int key;    //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	while (*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
	setcolor(RED);
	rectangle(400-50,220,550,260);
	setcolor(BLACK);
	rectangle(400-50,130,550,170);
	rectangle(400-50,310,550,350);
	
	/*AddFrame(*MouseX,*MouseY,400-50,130,550,170,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,220,550,260,RED);
	AddFrame(*MouseX,*MouseY,400-50,310,550,350,BLACK);*/
	
	while (1)
	{
		newmouse(MouseX,MouseY,&press);

		//���ü�ֵ���õ��¼�ֵ
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 130 && *MouseY <= 170 && press || key == 0x4800)
		{//��������*�˺�����*����һ���Ϸ����������1��ʾ����registerinputaccounts����
			return 12; 
		}

		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 310 && *MouseY <= 350 && press|| key == 0x5000 || key == 0x1c0d)
		{//��������*�ٴ���������*����enter�����·���������3��ʾ����registersecondcode����
			return 10;       
		}

		if (*MouseX >= 400 && *MouseX <= 500 && *MouseY >= 380 && *MouseY <= 420 && press)
		{//��������*ȷ��*�����ע�ᣩ������11
			return 11;       
		}
		
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 50 && *MouseY <= 90 && press)
			return 1;
		//�����ҵ�����
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 90 && *MouseY <= 130 && press)
			return 2;
		//���밮������
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 130 && *MouseY <= 170 && press)
			return 3;
		//�����ҵ�Ǯ��
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 210 && *MouseY <= 250 && press)
			return 5;
		//�����������
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 250 && *MouseY <= 290 && press)
			return 6;	
		//���볣������
		if(*MouseX >=0  && *MouseX <= 150 &&* MouseY >= 290 && *MouseY <= 330 && press)
			return 7;
		//���������ҳ(20,420,120,460)
		if(*MouseX >=20  && *MouseX <= 120 && *MouseY >= 420 &&*MouseY <= 460 && press)
			return 8;
        /*������˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				setfillstyle(1, WHITE);
				clrmous(*MouseX,*MouseY); 
				bar(344 + i * 11, 132+90, 355 + i * 11, 168+90);

				//backgroundChange(*MouseX, *MouseY, 355 + i * 11, 220, 366 + i * 11, 260);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����new_code������*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(355 + i * 11, 132+90, 366 + i * 11, 168+90);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(355+ i * 11, 135+90, temp);
		//	backgroundChange(*MouseX, *MouseY, 355 + i * 11, 130+90, 366 + i * 11, 170+90);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++; 
		}   		
	}
}
/****************************************
Function :putinjudgecode(char *tcode ,int *MouseX, int *MouseY)
Description:����ȷ������
Attention:��
Return����һ�������judgeֵ
***************************************/
int putinjudgecode(char *tcode ,int *MouseX, int *MouseY)
{
	
	char *p = tcode;//���������ַ�
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������
	int press=0;//���Ĳ�������	
	int key;//��ʾ��ֵ�ı���
	int i = 0;//���ڼ�����������ַ���Ŀ�ı���
	while (*p != '\0')//ʹpָ��'\0',i��ʾ��ǰ�ַ���
	{
		i++;
		p++;
	}
    setcolor(RED);
	rectangle(400-50,310,550,350);
	setcolor(BLACK);
	rectangle(400-50,130,550,170);
	rectangle(400-50,220,550,260);
	/*
	AddFrame(*MouseX,*MouseY,400-50,130,550,170,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,220,550,260,BLACK);
	AddFrame(*MouseX,*MouseY,400-50,310,550,350,RED);*/
	while (1)
	{
		newmouse(MouseX, MouseY, &press);

		//���ü�ֵ���õ��¼�ֵ
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 130 && *MouseY <= 170&& press )
		{//��������*ԭ��������*������1��ʾ����putinoldcode����
		    
			return 12; 
		}

		if (*MouseX >=350  && *MouseX <=550 && *MouseY >= 220 && *MouseY <= 260 && press|| key == 0x4800)
		{//��������*����������*������2��ʾ����putinnewcode����
		    
			return 9;       
		}

		if (*MouseX >= 400 && *MouseX <= 500 && *MouseY >= 380 && *MouseY <= 420 && press)
		{//��������*ȷ��*������޸ģ�������11
			return 11;       
		}
		
		//�����ҵı���
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 50 && *MouseY <= 90 && press)
			return 1;
		//�����ҵ�����
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 90 && *MouseY <= 130 && press)
			return 2;
		//���밮������
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 130 && *MouseY <= 170 && press)
			return 3;
		//�����ҵ�Ǯ��
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 210 && *MouseY <= 250 && press)
			return 5;
		//�����������
		if(*MouseX >=0  && *MouseX <= 150 && *MouseY >= 250 && *MouseY <= 290 && press)
			return 6;	
		//���볣������
		if(*MouseX >=0  && *MouseX <= 150 &&* MouseY >= 290 && *MouseY <= 330 && press)
			return 7;
		//���������ҳ(20,420,120,460)
		if(*MouseX >=20  && *MouseX <= 120 && *MouseY >= 420 &&*MouseY <= 460 && press)
			return 8;
		/*������˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != tcode)
			{
				setfillstyle(1, WHITE);
				
				clrmous(*MouseX,*MouseY); 
				bar(344 + i * 11, 132+90+90, 355 + i * 11, 168+90+90);

				//backgroundChange(*MouseX, *MouseY,  355 + i * 11, 220+90, 366 + i * 11, 260+90);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����jud_code������*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			/*���ַ���ʾ����*/
			setfillstyle(1, WHITE);
			bar(355 + i * 11, 132+90+90, 366 + i * 11, 168+90+90);
			temp[0] = ch;
			settextstyle(2, 0, 6);
			setcolor(BLACK);
			clrmous(*MouseX,*MouseY); 
			outtextxy(355+ i * 11, 135+90+90, temp);
			//backgroundChange(*MouseX, *MouseY, 355 + i * 11, 130+90+90, 366 + i * 11, 170+90+90);

			/*���ַ�����������*/
			*p = ch;
			p++;
			*p = '\0';
			i++; 
		}   		
	}
}
/****************************************
Function :changecode(setuser *head,setuser *person)
Description:�޸�����������
Attention:��
Return����һ�������judgeֵ
***************************************/
int changecode(setuser *head,setuser *person)
{
	FILE *fp = NULL;   
	char ch = '\0';
	char CurrentAccounts[11];
	char *p = NULL;
	int length =0;
	int i;
	//int mark = 0;
	int judge = 0;
	int press,MouseX,MouseY;
	//int driver = VGA;
	//int mode = VGAHI;
    	char old_code[11]="\0";
	char new_code[11]="\0";
	char jud_code[11]="\0";
	char *rightcode=NULL;
	rightcode = searchaccounts(head,(*person).accounts);
	strcpy(CurrentAccounts,rightcode);
                delay(100);
                save_bk_mou(MouseX,MouseY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 50 && MouseY <= 90 && press)
		{
			judge = 1;
		}
		//�����ҵ�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 90 && MouseY <= 130 && press)
		{
			judge = 2;
		}
		//���밮������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 130 &&MouseY <= 170 && press)
		{
			judge = 3;
		}
		//�����޸�����
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 170 &&MouseY <= 210 && press)
		{
			judge = 4;
		}
		//�����ҵ�Ǯ��
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 210 && MouseY <= 250 && press)
		{
			judge = 5;
		}
		//�����������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 250 &&MouseY <= 290 && press)
		{
			judge = 6;
		}
		//���볣������
		if(MouseX >=0  && MouseX <= 150 && MouseY >= 290 &&MouseY <= 330 && press)
		{
			judge = 7;
		}
		//���������ҳ(505,10,590,40)
		if(MouseX >=20  && MouseX <= 120 && MouseY >= 420 &&MouseY <= 460 && press)
		{
			judge = 8;
		}
		if(MouseX >=350  && MouseX <= 550 && MouseY >= 130 && MouseY <= 170 && press)
		{
			judge = 12;
		}
		if(MouseX >=350  && MouseX <= 550 && MouseY >= 220 && MouseY <= 260 && press)
		{
			judge = 9;
		}
		if(MouseX >=350  && MouseX <= 550 && MouseY >= 310 && MouseY <= 350 && press)
		{
			judge = 10;
		}
		if(MouseX >=400  && MouseX <= 500 && MouseY >= 380 && MouseY <= 420 && press)
		{
			judge = 11;
		}
		switch(judge)
		{
			case 1:
		    {
				return 1;
			}
			case 2:
		    {
				return 2;
			}
			case 3:
		    {
				return 3;
			}
			case 4:
		    {
				return 4;
			}
			case 5:
		    {
				return 5;
			}
			case 6:
		    {
				return 6;
			}
			case 7:
		    {
				return 7;
			}
			case 8:
			{
				return 8;
			}
			case 12://���ԭ�����
			{
				clrmous(MouseX,MouseY);
				judge =putinoldcode(old_code,&MouseX,&MouseY);
				break;
			}
			case 9://����������
			{
				clrmous(MouseX,MouseY);
				judge=putinnewcode(new_code,&MouseX,&MouseY);
				break;
			}
			case 10://���ȷ�������
			{
				clrmous(MouseX,MouseY);
				judge=putinjudgecode(jud_code,&MouseX,&MouseY);
				break;
			}
			case 11://���ȷ�ϰ�ť
			{ 
				setfillstyle(1,LIGHTGRAY);
				if(strcmp(new_code,"\0")!=0)//�����벻Ϊ��
				{
					if(strcmp(old_code,(*person).code)==0)
					{
						if(strcmp(old_code,new_code)==0)
						{
							bar(300,360,550,379);
							puthz(300,360,"�¾�������ͬ",16,30,BLACK);
							judge=9;
						}
						else
						{
							if(strcmp(jud_code,new_code)!=0)
							{
								bar(300,360,550,379);
								puthz(300,360,"���������벻��ͬ",16,30,BLACK);
								judge=10;
							}
							else
							{
								bar(300,360,550,379);
								strcpy(person->code,new_code);
								puthz(300,360,"�޸ĳɹ�",16,30,BLACK);
								changenewcode(&head,person);
								//saveinftolist(head,person);
								length = strlen(new_code);
	if ((fp = fopen("./t_file/user/accandco.txt", "r+")) == NULL)
	{
		closegraph();
		printf("Can't open accandco.txt");
		getchar();
		exit(1);
	}
    while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '#')
		{
			ch = fgetc(fp);
			for (p = CurrentAccounts;ch != '*';ch = fgetc(fp))
			{
				*p = ch;
				*(p + 1) = '\0';
				p++;
			}
			if (strcmp(CurrentAccounts, (*person).accounts) == 0)
			{
				p = new_code;
				fseek(fp, 0, SEEK_CUR);
				fputs(new_code, fp);
				for (i = 0;i < 10 - length;i++)
				putc(' ', fp);
			    fclose(fp);
				break;
			}
		}
	}
						 fclose(fp);
						delay(1000);
						return 4;
					   }

					}
				}
				else
				{bar(300,360,550,379);
					puthz(300,360,"ԭ�������",16,30,BLACK);
					judge=8;
				}
			}
			else
			{bar(300,360,550,379);
				puthz(300,360,"������Ϊ��",16,30,BLACK);
				judge=9;
				//fclose(fp);
				//DestroyUList(&UL);
			}
			}
		}
	}
}
//����*�������ġ����޸�����*����Ļ���
/****************************************
Function :drawchangecode(void)
Description:���޸��������
Attention:��
Return����
***************************************/
void drawchangecode(void)
{
	drawuserself();
	setfillstyle(1,RED);
	bar(170,130+40,180,170+40);
	setfillstyle(1,LIGHTGRAY);
	bar(230,110,570,440);
	
	setfillstyle(1,WHITE);
	bar(400-50,130,550,170);//ԭ�����
	bar(400-50,210+10,550,250+10);//�������
	bar(400-50,290+20,550,330+20);//ȷ�������
	
	setfillstyle(1,CYAN);
	bar(400,380,500,420);//ȷ�Ͽ�
	setcolor(BLACK);
	puthz(250,140,"ԭ����",16,25,BLACK);
	puthz(250,230,"������",16,25,BLACK);
	puthz(250,320,"ȷ������",16,25,BLACK);
	puthz(420,390,"ȷ��",16,35,WHITE);
	rectangle(400-50,130,550,170);
	rectangle(400-50,210+10,550,250+10);
	rectangle(400-50,290+20,550,330+20);
}
