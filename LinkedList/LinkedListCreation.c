#include "LinkedList.h"

void LinkedListCreation()
{
    int data,choice=1;
    do{
        temp = (struct node *)malloc(sizeof(struct node *));
        printf("Enter numeric data:-\n");
        scanf("%d",&data);
        temp->num=data;
        if(head==0)
        {
            temp->ptr=0;
            prev=head=temp;
        }
        else
        {
            prev->ptr=temp;
            prev=temp;
            prev->ptr=0;
        }
        printf("Do you want to continue 0:No?\n");
        scanf("%d",&choice);
        if(choice==0)
            break;
    }while(1);
}
