#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<CertExit.h>
#include<stdlib.h>
struct Nodelsit {
	int date;
	struct Nodelist* next;
};
typedef struct Nodelsit List;

void Init_List(List** L)//创建头节点
{
	*L = (List*)malloc(sizeof(List));
	if (L == NULL)
	{
		exit(-1);
	}
	(*L)->date = 0;
	(*L)->next = NULL;
}

void Insert_L(List* L, int x)//尾插入
{
	List* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	List* temp = (List*)malloc(sizeof(List));
	if (temp == NULL)
	{
		exit(-1);
	}
	temp->next = NULL;
	temp->date = x;
	p->next = temp;
}

//再e前插入
void Insert_Lis_x(List* L, int num, int e)
{
	List* p = L;
	while (p->next)
	{
		List* x = p->next;
		if (x->date == num)
		{
			List* temp = (List*)malloc(sizeof(List));
			if (temp == NULL)
				exit(-1);
			temp->date = e;
			temp->next = x;
			p->next = temp;
			break;
		}
		p = p->next;
	}
}

//在链表删除某一个数
void delete_List(List* L, int x)
{
	List* p = L;
	while (p->next)
	{
		List* del = p->next;
		if (del->date == x)
		{
			p->next = del->next;
			free(del);
			break;
		}
	}
}

void delete_surplus(List* L)
{
	List* p = L->next;
	while (p)
	{
		List *temp = p;
	}
}
//打印链表
void print_List(List* L)
{
	List* p = L->next;
	while (p)
	{
		printf("%d ", p->date);
		p = p->next;
	}
	printf("\n");
}
void  test()
{
	List* M = NULL;
	Init_List(&M);
	Insert_L(M, 10);
	Insert_L(M, 20);
	Insert_L(M, 30);
	print_List(M);
	Insert_Lis_x(M, 20, 21);
	print_List(M);
}

int main()
{
	test();
}