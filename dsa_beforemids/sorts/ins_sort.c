#include<stdio.h>
int main()
{
	int i;
	int a[10]={4,3,2,6,7,8,1,9,3,5};
	insertionsort(a,10);
	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
	}
}

void insertionsort(int a[],int n)
{
	int key,i,j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
