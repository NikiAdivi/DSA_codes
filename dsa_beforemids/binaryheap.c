#include<stdio.h>
 //heap size. It must be passed as a pointer because it can get updated in any function but the changes should reflect in the variable even after the fn terminates.

void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


void topdownheapify(int a[],int i,int n)
{
	int l;
	while((2*i+1)<n)   //if there is only left child this loop doesnt hold good.
	{
		if(2*i+1!=n-1)
		{
		if(a[2*i+2]>a[2*i+1])           //if there is only left child we cant access right child hence we are taking the condition 2i+1!=n-1
			l=2*i+1;
		else
			l=2*i+2;
		}
		else
			l=2*i+1;
		if(a[i]>a[l])
		{
			swap(&a[i],&a[l]);
			i=l;
		}
		else
			break;
	}
}

void bottomupheapify(int a[],int i,int n)
{
	int p=(i-1)/2;
	while(p>=0)
	{
		if(a[p]>a[i])
		{	swap(&a[p],&a[i]);
			i=p;
			p=(i-1)/2;
		}
		else
			break;
	}
}


void buildheap(int a[],int n)
{
	int i;
	for(i=n/2-1;i!=-1;i--)
	{
		topdownheapify(a,i,n);
	}
}



void add(int a[],int* n,int key)
{
	a[*n]=key;
	*n=*n+1;
	//printf("%d...",*n);
	//printf("%d...",key);
	bottomupheapify(a,*n-1,*n);    //n at any point will be the size of the filled heap...initially array of large size must be declared.
}

void delete_min(int a[],int* n)  //min is always at the top of the binary heap.
{
	swap(&a[0],&a[*n-1]);
	*n=*n-1;
	topdownheapify(a,0,*n);
}




void update_key(int a[],int n,int i,int new_key)
{
	if(new_key<a[i])
	{
		a[i]=new_key;
		bottomupheapify(a,i,n);
	}
	else
	{
		a[i]=new_key;
		topdownheapify(a,i,n);
	}
}

void heapsort(int a[],int n)             //Given an array first we must build the heap and then keep deleting min to sort it
{
	buildheap(a,n);
	int i=n;
	while(i>0)
	{
		swap(&a[0],&a[i-1]);
		topdownheapify(a,0,i-1);
		i--;
	}
}



int main()
{
	int a[1000];
	int n=8;
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=n-i;
	}
	buildheap(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf(".........");
	delete_min(a,&n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf(".........");
	heapsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf(".........");
	buildheap(a,n);
	add(a,&n,1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("..............");
	update_key(a,n,3,10);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf(".........");
	return 0;
}
	
	
	
	
//Problem value of n is not decreasing or increasing even if its a global variable !!!!!


