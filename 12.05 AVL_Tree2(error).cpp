#include<stdio.h> 
#include<stdlib.h> 
#define TMAX(a, b) (a)

typedef struct AVLNode
{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;

int get_height(AVLNode *node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + TMAX(get_height(node->left),
			get_height(node->right));

	return height;
}

int get_balance(AVLNode* node)
{
	if (node == NULL) return 0;

	return get_height(node->left)
		- get_height(node->right);
}

AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

AVLNode *rotate_right(AVLNode *parent)
{
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

AVLNode *rotate_left(AVLNode *parent)
{
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}

AVLNode* insert(AVLNode* node, int key)
{
	if (node == NULL)
		return(create_node(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else	
		return node;

	int balance = get_balance(node);

	// LL 타입 처리
	if (balance > 1 && key < node->left->key)
		return rotate_right(node);

	// RR 타입 처리
	if (balance < -1 && key > node->right->key)
		return rotate_left(node);

	// LR 타입 처리
	if (balance > 1 && key > node->left->key)
	{
		AVLNode* temp = node->left;
		node->left = rotate_left(temp);
		return rotate_right(node);
	}

	// RL 타입 처리
	if (balance < -1 && key < node->right->key)
	{
		AVLNode* temp = node->right;
		node->right = rotate_right(temp);
		return rotate_left(node);
	}
	return node;
}

void preorder(AVLNode *root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);	
	}
}

int main(void)
{
	AVLNode *root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);
/*	root = insert(root, 60);
	root = insert(root, 50);
	root = insert(root, 20);
	root = insert(root, 80);
	root = insert(root, 90);
	root = insert(root, 70);
	root = insert(root, 55);
	root = insert(root, 10);
	root = insert(root, 40);
	root = insert(root, 35);*/
	printf("전위 순회 결과 \n");
	preorder(root);

	return 0;
}
