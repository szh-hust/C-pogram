#ifndef _userll_h_
#define _userll_h_


//����usercode.txt�ļ��е���Ϣ�����û�����
void createuserlist(setuser *head);

//�ͷ�������ڴ�ռ䲢��ͷָ����ΪNULL
//�ļ����밴Ҫ���ʽ����д;
//һ��Ҫ��ָ��ĵ�ַ������
void freeuserlist(setuser **head);

//��person����Ϣ����������
void saveinftolist(setuser **head ,setuser *person);

//���ݴ����������˻��ַ�����
//�ڽ������û������У�������Ӧ���룬���
//�ҵ��˷������Ӧ�������ַ�������ַ�������򷵻�NULL��
//�����û������ͷָ����˻��ַ���
char *searchaccounts(setuser *head, char *str);

//�ı����뺯��
void changenewcode(setuser **head ,setuser *person);

#endif