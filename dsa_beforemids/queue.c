#include<stdlib.h>
#include<stdio.h>
typedef struct Queue
{
  int front,rear;
  int capacity,size;
  int* data;
}Queue;

Queue* createqueue(int capacity)
{
  Queue* temp=(Queue*)malloc(sizeof(Queue));
  temp->capacity=capacity;
  temp->front=0;
  temp->size=0;
  temp->rear=capacity-1;
  temp->data=(int*)malloc(capacity*sizeof(int));
  return temp;
}

int isfull(Queue* que)
{
  if(que->size==que->capacity)
  {
    return 1;
  }
  else
  return 0;
}

int isempty(Queue* que)
{
  if(que->size==0)
  {
    return 1;
  }
  else
    return 0;
}

void enqueue(Queue* que,int data)
{
  if(isfull(que)==0)
  {
  que->size++;
  que->rear=(que->rear+1)%que->capacity;
  que->data[que->rear]=data;
}
else
printf("Queue is full");
}

int dequeue(Queue* que)
{
  if(isempty(que)==0)
  {
    que->size--;
    int data=que->data[que->front];
    que->front++;
    return data;
  }
  else
   printf("queue is empty");
}

int front(Queue* que)
{
  return que->data[que->front];
}

int rear(Queue* que)
{
  return que->data[que->rear];
}

void printqueue(Queue* que)
{
  int i=que->front;
  int count=0;
  while(count<que->size)
  {
    printf("%d",que->data[i]);
    i=(i+1)%que->capacity;
    count++;
  }
  /*This will not work for one element queue
  while(i!=que->rear)
  {
    printf("%d",que->data[i]);
    i=(i+1)%que->capacity;
  }*/
}

int main()
{
  Queue* q1=createqueue(4);
  enqueue(q1,1);
  printqueue(q1);
  enqueue(q1,2);
  enqueue(q1,3);
  enqueue(q1,4);
  printqueue(q1);
  dequeue(q1);
  enqueue(q1,5);
  printqueue(q1);
}
//Queues using linked lists: geeks for geeks

