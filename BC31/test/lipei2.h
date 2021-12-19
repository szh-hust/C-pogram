#ifndef _LIPEI2_H_
#define _LIPEI2_H_
int xzlpfs(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn);
void drawxzlpfs(void);
void drawzzlp(void);
int zzlp(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn);
void drawrgfw(void);
int rgfw(struct POLICY policy[10],int t,struct CLAIM claim[10],int cn);
int cinlpje(char * lpje,int *MouseX, int *MouseY);
void drawxzdd(void);
int xzdd(char *didian);
int putclaim(setuser *person,struct CLAIM claim[10],int cn);
#endif