#include<stdio.h>
#include<stdlib.h>
int vertices;
void dfs(int vertex,int** matrix,int* visited)
{
	if(visited[vertex]==1)
		return;
	printf("%d ",vertex);
	visited[vertex] = 1;
	for(int i = 0 ; i < vertices ; i++)
	{
		if(matrix[vertex][i] == 1)
			dfs(i,matrix,visited);
	}
}
int main()
{
	scanf("%d",&vertices);
	int** adj_mat = (int**)malloc(sizeof(int*)*vertices);
	for(int i = 0 ; i < vertices ; i++)
		adj_mat[i] = (int*)calloc(sizeof(int),vertices);
	int edges,*visit = (int*)calloc(sizeof(int),vertices);
	scanf("%d",&edges);
	while(edges--)
	{
		int vertex1,vertex2;
		scanf("%d%d",&vertex1,&vertex2);
		adj_mat[vertex1][vertex2] = 1;
	}
	dfs(0,adj_mat,visit);
	printf("\n");
	return 0;
}
