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

int peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return s->data[s->top];
}

void match(char exp[])
{
	struct StackType s;
	int a;
	int num, len = strlen(exp);

	push(&s, exp[0]-'0');
	
	for(int i=1; i<=len; i++)
	{
		num=exp[i]-'0';
		if(num!=peek(&s))
		{
			printf("%d ", pop(&s));	
			push(&s, num);
		}
	}
	/*	
	for (int i = 0; i <= len; i++) 
	{
		num = exp[i] - '0';
		
		if (is_empty(&s) || num == peek(&s)) 
			push(&s, num);
		
		else if (num != peek(&s)) 
		{
			printf("%d", peek(&s));
			
			while (!is_empty(&s))
				pop(&s);
			
			push(&s, num);
		}
	}		///정답 
	*/
}

int main(void)
{
	char exp[100];
	printf("정수를 입력하시오: ");
	scanf("%s", exp);
	printf("출력: ");
	match(exp);
	
	return 0;
}
