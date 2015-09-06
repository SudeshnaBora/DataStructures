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
void creation()
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
void display()
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
