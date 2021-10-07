#include <stdio.h>
#define MAX 100
void insert();
void delete();
void display();
int queue_array[MAX];
int n;
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    printf("Enter the size of Stack [max=100]: ");
   	scanf("%d", &n);
    while (1)
    {
	    printf("\nQUEUE OPERATIONS USING ARRAY");
	    printf("\n================================");
	    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
	    printf("\n--------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Wrong choice \n");
        } 
    } 
} 
 
void insert()
{
    int add_item;
    if (rear == n - 1)
    printf("\nQueue OVERFLOW \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("\nInsert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("\nQueue UNDERFLOW \n");
        return ;
    }
    else
    {
        printf("\nElement deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} 
 
void display()
{
    int i;
    if (front == - 1)
        printf("\nQueue is empty. \n");
    else
    {
        printf("\nQUEUE: \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 