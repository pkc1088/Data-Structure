#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int value;
	struct node *next;
};

int get_integer() 
{
	int num;
	scanf("%d",&num);
	return num;
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

/*struct node *insertFirst(struct node *list, int n)
{
	struct node *newnode=(struct node*)malloc(sizeof(node));

	newnode->next=list->next;
	newnode->value=n;
	list->next=newnode;
	return list;
}*/

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
	struct node *list=NULL;
	struct node *curr = NULL, *prev = NULL;
	int i;

	while(1) {

		i = get_integer();
		if(i == 0)
			break;

		curr = (struct node *)malloc(sizeof(struct node));
		curr->value= i;
		curr->next = NULL;

		if(prev == NULL)
			list = curr; 
		else 
			prev->next = curr;

		prev = curr;
	}					//생성이 메인에서 이뤄지니 로컬 신경 쓸 필요없는거인듯... 
/*	list->next=NULL;
	for(int n=20; n>0; n--)
		insertFirst(list, n);
	insertFirst(list, 60);	
	insertFirst(list, 50);
	insertFirst(list, 40);	
	insertFirst(list, 30);
	insertFirst(list, 20);	
	insertFirst(list, 10);	*/
	printf("%d\n", list->value);
	printf("%d", list->next->value);
	
/*	display(list);

	
	deleteNode(list->next, 5);	
	display(list);


	insertMiddle(list->next, 3);
	//매겨변수로 list가 아니라 list->next 즉 head 넣어야함을 명심! 
	display(list);
	
	
	if(search(list->next, 3))
		printf("Found\n");
	else
		printf("Cant find\n");
	
	
	update(list->next, 3, 100);
	display(list);
	
	
	//해제하기 
	while(list->next)
	{
		struct node *next=list->next->next;
		free(list->next);
		list->next=next;
	}
	free(list->next);	*/
	return 0;
}
