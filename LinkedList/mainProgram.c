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

   // program to delete from list
    while(choice!=0)
    {
        printf("Enter the value you want to delete\n");
        scanf("%d",&data);
        LinkedListDeletion(data);
        printf("Do you want to continue 0:no\n");
        scanf("%d",&choice);
    }
    LinkedListDisplay();

    // program to insert in a linked list - 1. beginning 2. end 3. after a position

    printf("\n Enter linked list insertion position :- 1. front, 2. end 3. After position\n");
    scanf("%d",&choice);
    printf("Enter data\n");
    scanf("%d",&data);
    LinkedListInsertion(choice,data);
    LinkedListDisplay();

     // program to calculate length of the linked list either iteratively or recursively

     printf("\nLength:- %d\n",CalculateLengthIterative());

     printf("Length:- %d\n",CalculateLengthRecursive(head));
    return 0;
}
