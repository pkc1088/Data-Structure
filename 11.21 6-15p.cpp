#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	int data;
	struct list *next;
};

struct list* insert_ordered(struct list* p)
{
	
	for(int i=0; i<3; i++)
	{
		struct list* newnode = (struct list*)malloc(sizeof(struct list));
		newnode->next = NULL;
	
		printf("\n노드 #%d 데이터\n", i+1); 
		printf("DATA : ");
		scanf("%d", &newnode->data);
	
	
		if(p == NULL)
			p = newnode;
		else 	
		{
			struct list* q = p;
			while (q->next != NULL) 
				q = q->next;
			q->next = newnode;
		}
	}
	return p;
}

void print_ordered_list(struct list* p)
{
	printf("\n");
	for(; p!=NULL; p=p->next)
		printf("%d->", p->data);
	printf("NULL\n");
}

int search_max(struct list* p)
{
	if (p == NULL) 
	{
		printf("리스트가 비었습니다.\n");
		return 0;
	}
	
	int max = p->data;
	for (p = p->next; p != NULL; p = p->next) 
		if (max < p->data)
			max = p->data;

	return max;
}

int main(void)
{
	struct list *p = NULL;
	
	p=insert_ordered(p);
	print_ordered_list(p);
	printf("\nmax : %d", search_max(p));
	
	return 0;
}
