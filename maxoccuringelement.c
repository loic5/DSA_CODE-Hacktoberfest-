#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);    
    int a[n];
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
    int i, j, max, count;
    int maxCount = 0;
    for(i = 0; i< n; i++)
    {
        count = 1;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] == a[i])
            {
                count++;
                if(count > maxCount)
                {
                    max = a[j];
                    maxCount=count;
                }
            }
        }
    }
    printf("\nMaximum Occuring Element is: %d\n",max);
    return 0;
}
