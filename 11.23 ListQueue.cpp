#include <stdio.h>
#include <stdlib.h>

struct QueueNode 
{	
	int data;
	struct QueueNode *next;
};

struct LinkedQueueType
{			
	struct QueueNode *front, *rear;
};

void init(struct LinkedQueueType *q)
{
	q->front = q->rear = 0;
}
int is_empty(struct LinkedQueueType *q)
{
	return (q->front == NULL);
}
int is_full(struct LinkedQueueType *q)
{
	return 0;
}

void enqueue(struct LinkedQueueType *q, int data)
{
	struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode));
	temp->data = data; 		
	temp->next = NULL; 		
	if (is_empty(q)) 
	{ 		
		q->front = temp;
		q->rear = temp;
	}
	else 
	{ 		
		q->rear->next = temp;  
		q->rear = temp;
	}
}

int dequeue(struct LinkedQueueType *q)
{
	struct QueueNode *temp =q-> front;
	int data;
	if (is_empty(q)) 
	{	
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else 
	{
		data = temp->data; 	
		q->front = q->front->next; 
		if (q->front == NULL) 	
			q->rear = NULL;
		free(temp); 		
		return data; 		
	}
}
void print_queue(struct LinkedQueueType *q)
{
	struct QueueNode *p;
	for (p= q->front; p != NULL; p = p->next)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main(void)
{
	LinkedQueueType queue;

	init(&queue);		
	enqueue(&queue, 1);	print_queue(&queue);
	enqueue(&queue, 2);	print_queue(&queue);
	enqueue(&queue, 3);	print_queue(&queue);
	enqueue(&queue, 4);	print_queue(&queue);
//	dequeue(&queue);		print_queue(&queue);
//	dequeue(&queue);		print_queue(&queue);
//	dequeue(&queue);		print_queue(&queue);
	return 0;
}
