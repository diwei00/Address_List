#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
//一个人的信息
struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录
struct contact
{
	struct peoinfo date[MAX];
	int size;
};
enum name
{
	Exit,
	Add,
	Del,
	Search,
	modify,
	Show,
	Sort
};
//函数声明
void menu();
void Initcontact(struct contact* ps);
void Addcontact(struct contact* ps);
void Showcontact(const struct contact* ps);
void Delcontact(struct contact* ps);
void Seacontact(const struct contact* ps);
void modifyContact(struct contact* ps);
void Sortcontact(struct contact* ps);