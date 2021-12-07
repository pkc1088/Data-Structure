#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct DequeType 
{ 
	int  data[MAX_QUEUE_SIZE];
	int  front, rear;
};

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}

int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}

int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType *q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) 
	{
		int i = q->front;
		
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType *q, int item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int delete_front(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int get_front(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, int val)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

int get_rear(DequeType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[q->rear];
}

int main(void)
{
	DequeType queue;

	init_deque(&queue);
	
	for (int i = 0; i < 6; i++) 
	{
		add_rear(&queue, i);
	}
	
	printf("\n%d\n", get_rear(&queue));
	
	for (int i = 0; i < 6; i++) 
	{
		deque_print(&queue);
	}
	
/*	for (int i = 0; i < 3; i++) 
	{
		delete_rear(&queue);
		deque_print(&queue);
	}
*/	
	
	return 0;
}
