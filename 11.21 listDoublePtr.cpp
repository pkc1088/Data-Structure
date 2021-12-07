#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct list{
	int data;
	struct list *next;
};

void insert_ordered(struct list** p, int x)
{
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = x;
	newnode->next = NULL;

	*p = newnode;
}

void print_list(struct list* p)
{
	printf("%d\n", p->data);
	
	printf("NULL");	
}

int main(void)
{
	struct list *p = NULL;
	insert_ordered(&p, 10);
	print_list(p);
	return 0;
}

