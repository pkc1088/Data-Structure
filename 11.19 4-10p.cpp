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
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

int pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else 
		return s->data[(s->top)--];
}

int peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else 
		return s->data[s->top];
}

int main(void)
{	
	StackType s;
	int n, m;
	printf("���� �迭�� ũ�� : ");
	scanf("%d", &n);
	
	printf("������ �Է��Ͻÿ� : "); 
	for(int i=0; i<n; i++)
	{
		scanf("%d", &m);
		push(&s, m);
	}
	
	printf("������ ���� �迭 : "); 
	for(int i=0; i<n; i++)
		printf("%d ", pop(&s));
	
	return 0;
}

