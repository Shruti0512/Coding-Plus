#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int data;
};
void enqueue(struct node**);
void dequeue(struct node**);
void display(struct node*);
void peek(struct node*);

int main()
{
struct node*front=0,*rear=0;
int choice;
printf("Enter 1 for Enqueue\nEnter 2 for dequeue\nEnter 3 for peek\nEntr 4 for display\nEnter 5 for exit:\n ");
do
{
   printf("\n\nEnter Your Choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:enqueue(&rear);
    if(front==0)
    {
        front=rear;
    }
    break;


    case 2:if(front==0 && rear==0)
    {
        printf("Queue is empty");
        break;
    }
    else
    {
        dequeue(&front);
        if(front==0)
        {
            rear=0;
        }
        break;
    }

    case 3:if(front==0)
    {
        printf("Queue is Empty");
        break;
    }
    else
    {
        peek(front);
        break;
    }


    case 4: if(front==0)
    {
        printf("Queue is Empty");
        break;
    }
    else
    {
        display(front);
        break;
    }


    case 5: break;
    default:printf("INVALID CHOICE");
   }
 }while(choice!=5);
}


void enqueue(struct node* *rear)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if((*rear)==0)
    {
        (*rear)=newnode;
    }
    else
    {
       (*rear)->next=newnode;
       (*rear)=newnode;
    }
}


void dequeue(struct node* *front)
{
    struct node *temp=(*front);
    printf("The element which is dequeued is %d",(*front)->data);
    (*front)=(*front)->next;
    free (temp);
}

void peek(struct node *front)
{
    printf("The peek element data is %d",front->data);

}

void display(struct node *front)
{
    struct node* temp=front;
    printf("The elements are: ");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

