#include <stdio.h>

int min(int a,int b)
{
if(a>b)
	return b;
else
	return a;
}

int assemblyLineScheduling(int n, int entry[], int exit[],int processing[][n],int transfer[][n-1])
{
    int dp[2][n+1];
    int i;

    dp[0][0]=entry[0]+processing[0][0];
    dp[1][0]=entry[1]+processing[1][0];

    for(i=1;i<n;i++)
    {
        dp[0][i]=min(dp[0][i-1],dp[1][i-1]+transfer[1][i-1])+processing[0][i]; 
        dp[1][i]=min(dp[1][i-1],dp[0][i-1]+transfer[0][i-1])+processing[1][i]; 
    }

if(dp[0][n-1]+exit[0] < dp[1][n-1]+exit[1])
 printf("path1 %d ",n-1);
else
 printf("path2 %d ",n-1);

for(i=n-2;i>=0;i--){
	if(dp[0][i] < dp[1][i])
	 printf("path1  %d ",i);
	else
	 printf("path2  %d ",i);

}

    dp[0][n]=dp[0][n-1]+exit[0];
    dp[1][n]=dp[1][n-1]+exit[1];

    return min(dp[0][n],dp[1][n]);

}

int main()
{
    int i,n;
    int entry[2], exit[2];

    printf("Enter the number of assembly :\n");
    scanf("%d",&n);

    int processing[2][n];
    int transfer[2][n-1];

    printf("Enter the entry time for assebly line 1 and 2 respectively :\n");
    scanf("%d %d",&entry[0],&entry[1]);

    printf("Enter the exit time for assebly line 1 and 2 respectively :\n");
    scanf("%d %d",&exit[0],&exit[1]);

    printf("Entry the processing time at all staions on assembly line 1 :\n");
    for(i=0;i<n;i++)
        scanf("%d",&processing[0][i]);

    printf("Entry the processing time at all staions on assembly line 2 :\n");
    for(i=0;i<n;i++)
        scanf("%d",&processing[1][i]);

    printf("Enter the transfer time from each station of assembly line 1 to next station of assembly line 2 :\n");
    for(i=0;i<n-1;i++)
        scanf("%d",&transfer[0][i]);

    printf("Enter the transfer time from each station of assembly line 2 to next station of assembly line 1 :\n");
    for(i=0;i<n-1;i++)
        scanf("%d",&transfer[1][i]);

	int t=assemblyLineScheduling(n, entry, exit, processing, transfer);
    printf("\nThe minimum time required to get all the jobs done is : ");
    printf("%d \n",t);

    return 0;

}
