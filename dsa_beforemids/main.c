#include<stdio.h>
#include"stack.c"
int main()
{
	int d;


	stack* st;
	   st=createstack(100);
	 printstack(st);


	push(st,10);


	printstack(st);
	
	push(st,20);

	printstack(st);
	
	d=pop(st);
	printstack(st);
	

return 0;
}
