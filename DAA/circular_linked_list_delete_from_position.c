#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *newnode,*tail,*current,*nextnode;
    int choice,position,i=1,length=0;
    tail=0;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        length++;
        printf("Do you wanna continue (0,1): ");
        scanf("%d",&choice);
    }

    current=tail->next;
    printf("Enter the position from which you wanna delete the element: ");
    scanf("%d",&position);
    if(position<0 && position>length){
        printf("Invalid Position");
    }
    else{
        while(i<position-1){
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }
    printf("After deleting element from position %d the resultant elements in the list are: ",position);
    current=tail->next;
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current!=tail->next);
}
