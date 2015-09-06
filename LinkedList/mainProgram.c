#include<stdio.h>
#include "LinkedList.h"

int main()
{
    creation();
    //creates a linked list
    printf("\n");
    //display the list created only if the list exists
    if(head!=0)
    {
       display();
    }
    return 0;
}
