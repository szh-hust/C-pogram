#ifndef _chonzh_h_
#define _chonzh_h_

int usermoney(setuser *head,setuser *person);
void drawmymoney(setuser *person);
void fugai(int a);
//void drawm(void);
int cinmoney(char * chongzhi,int *MouseX,int *MouseY);
int cincode(char *code,int *MouseX,int *MouseY,int k);
void putmoney(char *accounts,long money);
int dumoney(char *acccountsperson,long  * money);
void changemoney(char *accountsperson,long money);
int zhifu(char *item,int money,setuser *person,int xiangxiang);
#endif
