#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

struct StackType
{
	int data[26];
	int top=-1;
};

int is_empty(StackType* s)
{
	return s->top == -1;
}

int is_full(StackType* s)
{
	return s->top == (MAX_STACK_SIZE - 1);
}

int push(StackType* s, int item)
{
	if (is_full(s)) 
	{
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else 
		s->data[++(s->top)] = item;
}

int pop(StackType* s)
{
	if (is_empty(s)) 
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
 	else 
	 	return s->data[(s->top)--];
}

void match(char exp[])
{
	StackType s;
	char ch;
	int num, len = strlen(exp);
	
	for(int i=0; i<len; i++)
	{
		num=1;
		ch = tolower(exp[i]);
		while(ch==tolower(exp[i+1])) 
		{
			num++;
			i++;
		}
		push(&s, num);
		
		printf("%d%c ", pop(&s), ch);
	}
}

int main(void)
{
	char exp[100];
	printf("문자열을 입력하시오: ");
	scanf("%s", exp);
	printf("압축된 문자열: ");
	match(exp);
	
	return 0;
}
