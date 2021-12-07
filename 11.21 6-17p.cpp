#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list{
	char data[10];
	struct list *next;
};

struct list* insert_ordered(struct list* p, char xdata[])
{
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	strcpy(newnode->data, xdata);
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
		printf("%s->", p->data);
	printf("NULL");	
}

struct list* list_alternate(struct list *A, struct list *B, struct list *r)
{
    while(A || B) 
	{
        if(A != NULL) 
		{
            r = insert_ordered(r, A->data);
            A = A->next;
        }
        if(B != NULL) 
		{
            r = insert_ordered(r, B->data);
            B = B->next;
        }
    }
    return r;
}

int main(void)
{
	struct list *A = NULL;
	struct list *B = NULL;
	struct list *C = NULL;
	A=insert_ordered(A, "a1");
	A=insert_ordered(A, "a2");
	A=insert_ordered(A, "a3");
	B=insert_ordered(B, "b1");
	B=insert_ordered(B, "b2");
	B=insert_ordered(B, "b3");

	
	C=list_alternate(A, B, C);
	
	print_ordered_list(C);

//	print_ordered_list(A);
//	print_ordered_list(B);

    return 0;
}

