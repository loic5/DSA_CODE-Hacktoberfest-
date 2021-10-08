/* Reverse the given Linked list.
Examples:
Input : 1->2->3->4->5
Output: 5->4->3->2->1

Input : 1->3->5->7
Output: 7->5->3->1

Note: Reverse the node itself, not the data part.
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
        temp=*start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new;
    }
}

void reverse(struct node **start)
{
    struct node* prev = NULL;
    struct node* current = (*start);
    struct node* temp;
    while (current != NULL) 
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    *start = prev;
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
        printf("2 To reverse the node\n");
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
            printf("Reversing... \n");
            reverse(&start);
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
