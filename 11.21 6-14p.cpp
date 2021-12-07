#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	char name[20];
	int age;
	double height;
	struct list *next;
};

struct list* insert_ordered(struct list* p, char name[], int age, double height)
{
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	strcpy(newnode->name, name);
	newnode->age = age;
	newnode->height = height;
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
		printf("\n%s %d %.2lf\n", p->name, p->age, p->height);
	printf("NULL");	
}


int main(void)
{
	int age; double height; char name[20];
	struct list *p = NULL;
	
	for(int i=0; i<3; i++)
	{
		printf("\n��� #%d ������\n", i+1); 
		printf("NAME : ");
		scanf("%s", name);
		printf("AGE : ");
		scanf("%d", &age);
		printf("HEIGHT : ");
		scanf("%lf", &height);
		p=insert_ordered(p, name, age, height);
	}
	
	print_ordered_list(p);
	
	return 0;
}
