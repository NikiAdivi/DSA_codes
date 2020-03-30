int partition(int x[], int l, int r){
	int pivot = x[l];
	int i = l + 1, j = r;
	while(i <= j){
		while(i <= j && x[i] <= pivot)
			i++;
		while(i <= j && x[j] > pivot)
			j--;
		if(i <= j){
			int temp = x[i];
			x[i] = x[j];
			x[j] = temp;
		}	
	}
	int temp = x[l];
	x[l] = x[j];
	x[j] = temp;
	return j;	
}	
void quicksort(int x[], int l, int r){
	if(l < r){
		int p = l + rand() % (r - l + 1);
		int temp = x[l];
		x[l] = x[p];
		x[p] = temp;
		int k = partition(x, l, r);
		quicksort(x, l, k - 1);
		quicksort(x, k + 1, r);
	} 
}

void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	long long int i, j,n,c; float x[1000000], y[1000000];

	n=100000;c=0;
	x[0]=23;
	y[0]=31;
	for (i=1;i<n;++i){
	x[i]=x[i-1]+i+rand()%2534;
	y[i]=y[i-1]+i+rand()%3232;

}
printf("%d\n",c);

	int b[1000000],i;
	int count;
	for(i=0;i<n;i++)
	{
		b[x[i]]=y[i];
	}
	quicksort(x,0,n-1);
	for(i=1;i<n;i++)
	{
		if(b[x[i]]>b[x[i-1]])
		{
			count++;
			swap(&x[i],&x[i-1]);
		}
	}
}

			

















			
		
		
		
		
