#include <stdio.h>
#include <stdlib.h>

struct list 
{ 	
	int data;
	struct list *next;
} list;


void print_list(struct list* head)
{
	struct list* p;
	
	if (head == NULL) 
		return;
	
	p = head->next;
	do {
		printf("%d->", p->data);
		p = p->next;
	} while (p != head);
	printf("%d->", p->data);
}

struct list* insert_first(struct list* head, int data)
{
	struct list *node = (struct list *)malloc(sizeof(struct list));
	node->data = data;
	if (head == NULL) 
	{
		head = node;
		node->next = head;
	}
	else 
	{
		node->next = head->next;	
		head->next = node;		
	}
	return head;	
}

struct list* insert_last(struct list* head, int data)
{
	struct list *node = (struct list *)malloc(sizeof(struct list));
	node->data = data;
	if (head == NULL) 
	{
		head = node;
		node->next = head;
	}
	else 
	{
		node->next = head->next;
		head->next = node;		
		head = node;		
	}
	return head;	 
}


int main(void)
{
	struct list *head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);


	return 0;
}
