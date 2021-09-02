#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 20
#define MAX_SEX  10
#define MAX_AGE  5
#define MAX_TEL  12
#define MAX_ADDR 25
#define INC_SZ 2
enum Choice
{
	�˳�ͨѶ¼,
	�����ϵ��,
	ɾ����ϵ��,
	������ϵ��,
	�޸���ϵ��,
	�鿴������,
	�����ϵ��,
	������ϵ��
};
typedef struct Info
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char age[MAX_AGE];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}Info;
typedef struct Contact
{
	Info* peo;
	int sz;
	int capacity;
}Contact;

void InitContact(Contact* p);
void AddContact(Contact* p);
void Findbyname(Contact* p);
int Search(Contact* p, char name[]);
void DelContact(Contact* p);
void ModifyContact(Contact* p);
void Show(Contact* p);
void Clear(Contact* p);
void Sort(Contact* p);
void Destroy(Contact* p);