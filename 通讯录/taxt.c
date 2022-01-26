#include "contact.h"
int main()
{
	int input = 0;
	struct contact con;//通讯录
	Initcontact(&con);
	do
	{
		menu();
		printf("请输入你选择：");
		scanf_s("%d", &input);
		switch(input)
		{
		case Add:
			Addcontact(&con);
			break;
		case Del:
			Delcontact(&con);
			break;
		case Search:
			Seacontact(&con);
			break;
		case modify:
			modifyContact(&con);
			break;
		case Show:
			Showcontact(&con);
			break;
		case Sort:
			Sortcontact(&con);
			break;
		case Exit:
			printf("退出");
			break;
		default:
			printf("输入错误请重新输入：");
			break;
		}

	} while (input);
	

	return 0;
}