#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,max=0,num;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of array\n");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	printf("Enter the number\n");
	scanf("%d",&num);
	int j=0,index,flag=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==num)
		{ 
                        flag=1;
                        index=i;
			j=j+1;
			max=i;
		}
	}
        if(flag==1)
        {
        printf("Last occuring Index of the element is %d\n",index);
	}
        printf("Times found= %d at position in reverse of the given array = %d\n", j,n-max);
}
