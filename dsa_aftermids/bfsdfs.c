#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
void dfs(int v,int a[7][7],int isvisited[7])
{
	if(isvisited[v]==1)
		return;
	printf("%d ",v);
	isvisited[v]=1;
	for(int i=0;i<7;i++)
	{
		if(a[v][i]==1)
			dfs(i,a,isvisited);
	}
}


//Queue implementation
struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    //printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 

void bfs(int v,int a[7][7])
{
	int notvisited[7]={0};
	struct Queue* q=createQueue(100);
	enqueue(q,v);
	notvisited[v]=1;
	while(isEmpty(q)==0)
	{
		int t=dequeue(q);
		printf("%d ",t);
		for(int i=0;i<7;i++)
		{
			if(a[t][i]==1 && notvisited[i]==0)
			{	enqueue(q,i);
				notvisited[i]=1;}	
		}
	}
}
		
int main()
{
	//adjacency matrix
	int a[7][7]={{0,1,0,0,0,1,0},{1,0,1,0,1,0,0},{0,1,0,1,0,0,1},{0,0,1,0,0,0,0},{0,1,0,0,0,1,0},{1,0,0,0,1,0,0},{0,0,1,0,0,0,0}};
	int isvisited[7]={0};
	printf("........DFS.........\n");
	dfs(0,a,isvisited);
	printf("........BFS........\n");
	bfs(0,a);
}	
	
