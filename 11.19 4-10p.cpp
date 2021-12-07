#include <stdio.h>
#include <stdlib.h>

struct StackType 
{
	int data[100];
	int top=-1;
};

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (100 - 1));
}

void push(StackType *s, int item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

int pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[(s->top)--];
}

int peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[s->top];
}

int main(void)
{	
	StackType s;
	int n, m;
	printf("정수 배열의 크기 : ");
	scanf("%d", &n);
	
	printf("정수를 입력하시오 : "); 
	for(int i=0; i<n; i++)
	{
		scanf("%d", &m);
		push(&s, m);
	}
	
	printf("반전된 정수 배열 : "); 
	for(int i=0; i<n; i++)
		printf("%d ", pop(&s));
	
	return 0;
}

