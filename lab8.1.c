#include<stdio.h>
#include<time.h> 
#include<stdlib.h>
void swapping(int *x, int *y)
{
int temp = *x;
*x = *y;
*y = temp;
}
void heapify(int a[], int n, int i)
{
int max = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && a[left] > a[max])
max = left;
if (right < n && a[right] > a[max])
max = right;
if (max != i)
{
swapping(&a[i], &a[max]);
heapify(a, n, max);
}
}
void heapSort(int a[], int n)
{
for (int i = n / 2 - 1; i >= 0; i--)
heapify(a, n, i);
for (int i = n - 1; i >= 0; i--)
{
swapping(&a[0], &a[i]);
heapify(a, i, 0);
}
}
void display(int a[], int n)
{
for(int i = 0; i < n; i++)
{
printf("%d\t", a[i]);
}
}
int main()
{
printf("Enter the number of random numbers to be generated\n");
int limit;
scanf("%d",&limit);
int a[limit];
clock_t start=clock();
for(int i=0;i<limit;i++)
{
a[i]= (rand() %(100 - 0 + 1)) + 0;//generating random integers between 0 and 100
}
printf("\nOriginal array:\n");
display(a,limit);
heapSort(a,limit);
printf("\nSorted array:\n");
display(a,limit);
clock_t end=clock();
clock_t timereq;
timereq =(double)(end-start);
printf("\nProcessor time taken :%f\n",(double)timereq);
return 0;
}
