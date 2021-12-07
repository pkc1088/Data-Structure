#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode 
{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode * element;
typedef struct 
{ 
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

int get_node_count(TreeNode *node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) +
		get_node_count(node->right);
	return count;
}

int get_leaf_count(TreeNode *node)
{
	int count = 0;
	if (node != NULL) 
	{
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) +
			get_leaf_count(node->right);
	}
	return count;
}

int height_max(int a, int b)
{
	return (a>b) ? a : b;
}

int get_height(TreeNode *node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + height_max(get_height(node->left),
			get_height(node->right));

	return height;
}

int isBalanced(TreeNode* root)
{
	TreeNode* p = root;
	int left_height = get_height(p->left);
	int right_height = get_height(p->right);
	int height = left_height - right_height;
	if (height <= 1 && height >= -1) 
		return 1;
	else 
		return 0;
}

// 중위 순회 
void inorder(TreeNode *root) 
{
	if (root != NULL) 
	{
		inorder(root->left);
		printf("[%d] ", root->data); 
		inorder(root->right);
	}
}
// 전위 순회
void preorder(TreeNode *root) 
{
	if (root != NULL) 
	{
		printf("[%d] ", root->data); 
		preorder(root->left);
		preorder(root->right);
	}
}
// 후위 순회
void postorder(TreeNode *root)
{
	if (root != NULL) 
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data); 
	}
}

int sum=0;

int sum_inorder(TreeNode *root) 
{	
	if (root != NULL) 
	{
		sum_inorder(root->left);
		sum+=root->data; 
		sum_inorder(root->right);
	}
	return sum;
}
int add_node(TreeNode* root)			//답지 풀이 
{
	int sum = 0;
	if (root == NULL) return 0;
	sum = root->data;
	sum = sum + add_node(root->left) + add_node(root->right);
	return sum;
}

TreeNode na = { 50, NULL, NULL};
TreeNode nb = { 30, NULL, &na};
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, &nb };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

int main(void)
{
	inorder(root);
	printf("\n%d\n", sum_inorder(root));
		
	return 0;
}

/*
1 / 4 / 15 \ 20 /\ (16,25) \ 30 \ 50   인 상태 
*/
