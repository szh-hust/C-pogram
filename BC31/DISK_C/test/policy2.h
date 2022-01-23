#ifndef _policy2_h_
#define _policy2_h_
void drawxinxiluru(void);
int xinxiluru(char *sfzh,char *dianhua,char *chejia,char *fdjh,char *time,setuser *person);
int cincjh(char *chejia,int *MouseX,int *MouseY,setuser *person);
int cinfdj(char *fdj,int *MouseX,int *MouseY,setuser *person);
int cinsfzh(char *sfzh,int *MouseX,int *MouseY,setuser *person);
int cindianhua(char*dianhua,int *MouseX,int *MouseY,setuser *person);
int nianfen(char *time);
int yuefen(char *time);
int riqi(char *time);
void drawbdpage(void);
int bdpage(setuser *person,char *dianhua,char *plate,char *pinpai,char *chejia,int *flagnew,char money_str[][10],char baofei[][10],char *pcity,char *bdh);
#endif
