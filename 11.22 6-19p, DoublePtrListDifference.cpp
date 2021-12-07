#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	int data;
	struct list *next;
};

struct list* insert_ordered(struct list* p, int data)
{
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = data;
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
	printf("NULL\n");	
}

void split(struct list *p, struct list **A, struct list **B)
{
	//리턴해서 p값 바꾸는게 아니니까 마지막까지 가도 노상관 
	for(int cnt=1; p!=NULL; p=p->next)
	{
		if(cnt==1)
		{
			*A=insert_ordered(*A, p->data);
			cnt=2;
		}		
		else if(cnt==2)
		{
			*B=insert_ordered(*B, p->data);
			cnt=1;
		}	
	}
}

struct list *split2(struct list *s, struct list **A, struct list **B) 
{
 	struct list *p = s;					//얘를 안해주면 리스트 마지막까지 간걸 리턴하니까 널나옴 
    for(int cnt=1; p!=NULL; p=p->next)
	{
		if(cnt==1)
		{
			*A=insert_ordered(*A, p->data);
			cnt=2;
		}		
		else if(cnt==2)
		{
			*B=insert_ordered(*B, p->data);
			cnt=1;
		}	
	}
    return s;
}

int main(void)
{
	struct list *p=NULL, *a=NULL, *b=NULL;
	p=insert_ordered(p, 1);
	p=insert_ordered(p, 2);
	p=insert_ordered(p, 3);
	p=insert_ordered(p, 4);
	p=insert_ordered(p, 5);
	p=insert_ordered(p, 6);
	p=insert_ordered(p, 7);
	print_ordered_list(p);
	
//	split(p, &a, &b);
	p=split2(p, &a, &b);
	print_ordered_list(p);	
	print_ordered_list(a);	
	print_ordered_list(b);

	
	return 0;
} 
