#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct nodeAVL
{
 int data;
 struct nodeAVL *left;
 struct nodeAVL *right;
} *root;

class classAVL
{
 public:
  int height(nodeAVL *);
  int diff(nodeAVL *);
  nodeAVL *rr(nodeAVL *);
  nodeAVL *ll(nodeAVL *);
  nodeAVL *lr(nodeAVL *);
  nodeAVL *rl(nodeAVL *);
  nodeAVL *balance(nodeAVL *);
  nodeAVL *insert(nodeAVL *, int );
  void display(nodeAVL *, int );
  void inorder(nodeAVL *);
  void preorder(nodeAVL *);
  void postorder(nodeAVL *);
  classAVL()
  {
   root = NULL;
  }
};

int main(void)
{
 int choice, item;
 classAVL AVL;
 while(1)
 {
  cout << "\n----------------------------" << endl;
  cout << "    C++�� ������ AVL Ʈ��" << endl;
  cout << "----------------------------" << endl;
  cout << "1. ���Ҹ� �����ҷ���." << endl;
  cout << "2. AVL Ʈ���� �����ּ���." << endl;
  cout << "3. ���� ��ȸ�� �ϰ�;��." << endl;
  cout << "4. ���� ��ȸ�� �ϰ�;��." << endl;
  cout << "5. ���� ��ȸ�� �ϰ�;��." << endl;
  cout << "6. ���α׷��� �����ҷ���." << endl;
  cout << "����� ������ �Է��ϼ��� : ";
  cin >> choice;
  switch(choice)
  {
   case 1:
    cout << "������ ������ �Է��ϼ��� : ";
    cin >> item;
    root = AVL.insert(root, item);
   case 2:
    if(root == NULL)
    {
     cout << "���� Ʈ���� ������ϴ�." << endl;
     continue;
    }
    cout << "[ AVL Ʈ�� ��� ]" << endl;
    AVL.display(root, 1);
    break;
   case 3:
    cout << "[ ���� ��ȸ ]" << endl;
    AVL.inorder(root);
    cout << endl;
    break;
   case 4:
    cout << "[ ���� ��ȸ ]" << endl;
    AVL.preorder(root);
    cout << endl;
    break;
   case 5:
    cout << "[ ���� ��ȸ ]" << endl;
    AVL.postorder(root);
    cout << endl;
    break;
   case 6:
    exit(1);
    break;
   default:
    cout << "�߸��� �Է��Դϴ�." << endl;
  }
 }
 return 0;
}

// AVL Ʈ���� ���̸� ����մϴ�.
int classAVL::height(nodeAVL* temp)
{
 int h = 0;
 if(temp != NULL)
 {
   // ��������� ���� Ȥ�� ���������� �˻��մϴ�.
  int left = height(temp->left);
  int right = height(temp->right);
  int maxHeight = max(left, right);
  h = maxHeight + 1;
 }
 return h;
} 

// �����μ�(������ ����)�� ��ȯ�մϴ�.
int classAVL::diff(nodeAVL* temp)
{
 // ���� �ڽ��� ���̿� ������ �ڽ��� ���� ���̸� ��ȯ�մϴ�.
 int left = height(temp->left);
 int right = height(temp->right);
 int factor = left - right;
 return factor;
}

// RR ȸ�� �Լ��Դϴ�.
nodeAVL *classAVL::rr(nodeAVL* parent)
{
 // ���� ȸ������ �׳� �θ� ����� ������ �ڽĳ��� �����͸� ��ȯ�ϴ� ���Դϴ�.
 nodeAVL *temp;
 temp = parent->right;
 parent->right = temp->left;
 temp->left = parent;
 return temp;
}

// ll ȸ�� �Լ��Դϴ�.
nodeAVL *classAVL::ll(nodeAVL* parent)
{
 // RR ȸ���� �ݴ��Դϴ�.
 nodeAVL *temp;
 temp = parent->left;
 parent->left = temp->right;
 temp->right = parent;
 return temp;
}

// LR ȸ�� �Լ��Դϴ�.
nodeAVL *classAVL::lr(nodeAVL* parent)
{
 // LR ȸ���� ���� �ڽ��� �������� RR, ������ �������� LLȸ���մϴ�.
 nodeAVL * temp;
 temp = parent->left;
 parent->left = rr(temp);
 return ll(parent);
}

// RL ȸ�� �Լ��Դϴ�.
nodeAVL *classAVL::rl(nodeAVL* parent)
{
 // LR ȸ���� �ݴ��Դϴ�.
 nodeAVL * temp;
 temp = parent->right;
 parent->right = ll(temp);
 return rr(parent);
}

// AVL Ʈ���� ������ ���ߴ� �Լ��Դϴ�.
nodeAVL *classAVL::balance(nodeAVL *temp)
{
 int factor = diff(temp);
 // ���� ����Ʈ�������� ������ �Ǿ� ������ ���� ����Դϴ�.
 if(factor > 1)
 {
  // �� ���� �ڽĳ�忡 ������ �߻��߽��ϴ�.
  if(diff(temp->left) > 0)
  {
   temp = ll(temp);
  }
  // �� ������ �ڽ� ��忡 ������ �߻��߽��ϴ�.
  else
  {
   temp = lr(temp);
  }
 }
 else if(factor < -1)
 {
  if(diff(temp->right) > 0)
  {
   temp = rl(temp);
  }
  else
  {
   temp = rr(temp);
  }
 }
 return temp;
}

// Ʈ���� ���Ҹ� �����ϴ� �Լ��Դϴ�.
nodeAVL * classAVL::insert(nodeAVL *root, int value)
{
 // ���� Ʈ���� ����� ��
 if(root == NULL)
 {
  root = new nodeAVL;
  root->data = value;
  root->left = NULL;
  root->right = NULL;
  return root;
 }
 else if(value < root->data)
 {
  root->left = insert(root->left, value);
  root = balance(root);
 }
 // ũ�ų� ���� ��� ������ ����Ʈ���� �����մϴ�.
 else if(value >= root->data)
 {
  root->right = insert(root->right, value);
  root = balance(root);
 }
 return root;
}

void classAVL::display(nodeAVL * ptr, int level)
{
 int i;
 // ���� Ʈ���� ������� ���� ����Դϴ�.
 if(ptr != NULL)
 {
  display(ptr->right, level + 1);
  printf("\n");
  // ���� ��Ʈ ����� ����Դϴ�.
  if(ptr == root)
  {
   cout << "Root -> ";
  }
  // i�� ���������� ���� ��Ʈ�� �ƴ� ����� ������ �Դϴ�.
  for(i = 0; i < level && ptr != root; i++)
  {
   cout << "        ";
  }
  // �ڽ��� ��ġ�� �����͸� ����մϴ�.
  cout << ptr->data;
  // ���� ��嵵 ������ݴϴ�.
  display(ptr->left, level + 1);
 }
}

/* Ʈ���� ��ȸ�ϴ� �� ���� �Լ��Դϴ�. */
void classAVL::inorder(nodeAVL *tree)
{
 if(tree == NULL)
  return;
 inorder(tree->left);
 cout << tree->data << "  ";
 inorder(tree->right);
} 
void classAVL::preorder(nodeAVL *tree)
{
 if(tree == NULL)
  return;
 cout << tree->data << "  ";
 preorder(tree->left);
 preorder(tree->right);
} 
void classAVL::postorder(nodeAVL *tree)
{
 if(tree == NULL)
  return;
 postorder(tree->left);
 postorder(tree->right);
 cout << tree->data << "  ";
} 
