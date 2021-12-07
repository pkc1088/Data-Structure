#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 8  
#define FALSE 0 / 
#define TRUE 1
   
struct node   
{
	int vertex;
	struct node* link;
};

struct node* graph[MAX_VERTICES]; 
int visited[MAX_VERTICES];   

struct node* createnode(int data)
{
	struct node* ptr; 
	ptr = (struct node*)malloc(sizeof(struct node)); 
	ptr -> vertex = data; 
	ptr -> link = NULL;  
	return ptr;
}

void dfs(int v)
{
	struct node* w;
	visited[v] = TRUE;
	printf("V%d -> ", v);
	for(w = graph[v]; w; w = w -> link)  
		if(!visited[w->vertex])
			dfs(w->vertex);
}

int main( )
{
	graph[0] = createnode(1); 
	graph[0] -> link = createnode(2);   
	graph[1] = createnode(0);
	graph[1] -> link = createnode(3);
	graph[1] -> link->link = createnode(4);
	graph[2] = createnode(0);
	graph[2] -> link = createnode(5);
	graph[2] -> link->link = createnode(6);
	graph[3] = createnode(1);
	graph[3] -> link = createnode(7); 
	graph[4] = createnode(1);
	graph[4] -> link = createnode(7);
	graph[5] = createnode(2);
	graph[5] -> link = createnode(7);
	graph[6] = createnode(2);
	graph[6] -> link = createnode(7);
	graph[7] = createnode(3);
	graph[7] -> link = createnode(4);
	graph[7] -> link -> link = createnode(5);
	graph[7] -> link->link->link = createnode(6);
	dfs (0);   
	printf("NULL\n");   
}
/*int visited[MAX_VERTICES];

// ���� ����Ʈ�� ǥ���� �׷����� ���� ���� �켱 Ž��
void dfs_list(GraphType* g, int v)
{
	GraphNode* w;
	visited[v] = TRUE;   		// ���� v�� �湮 ǥ�� 
	printf("���� %d -> ", v);		// �湮�� ���� ���
	for (w = g->adj_list[v]; w; w = w->link)// ���� ���� Ž�� 
		if (!visited[w->vertex])
			dfs_list(g, w->vertex); //���� w���� DFS ���� ����
}*/
