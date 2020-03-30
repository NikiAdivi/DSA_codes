#include"sort.h"
#include<stdlib.h>
#include<stdio.h>
void merge(int* a,int* l,int* r,int sl,int sr)
{
	int i=0,j=0,k=0;
	while(i<sl && j<sr)
	{
		if(l[i]<r[j])
		{
			a[k]=l[i];
			i++;k++;
		}
		else
		{
			a[k]=r[j];
			j++;k++;
		}
	}
	while(i<sl)
	{a[k]=l[i];
	k++;i++;}
	while(j<sr)
	{
	a[k]=r[j];
	k++;j++;
	}
}

void mergesort(int* a,int n)
{
	if(n<2)
		return;//This step is the end condition of recursion.Return is just to aid recursion.
	int mid=n/2,i;
	int* l=(int*)malloc(mid*sizeof(int));
	int* r=(int*)malloc((n-mid)*sizeof(int));
	for(i=0;i<mid;i++)
	{
	l[i]=a[i];
	}
	for(i=0;i<n-mid;i++)
	{
	r[i]=a[mid+i];
	}
	mergesort(l,mid);
	mergesort(r,n-mid);
	merge(a,l,r,mid,n-mid);
}
/*
void partition(int* a,int i,int j)
{
	int pivot=i+(rand()%(j-i));
	while(l<=r)
	{
		while(l<=r && a[l]<=a[pivot])
		{l++;}
		while(l<=r && a[l]>a[pivot])	

*/
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selection(int a[],int n)
{
	int min,i,j;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{	min=j;}
			//	printf("%d",a[j]);}
		}
		swap(&a[i],&a[min]);
	}
}




//void quicksort(int* a,int i,int j)
//{
	




