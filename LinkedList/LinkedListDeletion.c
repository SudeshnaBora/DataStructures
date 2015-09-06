#include<stdio.h>
#include<malloc.h>
#include "LinkedList.h"

void LinkedListDeletion(int data)
{
    printf("Inside deletion\n");
    prev=temp=head;
    int flag=0;

    while(temp!=0)
    {
        //node is first node
        if(head->num==data)
        {
            temp=head->ptr;
            head=head->ptr;
            return;
        }
        //node is last node
        if(temp->num==data && temp->ptr==0)
        {
            prev->ptr=0;
            return;
        }
        //node is in the middle
        if(temp->num==data)
        {
            prev->ptr=temp->ptr;
            prev=temp->ptr;
            return;
        }
        prev=temp;
        temp=temp->ptr;
    }
   printf("No such data\n");
   return;
}
