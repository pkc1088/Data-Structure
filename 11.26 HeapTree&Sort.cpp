#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 8
struct element 
{
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
	struct element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	struct element e4, e5, e6;
	struct HeapType* heap;

	heap = create(); 	
	init(heap);
	
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	
	//히프 정렬 
	struct element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i].key);
	printf("\n");
	
	
	return 0;
}

