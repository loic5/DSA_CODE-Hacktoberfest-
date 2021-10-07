//program of bubble sort with huge number of inputs
#include <math.h>
#include <stdio.h>
#include <time.h> 
#include<stdlib.h>
void bubbleSort(int arr[], int n)
{
int swap;
for(int i = 0 ; i < n - 1; i++)
{
for(int j = 0 ; j < n - i - 1; j++)
{
if (arr[j] > arr[j+1])
{
swap = arr[j];
arr[j] = arr[j+1];
arr[j+1] = swap;
}
}
}
}
int main()
{
printf("Enter the number of random numbers to be generated\n");
int n;
scanf("%d",&n);
int arr[n];
clock_t start=clock();
for(int i=n-1;i>0;i--)
{
arr[i]=(float)rand()/(float)(RAND_MAX/3);
}
printf("\nBefore\n");
for(int i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
bubbleSort(arr,n);
printf("\nAfter Sorting\n");
for(int i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
clock_t end=clock();
clock_t timereq;
timereq =(double)(end-start);
printf("\nProcessor time taken :%f\n",(double)timereq);
return 0;
}
