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
	printf("%d�� ����Ʈ���� %d�� ��Ÿ���ϴ�\n", x, cnt);  
}

struct list* deleteOnce(struct list *p, int x)
{
	struct list *target, *q;
	for(target=p, q=p; target!=NULL; target=target->next)
		if(target->data==x)
		{
			while(q->next!=target)
			{
				q=q->next;
			}
			q->next=target->next;
			free(target);
			return p;
		}
}

struct list* deleteAllCase(struct list* p, int x)
{
	struct list* node = p;	//node�� ���̽� ����Ŀ (p�� �ʱ�ȭ �Ǿ����ϱ�) 
	struct list* q = NULL;
	struct list* target = NULL;

	while (node != NULL) 
	{
		target = node;
		if (target->data != x) 
		{
			q = target;
			node = node->next;
		}
		else 
		{
			node = node->next;
			if (q == NULL)
				p = p->next;
			else
				q->next = target->next;	 //q->next=node; ��� �ص� ����.. 
			free(target);
		}
	}
	return p;
}

struct list* deleteEven(struct list* p)
{
	struct list* node = p;
	struct list* q = NULL;
	struct list* target = NULL;
	int cnt=1;
	while (node != NULL) 
	{
		target = node;
		if (cnt!=2) 
		{
			q = target;
			node = node->next;
			cnt++;
		}
		else 
		{
			node = node->next;
			if (q == NULL)
				p = p->next;
			else
				q->next = target->next;	 //q->next=node; ��� �ص� ����.. 
			free(target);
			cnt=1;
		}
	}
	return p;
}

void remove_odd_node(struct list **p) 
{	//���� �����ͽἭ Ȧ����° ���� 
	*p = (*p)->next;
	struct list* q = NULL, *removed = *p;
	while (removed->next != NULL) {
		q = removed;
		removed = removed->next;
		q->next = removed->next;
		if (removed->next != NULL)
			removed = removed->next;
		else
			break;
	}
	return;
}

int search_max(struct list* p)
{
	if (p == NULL) 
	{
		printf("����Ʈ�� ������ϴ�.\n");
		return 0;
	}
	int max = p->data;
	for (p = p->next; p != NULL; p = p->next) 
		if (max < p->data)
			max = p->data;
	return max;
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
		
	if(prev==NULL)					//������ insert_first�� ���� 
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

struct list* sort(struct list *s)	//���� ���� -> ���� ���� 
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
        
        if(A == NULL)		//else if �ƴ��� Ȯ���ϱ� 
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
        
		else if(A==NULL)		//if�ƴ� ����!! 
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

void split(struct list *p, struct list **A, struct list **B)
{
	//�����ؼ� p�� �ٲٴ°� �ƴϴϱ� ���������� ���� ���� 
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
 	struct list *p = s;					//�긦 �����ָ� ����Ʈ ���������� ���� �����ϴϱ� �γ��� 
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
	int num, num2, xdata;
	struct list *p = NULL;
	
	printf("����� ���� : "); 
	scanf("%d", &num);
	for(int i=0; i<num; i++)
	{
		printf("��� #%d ������ : ", i+1); 
		scanf("%d", &xdata);
		p=insert_ordered(p, xdata);
	}
	print_ordered_list(p);
	
	
	printf("\n\n������ �� : ");
	scanf("%d", &num2); 
	p=deleteAllCase(p, num2);
	print_ordered_list(p);
	
	
	printf("\n\n¦�� ��° ��� ����\n"); 
	p=deleteEven(p);	
	print_ordered_list(p);
	
	
	printf("\n\n¦�� ��° ��� ����2\n");
	remove_odd_node(&p);
	print_ordered_list(p);
	
	/*
	split(p, &a, &b); 
	p=split2(p, &a, &b);	
	print_ordered_list(p);	
	print_ordered_list(a);	
	print_ordered_list(b);	
	*/
	return 0;
}
