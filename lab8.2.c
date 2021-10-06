#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10000
void swap(int*p,int*q)
{
  int temp;
  temp=*p;
  *p=*q;
  *q=temp;
}
int left(int i)
{
  return 2*i+1;
}
int right(int i)
{
  return 2*i+2;
}
void display(int a[],int n)
{
  int i;
  if(n==0)
  {
    printf("Queue Underflow!!\n");
    return;
  }
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
   printf("\n");
}

int parent(int i)
{
  int p;
  p=((int)i/2.0)-1.0;
  return p;
}

void insert(int a[],int heapsize,int data,int lb)
{
  int i,p;
  int parent(int);
  if(heapsize==MAX)
  {
    printf("Queue Overflow\n");
    return;
  }
  i=lb+heapsize;
  a[i]=data;
  while(i>lb && a[p=parent(i)]<a[i])
  {
    swap(&a[p],&a[i]);
    i=p;
  }
}
int del_hi_priori(int a[],int heapsize,int lb)
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
  clock_t start=clock();
  while(choice != 4)
  {
    printf("Enter your choice\n");
    printf("\n1.Insert.\n");
    printf("2.Delete.\n");
    printf("3.Display.\n");
    printf("4.Quit.\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter data to be inserted : ");
        data= (rand() %(100 - 0 + 1)) + 0;
        insert(a,n,data,lb);
        printf("The data inserted is : %d",data);
        n++;
        break;
      case 2:
        s=del_hi_priori(a,n+1,lb);
        if(s!=0)
          printf("The deleted value is : %d",s);
        if(n>0)
          n--;
          break;
        case 3:
          printf("\n");
          display(a,n);
          break;
        case 4:
          return 0;
        default:
          printf("Invalid choice\n");
    }
    printf("\n\n");
  }
  clock_t end=clock();
  clock_t timereq;
  timereq =(double)(end-start);
  printf("\nProcessor time taken :%f\n",(double)timereq);
  return 0;
}
