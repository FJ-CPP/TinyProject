#define _CRT_SECURE_NO_WARNINGS 1
#include "Chess.h"
int main()
{
	int choice;
	do {
		Menu();
		printf("��ѡ��>>");
		scanf("%d", &choice);
		switch (choice)
		{
		default:	
			system("cls");
			printf("������˵�������ѡ�\n");
			break;
		case PvP:
			system("cls");
			GamePVP();
			break;
		case PvE:
			break;
		case Over:
			printf("��Ϸ����|BYE BYE!");
			break;
		}
	} while (choice);
	return 0;
}
