#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void menu()
{
	printf("****1.add     2.del****\n");
	printf("***3.search 4.modify***\n");
	printf("****5.show   6.sort****\n");
	printf("******* 0.exit ********\n");
}
int main()
{
	//创建通讯录
	struct contact con;
	//初始化通讯录
	Initcontact(&con);
	int input = 0;
	do
	{ 
		menu();
		printf("请输入选择>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Addcontact(&con);
			break;
		case del:
			Delcontact(&con);
			break;
		case search:
			Searchcontact(&con);
			break;
		case modify:
			Modifycontact(&con);
			break;
		case show:
			Showcontact(&con);
			break;
		case sort:
			Sortcontact(&con);
			break;
		case EXIT:
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}