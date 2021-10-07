#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
void knapsack(int n, float weight[], float profit[], float capacity)
{
float x, tp = 0;
int i, u;
u = capacity;
for(i = 0; i < n; i++)
{
if(weight[i] > u)
{
break;
}
else
{
tp = tp + profit[i];
u = u - weight[i];
}
}
x = u / weight[i];
tp = tp + (x * profit[i]);
printf("\nMaximum profit is:- %.3f \n", tp);
}
int main()
{
float weight[20000], profit[20000], capacity;
int num, i, j;
float ratio[20000], temp;
clock_t start=clock();
printf("Enter the number of objects: \n");
scanf("%d", &num);
for(i = 0; i < num; i++)
{
profit[i]=(rand() %(100 - 0 + 1)) + 0;
printf("The profit of knapsack is : %f\n",profit[i]);
weight[i]=(rand() %(100 - 0 + 1)) + 0;
printf("The weight of knapsack is : %f\n\n",weight[i]);
}
capacity=(rand() %(50 - 1 + 1)) + 1;
printf("The capacity of knapsack is : %f\n",capacity);
for(i = 0; i < num; i++)
{
ratio[i] = profit[i] / weight[i];
}
for(i = 0; i < num; i++)
{
for(j = i + 1; j < num; j++)
{
if(ratio[i] < ratio[j])
{
temp = ratio[j];
ratio[j] = ratio[i];
ratio[i] = temp;

temp = weight[j];
weight[j] = weight[i];
weight[i] = temp;
 
temp = profit[j];
profit[j] = profit[i];
profit[i] = temp;
}
}
}
knapsack(num, weight, profit, capacity);
clock_t end=clock();
clock_t timereq;
timereq =(double)(end-start);
printf("\nProcessor time taken :%f\n",(double)timereq);
return(0);
}
