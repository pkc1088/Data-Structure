#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

struct element 
{
	char word[MAX_WORD_SIZE];		
	char meaning[MAX_MEANING_SIZE];
};

struct TreeNode 
{
	struct element key;
	struct TreeNode *left, *right;
};

int compare(struct element e1, struct element e2)
{
	return strcmp(e1.word, e2.word);
}

void display(struct TreeNode * p)
{
	if (p != NULL) 
	{
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
}

struct TreeNode * search(struct TreeNode * root, struct element key)
{
	struct TreeNode * p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p; 	
}

struct TreeNode * new_node(struct element item)
{
	struct TreeNode * temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct TreeNode * insert_node(struct TreeNode * node, struct element key)
{
	if (node == NULL) return new_node(key);

	if (compare(key, node->key)<0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key)>0)
		node->right = insert_node(node->right, key);

	return node;
}

struct TreeNode * min_value_node(struct TreeNode * node)
{
	struct TreeNode * current = node;

	while (current->left != NULL)
		current = current->left;
	return current;
}

struct TreeNode * delete_node(struct TreeNode * root, struct element key)
{
	if (root == NULL) return root;

	if (compare(key, root->key)<0)
		root->left = delete_node(root->left, key);
	if (compare(key, root->key)>0)
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

void help()
{
	printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}

int main(void)
{
	char command;
	struct element e;
	struct TreeNode * root = NULL;
	struct TreeNode * tmp;

	do {
		help();
		command = getchar();
		getchar();
		switch (command) 
		{
		case 'i':
			printf("단어:");
			gets(e.word);
			printf("의미:");
			gets(e.meaning);
			root = insert_node(root, e);
			break;
		case 'd':
			printf("단어:");
			gets(e.word);
			root=delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("단어:");
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미:%s\n", e.meaning);
			break;
		}

	} while (command != 'q');

	return 0;
}
