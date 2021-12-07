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

int main(void)
{
	struct Dlist* head = (struct Dlist *)malloc(sizeof(struct Dlist));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) 
	{
		dinsert(head, i);
		print_Ordered(head);
	}
	
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) 
	{
		print_Ordered(head);
		ddelete(head, head->Rlink);	// ddelete(head, head->Llink); 하면 ordered로 지움 
	}
	free(head);
	
	
	return 0;
}
