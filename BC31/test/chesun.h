#ifndef _CHESUN_H_
#define _CHESUN_H_
void drawchesun();
int chesun(setuser *person,struct POLICY policy[10]);
int choosepla(struct POLICY policy[10],int x,int y,char pcity[3],char plate[7],char pinpai[15]);
void drawwaiting(char *item);

#endif