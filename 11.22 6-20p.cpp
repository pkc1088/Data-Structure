#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	int co;
	int ex;
	struct list *next;
};

struct list* insert_ordered(struct list* p, int co, int ex)
{
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	newnode->co = co;
	newnode->ex = ex;
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
		printf("%dx^%d ", p->co, p->ex);
	printf("\n");	
}

struct list* poly_add(struct list *p, struct list* A, struct list* B)
{
	while(A||B)
	{
		if(A && B ) 
		{
            if(A->ex > B->ex) 
			{
                p = insert_ordered(p, A->co, A->ex);
                A = A->next;
            } 
			else if(B->ex > A->ex) 
			{
                p = insert_ordered(p, B->co, B->ex);
                B = B->next;
            }
            else if(A->ex == B->ex)
            {
            	p = insert_ordered(p, (A->co)+(B->co), A->ex);
            	A = A->next;
            	B = B->next;
			}
        }
        
		else if(A==NULL)		//if¾Æ´Ô ÁÖÀÇ!! 
		{
			p=insert_ordered(p, B->co, B->ex);
			B=B->next;
		}
		else if(B==NULL)
		{
			p=insert_ordered(p, A->co, A->ex);
			A=A->next;
		}
	}
	return p;
}

int main(void)
{
	struct list *p=NULL, *a=NULL, *b=NULL;
	a=insert_ordered(a, 3, 6);
	a=insert_ordered(a, 7, 3);
	a=insert_ordered(a, -2, 2);
	a=insert_ordered(a, -9, 0);
	
	b=insert_ordered(b, -2, 6);
	b=insert_ordered(b, -4, 4);
	b=insert_ordered(b, 6, 2);
	b=insert_ordered(b, 6, 1);
	b=insert_ordered(b, 1, 0);
	
	p=poly_add(p, a, b);
	
	printf("A(x) =  "); print_ordered_list(a);	
	printf("B(x) = "); 	print_ordered_list(b);
	printf("P(x) =  "); print_ordered_list(p);
	 
	return 0;
} 
