#include "contact.h"
int main()
{
	int input = 0;
	struct contact con;//ͨѶ¼
	Initcontact(&con);
	do
	{
		menu();
		printf("��������ѡ��");
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
			printf("�˳�");
			break;
		default:
			printf("����������������룺");
			break;
		}

	} while (input);
	

	return 0;
}