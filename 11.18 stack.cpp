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

// ���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(struct element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
// ���� �Լ�
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else 
		return stack[top--];	
}
// ��ũ�Լ�
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
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
	oe = pop();		//���࿡ pop�� --top�̿����� 123�� ����� 
	printf("�й�: %d\n", oe.student_no);
	printf("�й�: %s\n", oe.name);
	printf("�й�: %s\n", oe.address);
	printf("\n");
	printf("�й�: %d\n", stack[0].student_no);
	printf("�й�: %s\n", stack[0].name);
	printf("�й�: %s\n", stack[0].address);
	printf("\n");
	printf("�й�: %d\n", stack[1].student_no);
	printf("�й�: %s\n", stack[1].name);
	printf("�й�: %s\n", stack[1].address);


	return 0;
}

