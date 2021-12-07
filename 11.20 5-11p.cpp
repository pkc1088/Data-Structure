#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUEUE_SIZE 20

struct DequeType 
{ 
	char data[MAX_QUEUE_SIZE];
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
			printf("%c | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType *q, int item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

void delete_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
}

char get_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, char val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

char get_rear(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

void check_palindrome(DequeType *q, int *count)
{
	if(is_empty(q))
	{
		printf("잘못된 입력!\n");
		exit(1);
	}
	
	for (int i = 0; i < *count / 2; i++) 
	{
		if(get_front(q)!=get_rear(q))
		{
			printf("\nNot Palindrome\n");
			return exit(1);
		}
		delete_rear(q);
		delete_front(q);
	}
	printf("\nPalindrome\n");
}

int main(void)
{
	DequeType q;
	init_deque(&q);
	char ch;	int count=0;
	
	while((ch=getchar()) != '\n')
	{
		if(isalpha(ch))
		{
			add_rear(&q, tolower(ch));
			count++;
		}
	}
	
	check_palindrome(&q, &count);	
		
		
	return 0;
}
