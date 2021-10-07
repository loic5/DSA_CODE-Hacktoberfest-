#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int ar[], int low, int high)
{
    int pivot = ar[high], i = low, j;
    for (j = low; j < high; j++)
    {
        if (ar[j] < pivot)
        {
            swap(&ar[i], &ar[j]);
            i++;
        }
    }
    swap(&ar[i], &ar[high]);
    return (i);
}

void quick_sort(int ar[], int i, int j)
{
    if (i < j)
    {
        int p = partition(ar, i, j);
        quick_sort(ar, i, p - 1);
        quick_sort(ar, p + 1, j);
    }
}

int main()
{
    int ar[20], n, i;
    printf("Enter number of element you want: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    quick_sort(ar, 0, n - 1);

    //printing sorted array
    printf("Printing sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", ar[i]);
    return 0;
}