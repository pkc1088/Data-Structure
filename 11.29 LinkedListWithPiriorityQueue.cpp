#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 200
#define MAX 987654321
#define MIN -987654321
//*****연결리스트로 우선순위 큐 구현 
typedef struct HeapType{
	int data;
	struct HeapType* link;
}HeapType;


HeapType* create_node(int data) {
	HeapType* new_node;
	new_node = (HeapType*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

void insert_max_heap(HeapType** phead, HeapType* new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		new_node->link = NULL;
		HeapType* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_node;
	}
}

int pop_max_heap(HeapType** head) {
	int m = MIN;
	HeapType* p = NULL, * removed = *head;
	HeapType* temp1 = NULL, * temp2 = *head;
	while (removed != NULL) {
		if (removed->data > m) {
			m = removed->data;
			temp1 = p;
			temp2 = removed;
		}
		p = removed;
		removed = removed->link;
	}

	if (temp1 == NULL)
		*head = (*head)->link;
	else
		temp1->link = temp2->link;	//free가 필요없는 방식 

	return m;
}


bool is_empty(HeapType* h) {
	return h == NULL;
}

bool is_full(HeapType* h) {
	HeapType* n;
	n = (HeapType*)malloc(sizeof(n));
	return n == NULL;
}

int find_max_heap(HeapType* h) {
	int m = MIN;
	HeapType* p = h;
	while (p != NULL) {
		if (p->data > m)
			m = p->data;
		p = p->link;
	}
	return m;
}
