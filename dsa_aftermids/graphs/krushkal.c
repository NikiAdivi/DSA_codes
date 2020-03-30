#include<stdio.h>
#include<stdlib.h>
typedef struct edge
{
	int v1,v2,weight;
}edge;
typedef struct cell
{
        int data;
        struct cell *next_cell,*tail;
}cell;
void swap(edge** a,edge** b)
{
        edge* c = *a;
        *a = *b;
        *b = c;
}
int generate_random(int initial,int last)
{
        return initial + (rand() % (last - initial + 1));
}
int partition(edge** ar,int start,int end)
{
        int pivot = (*(ar+end))->weight;
        int j = start;
        for(int i = start;i < end;i++)
        {
                if((*(ar+i))->weight < pivot)
                {
                        swap(ar+i,ar+j);
                        j++;
                }
        }
	        swap(ar+j,ar+end);
        return j;
}
void quick_sort(edge** ar,int start,int end)
{
        if(start < end)
        {
                int pivot = generate_random(start,end);
                swap(ar+pivot,ar+end);
                int part = partition(ar,start,end);
                quick_sort(ar,start,part-1);
                quick_sort(ar,part+1,end);
        }
}
edge** kruskhal(edge** sort_list,int vertices,int edges)
{
	int *colour_list,*number_list;
	colour_list = (int*)malloc(sizeof(int)*vertices);
	number_list = (int*)malloc(sizeof(int)*vertices);
	cell** colour_set = (cell**)malloc(sizeof(cell*)*vertices);
	edge** result = (edge**)malloc(sizeof(edge*)*vertices);
	for(int i = 0 ; i < vertices ; i++)
	{
		cell* sample = (cell*)malloc(sizeof(cell));
		sample -> data = i;
		sample -> next_cell = NULL;
		sample -> tail = sample;
		colour_list[i] = i;
		number_list[i] = 1;
		colour_set[i] = sample;
	}
	for(int i = 0 ; i < edges ; i++)
	{
		if(colour_list[sort_list[i] -> v1] != colour_list[sort_list[i] -> v2])
		{
			result[i] = sort_list[i];
			if(number_list[sort_list[i] -> v1] < number_list[sort_list[i] -> v2])
			{
				int dominant_colour = colour_list[sort_list[i] -> v2];
				int dominant_number = number_list[sort_list[i] -> v1] + number_list[sort_list[i] -> v2];
				cell* point = colour_set[colour_list[sort_list[i] -> v1]];
				colour_set[colour_list[sort_list[i] -> v2]] -> tail -> next_cell = point;
				colour_set[colour_list[sort_list[i] -> v2]] -> tail = point -> tail;
				colour_set[colour_list[sort_list[i] -> v1]] = NULL;
				while(point != NULL)
				{
					colour_list[point -> data] = dominant_colour;
				       	number_list[point -> data] = dominant_number;
				}
			}
			else
			{	
				int dominant_colour = colour_list[sort_list[i] -> v1];
                                int dominant_number = number_list[sort_list[i] -> v2] + number_list[sort_list[i] -> v1];
                                cell* point = colour_set[colour_list[sort_list[i] -> v2]];
				//printf("%d\n",point->data);
                                colour_set[colour_list[sort_list[i] -> v1]] -> tail -> next_cell = point;
                                colour_set[colour_list[sort_list[i] -> v1]] -> tail = point -> tail;
                                colour_set[colour_list[sort_list[i] -> v2]] = NULL;
                                while(point != NULL)
                                {       
                                        colour_list[point -> data] = dominant_colour;
                                        number_list[point -> data] = dominant_number;
					point = point -> next_cell;
                                }
			}
		}
	}
	return result;
}
int main()
{
	int n,edges;
	scanf("%d%d",&n,&edges);	
	int** adjmat = (int**)malloc(sizeof(int*)*n);
	for(int i = 0 ; i < n ; i++)
		adjmat[i] = (int*)malloc(sizeof(int)*n);
	edge** list = (edge**)malloc(edges*sizeof(edge*));
	for(int i = 0 ; i < edges ; i++)
	{
		int a,b,w;
		edge* c;
		c = (edge*)malloc(sizeof(edge));
		scanf("%d%d%d",&a,&b,&w);
		adjmat[a][b] = w;
		c -> v1 = a;
		c -> v2 = b;
		c -> weight = w;
		list[i] = c;
	}
	quick_sort(list,0,edges-1);
	edge** result = kruskhal(list,n,edges);
	for(int i = 0 ; i < n - 1 ; i++)
		printf("(%d,%d)\n",result[i] -> v1,result[i] -> v2);
	return 0;
}
