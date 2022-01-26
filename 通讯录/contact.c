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
	ps->size = 0;//设置通讯录里最初没人
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
		printf("通讯录已满");
	}
	else
	{
		printf("请输入姓名：");
		scanf_s("%s", ps->date[ps->size].name, MAX_NAME);
		printf("请输入年龄：");
		scanf_s("%d", &(ps->date[ps->size].age));
		printf("请输入性别：");
		scanf_s("%s", ps->date[ps->size].sex,MAX_SEX);
		printf("请输入电话：");
		scanf_s("%s", ps->date[ps->size].tele,MAX_TELE);
		printf("请输入家庭地址：");
		scanf_s("%s", ps->date[ps->size].addr,MAX_ADDR);
		ps->size++;
		printf("录入完成\n");
	}
}
void Delcontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入你要删除的名字：\n");
	scanf_s("%s", name, MAX_NAME);
	int tmp = FindDate(ps, name);
	if (tmp == -1 )
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = tmp; j < ps->size-1 ; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		printf("删除成功\n");
		ps->size--;
	}

}
void Seacontact(const struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入你要查找人的名字：\n");
	scanf_s("%s", name, MAX_NAME);
	int tmp = FindDate(ps, name);
	if (tmp == -1)
	{
		printf("要查找的人不存在");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入你要修改人的名字：");
	scanf_s("%s", name, MAX_NAME);
	int tmp = FindDate(ps, name);
	if (tmp == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入你要修改人的信息：\n");
		printf("请输入姓名：");
		scanf_s("%s", ps->date[tmp].name, MAX_NAME);
		printf("请输入年龄：");
		scanf_s("%d", &(ps->date[tmp].age));
		printf("请输入性别：");
		scanf_s("%s", ps->date[tmp].sex, MAX_SEX);
		printf("请输入电话：");
		scanf_s("%s", ps->date[tmp].tele, MAX_TELE);
		printf("请输入家庭地址：");
		scanf_s("%s", ps->date[tmp].addr, MAX_ADDR);
		printf("修改完成\n");

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
	printf("请输入用什么排序：");
	scanf_s("%s", tmp1, MAX_NAME);
	int tmp2 = strcmp(tmp1,"年龄");
	if (tmp2 == 0)
	{
		qsort(ps->date, ps->size, sizeof(ps->date[0]), w_age);
	}
	else
	{
		qsort(ps->date, ps->size, sizeof(ps->date[0]), w_name);
	}

	printf("排序成功\n");
}
void Showcontact(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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