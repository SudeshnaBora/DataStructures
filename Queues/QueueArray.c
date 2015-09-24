#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<limits.h>

struct Queue {
    int front,rear,size;
    unsigned capacity;
    int *array;
    };
struct Queue* CreateQueue(unsigned Capacity)
{
    struct Queue *queue = (struct queue *)malloc(sizeof(struct Queue));
    queue->capacity = Capacity;
    queue->front = queue->size = 0;
    queue->rear = Capacity-1;
    queue->array = (int *)malloc(Capacity*sizeof(int));
    return queue;
}
int isFull(struct Queue *queue)
{
    return (queue->rear == queue->capacity);
}
void Enqueue(struct Queue *queue,int element)
{
    if(isFull(queue))
      return;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=element;
    queue->size +=1;
}
int isEmpty(struct Queue *queue)
{
    return queue->size==0;
}
int Dequeue(struct Queue *queue)
{
   if(isEmpty(queue))
        return INT_MIN;
   int data = queue->array[queue->front];
   queue->front = (queue->front+1)%queue->capacity;
   queue->size -=1;
   return data;
}
int front(struct Queue *queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
int rear(struct Queue *queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
int main()
{
    struct Queue *queue =CreateQueue(500); //creates a queue memory space
    Enqueue(queue,1);
    Enqueue(queue,2);
    Enqueue(queue,3);
    Enqueue(queue,4);

    printf("%d is dequeued\n",Dequeue(queue));
    printf("%d is in front now\n",front(queue));
    printf("%d is in rear now\n",rear(queue));


}
