#ifndef _DAOLU_H_
#define _DAOLU_H_
void drawdaolujiuyuan();
int daolujiuyuan(struct POLICY policy[10]);
void drawxunzedidian();
int xunzedidian(char *didian);
int zizhudw();
int zhiyin(int m,int *MouseX,int *MouseY);
int choosepla1(struct POLICY policy[10],int x,int y,char pcity[3],char plate[7],char pinpai[15],char dianhua[12]);
void drawxiayibu();
int xiayibu(struct POLICY policy[10]);
extern int MouseS;
#endif