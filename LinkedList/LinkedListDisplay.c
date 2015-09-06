#include "Linkedlist.h"

void LinkedlistDisplay()
{
    temp=0;
    temp=head;
    while(temp->ptr!=0)
    {
        printf("%d->",temp->num);
        temp=temp->ptr;
    }
    printf("%d\n",temp->num);
}
