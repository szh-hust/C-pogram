#ifndef _CCODE_H_
#define _CCODE_H_

int putinoldcode(char *old_code, int *MouseX, int *MouseY);
int putinnewcode (char *code ,int *MouseX,int *MouseY);
int putinjudgecode(char *tcode ,int *MouseX, int *MouseY);
int changecode(setuser *head,setuser *person);
void drawchangecode(void);
#endif
