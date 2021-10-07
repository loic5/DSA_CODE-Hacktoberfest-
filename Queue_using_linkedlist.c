#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void enqueue();  
void dequeue();  
void display();  
void main ()  
{  
    int choice;   
    while(choice != 4)   
    {
	    printf("\nQUEUE OPERATIONS USING ARRAY");
	    printf("\n================================");
	    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
	    printf("\n--------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);      
        switch(choice)  
        {  
            case 1:  
	            enqueue();  
	            break;  
            case 2:  
	            dequeue();  
	            break;  
            case 3:  
	            display();  
	            break;  
            case 4:  
	            exit(0);  
	            break;  
            default:   
           		printf("\nEnter valid choice!!\n");  
        }  
    }  
}  
void enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nQueue OVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nInsert element in queue: ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void dequeue()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nQueue UNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        printf("\n[%d was Dequeued]\n", front -> data);
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nQUEUE:\n");  
        while(ptr != NULL)   
        {  
            printf("%d ",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
    printf("\n");
}  
