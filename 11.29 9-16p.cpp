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

struct HeapType* delete_certain_heap(struct HeapType* h, int xkey)
{
	int i=1;
	
	while (h->heap[i].key != 0) 
	{	
		if( h->heap[i].key == xkey)
		{
			printf("Delete %d\n", h->heap[i].key);
			for(int j=i; j<=h->heap_size; j++)
			{
				h->heap[j] = h->heap[j+1];
			}
			h->heap_size--;
			return h;
		}	
		else
			i++;
	}
	printf("Couldn't find\n");
	return h;
}

struct HeapType* delete_certain_heap2(HeapType* h, int key)
{
	int parent, child;
	for (int i = 1; i < h->heap_size; i++) 
	{
		if (h->heap[i].key == key) 
		{
			parent = i;
			child = i * 2;
			break;
		}
	}
	element item = h->heap[parent];
	element temp = h->heap[(h->heap_size)--];
	while (child <= h->heap_size) 
	{
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key) 
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return h;
}

int main(void)
{
	struct element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, e4 = { 3 }, e5 = { 17 };
	struct element ep = { 0 };
	int j;
	struct HeapType* heap;
	heap = create(); 	
	init(heap);
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e4);
	insert_max_heap(heap, e5);
	
	printf("Heap Size : %d\n", heap->heap_size);
	delete_certain_heap(heap, 17);		
	printf("Heap Size : %d\n\n", heap->heap_size);
	
	int k=heap->heap_size;	//Áß¿ä 
	for(j=1; j<=k; j++)
	{	ep=delete_max_heap(heap);
		printf("< %d > ", ep.key);
	}

	free(heap);
	return 0;
}

