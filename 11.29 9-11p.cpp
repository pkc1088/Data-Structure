#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200
#define SIZE 8
struct element 
{
	char str[30];
	int key;
};

struct HeapType 
{
	struct element heap[MAX_ELEMENT];
	int heap_size;
};

struct HeapType* create()
{
	return (struct HeapType*)malloc(sizeof(struct HeapType));
}

void init(struct HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(struct HeapType* h, struct element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) 
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;    
}

struct element delete_max_heap(struct HeapType* h)
{
	int parent, child;
	struct element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) 
	{
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(struct element a[], int n)
{
	int i;
	struct HeapType* h;
	h = create();
	init(h);
	
	for (i = 0; i<n; i++) 
		insert_max_heap(h, a[i]);
	for (i = (n - 1); i >= 0; i--) 
		a[i] = delete_max_heap(h);
	
	free(h);
}


int main(void)
{
	char ch='\0';
	struct element p;
	struct HeapType *heap;
	heap = create(); 	
	init(heap);	
	
	while(ch!='q')
	{	
		printf("삽입(i), 삭제(d), 종료(q) : ");
		ch=getchar();
		getchar();
		if(ch=='i')
		{
			printf("할 일: "); 
			scanf("%[^\n]s", p.str);
			printf("우선순위 : "); 
			scanf("%d", &p.key);
			getchar();
			insert_max_heap(heap, p);
		}	
		
		else if(ch=='d')
		{
			p=delete_max_heap(heap);
			printf("제일 우선 순위가 높은 일은 %s\n", p.str); 
		}	
	}
	
	return 0;
}
