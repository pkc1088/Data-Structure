#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100


struct element{
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
};
struct element stack[MAX_STACK_SIZE];
int  top = -1;

// 공백 상태 검출 함수
int is_empty()
{
	return (top == -1);
}
// 포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(struct element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}
// 삭제 함수
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return stack[top--];	
}
// 피크함수
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
		return stack[top];
}

int main(void)
{
	struct element ie = { 	123,
			"Hong",
			"Soeul"	};
	struct element oe = { 	456,
			"Pyeon",
			"Pusan"	};

	push(ie);
	push(oe);
	oe = pop();		//만약에 pop이 --top이였으면 123을 출력함 
	printf("학번: %d\n", oe.student_no);
	printf("학번: %s\n", oe.name);
	printf("학번: %s\n", oe.address);
	printf("\n");
	printf("학번: %d\n", stack[0].student_no);
	printf("학번: %s\n", stack[0].name);
	printf("학번: %s\n", stack[0].address);
	printf("\n");
	printf("학번: %d\n", stack[1].student_no);
	printf("학번: %s\n", stack[1].name);
	printf("학번: %s\n", stack[1].address);


	return 0;
}

