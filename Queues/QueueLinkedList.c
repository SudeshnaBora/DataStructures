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
int main()
{
 // create a capacity for the Queue
 struct Queue *queue = CreateQueue();
 Enqueue(queue,1);
 Enqueue(queue,2);
 Enqueue(queue,3);
 Enqueue(queue,5);
 printf("%d\n",Dequeue(queue)->element);
 Enqueue(queue,4);
 Dequeue(queue);
 //it is not necessary to take the value returned
 return 0;
}
