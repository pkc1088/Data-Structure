#include <stdio.h>

#include <stdlib.h>

struct NODE {
	int data;
	struct NODE *next;
};

void print_list(struct NODE *plist);
int get_integer();

int main(void) 
{
	struct NODE *plist=NULL;
	struct NODE *curr = NULL, *prev = NULL;
	int i;

	while(1) {

		i = get_integer();
		if(i == 0)
			break;

		curr = (struct NODE *)malloc(sizeof(struct NODE));
		curr->data = i;
		curr->next = NULL;

		if(prev == NULL)
			plist = curr; 
		else 
			prev->next = curr; 
			
		prev = curr;
	}				
	print_list(plist);	//cur은 생성해주고 prev는 페이스메이커고 plist가 얹혀서 다 연결먹음 

	return 0;
}

void print_list(struct NODE *plist) 
{
	while(plist) 
	{
		printf("%d->",plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

int get_integer() 
{
	int num;
	scanf("%d",&num);
	return num;
}
