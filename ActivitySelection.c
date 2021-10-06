//Activity Selection using Greedy Approach

#include <stdio.h>
#include<time.h> 
void ActivitySelection(int start[], int finish[], int n) 
{
  printf("The following activities are selected:\n");
  int j = 0;
  printf("%d ", j);
  int i;
  for (i = 1; i < n; i++)
  {
    if (start[i] >= finish[j])
    {
      printf("%d ", i);
      j = i;
    }
  }
  printf("\n");
}
void sort(int finish[],int n)
{
int min;
	for(int i=0;i<n;i++)
	{
		min = i;
		for(int j=i+1;j<n;j++)
		{
			if(finish[j]<finish[min])
				min=j;
		}
		int temp= finish[min];
		finish[min]=finish[i];
		finish[i]=temp;
	}
}

int main() 
{
int n;
double total_time;
printf("Enter the number of objects: ");
scanf("%d", &n);
int start[n],finish[n];
clock_t begin = clock();
for(int i=0;i<n;i++)
{
	start[i]= rand()%(100 +1 - 1) + 1;
	finish[i]= rand()%(100 +1 - 2) + 2;
}
printf("The start and finish array are: \n");
printf("Start Array :\t");
for(int i=0;i<n;i++)
{
	printf("%d, ",start[i]);
}
printf("\nFinish Array :\t");
sort(finish,n);
for(int i=0;i<n;i++)
{
	printf("%d, ",finish[i]);
}
printf("\n");
ActivitySelection(start, finish, n);
clock_t end = clock(); 
total_time = (double)(end-begin)/CLOCKS_PER_SEC;
printf("Total time taken : %f \n",total_time);
  return 0;
}
