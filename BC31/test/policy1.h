#ifndef _policy1_h_
#define _policy1_h_
int policymain(setuser *person,struct POLICY policy[10],int j);
void drawpolicyone(int *flag,char *plate,char *pinpai,char *pcity);
int putpolicy(setuser *person,char *pcity,int *flag,char *plate,char *pinpai ,char money_str[6][10],char baofei[][10],int *flagnew,char *chejia,char *sfzh,char *fdjh,char *dianhua,char *bdh);
int policyone(int *flag,char *plate,char *pinpai,char *pcity,struct POLICY policy[10]);
int choosepcity(char *pcity);
int cinplate(char *plate,int *MouseX,int *MouseY);
int carleixing (char *pinpai);
int nopolicy(setuser *person);
int why(void);


#endif
