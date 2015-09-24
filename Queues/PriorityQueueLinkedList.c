#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Qnode {
   int element, priority;
   struct Qnode *next;
};
struct Queue {
  struct Qnode *front;
};
struct Queue *CreateQueue(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front=NULL;
    return q;
};
struct Qnode *CreateQNode(int data,int priority)
{
    struct Qnode *node = (struct Qnode *)malloc(sizeof(struct Qnode));
    node->element=data;
    node->priority=priority;
    node->next=NULL;
    return node;
};
void Insert(struct Queue *q,int data,int priority)
{
    struct Qnode *node = CreateQNode(data,priority);
    if(q->front==NULL)
    {
        q->front= node;
        return;
    }
    struct Qnode *temp =q->front;
    if(priority<temp->priority)
    {
        node->next=temp;
        q->front=node;
        return;
    }
    while(temp->next!=NULL && priority >=temp->next->priority )
        temp=temp->next;
    node->next=temp->next;
    temp->next=node;
}
struct Qnode *Delete(struct Queue *q){
    if(q->front == NULL)
        return;
    struct Qnode *temp = q->front;
    q->front = q->front->next;
    return temp;
};
int main()
{
    struct Queue *q = CreateQueue();
    Insert(q,1,1);
    Insert(q,2,6);
    Insert(q,6,2);
    printf("%d\n",Delete(q)->element);
    return 0;
}
