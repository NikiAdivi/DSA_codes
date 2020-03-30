#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void addedge(int src,int dest,int **adj,int n)
{
	adj[src][dest]=1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int **adj=calloc(n,sizeof(int *));
	for(int i=0;i<n;i++){
		adj[i]=calloc(n,sizeof(int));
	}
	int edges;
	scanf("%d",&edges);
	for(int i=0;i<edges;i++){
		int src;
		int dest;
		scanf("%d %d",&src,&dest);
		addedge(src,dest,adj,n);
		addedge(dest,src,adj,n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	return 0;
}
