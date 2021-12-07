#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	int data;
	struct list *next;
};

/*struct list* make_list(struct list *p, int xdata)
{
	struct list *newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data=xdata;
	newnode->next=NULL;
	if(p==NULL)
		p=newnode;
	else
		p->next=newnode;		//안되는이유: 두번쨰 노드만을 계속 최신화하는 꼴임 p는 항상첫노드 가리키니까 
	return p;
}*/

struct list* insert_first (struct list *p, int xdata)
{
	struct list *newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = xdata;			
	newnode->next = p;
	p = newnode;
	return p;
}
void print_list(struct list* p)
{
	int i, arr[10];
	for(i=0; p!=NULL; i++, p=p->next)
		arr[i]=p->data;
	
	for(i--; i>=0; i--)
		printf("%d->", arr[i]);	
	
	printf("NULL");	
}//내방법 insert_first에 넣고 print_list로 역순 프린트 

//////////////////////////////////////////

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


int main(void)
{
	int num, xdata;
	printf("노드의 개수 : "); 
	scanf("%d", &num);
	
	struct list *p = NULL;
	
	for(int i=0; i<num; i++)
	{
		printf("노드 #%d 데이터 : ", i+1); 
		scanf("%d", &xdata);
		p=insert_ordered(p, xdata);
		//insert함수를 void로 만들면 안되는듯... 그럴꺼면 더블포인터 
	}	
	print_ordered_list(p);
	
	return 0;
}
