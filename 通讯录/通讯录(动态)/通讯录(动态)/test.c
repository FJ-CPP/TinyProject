#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("---------------------------------------------\n");
	printf("--------1、添加联系人   2、删除联系人--------\n");
	printf("--------3、查找联系人   4、修改联系人--------\n");
	printf("--------5、查看所有人   6、清空联系人--------\n");
	printf("--------7、排序联系人   0、退出通讯录--------\n");
	printf("---------------------------------------------\n");
}
int main()
{
	int choice = 0;
	Contact p;
	InitContact(&p);
	do
	{
		menu();
		printf("请输入选项对应数字->");
		scanf("%d", &choice);
		switch (choice)
		{
		case 添加联系人:
			AddContact(&p);
			break;
		case 删除联系人:
			DelContact(&p);
			break;
		case 查找联系人:
			Findbyname(&p);
			break;
		case 修改联系人:
			ModifyContact(&p);
			break;
		case 查看所有人:
			Show(&p);
			break;
		case 清空联系人:
			Clear(&p);
			break;
		case 退出通讯录:
			Destroy(&p);
			break;
		case 排序联系人:
			Sort(&p);
			break;
		default:
			printf("请输入正确选项\n");
			break;
		}
	} while (choice);
	return 0;
}