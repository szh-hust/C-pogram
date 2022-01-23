#ifndef _userself_h_
#define _userself_h_

int userself(setuser *head,setuser *person,struct POLICY policy[10]);//用户个人中心主函数
void drawuserself(void);

int sccg();
int userpolicy(setuser *person,struct POLICY policy[10]);//用户的保单函数
void drawuserpolicy(setuser *person);
int chakan(struct POLICY policy[10],int p);
void shanchubd(setuser *person,int i);
int shanchu(setuser *person,struct POLICY policy[10],int number); 
int usercar(setuser *person,struct POLICY policy[10]);//用户爱车管理函数
void drawmycar(setuser *person);

int aboutus();//关于我们函数
void drawaboutus(setuser *person);
void drawadvice(void);
void yy(void);

int problem();//常见问题函数
void drawproblem(setuser *person);
//绘制*个人中心——意见反馈*界面的绘制

void drawmyclaim(void);
int myclaim(struct CLAIM claim[10],int k);

#endif
