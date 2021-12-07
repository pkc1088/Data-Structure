#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{ 	
	int data;
	struct ListNode *link;
};


void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

struct ListNode* search_list (ListNode *head, int x)
{
	ListNode *p = head;

	while (p != NULL) 
	{
		if (p->data == x) 
			return p;
		p = p->link;
	}
	return NULL;
}

struct ListNode* insert_first (struct ListNode *head, int value)
{
	struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	p->data = value;			
	p->link = head;
	head = p;
	return head;
}

struct ListNode* insert (struct ListNode *head, struct ListNode *pre, int value)
{
	struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));	
	p->data = value;		
	p->link = pre->link;	
	pre->link = p;			
	return head;			
}

struct ListNode* delete_first(struct ListNode *head)
{
	struct ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;	
	head = removed->link;	
	free(removed);		
	return head;		
}

struct ListNode* delete_node (struct ListNode *head, struct ListNode *pre)
{
	struct ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		
	free(removed);			
	return head;			
}

void print_list (struct ListNode *head)
{
	for (struct ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

struct ListNode* reverse(struct ListNode *head)
{
	struct ListNode *p, *q, *r;

	p = head;        	 // p�� �������� ���� ����Ʈ
	q = NULL;        	 // q�� �������� ���� ���
	while (p != NULL) 
	{
		r = q;           // r�� �������� �� ����Ʈ.	r�� q, q�� p�� ���ʷ� ���󰣴�
		q = p;
		p = p->link;
		q->link = r;     // q�� ��ũ ������ �ٲ۴�.
	}
	return q;
}

struct ListNode* concat_list (struct ListNode *head1, struct ListNode *head2)
{
	if (head1 == NULL) 
		return head2;
	
	else if (head2 == NULL) 
		return head2;
	
	else 
	{
		struct ListNode *p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		
		return head1;
	}
}

int main(void)
{
	struct ListNode *head = NULL;

	for (int i = 0; i < 5; i++) 
	{
		head = insert_first(head, i);
	//	print_list(head);
	}
	print_list(head);
/*	for (int i = 0; i < 5; i++) 
	{
		head = delete_first(head);
		print_list(head);
	}
*/
//	if (search_list(head, 30) != NULL)
//		printf("����Ʈ���� 30�� ã�ҽ��ϴ�. \n");

//	ListNode *total = concat_list(head1, head2);
//	print_list(total);
	
	return 0;
}
