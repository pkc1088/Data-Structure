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

int poly_cal(struct list *s, int x)
{
	struct list *p=s;
	int i=0, answer=0, s1, arr[10];
	for(; p; p=p->next)
	{
		s1=x;
		int ex_cnt=p->ex;
		
		if(ex_cnt==0)
		{
			arr[i]=p->co;
			break;
		}
		
		for(int j=1; j<ex_cnt; j++)
			s1 = s1 * x;
		s1 = s1 * p->co;
			
		arr[i++]=s1;
	}
	for(; i>=0; i--)
		answer+=arr[i];
	
	return answer;
}

int main(void)
{
	struct list *p=NULL;
	p=insert_ordered(p, 1, 3);
	p=insert_ordered(p, -2, 1);
	p=insert_ordered(p, 6, 0);
	
	printf("P(x) =  "); print_ordered_list(p);
	printf("P(2) =  %d", poly_cal(p, 3));
	 
	return 0;
} 
