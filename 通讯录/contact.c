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
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		printf("����������>");
		scanf("%s", ps->data[ps->size].name);
		printf("�������Ա�>");
		scanf("%s", ps->data[ps->size].sex);
		printf("����������>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("������绰����>");
		scanf("%s", ps->data[ps->size].tele);
		printf("������סַ>");
		scanf("%s", ps->data[ps->size].addr);
		(ps->size)++;
		printf("��ӳɹ�\n");
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
	return -1;//�Ҳ��������
}

void Showcontact(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		//����
		printf("%-20s\t%-5s\t%-4s\t%-11s\t%-20s\n","����","�Ա�","����","�绰","סַ");
		//����
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
	printf("������Ҫɾ���˵�����>");
	scanf("%s", name);
	//1.����ɾ���˵���Ϣ
	//������ҵ��˷����±꣬û���ҵ�����-1
	int pos = Findbyname(ps, name);
	if (pos == -1)
	{
		printf("ͨѶ¼�в����ڴ���\n");
	}
	//2.ɾ��
	else
	{
		int j = 0;
		for (j = pos; j <ps->size-1 ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		(ps ->size)--;
		printf("ɾ���ɹ�\n");
	}
}

void Searchcontact(const struct contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ������ϵ�˵�����>");
	scanf("%s", name);
	int pos=Findbyname(ps, name);
	if (pos == -1)
	{
		printf("ͨѶ¼�в����ڸ���ϵ��\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-4s\t%-11s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
		//����
		
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
	printf("������Ҫ�޸���ϵ�˵�����>");
	scanf("%s", name);
	int pos = Findbyname(ps, name);
	if (pos == -1)
	{
		printf("ͨѶ¼�в����ڸ���ϵ��\n");
	}
	else
	{
		printf("����������>");
		scanf("%s", ps->data[pos].name);
		printf("�������Ա�>");
		scanf("%s", ps->data[pos].sex);
		printf("����������>");
		scanf("%d", &(ps->data[pos].age));
		printf("������绰����>");
		scanf("%s", ps->data[pos].tele);
		printf("������סַ>");
		scanf("%s", ps->data[pos].addr);
	
		printf("�޸ĳɹ�\n");
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