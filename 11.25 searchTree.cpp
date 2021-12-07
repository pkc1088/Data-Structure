#include <stdio.h>
#include <stdlib.h>

struct TreeNode 
{
	int key;
	struct TreeNode *left, *right;
};

struct TreeNode *search(struct TreeNode * node, int key)
{
	if (node == NULL) return NULL;
	
	if (key == node->key) 
		return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

struct TreeNode *new_node(int item)
{
	struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct TreeNode *insert_node(struct TreeNode *node, int key)
{
	if (node == NULL) return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

struct TreeNode *min_value_node(struct TreeNode *node)
{
	struct TreeNode *current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

struct TreeNode *delete_node(struct TreeNode  *root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);		 
	else if (key > root->key)
		root->right = delete_node(root->right, key);	
	else												
	{
		if (root->left == NULL)							
		{
			struct TreeNode * temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) 
		{
			struct TreeNode * temp = root->left;
			free(root);
			return temp;
		}

		struct TreeNode * temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder_print(struct TreeNode * root) 
{
	if (root) 
	{
		inorder_print(root->left);		//반환형이 void니까 root->left=inroder_print() 이게 아님 
		printf("[%d] ", root->key);
		inorder_print(root->right);
	}
}

void Descending_print(struct TreeNode * root) 
{
	if (root) 
	{
		Descending_print(root->right);	
		printf("[%d] ", root->key);
		Descending_print(root->left);
	}
}

int main(void)
{
	struct TreeNode * root = NULL;
	struct TreeNode * tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	root=delete_node(root, 30);
	inorder_print(root);

	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	
	return 0;
}
