#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
//������Ϣ�ṹ�崴��
struct Peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};
//ͨѶ¼�ṹ��Ĵ���
struct contact
{
	struct Peoinfo data[MAX];//���max����Ϣ
	int size;//��¼�����Ϣ����
};

enum option
{
	EXIT,
	add,
	del,
	search,
	modify,
	show,
	sort
};

//��������
//ͨѶ¼��ʼ���ĺ���
void Initcontact(struct contact* ps);

//ͨѶ¼��ӵĺ���
void Addcontact(struct contact* ps);

//ͨѶ¼��ʾ�ĺ���
void Showcontact(const struct contact* ps);

//ͨѶ¼��Ϣ��ɾ��
void Delcontact(struct contact* ps);

//ͨ�����ֲ�����ϵ�˵���Ϣ
void Searchcontact(const struct contact* ps);

//�޸�ָ����ϵ�˵���Ϣ
void Modifycontact(struct contact* ps);

//����ϵ��ͨ�����ֽ�������
void Sortcontact(struct contact* ps);