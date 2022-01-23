#ifndef _userll_h_
#define _userll_h_


//根据usercode.txt文件中的信息创建用户链表
void createuserlist(setuser *head);

//释放链表的内存空间并将头指针置为NULL
//文件必须按要求格式化书写;
//一定要把指针的地址传过来
void freeuserlist(setuser **head);

//将person的信息存入链表中
void saveinftolist(setuser **head ,setuser *person);

//根据传进函数的账户字符串，
//在建立的用户链表中，搜索相应密码，如果
//找到了返回其对应的密码字符串（地址），否则返回NULL。
//传入用户链表的头指针和账户字符串
char *searchaccounts(setuser *head, char *str);

//改变密码函数
void changenewcode(setuser **head ,setuser *person);

#endif