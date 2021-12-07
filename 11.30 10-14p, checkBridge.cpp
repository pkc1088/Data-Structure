#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct graphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];
bool isFindTarget = false; 
 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
	return;
}

void init_visited() {
	for (int i = 0; i < MAX_VERTICES; i++) {
		visited[i] = false;
	}
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "버텍스가 너무 많습니다.!");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "Graph: Vertex number error!");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void delete_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "Graph: Vertex number error!");
		return;
	}
	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}

void check_bridge_mat(GraphType* g, int v, int target)
{
	if (v == target) 
		isFindTarget = true;
	int i;
	visited[v] = true;
	
	for (i = 0; i < g->n; i++)
		if (g->adj_mat[v][i] && !visited[i]) 
			check_bridge_mat(g, i, target);
}

int findBridge(GraphType* g, int target){

	int totalBridge = 0;

	for (int i = 0; i < g->n; i++) 
	{  
		if (g->adj_mat[target][i] == 1) 
		{
			init_visited(); 
			isFindTarget = false;

			delete_edge(g, target, i); 
			check_bridge_mat(g, i, target);

			if (isFindTarget==false) 
			{
				printf("브릿지 : %d - %d\n", target, i);  
				totalBridge++;
			}
			insert_edge(g, target, i);
		}
	}
	return totalBridge;
}

int main(void)
{
	GraphType *g;
	int sum = 0;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 10; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 5, 7);
	insert_edge(g, 5, 6);
	insert_edge(g, 6, 7);
	insert_edge(g, 7, 8);
	insert_edge(g, 7, 9);

	for (int i = 0; i < 10; i++) {
		sum+= findBridge(g, i); 
	}

	printf("브릿지의 총 수 : %d \n", sum/2);
	free(g);
	return 0;
}
