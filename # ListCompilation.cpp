#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int value;
	struct node *next;
};

void display(struct node *list)
{
	while(list)
	{
	printf("%d ", list->value);
	list=list->next;
	}
	printf("\n");
}

struct node *insertFirst(struct node *list, int n)
{
	struct node *newnode=(struct node*)malloc(sizeof(node));

	newnode->next=list->next;
	newnode->value=n;
	list->next=newnode;
	return list;
}

struct node *insertMiddle(struct node *list, int n)
{
	struct node *cur, *prev;
	struct node *newInserted=(struct node*)malloc(sizeof(node));

	for(cur=list, prev=NULL;
		cur!=NULL && cur->value<n;
		prev=cur, cur=cur->next)
		;
	
	if(cur==NULL)
		return list;	
	if(prev==NULL)
		list=list->next;
	/*if(prev==NULL)
	{
		newInserted->next = s;
		newInserted->data = n;
		s = newInserted;
		return s;
	}*/ 						//난 이걸로 고쳐서 썼음  
	prev->next=newInserted;
	newInserted->next=cur;
	newInserted->value=n;
	return list;
}

struct node *deleteNode(struct node *list, int n)
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

struct node *search(struct node *list, int n)
{
	while (list != NULL && list->value !=n)
		list=list->next;
	return list; 
}

struct node *update(struct node *list, int findnum, int updatenum)
{
	for(;list!=NULL & list->value!=findnum;list=list->next)
		;
	list->value=updatenum;

	return list;
}

int main(void)
{
	struct node *list=(struct node*)malloc(sizeof(node));

	list->next=NULL;
	for(int n=20; n>0; n--)
		insertFirst(list, n);	//여기서 넣으니까 로컬노상관.. 
/*	insertFirst(list, 60);	
	insertFirst(list, 50);
	insertFirst(list, 40);	
	insertFirst(list, 30);
	insertFirst(list, 20);	
	insertFirst(list, 10);	*/
	display(list->next);

	
	deleteNode(list->next, 10);	
	display(list->next);


	insertMiddle(list->next, 15);
	//매겨변수로 list가 아니라 list->next 즉 head 넣어야함을 명심! 
	display(list->next);
	
	
	if(search(list->next, 15))
		printf("Found\n");
	else
		printf("Cant find\n");
	
	
	update(list->next, 15, 100);
	display(list->next);
	
	
	//해제하기 
	while(list->next)
	{
		struct node *next=list->next->next;
		free(list->next);
		list->next=next;
	}
	free(list->next);
	return 0;
}
