#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void construct(int arr[], int n, int *st)
{
    int i;
    for(i=0; i<2*n; i++)
    {
        st[i]=INT_MAX;
    }
    for(i=0; i<n; i++)
    {
        st[i+n-1]=i;
    }
    for(i=n-2; i>-1; i--)
    {
        if(arr[st[2*i+1]]<arr[st[2*i+2]])
            st[i]=st[2*i+1];
        else
        {
            st[i]=st[2*i+2];
        }
        
    }
}

void update(int arr[], int n, int *st, int index, int x)
{
    arr[index]=x;
    int j = index + n -1;
    int l;
    while(j>0)
    {
        int k = (j-1)/2;
        if(arr[st[2*k+1]]<arr[st[2*k+2]])
            l = 2*k+1;
        else
        {
            l = 2*k+2;
        }
        st[k]=st[l];
        j=k;
    }
}

int rmq(int arr[],int *st, int l, int r, int i, int j, int k)
{
    if(i<=l && j>=r)
        return st[k];
    else if(r<i || j<l)
        return -1;
    else
    {
        int mid = (l+r)/2;
        int p1 = rmq(arr, st, l, mid, i, j, 2*k+1);
        int p2 = rmq(arr, st, mid+1, r, i, j, 2*k+2);
        if(p1==-1)
            return p2;
        else if(p2==-1)
            return p1; 
        
        else if(arr[p1]<arr[p2])
            return p1;
        else
        {
            return p2;
        }
        
    }
    
}

int main()
{
    int arr[] = {12, 4, 9, 7, 18, 21, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = (int *)malloc(2*n*sizeof(int));
    construct(arr, n, st);
    printf("\n%d\n", rmq(arr, st, 0, 7, 2, 5, 0));
    return 0;


}
