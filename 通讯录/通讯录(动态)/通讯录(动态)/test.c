#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("---------------------------------------------\n");
	printf("--------1�������ϵ��   2��ɾ����ϵ��--------\n");
	printf("--------3��������ϵ��   4���޸���ϵ��--------\n");
	printf("--------5���鿴������   6�������ϵ��--------\n");
	printf("--------7��������ϵ��   0���˳�ͨѶ¼--------\n");
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
		printf("������ѡ���Ӧ����->");
		scanf("%d", &choice);
		switch (choice)
		{
		case �����ϵ��:
			AddContact(&p);
			break;
		case ɾ����ϵ��:
			DelContact(&p);
			break;
		case ������ϵ��:
			Findbyname(&p);
			break;
		case �޸���ϵ��:
			ModifyContact(&p);
			break;
		case �鿴������:
			Show(&p);
			break;
		case �����ϵ��:
			Clear(&p);
			break;
		case �˳�ͨѶ¼:
			Destroy(&p);
			break;
		case ������ϵ��:
			Sort(&p);
			break;
		default:
			printf("��������ȷѡ��\n");
			break;
		}
	} while (choice);
	return 0;
}