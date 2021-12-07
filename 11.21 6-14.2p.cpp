#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	char name[20];
	int age;
	double height;
	struct list *next;
};

struct list* insert_ordered(struct list* p)
{
	
	for(int i=0; i<3; i++)
	{
		struct list* newnode = (struct list*)malloc(sizeof(struct list));
		newnode->next = NULL;
	
		printf("\n노드 #%d 데이터\n", i+1); 
		printf("NAME : ");
		scanf("%s", newnode->name);
		printf("AGE : ");
		scanf("%d", &newnode->age);
		printf("HEIGHT : ");
		scanf("%lf", &newnode->height);
	
	
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
	for(; p!=NULL; p=p->next)
		printf("\n%s	%d	%.2lf\n", p->name, p->age, p->height);
}


int main(void)
{
	int age; double height; char name[20];
	struct list *p = NULL;
	
	p=insert_ordered(p);
	print_ordered_list(p);
	
	return 0;
}
