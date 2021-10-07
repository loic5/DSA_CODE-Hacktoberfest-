#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{   
    struct node *prev;
	int data;
	struct node *next;
}node;

struct node *head=NULL;

//CREATE DOUBLE LINKED LIST
struct node *createll(struct node *head)
 {
 		 															 
	struct node *q, *p;      //q=newnode
	int n;
	printf("\nEnter -1 To Terminate \n");
	printf("Enter The Data : ");
	scanf("%d",&n);
	while(n != -1)
	{
		 q = (struct node*)malloc(sizeof(struct node));
	    q -> data = n;
		if(head == NULL)
		{    q->prev=NULL; 
			q -> next =NULL;
			head = q;
		}
		else
		{
			p = head;
			while(p -> next != NULL)
		    	p = p -> next;
			p -> next = q;
			q->prev=p;
			 q-> next = NULL;
		} 
		printf("\nEnter The Data : ");
		scanf("%d", &n);
 	}
	return head;
}
  
   //DISPLAY
  
   struct node *displaydll(struct node *head){
   		struct node *p;
	if(head==NULL)
	{
		printf("\nCurrent List :- \n");
		printf("\nList is empty.\n");
	}

	else
	{
		p=head;
		printf("\nCurrent List :- \n");
		while(p!=NULL)
		{
			printf("%d  ", p->data);
			p=p->next;
		}
		printf("\n");
	}
	return head;
   }



   //SEARCH A KEY VALUE
   
   struct node * searchkey(struct node *head)  {
   	struct node *p=head;
   	int key,i=0 ,temp=0;
   	printf("Enter the key value=");
   	scanf("%d",&key);
   	  
   	  while(p->next!=NULL) {
   	  	if(p->data==key)
   	  	 {
			    printf("node is found at position %d ",i+1);
   	  	  
   	        
   	        temp=0;
			   return head;
			   ;}
   	     else
   	        {
   	        	temp=1;
			   }
			   
			   i++;
   	       	        p = p->next;
		 }
		 
		 if(temp==1)
		 printf("not found!");
		 
		 return head;
   }


 //INSERT AT BEGINNING
   
   struct node * insertatbeg(struct node *head)
   {
   	    struct node *newnd; 
			int n;
			
   	 {
		  if(head==NULL)
	    {
		printf(" overflow");
          return head;
	    }
	  else	  
			
	        printf("\n Enter the data = "); 
		    scanf("%d", &n);
		    newnd = (struct node *)malloc(sizeof(struct node)); 
		              newnd->prev=NULL;
				 	  newnd ->data=n;
				 	  head->prev=newnd;
					  newnd ->next=head;
					  head=newnd;
					  
   	}
   	
   	return head;
	                    	
   }
   
   
    //INSERT AT END
   
    struct node * insertatend(struct node *head)
   {
        struct node *newnd,*p; 
			int n;
			
   	 {
		  if(head==NULL)
	   {
		 printf(" overflow");
          return head;
        }
         else
              newnd = (struct node *)malloc(sizeof(struct node)); 
              printf("\n Enter the data = "); 
		      scanf("%d", &n);
		      newnd->data=n;
		      newnd->next=NULL;
		      p=head;
		      while(p->next != NULL){
		      
			  	p=p->next;
		      	
			  }
			     p->next=newnd;
			     newnd->prev=p;
			     
			  
		}
		   return head;
		   
	}
	
	  //INSERT BEFORE A GIVEN VALUE
	
	struct node * insertbefore(struct node *head)
	{
		struct node *newnd,*p; 
			int n,val;
			
   	 {
		  if(head==NULL)
	     {
		   printf(" overflow");
          return head;
         }
        else
              newnd = (struct node *)malloc(sizeof(struct node));
			  printf("enter the value before which do you want to insert value=");
			  scanf("%d",&val); 
              printf("\n Enter the data = "); 
		      scanf("%d", &n);
		      newnd->data=n;
		      p=head;
			
			  while(p->data != val)
			  {
			  	
			  	p=p->next;
			  }
			  newnd->next=p;
			  newnd->prev=p->prev;
			  p->prev->next=newnd;
			  p->prev=newnd;
		
		}		      
		
		return head;
	}
	//INSERT AFTER A GIVEN VALUE 
	
	
		struct node * insertafter(struct node *head)
	{
		struct node *newnd,*p; 
			int n,val;
			
   	 {
		  if(head==NULL)
	 {
	 printf(" overflow");
          return head;}
          
        else
            newnd = (struct node *)malloc(sizeof(struct node));
			  printf("enter the value after which do you want to insert value=");
			  scanf("%d",&val); 
              printf("\n Enter the data = "); 
		      scanf("%d", &n);
		      newnd->data=n;
		      p=head;
			  
			  while(p->data != val)
			  {
			  	p=p->next;
			  }
			  
			   newnd->next=p->next;
			   p->next->prev=newnd;
			    p->next=newnd;
			   newnd->prev=p;
			   
			  
		}
		return head;
	}
	
		//DELETE AT BEGINNING
	
		struct node * deleteatbeg(struct node *head)
		{  
			struct node *p;
			if(head==NULL)
			printf("overflow=LL is empty");
			else 
			   p=head;
			   head=head->next;
			   head->prev=NULL;
			   free(p);
			   
			   
			   return head;
			   	
		}

 //DELETE AT END

		struct node * deleteatend(struct node *head)
		{
			struct node *p,*q;
			{
				if(head==NULL)
				printf("LL is empty");
				
				else
				p=head;
			
				while(p->next != NULL)
				{
	
				   p=p->next;	
				}
				p->prev->next=NULL;
				free(p);
				}
				
				return head;
		}   

