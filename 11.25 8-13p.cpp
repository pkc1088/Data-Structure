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

// ���� ��ȸ 
void inorder(TreeNode *root) 
{
	if (root != NULL) 
	{
		inorder(root->left);
		printf("[%d] ", root->data); 
		inorder(root->right);
	}
}
// ���� ��ȸ
void preorder(TreeNode *root) 
{
	if (root != NULL) 
	{
		printf("[%d] ", root->data); 
		preorder(root->left);
		preorder(root->right);
	}
}
// ���� ��ȸ
void postorder(TreeNode *root)
{
	if (root != NULL) 
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data); 
	}
}

//�� Ǯ�� 
int isBalanced(TreeNode *root)
{
	TreeNode *Lt=root;
	TreeNode *Rt=root;
	while(Lt->left!=NULL && Rt->right!=NULL)
	{
		Lt = Lt->left;
		Rt = Rt->right;	
	}
	if(Lt->left==NULL && Rt->right!=NULL)
	{
		if(Rt->right->right!=NULL)
			return false;	
	}	
	else if(Lt->left!=NULL && Rt->right==NULL)
	{
		if(Lt->left->left!=NULL)
			return false;	
	}
	return true;
}

int isBalanced2(TreeNode* root)
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
	printf("\n");
	if(isBalanced(root))
		printf("Balanced Tree\n");
	else 
		printf("Unbalanced Tree\n");
		
	return 0;
}

/*
1 / 4 / 15 \ 20 /\ (16,25) \ 30 \ 50   �� ���� 
*/
