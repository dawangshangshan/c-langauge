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

void delete_surplus(List* *L)
{
	List* p = (*L)->next;
	while (p)
	{
		List *temp = p;
		List* del=p->next;
		while (del)
		{
			if (del->date == p->date)
			{
				temp->next = del->next;
				free(del);
				del = temp->next;
				continue;
			}
			temp = temp->next;
			if(temp)
				del = del->next;
		}
		p = p->next;
	}
	
}
//
void reverse_lsit(List** L)
{
	List* p = (*L)->next;
	List* cur = *L;
	while (p->next)
	{
		p = p->next;
	}
	List* tail = p;
	while (1)
	{
		cur = *L;
		if (cur->next == p)
		{
			p->next = NULL;
			(*L)->next = tail;
			break;
		}
		while (cur->next != p)
		{
			cur = cur->next;
		}
		p->next = cur;
		p = cur;
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
	Insert_L(M, 20);
	Insert_L(M, 20);
	Insert_L(M, 20);
	Insert_L(M, 30);
	delete_surplus(&M);
	print_List(M);
	reverse_lsit(&M);
	print_List(M);
}

int main()
{
	test();
}


struct Nodelist {
	int date;
	struct Nodelist* next;
	struct Nodelist* tail;
};
typedef struct Nodelist List;


void Init_List(List** L)
{
	*L = (List*)malloc(sizeof(List));
	if (*L == NULL)
	{
		exit(-1);
	}
	(*L)->next = *L;
	(*L)->tail = *L;
	(*L)->date = 0;
}

void Insert_List(List* L, int x)
{
	List* temp = L;
	temp = temp->tail;
	List* p = (List*)malloc(sizeof(List));
	p->date = x;
	p->tail = temp;
	temp->tail->tail = p;
	p->next = L;
	temp->next = p;
}
int compare(List *L, List *M)
{
	List *l = L->next;
	List *m = M->next;
	while (l != L && m != M)
	{
		if (l->date != m->date)
			return 0;
		else if (l->next == L && m->next == M)
			return 1;
		l = l->next;
		m = m->next;
	}
	return 0;
}
int main()
{
	List *M;
	List *L;
	Init_List(&M);
	Init_List(&L);
	Insert_List(M, 1);
	Insert_List(M, 2);
	Insert_List(M, 3);
	Insert_List(M, 1);
	Insert_List(L, 1);
	Insert_List(L, 1);
	Insert_List(L, 1);
	printf("%d",compare(L, M));
}