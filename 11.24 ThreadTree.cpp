#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread;	// 스레드이면 TRUE
} TreeNode;


//		     G
//	     C		  F
//    A	   B   D     E
TreeNode n1 = { 'A',  NULL, NULL, 1 };
TreeNode n2 = { 'B',  NULL,  NULL, 1 };
TreeNode n3 = { 'C',  &n1,  &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4,  &n5, 0 };
TreeNode n7 = { 'G', &n3,  &n6, 0 };
TreeNode * exp = &n7;

TreeNode * find_successor(TreeNode * q)
{
	TreeNode * T = q->right;
	if (T == NULL || q->is_thread == TRUE)
		return T;
	while (T->left != NULL) 
		T = T->left;
	return T;
}

void thread_inorder(TreeNode * t)
{
	TreeNode * q;
	q = t;
	while (q->left) 
		q = q->left;
	do {
		printf("%c -> ", q->data);
		q = find_successor(q);
	} while (q);		
}
int main(void)
{
	// 스레드 설정 
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	// 중위 순회
	thread_inorder(exp);
	printf("\n");
	return 0;
}
