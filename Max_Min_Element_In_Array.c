// Divide and conquer method to recursively implement and to find the maximum and minimum in a given list of n elements.

#include<stdio.h>
#include<time.h>
int min,max;
void max_min(int arr[], int low, int high)
{
	int mid,max1,min1;
	if(low == high)
	{
		max=min=arr[low];
	}
	else
	{
		if(low == (high-1))
		{
			if(arr[low]<arr[high])
			{
				max = arr[high];
				min = arr[low];
			}
			else
			{
				max = arr[low];
				min = arr[high];
			}
		}
		else
		{
			mid = (low+high)/2;
			max_min(arr,low, mid);
   			max1 = max; 
   			min1 = min;
   			max_min(arr,mid+1, high);
   			if(max <max1)
    				max = max1;
   			if(min > min1)
    				min = min1;
		}
	}
}

void print_array(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	long int n;
	printf("Enter the size of array:\n");
	scanf("%ld",&n);
	int arr[n];
	double total_time;
	for(int i=0;i<n;i++)
	{
		arr[i]=(rand()%1000);
	}
	clock_t begin = clock();
	    print_array(arr,n);
	    max_min(arr,0,n-1);
    	printf("The minimum array element is %d\n" , min);
    	printf("The maximum array element is %d\n" , max);
	clock_t end = clock();
	total_time = (double)(end-begin) / CLOCKS_PER_SEC;
	
	printf("Total time taken: %f \n",total_time);
	
	
	return 0;
}
