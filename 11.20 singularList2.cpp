#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
	char name[100];
};

struct ListNode 
{ 	
	struct element data;
	struct ListNode *link;
};

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

struct ListNode* insert_first(struct ListNode *head, struct element value)
{
	struct ListNode *p = (struct ListNode *)malloc(sizeof(ListNode));	
	p->data = value;				
	p->link = head;	
	head = p;	
	return head;
}

void print_list(struct ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

int main(void)
{
	struct ListNode *head = NULL;
	struct element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);
	return 0;
}
