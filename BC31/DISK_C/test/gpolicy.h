#ifndef _gpolicy_h_
#define _gpolicy_h_

void drawgetpolicy(char money_str[][10],int *flagnew,char *plate,char *pinpai,char baofei[][10],int *flag);
int getpolicy(char money_str[][10],int *flagnew,char *plate,char *pinpai,char baofei[][10],int *flag,char *time);
void drawtoubao(int *flagnew,char money_str[][10],char baofei[][10],int *flag);
void drawjiajian(int x,int y);
int tips(int returnnum);
int toubao(int *flagnew,char money_str[][10],char baofei[][10],int *flag,char *time,char *pinpai);
void  drawxiangqing(int i,char money_str[][10]);
int xiangqing(int i,char money_str[][10],int *flagnew);
int getbaofei(int i,char money_str[][10],char baofei[][10],int *flag,char *time,char *pinpai);

#endif
