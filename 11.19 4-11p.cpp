#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return s->top == -1;
}

int is_full(StackType* s)
{
	return s->top == (MAX_STACK_SIZE - 1);
}

void push(StackType* s, int item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

int pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

void match(char exp[])
{
	StackType s;
	init_stack(&s);
	char ch;
	int len = strlen(exp);
	int no = 0;
	for (int i = 0; i < len; i++) 
	{
		ch = exp[i];
		switch (ch) {
		case '(' :
			no++;
			printf("%d ", no);
			push(&s, no);
			break;
		case ')':
			printf("%d ", pop(&s));
			break;
		}
	}
}

int main(void)
{
	char exp[100];
	printf("����: ");
	scanf("%s", exp, sizeof(exp));
	printf("��ȣ ��: ");
	match(exp);
	return 0;
}

