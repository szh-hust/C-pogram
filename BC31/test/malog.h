#ifndef _malog_h_
#define _malog_h_

#include "common.h"
#include "malog.h"

/***************************************************
�û���¼������˺����뺯��
��Сд��ĸ������
1��10λ
*x��*y�������λ�ã�����ָ�����ʽ����
***************************************************/
int mcinloginaccouhts(char *accounts,int *MouseX,int *MouseY);

/***************************************************
�û���¼������������뺯�� 
��д��СдӢ�ġ�����
1��10λ
*MouseX��*MouseY�������λ�ã�����ָ�����ʽ����
***************************************************/
int mcinlogincode(char *mode , int *MouseX,int *MouseY);
int mastercpy(char *a,char *c);

/***************************************************
�û���¼����ĺ�̨����
***************************************************/
int  manage_login(setuser *head,char *accounts,char *code);

#endif

