#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 200

struct element 
{   
	char word[MAX_WORD_LENGTH];
    char mean[MAX_MEAN_LENGTH];
};

struct treeNode
{   
	struct element key;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode* insertKey(struct treeNode *p, struct element key)
{   
	struct treeNode *newNode;
    int compare; 

    if(p==NULL)
	{ 
        newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else
	{  
	    compare = strcmp(key.word, p->key.word);
        if(compare < 0)
            p->left = insertKey(p->right, key);
        else if(compare > 0)
            p->right = insertKey(p->right, key);
        else
            printf("\n �̹� ���� �ܾ �ֽ��ϴ�! \n");

        return p;   
	}
}

void insert(struct treeNode** root, struct element key)
{
    *root = insertKey(*root, key);
}

void deleteNode(struct treeNode *root, struct element key)
{  
	struct treeNode *parent, *p, *succ, *succ_parent;
    struct treeNode *child;
    parent = NULL;
    p = root;

    while((p != NULL) && (strcmp(p->key.word, key.word) != 0))
	{
        parent = p;
        if(strcmp(key.word, p->key.word) < 0)
            p=p->left;
        else p=p->right;
    }

    if(p == NULL)
	{
		printf("\n ������ �ܾ ������ �����ϴ�!!");
        return;
    }

    if((p->left == NULL) && (p->right == NULL))
	{
        if(parent != NULL)
		{
            if(parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;
    }
    
    else if((p->left == NULL) || (p->right == NULL))
	{
        if(p->left != NULL)
            child = p->left;
        else
            child = p->right;

        if(parent != NULL)
		{
            if(parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;
    }
    
    else
	{
        succ_parent = p;
        succ = p->right;
        while(succ->left != NULL)
		{
            succ_parent = succ;
            succ = succ->left;
        }
        if(succ_parent->left == succ)
            succ_parent->left = succ->right;
        else
            succ_parent->right = succ->right;

        p->key = succ->key;
        p = succ;
    }
    free(p);
}

struct treeNode* searchBST(struct treeNode* root, struct element key)
{  
	struct treeNode* p;
    int compare;
    p = root;
    while(p != NULL)
	{
        compare = strcmp(key.word, p->key.word);
        if(compare < 0)
            p = p->left;
        else if(compare > 0)
            p = p->right;
        else
		{
            printf("\nã�� �ܾ� : %s", p->key.word);
            return p;
        }
    }
    return p;
}

void displayInorder(struct treeNode* root)
{ 
 	if(root)
	{
        displayInorder(root->left);
        printf("\n%s : %s", root->key.word, root->key.mean);
        displayInorder(root->right);
    }
}

void menu()
{
    printf("\n*-------------------------------*");
    printf("\n\t1 : ���");
    printf("\n\t2 : �Է�");
    printf("\n\t3 : ����");
    printf("\n\t4 : �˻�");
    printf("\n\t5 : ����");
    printf("\n*-------------------------------*\n  ");
}

int main()
{
    char choice;
    struct element e;
    struct treeNode *root = NULL, *temp = NULL;
    do{
        menu();
        choice = getchar(); getchar();
        switch(choice-'0')
		{
            case 1:
                printf("\t[���� ���]");
                displayInorder(root);
                printf("\n\t[���� ��]\n");
                break;
            case 2:
                printf("\n[�ܾ� �Է�] �ܾ �Է��ϼ��� : ");
                gets(e.word);
                printf("[�ܾ� �Է�] �ܾ� ���� �Է��ϼ��� : ");
                gets(e.mean);
                insert(&root, e);
                break;
            case 3:
                printf("\n[�ܾ� ����] ������ �ܾ� : ");
                gets(e.word);
                deleteNode(root, e);
                break;
            case 4:
                printf("\n[�ܾ� �˻�] �˻��� �ܾ� : ");
                gets(e.word);
                temp = searchBST(root, e);

                if(temp != NULL)
                    printf("\n�ܾ� �� : %s", temp->key.mean);
                else
                    printf("\n������ ���� �ܾ��Դϴ�.");
                break;
        }
    }while((choice-'0') != 5);
	return 0;
}
