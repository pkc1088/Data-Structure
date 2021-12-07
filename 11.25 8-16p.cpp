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

TreeNode na = { 50, NULL, NULL};
TreeNode nb = { 30, NULL, &na};
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, &nb };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

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

int add_node(TreeNode* root)		
{
	int sum = 0;
	if (root == NULL) return 0;
	sum = root->data;
	sum = sum + add_node(root->left) + add_node(root->right);
	return sum;
}

void findSmall_inorder(TreeNode *root, int num) 
{
	if (root != NULL) 
	{
		findSmall_inorder(root->left, num);
		if(root->data<num)
		{
			printf("%d보다 작은 노드 : %d\n", num, root->data); 
		}	
		findSmall_inorder(root->right, num);
	}
}

int OneChildCount(TreeNode *root)
{
 	int cnt=0;
	if (root == NULL)		//이거 중요! 
		return NULL; 
	if( (root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL) )
		cnt++;

	cnt=cnt+OneChildCount(root->left)+OneChildCount(root->right);
	return cnt;
}

int main(void)
{
	int num;
	inorder(root);
	printf("\n\n");
	printf("자식이 하나인 노드의 개수 : ");
	printf("%d\n", OneChildCount(root));
	
	 
	return 0;
}
