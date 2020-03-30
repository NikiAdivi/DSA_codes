#include"stack.h"
#include<stdlib.h>
stack* createstack(int capacity)
{
	stack* temp=(stack*)malloc(sizeof(stack));
	temp->capacity=capacity;
	temp->top=-1;
	temp->data=(int*)malloc(temp->capacity*sizeof(int));
	return temp;

}

void push(stack* st,int d)
{
	st->top+=1;
	st->data[st->top]=d;


}

void printstack(stack *st)
{
	if(st->top>=0)
	{
		for(int i=0;i<=st->top;i++)
		{
			printf("%d",st->data[i]);
			printf("\n");
		}
	}
	else
	{
		printf("Dear Saad it is an ......empty stack");
		printf("\n\n");
	}
}

int isFull(stack* st)
{
	if(st->top==st->capacity-1)
	{
		printf("Full yooo");
	}
	else
	{
		printf("Empty hahaha");
	}
}

int pop(stack* st)
{
	int a= st->data[st->top];
	st->top=st->top-1;
	return a;

}
