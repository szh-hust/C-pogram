#ifndef_DRAW_H_
#define_DRAW_H_

#include "common.h"
#include"graphics.h"
#include <time.h>
#define LENGTH 640
#define WIDTH  480
int queren(char *item,int x,int y,int sizehanzi,int jianju,int returnnum);
int jueding(char *item,int returnnum);
void  button(int x,int y,int length,int wide,int color,int fillcolor,int i);
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor);//矩形加影子
void Drawtrashcan(int x, int y);
int putbmp(int x, int y, char *s);
void drawhaochezhu(int x,int y,int color,int fillcolor,double size);
void Drawjiazaitiao();
void Drawbeautiful(int x,int y,double size)	;
int suijishu(int n); 
void drawlittlecar(int x,int y,int color,double size);
int bingo(int x,int y,char *text);
void drawhust(int x,int y,int color,int size);
void drawdt(void);
#endif
