#ifndef _STRUCT_H_
#define _STRUCT_H_

/*用户型结构*/
typedef struct user
{
	char accounts[11];         	 //用户账号
	char code[11];           	 //用户密码
	long money;                  //用户余额
	struct policy * policy;      //保单结构体
	struct user *next;           //指向下一个用户的指针        
}setuser;

typedef struct POLICY
{
	int p;            //用于标志是否已经有相应数据
	/*p==0表示未使用   p==1表示已使用 */
	char pcity[3];    //车牌城市
	char plate[7];    //车牌
	int flag[4];      //0不使用
	char pinpai[15];
	char sfzh[19];    //身份证号
	char dianhua[12]; //电话
	char chejia[9];   //车架号
	char fdjh[9];     //发动机号
	char time[2];     //日期
	char money_str[6][10];//金额
	char baofei[6][10];   //保费
	int flagnew[6];//标记各种保险是否已买
	char bdh[9];
	int zt;//zt==1 表示已经办理理赔
};

typedef struct CLAIM 
{
	int p;//用于标志是否已经有相应数据
	/*p==0表示未使用   p==1表示已使用*/
	char accounts[11];
	char bdh[9];
	char ybe[10];
	char claimmoney[10];
	char dianhua[12];
	int  zhuangtai;
					/*zhuangtai==0表示未使用  
					  zhuangtai==1表示管理员已同意 
					  zhuangtai==2 表示管理员不同意*/
	int flag;
	/*标志人工理赔 1 还是自助理赔 2 的变量*/
	
};
#endif

