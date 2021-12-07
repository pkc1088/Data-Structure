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
	element data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

//		   15
//	   4		20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

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

	if (node != NULL) {
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

int isBalanced(TreeNode *root)			//내 풀이
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

int add_node(TreeNode* root)			//답지 풀이 
{
	int sum = 0;
	if (root == NULL) 
		return 0;
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

int findmaximum(TreeNode *root) 
{
	static int maxi=root->data;
	if (root != NULL) 
	{
		findmaximum(root->left);
		findmaximum(root->right);
		if(maxi<root->data)
			maxi=root->data; 
	}
	return maxi;
}

int findminimum(TreeNode *root) 
{
	static int mini=root->data;
	if (root != NULL) 
	{
		findminimum(root->left);
		findminimum(root->right);
		if(mini>root->data)
			mini=root->data; 
	}
	return mini;
}

int min(int x, int y)
{
	if (x < y) return x;
	else return y;
}

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}

int search_min(TreeNode* root)
{
	if (root == NULL) 
		return 0;
	int min_value = root->data;
	min_value = min(min_value, search_min(root->left));
	min_value = min(min_value, search_min(root->right));
	return min_value;
}

int search_max(TreeNode* root)
{
	if (root == NULL) 
		return 0;
	int max_value = root->data;
	max_value = max(max_value, search_max(root->left));
	max_value = max(max_value, search_max(root->right));
	return max_value;
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

void inorder(TreeNode *root) 			// 중위 순회
{
	if (root != NULL) 
	{
		inorder(root->left);
		printf(" [%d] ", root->data); 
		inorder(root->right);
	}
}

void preorder(TreeNode *root) 			// 전위 순회
{
	if (root != NULL) 
	{
		printf("[%d] ", root->data); 
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode *root)			// 후위 순회
{
	if (root != NULL) 
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data); 
	}
}

void level_order(TreeNode *ptr)			// 레벨 순회 
{
	QueueType q;

	init_queue(&q);	

	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) 
	{
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}


int main(void)
{
	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	printf("중위 순회=");
	inorder(root);
	return 0;
}
