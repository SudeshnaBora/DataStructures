#include<stdio.h>
#include<malloc.h>

struct node {
  int num;
  struct node *ptr;
} ;
// node is the structure of individual nodes in the linked list.
// For brevity I am making the datatype of the node to be int .
static struct node *head=0;
static struct node *temp=0;
static struct node *prev=0;

//Linked list display
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


void  LinkedListDisplay()
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

//function to delete nodes from Linked List
void LinkedListDeletion(int data)
{
    prev=temp=head;
    int flag=0;

    while(temp!=0)
    {
        //node is first node
        if(head->num==data)
        {
            temp=head;
            free(temp);
            temp=head->ptr;
            head=head->ptr;
            return;
        }
        //node is last node
        if(temp->num==data && temp->ptr==0)
        {
            prev->ptr=0;
            free(temp);
            return;
        }
        //node is in the middle
        if(temp->num==data)
        {
            prev->ptr=temp->ptr;
            prev=temp->ptr;
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->ptr;
    }
   printf("No such data\n");
   return;
}

// linked list insertion
void LinkedListInsertion(int choice,int data)
{
    int position,noNodes,flag=1;
    temp->num=data;
    printf("\nInside insertion\n");
    prev=head;
    switch(choice)
    {
    case 1:
        //before the beginning
        temp->ptr=prev;
        head=temp;
        return;
    case 2:
        //after the end
        prev=head;
        while(1)
        {
            if(prev->ptr==0)
            {
                prev->ptr=temp;
                return;
            }
            prev=prev->ptr;
        }
        break;
    case 3:
        printf("Enter the position\n");
        scanf("%d",&position);
        noNodes=1;
        prev=head;
        while(prev!=0)
        {
          if(noNodes==position)
          {
              temp->ptr=prev->ptr;
              prev->ptr=temp;
              return;
          }
          prev=prev->ptr;
          noNodes+=noNodes;
        }
        if(flag==1)
        {
            printf("Not enough nodes to insert\n");
        }
        break;
    }
}

int CalculateLengthIterative()
{
    int length=0;
    temp=head;
    while(temp!=0)
    {
        temp=temp->ptr;
        length++;
    }
    return length;
}

int CalculateLengthRecursive(struct node *head)
{
    int len=0;
    if(head->ptr!=0)
    {
        len+=CalculateLengthRecursive(head->ptr);
    }
    return (len+1);
}
