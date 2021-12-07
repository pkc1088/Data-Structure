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
            printf("\n 이미 같은 단어가 있습니다! \n");

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
		printf("\n 삭제할 단어가 사전에 없습니다!!");
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
            printf("\n찾은 단어 : %s", p->key.word);
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
    printf("\n\t1 : 출력");
    printf("\n\t2 : 입력");
    printf("\n\t3 : 삭제");
    printf("\n\t4 : 검색");
    printf("\n\t5 : 종료");
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
                printf("\t[사전 출력]");
                displayInorder(root);
                printf("\n\t[사전 끝]\n");
                break;
            case 2:
                printf("\n[단어 입력] 단어를 입력하세요 : ");
                gets(e.word);
                printf("[단어 입력] 단어 뜻을 입력하세요 : ");
                gets(e.mean);
                insert(&root, e);
                break;
            case 3:
                printf("\n[단어 삭제] 삭제할 단어 : ");
                gets(e.word);
                deleteNode(root, e);
                break;
            case 4:
                printf("\n[단어 검색] 검색할 단어 : ");
                gets(e.word);
                temp = searchBST(root, e);

                if(temp != NULL)
                    printf("\n단어 뜻 : %s", temp->key.mean);
                else
                    printf("\n사전에 없는 단어입니다.");
                break;
        }
    }while((choice-'0') != 5);
	return 0;
}
