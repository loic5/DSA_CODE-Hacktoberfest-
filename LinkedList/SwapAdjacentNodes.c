/* Create a singly linked list. Swap every two adjacent nodes and return the reordered list.
  Expamples:
  Input: 1->2->3->4
  Output: 2->1->4->3
  Input:  1
  Output: 1
*/  

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void create(struct node **start, int n)
{
    struct node *temp = *start;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data=n;
    new->next=NULL;
    if(*start == NULL)
        *start=new;
    else
    {
        temp=(*start);
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new;
    }
}

void swap_adjacent(struct node **start)
{
    if ((*start) == NULL || (*start)->next==NULL)
        return;
    struct node *prev = NULL;
    struct node *curr = (*start);
    struct node *temp = (*start)->next;
    while(curr != NULL && curr->next != NULL) 
    {
        
        curr->next = temp->next;
        temp->next = curr;
 
        if (prev == NULL) 
        {
            *start = temp;
        }
        else 
        {
            prev->next = temp;
        }
 
        prev = curr;
        curr = curr->next;
        if(curr != NULL)
            temp = curr->next;
    }
 
    
}

void display(struct node **start)
{
    struct node *temp=*start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int choice=1,n;
    struct node *start=NULL;
    while(choice!=0)
    {
        printf("Enter:\n");
        printf("1 To create a node\n");
        printf("2 To rearrange the node\n");
        printf("3 To display\n");
        printf("0 To EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data ");
            scanf("%d",&n);
            create(&start,n);
            break;
            case 2:
            printf("Swapping... \n");
            swap_adjacent(&start);
            break;
            case 3:
            printf("Display the Current list :\n");
            display(&start);
            break;
            case 0:
            printf("EXITING\n");
            break;
            default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