//DELETE BEFORE A GIVEN VALUE
	
		struct node * deletebefore(struct node *head)
	{
		struct node *p,*q; 
			int val;
			
   	 {
		  if(head==NULL)
	     {
		  printf("overflow");
          return head;
         }
        else
         
		  printf(" Enter the value before which do you want  to delete node =" );
		  scanf("%d",&val);
		  p=head;
		  q=p;
		  while(p->data != val){
		  	q=p;
		  	p=p->next;
		  }
		  p->prev=q->prev;
		  q->prev->next=p;
		  
		  free(q);
     	}
	       return head;
   }
   
   //DELETE AFTER A GIVEN VALUE
	
   struct node * deleteafter(struct node *head)
	{
		int data;
	printf("enter node after which to delete\n");
	scanf("%d",&data);
	struct node *temp,*ptr=head;
	while(ptr->next!=NULL)
	{
		if(ptr->data==data)
			break;
		ptr=ptr->next;
	}
	temp=ptr->next;
	if(ptr->next->next==NULL)
	{
		ptr->next=NULL;
	}
	else
	{
        ptr->next->next->prev=ptr;
		ptr->next=ptr->next->next;
	}
	free(temp);

	  return head;
	  
   }
   
	
































int main()
{
	int select;
	
	
	do {
		printf("\n _____________________MAIN MENU______________________________________________");
		printf("\n_______________________________________________________________________________");
		printf("\n 1 = create doubly linked list");
		printf("\n 2 = display DLL");
		printf("\n 3 = search a key value");
		printf("\n 4 = insert at beginning of Dll");
		printf("\n 5 = insert at end of Dll");
		printf("\n 6 = inserting before any element.");
        printf("\n 7 = inserting after any element.");
        printf("\n 8 = deleting the first element.");
        printf("\n 9 = deleting the last element.");
        printf("\n 10 = deleting before element.");
        printf("\n 11 = deleting after element");
        
        
        printf("\n Enter the option= ");
        
        scanf("%d",&select);
        
        switch(select){
        	case 1: 
			        head = createll( head);
			        printf("\nDLL CREATED");
			        printf("\nFOR DISPLAY PRESS 2");
        	       break;
		    case 2: 
			         head = displaydll(head);
				   break;
				  
			case 3:
				   
			         head=searchkey(head);
			         head=displaydll(head);
				   break;
				
		    case 4:
			       head=insertatbeg(head);
				     head=displaydll(head);
				   break;
				   
		    case 5:
			        head=insertatend(head);
				   head=displaydll(head);
				   break;
				   
		    case 6:
			         head=insertbefore(head);
				     head=displaydll(head);
				   break;
				   
		    case 7:
			       head= insertafter(head);
				   head=displaydll(head);
				   break;
				   
		    case 8:
			       head= deleteatbeg(head);
				   head=displaydll(head);
				   break;
				   
		    case 9:
			          head=deleteatend(head);
				      head=displaydll(head);
				   break;
				   
			case 10 :
			          head=deletebefore(head);
					 head=displaydll(head);
					 break;
					 
			case 11 :
			         head=deleteafter(head);
					 head=displaydll(head);
					 break;
					 
			default:
			        printf("your choice is invalid!");
					printf("\n PLEASE TRY AGAIN!"); 
		}
        
	}
	  while(select != 11);
	  return 0;
}

