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

struct list* deleteOdd2(struct list *p)	//내 방법 안되는듯 
{
	struct list *target, *q;
	int cnt=1;
	
	for(target=p, q=p; target!=NULL; target=target->next)
	{
		if(cnt==2)
		{
			while(q->next!=target)
			{
				q=q->next;
			}
			q->next=target->next;
			free(target);
			cnt=1;
		}
		else
			cnt++;
	}
	return p;
}

struct list* deleteOdd(struct list* p)
{
	struct list* node = p;
	struct list* q = NULL;
	struct list* target = NULL;
	int cnt=1;
	while (node != NULL) 
	{
		target = node;
		if (cnt!=2) 
		{
			q = target;
			node = node->next;
			cnt++;
		}
		else 
		{
			node = node->next;
			if (q == NULL)
				p = p->next;
			else
				q->next = target->next;	 //q->next=node; 라고 해도 노상관.. 
			free(target);
			cnt=1;
		}
	}
	return p;
}

int main(void)
{
	int i;
	struct list *p = NULL;
	
	for(i=1; i<10; i++)
	{
		p=insert_ordered(p, i);
	}
	print_ordered_list(p);
	p=deleteOdd(p);
	printf("\n");
	print_ordered_list(p);
	
	return 0;
}
