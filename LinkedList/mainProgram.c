#include<stdio.h>
#include "LinkedList.h"

int main()
{
    int data,choice=1;
    LinkedListCreation();
    //creates a linked list
    printf("\n");
    //display the list created only if the list exists
    if(head!=0)
    {
       LinkedListDisplay();
    }
    while(choice!=0)
    {
        printf("Enter the value you want to delete\n");
        scanf("%d",&data);
        LinkedListDeletion(data);
        printf("Do you want to continue 0:no\n");
        scanf("%d",&choice);
    }
    display();
    return 0;
}
