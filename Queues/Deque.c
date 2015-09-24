#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Qnode {
   int element;
   struct Qnode *next,*prev;
};
struct Queue {
   struct Qnode *front,*rear;
};
struct Queue *CreateQueue(){
   struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
   q->front = q->rear = NULL;
   return;
};
struct Qnode *CreateNode(int data)
{
    struct Qnode *node = (struct Qnode *)malloc(sizeof(struct Qnode));
    node->element=data;
    node->next=NULL;
    node->prev=NULL;
    return node;
};
void InsertFront(struct Queue *q,int data)
{
    struct Qnode *node = CreateNode(data);
    if(q->front==NULL)
    {
        q->front=q->rear=node;
        return;
    }
    node->next=q->front;
    q->front->prev=node;
    q->front=node;
    q->front->prev=NULL;
}
void InsertRear(struct Queue *q,int data)
{
    struct Qnode *node = CreateNode(data);
     if(q->front==NULL)
    {
        q->front=q->rear=node;
        return;
    }
    node->prev=q->rear;
    q->rear->next=node;
    q->rear=q->rear->next;
}
struct Qnode *DeleteFront(struct Queue *q)
{
    if(q->front == NULL)
        return;
    struct Qnode *temp = q->front;
    q->front=q->front->next;
    q->front->prev=NULL;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    return temp;
};
struct Qnode *DeleteRear(struct Queue *q)
{
    if(q->front == NULL)
        return;
    struct Qnode *temp = q->rear;
    q->rear=q->rear->prev;
    q->rear->next=NULL;
    if(q->rear == NULL)
    {
        q->front=NULL;
    }
    return temp;
};
int main()
{
    struct Queue *q = CreateQueue();
    InsertFront(q,1);
    InsertFront(q,3);
    InsertRear(q,0);
    InsertRear(q,5);
    printf("%d\n",DeleteFront(q)->element);
    printf("%d\n",DeleteRear(q)->element);
}
