#ifndef _STRUCT_H_
#define _STRUCT_H_

/*�û��ͽṹ*/
typedef struct user
{
	char accounts[11];         	 //�û��˺�
	char code[11];           	 //�û�����
	long money;                  //�û����
	struct policy * policy;      //�����ṹ��
	struct user *next;           //ָ����һ���û���ָ��        
}setuser;

typedef struct POLICY
{
	int p;            //���ڱ�־�Ƿ��Ѿ�����Ӧ����
	/*p==0��ʾδʹ��   p==1��ʾ��ʹ�� */
	char pcity[3];    //���Ƴ���
	char plate[7];    //����
	int flag[4];      //0��ʹ��
	char pinpai[15];
	char sfzh[19];    //���֤��
	char dianhua[12]; //�绰
	char chejia[9];   //���ܺ�
	char fdjh[9];     //��������
	char time[2];     //����
	char money_str[6][10];//���
	char baofei[6][10];   //����
	int flagnew[6];//��Ǹ��ֱ����Ƿ�����
	char bdh[9];
	int zt;//zt==1 ��ʾ�Ѿ���������
};

typedef struct CLAIM 
{
	int p;//���ڱ�־�Ƿ��Ѿ�����Ӧ����
	/*p==0��ʾδʹ��   p==1��ʾ��ʹ��*/
	char accounts[11];
	char bdh[9];
	char ybe[10];
	char claimmoney[10];
	char dianhua[12];
	int  zhuangtai;
					/*zhuangtai==0��ʾδʹ��  
					  zhuangtai==1��ʾ����Ա��ͬ�� 
					  zhuangtai==2 ��ʾ����Ա��ͬ��*/
	int flag;
	/*��־�˹����� 1 ������������ 2 �ı���*/
	
};
#endif

