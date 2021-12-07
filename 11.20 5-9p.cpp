#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

struct StackType 
{
	int data[MAX_STACK_SIZE];
	int top;
};

void init_stack(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, int item)
{
	if (is_full(s)) 
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else 
		s->data[++(s->top)] = item;
}

int pop(StackType *s)
{
	if (is_empty(s)) 
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[(s->top)--];
}

int peek(StackType *s)
{
	if (is_empty(s)) 
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[s->top];
}


int main(void)
{
	StackType s, t;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	
	push(&t, pop(&s));
	push(&t, pop(&s));
	push(&t, pop(&s));
	push(&t, pop(&s));
	
	printf("%d\n", pop(&t));
	printf("%d\n", pop(&t));
	printf("%d\n", pop(&t));
	printf("%d\n", pop(&t));

	return 0;
}


