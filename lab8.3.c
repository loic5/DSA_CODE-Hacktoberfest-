#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 20000

int Q[N],Pr[N];
int r = -1,f = -1;
void insert(int data,int p)
{
  int i;
  if((f==0)&&(r==N-1))
    printf("Queue is full");
  else
  {
    if(f==-1)
    {
      f = r = 0;
      Q[r] = data;
      Pr[r] = p;
    }
    else if(r == N-1)
    {
      for(i=f;i<=r;i++)
      {
        Q[i-f] = Q[i];
        Pr[i-f] = Pr[i];
        r = r-f;
        f = 0;
        for(i = r;i>f;i--)
        {
          if(p>Pr[i])
          {
            Q[i+1] = Q[i];
            Pr[i+1] = Pr[i];
          }
          else
            break;
          Q[i+1] = data;
          Pr[i+1] = p;
          r++;
        }
      }
    }
    else
    {
      for(i = r;i>=f;i--)
      {
        if(p>Pr[i])
        {
          Q[i+1] = Q[i];
          Pr[i+1] = Pr[i];	
        }
        else
        break;
      }
      Q[i+1] = data;
      Pr[i+1] = p;
      r++;
     }	
   }
}
void display()
{
int i;
for(i=f;i<=r;i++)
{
printf("\nElement = %d\tPriority = %d\n",Q[i],Pr[i]);
}
}
int delete()
{
  if(f == -1)
  {
    printf("Queue is Empty");
  }	
  else
  {
    printf("Deleted Element = %d\t Its Priority = %d",Q[f],Pr[f]);
    if(f==r)
      f = r = -1;
    else
      f++;
  }
}
int main()
{
  clock_t start=clock();
  int choice,n,i,data,p;
  printf("Enter Your Choice:-");
  do
  {
    printf("\n1 for Insert the Data in Queue"
           "\n2 for show the Data in Queue"
           "\n3 for Delete the data from the Queue"
           "\n0 for Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("\nEnter the number of data");
        scanf("%d",&n);
        i=0;
        while(i<n)
        {
          data=(rand() %(100 - 0 + 1)) + 0;
          p=(rand() %(5 - 0 + 1)) + 0;
          printf("\nData is :%d and Priority of data:%d",data,p);
          insert(data,p);
          i++;
        }
        break;
      case 2:
        display();
        break;
      case 3:
        delete();
        break;
      case 0:
        printf("EXITING\n");
        break;
      default:
        printf("\nIncorrect Choice");
    }
  }while(choice!=0);
  
  clock_t end=clock();
  clock_t timereq;
  timereq =(double)(end-start);
  printf("\nProcessor time taken :%f\n",(double)timereq);
  return 0;
}
