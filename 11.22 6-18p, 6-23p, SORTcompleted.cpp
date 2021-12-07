#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	printf("NULL");	
}

struct list* list_alternate(struct list *A, struct list *B, struct list *C)
{
    while(A || B) 
	{
        if(A != NULL) 
		{
            C = insert_ordered(C, A->data);
            A = A->next;
        }
        if(B != NULL) 
		{
            C = insert_ordered(C, B->data);
            B = B->next;
        }
    }
    return C;
}

struct list* insert_middle(struct list *s, int n)
{
	
	struct list *cur, *prev, *p=s;
	struct list *newInserted=(struct list*)malloc(sizeof(list));

	for(cur=s, prev=NULL;
		cur!=NULL && cur->data<n;
		prev=cur, cur=cur->next)
		;
	
	if(cur==NULL)
		return s;	
		
	if(prev==NULL)
	{
		newInserted->next = s;
		newInserted->data = n;
		s = newInserted;
		return s;
	}
	
	prev->next=newInserted;
	newInserted->next=cur;
	newInserted->data=n;
	return s;
}

struct list* sort(struct list *s)	//낮은 차수 -> 높은 차수 
{
	struct list *check=NULL, *cur=s, *p=s;	int temp;
	for(p=p->next; p!=NULL; p=p->next)
	{
		check=s;
		if(cur->data > p->data)
		{
			temp=p->data;
			p->data=cur->data;
			if(check==cur)
			{
				cur->data=temp;
				cur=cur->next;
			}
			else
			{
				while(check->next!=cur)
				{
					check=check->next;
				}
				check->next=p;		
				free(cur);
				s=insert_middle(s, temp);
				cur=p;	
			}
		}
		else
		{
			cur=cur->next;
		}
	}
	return s;
}


struct list* merge(struct list *A, struct list *B)
{
   struct list* result = NULL;
    while(A || B) 
	{
        if(A != NULL && B != NULL) 
		{
            if(A->data >= B->data) 
			{
                result = insert_ordered(result, B->data);
                B = B->next;
            } 
			else 
			{
                result = insert_ordered(result, A->data);
                A = A->next;
            }
        }
        
        if(A == NULL)
        { 	
			result = insert_ordered(result, B->data); 
			B = B->next; 
		}
		
        else if(B == NULL) 
		{	
			result = insert_ordered(result, A->data); 
			A = A->next;
		}
    }
    return result;
}
	

int main(void)
{
	struct list *A = NULL;
	struct list *B = NULL;
	struct list *C = NULL;
	
	A=insert_ordered(A, 12);
	A=insert_ordered(A, 13);
	A=insert_ordered(A, 1);
	A=insert_ordered(A, 5);
	A=insert_ordered(A, 3);
	A=insert_ordered(A, 4);
	A=insert_ordered(A, 2);
	A=insert_ordered(A, 10);
	A=insert_ordered(A, 8);
	print_ordered_list(A);

	printf("\n\n");
	B=insert_ordered(B, 4);
	B=insert_ordered(B, 6);
	B=insert_ordered(B, 10);
	B=insert_ordered(B, 8);
	print_ordered_list(B);
	
	printf("\n\n");
	C=list_alternate(A, B, C);
	print_ordered_list(C);

	printf("\n\n");
	A=sort(A); B=sort(B); 
	C=merge(A, B);
	print_ordered_list(C);
	
	printf("\n\n");
	C=sort(C);
	print_ordered_list(C);

    return 0;
}
