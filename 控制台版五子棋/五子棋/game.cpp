#define _CRT_SECURE_NO_WARNINGS 1
#include "Chess.h"
int main()
{
	int choice;
	do {
		Menu();
		printf("请选择>>");
		scanf("%d", &choice);
		switch (choice)
		{
		default:	
			system("cls");
			printf("请输入菜单中已有选项！\n");
			break;
		case PvP:
			system("cls");
			GamePVP();
			break;
		case PvE:
			break;
		case Over:
			printf("游戏结束|BYE BYE!");
			break;
		}
	} while (choice);
	return 0;
}
