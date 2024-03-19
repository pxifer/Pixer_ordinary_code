#include"contact.h"
void Initcontact(struct contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void Addcontact(struct contact* ps)
{
	if (ps->size==MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入姓名>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入性别>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入年龄>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入电话号码>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入住址>");
		scanf("%s", ps->data[ps->size].addr);
		(ps->size)++;
		printf("添加成功\n");
	}
}

static int Findbyname(const struct contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//找不到的情况
}

void Showcontact(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//标题
		printf("%-20s\t%-5s\t%-4s\t%-11s\t%-20s\n","姓名","性别","年龄","电话","住址");
		//数据
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-5s\t%-4d\t%-11s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

void Delcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字>");
	scanf("%s", name);
	//1.查找删除人的信息
	//如果查找到了返回下标，没有找到返回-1
	int pos = Findbyname(ps, name);
	if (pos == -1)
	{
		printf("通讯录中不存在此人\n");
	}
	//2.删除
	else
	{
		int j = 0;
		for (j = pos; j <ps->size-1 ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		(ps ->size)--;
		printf("删除成功\n");
	}
}

void Searchcontact(const struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找联系人的名字>");
	scanf("%s", name);
	int pos=Findbyname(ps, name);
	if (pos == -1)
	{
		printf("通讯录中不存在该联系人\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-4s\t%-11s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
		//数据
		
			printf("%-20s\t%-5s\t%-4d\t%-11s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].sex,
				ps->data[pos].age,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}

void Modifycontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改联系人的名字>");
	scanf("%s", name);
	int pos = Findbyname(ps, name);
	if (pos == -1)
	{
		printf("通讯录中不存在该联系人\n");
	}
	else
	{
		printf("请输入姓名>");
		scanf("%s", ps->data[pos].name);
		printf("请输入性别>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入年龄>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入电话号码>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入住址>");
		scanf("%s", ps->data[pos].addr);
	
		printf("修改成功\n");
	}
}

int compare(const void* e1, const void* e2)
{
	return strcmp(((struct Peoinfo*)e1)->name, ((struct Peoinfo*)e2)->name);
}
void Sortcontact(struct contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), compare);
}