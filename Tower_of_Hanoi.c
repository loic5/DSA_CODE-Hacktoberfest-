#include <stdio.h>
#include<time.h>

void hanoi(char,char,char,int);
int main()
{
int num;

printf("Enter No. of Disks u want :: ");
scanf("%d",&num);

clock_t start_t,end_t;
double total_t;
printf("\nTower of Hanoi for %d number of disks are :: \n", num);
start_t=clock();
hanoi('A','B','C',num);
end_t=clock();
total_t=(double)(end_t -start_t)/CLOCKS_PER_SEC;
printf("Time Taken :%f sec",total_t);
return 0;
}

void hanoi(char from,char to,char other,int n)
{
if(n<=0)
printf("\nPlease Provide at least one disk !!!!\n ");
if(n==1)
printf("\nMove Disk from %c to %c\n",from,other);

if(n>1)
{
hanoi(from,other,to,n-1);
hanoi(from,to,other,1);
hanoi(to,from,other,n-1);
}
}
