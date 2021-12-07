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
	
	printf("%d는 리스트에서 %d번 나타납니다\n", x, cnt);  
}


int main(void)
{
	int num, num2, xdata;
	printf("노드의 개수 : "); 
	scanf("%d", &num);
	
	struct list *p = NULL;
	
	for(int i=0; i<num; i++)
	{
		printf("노드 #%d 데이터 : ", i+1); 
		scanf("%d", &xdata);
		p=insert_ordered(p, xdata);
	}	
	print_ordered_list(p);
	printf("\n\n탐색할 값 : ");
	scanf("%d", &num2); 
	list_search(p, num2);
	
	return 0;
}
