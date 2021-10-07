#include<stdio.h>//Including the header file for standard input and output operations.
#include<math.h>//Including the header file for mathematical operations.
#include<time.h>//Including the time.h header file
#include<stdlib.h>//Including the stdlib.h header file
#define MAX 10000//Setting the MAX value as 10000
void swap(int*p,int*q)//The swap function
{
int temp;
temp=*p;
*p=*q;
*q=temp;
}
int left(int i)//the left fnction
{
return 2*i+1;
}
int right(int i)//The right function
{
return 2*i+2;
}
void display(int a[],int n)//The display function
{
int i;
if(n==0)
{
printf("Queue Underflow!!\n");//Condition of queue underflow
return;
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
}
int parent(int i)//parent function
{
int p;
p=((int)i/2.0)-1.0;
return p;
}
void insert(int a[],int heapsize,int data,int lb)//insert function
{
int i,p;
int parent(int);
if(heapsize==MAX)//If heapsize is exactly equal to the MAX
{
printf("Queue Overflow\n");//Queue overflow function
return;
}
i=lb+heapsize;
a[i]=data;
while(i>lb && a[p=parent(i)]<a[i])
{
swap(&a[p],&a[i]);//Calling swap function
i=p;
}
}
int del_hi_priori(int a[],int heapsize,int lb)//Function to delete high priority number
{
int data,i,l,r,max_child,t;
int left(int);
int right(int);
if(heapsize==1)
{
printf("Queue Underflow!!\n");
return 0;
}
t=a[lb];
swap(&a[lb],&a[heapsize-1]);
i=lb;
heapsize--;
while(1)
{
if((l=left(i))>=heapsize)
break;
if((r=right(i))>=heapsize)
max_child=l;
else
max_child=(a[l]>a[r])?l:r;
if(a[i]>=a[max_child])
break;
swap(&a[i],&a[max_child]);
i=max_child;
}
return t;
}
int main()
{
int lb,choice,num,n,a[MAX],data,s;
choice = 0;
n=0;
lb=0;
clock_t start=clock();//starting the clock timer
while(choice != 4)
{//Creating the menu driven format
printf("Enter your choice\n");
printf("\n1.Insert.\n");
printf("2.Delete.\n");
printf("3.Display.\n");
printf("4.Quit.\n");
printf("\nEnter your choice : ");
scanf("%d",&choice);//Accepting choice from the user
switch(choice)
{
case 1:
printf("Enter data to be inserted : ");
data= (rand() %(100 - 0 + 1)) + 0;//Generating and assigning a random number
insert(a,n,data,lb);//calling the insert function
printf("The data inserted is : %d",data);
n++;
break;
case 2:
s=del_hi_priori(a,n+1,lb);//calling delete high priority function
if(s!=0)
printf("The deleted value is : %d",s);
if(n>0)
n--;
break;
case 3:
printf("\n");
display(a,n);//calling the display function
break;
case 4:
return 0;
default:
printf("Invalid choice\n");//condition of encountering an invalid choice
}
printf("\n\n");
}
clock_t end=clock();//ending the clock timer
clock_t timereq;
timereq =(double)(end-start);//Calculating the total amount of time required
printf("\nProcessor time taken :%f\n",(double)timereq);//Calculating the total processor time required 
return 0;
}
