// implements stack from queue by making Enqueue costly

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct QueueNode {
  int element;
  struct QueueNode *next;
};
struct Queue {
  struct QueueNode *front,*rear;
};
struct Queue * CreateQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
};
struct QueueNode *CreateQNode(int data)
{
    struct QueueNode *node = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    node->element=data;
    node->next=NULL;
    return node;
};

void Enqueue(struct Queue *queue, int data)
{
    struct QueueNode *node = CreateQNode(data);
    //creates a node
    if (queue->front==NULL)
    {
        queue->front=queue->rear = node;
        return node;
    } // checks for empty queue
    queue->rear->next = node;
    queue->rear = node;
}
struct QueueNode * Dequeue(struct Queue *queue)
{
    if(queue->front == NULL)
        return NULL;
    struct QueueNode *temp = queue->front;
    queue->front=queue->front->next;
    if(queue->front==NULL)
        queue->rear=NULL;
        //if dequeue leads to making it empty, then we make rear as empty
    return temp;
};
void Push(struct Queue *q1,struct Queue *q2,int data)
{
    //this is similar to the Enqueue costly method of Queue from stack.
    // Only difference is they swap the names.
    // So, here they first Enqueue in q2
    // Dequeue- Enqueue from q1 to q2
    // swap the pointers - final motive is to keep the new entrant in the first position
    struct QueueNode *temp;
    Enqueue(q2,data);
    while(q1->front !=NULL)
    {
        temp = Dequeue(q1);
        Enqueue(q2,temp->element);
        free(temp);
    }
    struct Queue *t;
    t->front =q1->front;
    t->rear=q1->rear;
    q1->front=q2->front;
    q1->rear = q2->rear;
    q2->front = t->front;
    q2->rear = t->rear;
}
struct QueueNode * Pop(struct Queue *q1)
{
    return Dequeue(q1);
};
int main()
{
 // create a capacity for the Queue
 struct Queue *q1 = CreateQueue();
 struct Queue *q2 = CreateQueue();
 Push(q1,q2,1);
 Push(q1,q2,2);
 Push(q1,q2,3);
 Push(q1,q2,5);
 Dequeue(q1);
 printf("%d\n",Pop(q1)->element);
 //it is not necessary to take the value returned
 return 0;
}
