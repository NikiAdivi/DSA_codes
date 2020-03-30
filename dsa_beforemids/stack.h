typedef struct stack
{
	int capacity;
	int top;
	int* data;
}stack;

stack* createstack(int size);
void printstack(stack* st);
int isFull(stack* st);
void push(stack* st,int d);
int pop(stack* st);
