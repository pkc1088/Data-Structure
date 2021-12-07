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
		p->next=newnode;		//�ȵǴ�����: �ι��� ��常�� ��� �ֽ�ȭ�ϴ� ���� p�� �׻�ù��� ����Ű�ϱ� 
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
}//����� insert_first�� �ְ� print_list�� ���� ����Ʈ 

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
	printf("����� ���� : "); 
	scanf("%d", &num);
	
	struct list *p = NULL;
	
	for(int i=0; i<num; i++)
	{
		printf("��� #%d ������ : ", i+1); 
		scanf("%d", &xdata);
		p=insert_ordered(p, xdata);
		//insert�Լ��� void�� ����� �ȵǴµ�... �׷����� ���������� 
	}	
	print_ordered_list(p);
	
	return 0;
}
