#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
//个人信息结构体创建
struct Peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};
//通讯录结构体的创建
struct contact
{
	struct Peoinfo data[MAX];//存放max个信息
	int size;//记录存放信息个数
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

//函数声明
//通讯录初始化的函数
void Initcontact(struct contact* ps);

//通讯录添加的函数
void Addcontact(struct contact* ps);

//通讯录显示的函数
void Showcontact(const struct contact* ps);

//通讯录信息的删除
void Delcontact(struct contact* ps);

//通过名字查找联系人的信息
void Searchcontact(const struct contact* ps);

//修改指定联系人的信息
void Modifycontact(struct contact* ps);

//对联系人通过名字进行排序
void Sortcontact(struct contact* ps);