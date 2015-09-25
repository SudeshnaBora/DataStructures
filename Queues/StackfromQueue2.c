// Implement Stack from Queue
// Make Pop costly
// Always push into the present q1
// while popping , Dequeue-Enqueue from q1 to q2 and return the last element
// change the names

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
void Push(struct Queue *q1,int data)
{
    Enqueue(q1,data);
}
struct QueueNode * Pop(struct Queue *q1,struct Queue *q2)
{
    struct QueueNode *temp;
    while(q1->front->next!= NULL)
    {
        temp = Dequeue(q1);
        Enqueue(q2,temp->element);
        free(temp);
    }
    temp = Dequeue(q1);
    struct Queue *t;
    t->front=q1->front;
    t->rear=q1->rear;
    q1->front = q2->front;
    q1->rear =q2->rear;
    q2->front =t->front;
    q2->rear=t->rear;
    return temp;
};
int main()
{
 // create a capacity for the Queue
 struct Queue *q1 = CreateQueue();
 struct Queue *q2 = CreateQueue();
 Push(q1,1);
 Push(q1,2);
 Push(q1,3);
 Push(q1,5);
 Pop(q1,q2);
 printf("%d\n",Pop(q1,q2)->element);
 //it is not necessary to take the value returned
 return 0;
}
