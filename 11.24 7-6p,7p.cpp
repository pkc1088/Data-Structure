#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dlist 
{	
	int data;
	struct Dlist* Llink;
	struct Dlist* Rlink;
};

void init(struct Dlist* phead)
{
	phead->Llink = phead;
	phead->Rlink = phead;
}

void print_Reverse(struct Dlist* phead)
{
	struct Dlist* p;
	for (p = phead->Rlink; p != phead; p = p->Rlink)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}

void print_Ordered(struct Dlist* phead)
{
	struct Dlist* p;
	for (p = phead->Llink; p != phead; p = p->Llink)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}

void dinsert(struct Dlist *before, int data)
{
	struct Dlist *newnode = (struct Dlist *)malloc(sizeof(struct Dlist));
	newnode->data=data;
	newnode->Llink = before;
	newnode->Rlink = before->Rlink;
	before->Rlink->Llink = newnode;
	before->Rlink = newnode;
}

void ddelete(struct Dlist* head, struct Dlist* removed)
{
	if (removed == head) 
		return;
	removed->Llink->Rlink = removed->Rlink;
	removed->Rlink->Llink = removed->Llink;
	free(removed);
}

struct Dlist* search(struct Dlist *L, int data)
{
	struct Dlist *p;
	for (p = L->Rlink; p != L; p = p->Rlink)
	{
		if(p->data==data)
			return p;
	}
	return NULL;
}

int main(void)
{
	struct Dlist* head = (struct Dlist *)malloc(sizeof(struct Dlist));
	init(head);
	
	int num, num2;
	printf("데이터의 개수를 입력하시오 : ");
	scanf("%d", &num); 
	for (int i = 0; i < num; i++) 
	{
		printf("노드 #%d의 데이터를 입력하시오 : ", i+1);
		scanf("%d", &num2); 
		dinsert(head, num2);
		print_Ordered(head);
	}
	printf("\n");
	struct Dlist *p;
	p=search(head, 3);
	print_Ordered(p);
	print_Reverse(p);
	return 0;
}
