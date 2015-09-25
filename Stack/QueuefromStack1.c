// this method is enqueue costly
// using linked list method for stack implementation

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct StackNode {
  int element;
  struct StackNode *next;
};
struct Stack {
  struct StackNode *top;
};
struct Stack *CreateStack()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top=NULL;
    return s;
};
struct StackNode *CreateNode(struct Stack *s,int data)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    node->element = data;
    node->next=NULL;
};
void push(struct Stack *s,int data){
  struct StackNode *node = CreateNode(s,data);
  if(s->top == NULL)
  {
      s->top=node;
      return;
  }
  node->next=s->top;
  s->top=node;
  return;
}
struct StackNode *pop(struct Stack *s)
{
    if(s->top==NULL)
        return;
    struct StackNode *node = s->top;
    s->top=s->top->next;
    return node;
};
void Enqueue(struct Stack *s1,struct Stack *s2,int data)
{
    struct StackNode *temp;
    while(s1->top!=NULL) //push all the elements of s1 into s2
    {
        temp=pop(s1);
        push(s2,temp->element);
        free(temp);
    }
    s1->top=NULL;
    push(s1,data); //push the data to s1
    while(s2->top!=NULL) //push back all the elements from s2
    {
        temp=pop(s2);
        push(s1,temp->element);
        free(temp);
    }
    s2->top=NULL;
}
struct StackNode *Dequeue(struct Stack *s1)
{
    if(s1->top==NULL) //Dequeue consist of plan popping
        return;
    struct StackNode *node = pop(s1);
    return node;
};
int main()
{
    struct Stack *s1 = CreateStack(); //Stack 1 is the main stack , both enqueue and dequeue is done here
    struct Stack *s2 = CreateStack(); // temporary stack for intermediate functioning
    Enqueue(s1,s2,3);
    Enqueue(s1,s2,6);
    Enqueue(s1,s2,1);
    Dequeue(s1);
    printf("%d is popped\n",Dequeue(s1)->element);
    return 0;
}
