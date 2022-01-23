#ifndef _register_h_
#define _rehister_h_
//注册输入账号函数
int registercinaccounts(char *accounts, int *MouseX, int *MouseY);
//注册输入密码函数
int registercincode(char *code ,int *MouseX,int  *MouseY);
//注册再次输入密码函数
int registersecondcode(char *tcode ,int *MouseX, int *MouseY);
//将用户账号密码存入链表、文件函数
int addnew(setuser *head,char *accounts,char *code);
#endif


