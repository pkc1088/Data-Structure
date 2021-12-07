#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{ 
	char *data;
	struct ListNode *link;
};

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

struct ListNode* insert_first(ListNode *head, char* value)
{
	struct ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;				
	p->link = head;	
	head = p;
	return head;
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%s->", p->data);
	printf("NULL \n");
}

int main(void)
{
	struct ListNode *head = NULL;
	//char* xdata=(char* )malloc(sizeof(char)*10);
	char xdata[10];
	
	strcpy(xdata, "APPLE");
	head = insert_first(head, xdata);
	print_list(head);

	strcpy(xdata, "KIWI");
	head = insert_first(head, xdata);
	print_list(head);

	strcpy(xdata, "BANANA");
	head = insert_first(head, xdata);
	print_list(head);
	return 0;
}
