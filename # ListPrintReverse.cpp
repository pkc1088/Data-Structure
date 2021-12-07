#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int value;
	struct node *next;
};
/*
struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->next=NULL;
	list->next=new_node;	
	
	return list;
} Á¤¹æÇâ*/
struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	
	if(new_node==NULL)
	{
		printf("ERROR");
		exit(EXIT_FAILURE);
	}
	new_node->value=n;
	new_node->next=list;
	return new_node;
}

struct node *read_numbers(void)
{
	struct node *list=NULL;
	int n;
	printf("Enter a series of integers (0 to terminate) : ");
	for(;;){
		scanf("%d", &n);
		if(n==0)
			return list;
		list=add_to_list(list, n);
	}
}

void display(struct node *list)
{
	while(list)
	{
		printf("%d ", list->value);
		list=list->next;
	}

	printf("\n");
}

int get_integer() 
{
	int num;
	scanf("%d",&num);
	return num;
}

int main(void)
{
	display(read_numbers());	

	return 0;
}

