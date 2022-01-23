#ifndef _LIPEI1_H_
#define _LIPEI1_H_
int lipeimain(setuser *person,struct POLICY policy[10],struct CLAIM claim[10],int cn);
int changepolicy(int i,int j);
void drawchoosepolicy(struct POLICY policy[10]);
int choosepolicy(struct POLICY policy[10],int *t);
int shoumyy(struct POLICY policy[10],int yema);
int shuoming(void);
void drawlipei(struct POLICY policy[10],int t,int *g);
int lipei(struct POLICY policy[10],int t,int *g,struct CLAIM claim[10],int cn);
int scbmp(int *g);
void showtime(void);

#endif