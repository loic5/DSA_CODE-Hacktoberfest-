//Insertion Sort using Binary Search

#include<stdio.h>
#include<time.h>
int binary_search(int arr[],int startl,int endl,int search)
{
	int mid;
	while(startl<=endl)
	{
		mid=startl+(endl-startl)/2;
		if(arr[mid]==search)
		{
			return mid;
		}
		else if(arr[mid]>search)
			endl=mid-1;
		else 
			startl=mid+1;
	}
	return startl;
}


void insertion_sort(int arr[], int n)
{
	int j,key,b;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		key=arr[i];
		b= binary_search(arr,0,j,key);
		while(j>=b)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
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
	insertion_sort(arr,n);
	print_array(arr,n);
	clock_t end = clock();
	total_time = (double)(end-begin) / CLOCKS_PER_SEC;
	
	printf("Total time taken: %f \n",total_time);
	
	
	return 0;
}
