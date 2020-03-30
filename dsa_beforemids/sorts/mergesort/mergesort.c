#include<stdio.h>



void print_arr(int a[],int n)
{
printf("\n____________________________________________________________________\n");
for(int i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
printf("\n____________________________________________________________________\n");
}

void Merge(int a[],int i,int j,int m)
{

int b[100];
int l=i;
int r=m+1;
printf("\nInside merge function\nl=\t%d\nr=\t%d\ni=%d\nj=%d\n",l,r,i,j);
int p=0;
while(l<=m&&r<=j)
{
if(a[l]<a[r])
b[p++]=a[l++];
else
b[p++]=a[r++];
}
while(l<=m)
b[p++]=a[l++];
while(r<=j)
b[p++]=a[r++];
p=0;
for(int k=i;k<=j;k++)
{
a[k]=b[p];//The starting index is not 0 in most cases...it starts from whichever index is passed to the Msort as i in the recursive call
p++;
}
}


void Msort(int a[],int i, int j)
{
int m;
if(i>=j)
{return;}
else
{
m=(i+j)/2;
printf("\nin Msort\n %d\t%d\t%d\n",i,m,j);
Msort(a,i,m);
printf("\n After MSORT 1\n");
Msort(a,m+1,j);
printf("After Msort 2\n");
Merge(a,i,j,m);
printf("\n__________________________________________________________\n%d\n%d\n%d\n___________________________________________________\n",i,m,j);
}
}



int main()
{
int a[100];
int n;
printf("Enter Number of elements\n");
scanf("%d",&n);
printf("enter the elements");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
print_arr(a,n);
Msort(a,0,n-1);
print_arr(a,n);
return 0;
}
