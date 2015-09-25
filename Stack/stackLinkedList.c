// linked list implementation

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
int peek(struct Stack *s)
{
    if(s->top==NULL)
        return;
    return s->top->element;
}
int main()
{
    struct Stack *s = CreateStack();
    push(s,3);
    push(s,6);
    push(s,1);
    pop(s);
    printf("%d is popped\n",pop(s)->element);
    printf("%d is peeked\n",peek(s));
}
