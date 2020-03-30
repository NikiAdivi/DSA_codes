#include<stdio.h>
#include<stdlib.h>
#include"sort.h"
int main()
{
	int i,sl=3,sr=4;
	/*scanf("%d%d",&sl,&sr);
	int* l=(int*)malloc(sl*sizeof(int));
	int* r=(int*)malloc(sr*sizeof(int));
	int* a=(int*)malloc((sl+sr)*sizeof(int));
	for(i=0;i<sl;i++)
	{
		scanf("%d",&l[i]);
	}
	for(i=0;i<sr;i++)
	{
		scanf("%d",&r[i]);
	}*/

	/*int l[3]={1,5,7};
	int r[4]={2,3,8,9};
	int a[7];
	merge(a,l,r,sl,sr);
	for(i=0;i<sl+sr;i++)
	{
		printf("%d",a[i]);
	}*/

	int a[8]={1,6,4,3,2,7,8,2};
	selection(a,8);
	for(i=0;i<8;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
	
