#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(Contact* p)
{
	p->sz = 0;
	p->capacity = 3;
	Info* tmp = (Info*)malloc(sizeof(Info) * p->capacity);
	if (tmp)
	{
		p->peo = tmp;
		memset(p->peo, 0, 3 * sizeof(Info));
	}
	else
	{
		return;
	}
}
void CheckCapacity(Contact* p)
{
	if (p->sz == p->capacity)
	{
		p->capacity += INC_SZ;
		Info* tmp = (Info*)realloc(p->peo,(p->capacity)*sizeof(Info));
		if (tmp != NULL)
		{
			p->peo = tmp;
		}
		else
		{
			perror(CheckCapacity);
			return;
		}
	}
}
void AddContact(Contact* p)
{
	CheckCapacity(p);
	printf("请输入姓名:");
	scanf("%s", p->peo[p->sz].name);
	printf("请输入性别:");
	scanf("%s", p->peo[p->sz].sex);
	printf("请输入年龄:");
	scanf("%s", p->peo[p->sz].age);
	printf("请输入电话:");
	scanf("%s", p->peo[p->sz].tel);
	printf("请输入住址:");
	scanf("%s", p->peo[p->sz].addr);
	p->sz++;
	printf("添加成功！\n");
}
int Search(Contact* p, char name[])
{
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (!(strcmp(p->peo[i].name, name)))
		{
			return i;
		}
	}
	return -1;
}
void Findbyname(Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入查找人的姓名:");
	scanf("%s", name);
	int ret = Search(p, name);
	if (ret == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		printf("%-20s%-10s%-10s%-12s%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-20s%-10s%-5s%-12s%-20s\n",
			p->peo[ret].name,
			p->peo[ret].sex,
			p->peo[ret].age,
			p->peo[ret].tel,
			p->peo[ret].addr);
	}
}
void DelContact(Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入删除人的姓名:");
	scanf("%s", name);
	int ret = Search(p, name);
	if (ret == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		int i = 0;
		for (i = ret; i < p->sz - 1; i++)
		{
			p->peo[i] = p->peo[i + 1];
		}
		p->sz--;
		printf("删除成功\n");
	}
}
void ModifyContact(Contact* p)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入修改人的姓名:");
	scanf("%s", name);
	int ret = Search(p, name);
	if (ret == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		printf("请输入姓名:");
		scanf("%s", p->peo[ret].name);
		printf("请输入性别:");
		scanf("%s", p->peo[ret].sex);
		printf("请输入年龄:");
		scanf("%s", p->peo[ret].age);
		printf("请输入电话:");
		scanf("%s", p->peo[ret].tel);
		printf("请输入住址:");
		scanf("%s", p->peo[ret].addr);
		printf("修改成功！\n");
	}
}
void Show(Contact* p)
{
	if (p->sz == 0)
	{
		printf("当前无联系人\n");
		return;
	}
	int i = 0;
	printf("%-20s%-10s%-10s%-12s%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (i = 0; i < p->sz; i++)
	{
		printf("%-20s%-10s%-10s%-12s%-20s\n",
			p->peo[i].name,
			p->peo[i].sex,
			p->peo[i].age,
			p->peo[i].tel,
			p->peo[i].addr);
	}
}
void Clear(Contact* p)
{
	p->sz = 0;
	printf("清空成功！\n");
}
void Sort(Contact* p)
{
	int i = 0, j = 0;
	int flag = 1;
	for (i = 0; i < p->sz - 1; i++)
	{
		for (j = 0; j < p->sz - i - 1; j++)
		{
			if (strcmp(p->peo[j].name, p->peo[j + 1].name) > 0)
			{
				Info tmp = p->peo[j];
				p->peo[j] = p->peo[j + 1];
				p->peo[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
void Destroy(Contact* p)
{
	free(p->peo);
	p->peo = NULL;
}