// it implements Queue from stack using costly Dequeue method

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
void Enqueue(struct Stack *s1,int data)
{
    push(s1,data); // simply push
}
struct StackNode *Dequeue(struct Stack *s1,struct Stack *s2)
{
    struct StackNode *temp;
    while(s1->top!=NULL)
    {
        temp = pop(s1);
        push(s2,temp->element);
        free(temp);
    }
    temp = pop(s2);
    return temp;
};
int main()
{
    struct Stack *s1 = CreateStack(); //Stack 1 is the main stack , both enqueue and dequeue is done here
    struct Stack *s2 = CreateStack(); // temporary stack for intermediate functioning
    Enqueue(s1,3);
    Enqueue(s1,6);
    Enqueue(s1,1);
    //Dequeue(s1,s2);
    printf("%d is popped\n",Dequeue(s1,s2)->element);
    return 0;
}
