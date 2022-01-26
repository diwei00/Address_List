#include "contact.h"
void menu()
{
	printf("***************************************\n");
    printf("*****1.Add                  2.Del******\n");
	printf("*****3.Search               4.modify***\n");
	printf("*****5.Show                 6.Sort*****\n");
	printf("*****0.Exit                      ******\n");
	printf("***************************************\n");
}
void Initcontact(struct contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;//����ͨѶ¼�����û��
}
int FindDate(const struct contact* ps, char name[])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		int tmp = strcmp(ps->date[i].name, name);
		if (tmp == 0)
		{
			break;
		}
	}
	if (i == ps->size)
	{
		return -1;
	}
	else
	{
		return i;
	}
}
void Addcontact(struct contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����");
	}
	else
	{
		printf("������������");
		scanf_s("%s", ps->date[ps->size].name, MAX_NAME);
		printf("���������䣺");
		scanf_s("%d", &(ps->date[ps->size].age));
		printf("�������Ա�");
		scanf_s("%s", ps->date[ps->size].sex,MAX_SEX);
		printf("������绰��");
		scanf_s("%s", ps->date[ps->size].tele,MAX_TELE);
		printf("�������ͥ��ַ��");
		scanf_s("%s", ps->date[ps->size].addr,MAX_ADDR);
		ps->size++;
		printf("¼�����\n");
	}
}
void Delcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫɾ�������֣�\n");
	scanf_s("%s", name, MAX_NAME);
	int tmp = FindDate(ps, name);
	if (tmp == -1 )
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = tmp; j < ps->size-1 ; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		printf("ɾ���ɹ�\n");
		ps->size--;
	}

}
void Seacontact(const struct contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ�����˵����֣�\n");
	scanf_s("%s", name, MAX_NAME);
	int tmp = FindDate(ps, name);
	if (tmp == -1)
	{
		printf("Ҫ���ҵ��˲�����");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->date[tmp].name,
			ps->date[tmp].age,
			ps->date[tmp].sex,
			ps->date[tmp].tele,
			ps->date[tmp].addr);
	}


}
void modifyContact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ�޸��˵����֣�");
	scanf_s("%s", name, MAX_NAME);
	int tmp = FindDate(ps, name);
	if (tmp == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("��������Ҫ�޸��˵���Ϣ��\n");
		printf("������������");
		scanf_s("%s", ps->date[tmp].name, MAX_NAME);
		printf("���������䣺");
		scanf_s("%d", &(ps->date[tmp].age));
		printf("�������Ա�");
		scanf_s("%s", ps->date[tmp].sex, MAX_SEX);
		printf("������绰��");
		scanf_s("%s", ps->date[tmp].tele, MAX_TELE);
		printf("�������ͥ��ַ��");
		scanf_s("%s", ps->date[tmp].addr, MAX_ADDR);
		printf("�޸����\n");

	}
}
int w_age(const void* e1, const void* e2)
{
	return ((struct peoinfo*)e1)->age - ((struct peoinfo*)e2)->age;
}
int w_name(const void* e1, const void* e2)
{
	return ((struct peoinfo*)e1)->name - ((struct peoinfo*)e2)->name;
}
void Sortcontact(struct contact* ps)
{
	char tmp1[MAX_NAME]={0};
	printf("��������ʲô����");
	scanf_s("%s", tmp1, MAX_NAME);
	int tmp2 = strcmp(tmp1,"����");
	if (tmp2 == 0)
	{
		qsort(ps->date, ps->size, sizeof(ps->date[0]), w_age);
	}
	else
	{
		qsort(ps->date, ps->size, sizeof(ps->date[0]), w_name);
	}

	printf("����ɹ�\n");
}
void Showcontact(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
	
}