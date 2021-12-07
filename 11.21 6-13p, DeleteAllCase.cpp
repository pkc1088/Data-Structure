#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	int data;
	struct list *next;
};

struct list* insert_ordered(struct list* p, int xdata)
{
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = xdata;
	newnode->next = NULL;
	
	if(p == NULL)
		p = newnode;
	
	else 
	{
		struct list* q = p;
		while (q->next != NULL) 
			q = q->next;
		q->next = newnode;
	}
	
	return p;
}

void print_ordered_list(struct list* p)
{
	for(; p!=NULL; p=p->next)
		printf("%d->", p->data);
	printf("NULL");	
}

void list_search(struct list *p, int x)
{
	int cnt=0;
	
	for(; p!=NULL; p=p->next)
		if(p->data==x)
			cnt++;
	
	printf("%d�� ����Ʈ���� %d�� ��Ÿ���ϴ�\n", x, cnt);  
}

struct list* deleteOnce(struct list *p, int x)
{
	struct list *target, *q;
	
	for(target=p, q=p; target!=NULL; target=target->next)
		if(target->data==x)
		{
			while(q->next!=target)
			{
				q=q->next;
			}
			q->next=target->next;
			free(target);
			return p;
		}
}
struct list* deleteAll(struct list* p, int x)
{
	struct list* node = p;
	struct list* q = NULL;
	struct list* target = NULL;

	while (node != NULL) 
	{
		target = node;
		
		if (target->data != x) 
		{
			q = target;
			node = node->next;
		}
		
		else 
		{
			node = node->next;
			
			if (q == NULL)
				p = p->next;
			else
				q->next = target->next;	 //q->next=node; ��� �ص� ����.. 
			
			free(target);
		}
	}
	return p;
}


int main(void)
{
	int num, num2, xdata;
	printf("����� ���� : "); 
	scanf("%d", &num);
	
	struct list *p = NULL;
	
	for(int i=0; i<num; i++)
	{
		printf("��� #%d ������ : ", i+1); 
		scanf("%d", &xdata);
		p=insert_ordered(p, xdata);
	}
	
	printf("\n\n������ �� : ");
	scanf("%d", &num2); 
	p=deleteAll(p, num2);
//	p=deleteOnce(p, num2);	

	print_ordered_list(p);
	
	return 0;
}
