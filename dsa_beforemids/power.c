#include"power.h"
int fib(int n)
{
	int f[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	power(f,n-1);
	return f[0][0];
}

void power(int f[2][2],int n)
{
	int tf[2][2]={{1,1},{1,0}};
	if(n==1)
	{
		return;
	}
	if(n==0)
		return;
	if(n%2==0)
	{
		power(f,n/2);
		multiply(f,f);
		return;
	}
	power(f,n-1);
	multiply(f,tf);
	return;
}

void multiply(int f[2][2],int m[2][2])
{
	int i,j,x,y,z,w;
	x=f[0][0]*m[0][0]+f[0][1]*m[1][0];
	y=f[0][0]*m[0][1]+f[0][1]*m[1][1];
	z=f[1][0]*m[0][0]+f[1][1]*m[1][0];
	w=f[1][0]*m[0][1]+f[1][1]*m[1][1];
	f[0][0]=x;
	f[0][1]=y;
	f[1][0]=z;
	f[1][1]=w;
	return;
}
			
