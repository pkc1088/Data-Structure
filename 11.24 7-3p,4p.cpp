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
	printf("%d->NULL\n", p->data);

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

struct list *search(struct list *L, int data)
{
	if (L == NULL) 
		return L;

	struct list *p;
	p = L->next;
	
	do {
		if(p->data==data)
		{
			return p;
		}	
		p = p->next;
	} while (p != L);
	
	return NULL;
}

int get_size(struct list *L)
{
	struct list *p=L;
	int cnt=0;
	
	do {
		cnt++;
		p = p->next;
	} while (p != L);
	
	return cnt; 
}

int main(void)
{
	struct list *head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	printf("%d", get_size(head));	
	
	struct list *x=search(head, 30);
	printf("\n%d\n", x->data);
	print_list(x);
	
	
	return 0;
}
