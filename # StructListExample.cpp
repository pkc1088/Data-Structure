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
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
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
	struct node *first=NULL;
	int n;
	printf("Enter a series of integers (0 to terminate) : ");
	for(;;){
		scanf("%d", &n);
		if(n==0)
			return first;
		first=add_to_list(first, n);
	}
}*/

struct node *add_to_list(struct node **list, int n)
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node==NULL)
	{
		printf("ERROR");
		exit(EXIT_FAILURE);
	}
	new_node->value=n;
	new_node->next=*list;
	*list=new_node;
}

struct node *read_numbers(void)
{
	struct node *first=NULL;
	int n;
	printf("Enter a series of integers (0 to terminate) : ");
	for(;;){
		scanf("%d", &n);
		if(n==0)
			return first;
		first=add_to_list(&first, n);
	}
}
struct node *search_list(struct node *list, int n)
{
	while (list != NULL && list->value !=n)
		list=list->next;
	return list; 
}
struct node *delete_from_list(struct node *list, int n)
{
	struct node *cur, *prev;
	
	for(cur=list, prev=NULL;
		cur!=NULL && cur->value!=n;
		prev=cur, cur=cur->next)
		;
		
	if(cur==NULL)
		return list;
		
	if(prev==NULL)
		list=list->next;
	else
		prev->next = cur->next;
	
	free(cur);
	return list;
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
int main(void)
{
	struct node *test;
	test=read_numbers();
//	add_to_list(&test, 10);
	display(test);	 
	
	/*
	if(search_list(test, 3))
		printf("found\n");
	else 
		printf("Not found\n");
	
	delete_from_list(test, 3);
	display(test);
	add_to_list(&test, 2);
	*/
	return 0;
}
