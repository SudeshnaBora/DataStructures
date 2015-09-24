// implements stack via array
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Stack {
  int top;
  unsigned Capacity;
  int *element
};
struct Stack *CreateStackCapacity(unsigned cap)
{
    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));
    s->Capacity=cap;
    s->top = -1;
    s->element=(int *)malloc(cap*sizeof(int));
    return s;
};
int isFull(struct Stack *s)
{
    return s->top==(s->Capacity-1);
}
void push(struct Stack *s,int data)
{
    if(isFull(s))
    {
        return;
    }
    s->element[++s->top]=data;
}
int isEmpty(struct Stack *s)
{
    return s->top==-1;
}
int pop(struct Stack *s){
    if(isEmpty(s))
        return;
    return s->element[s->top--];
}
int peek(struct Stack *s){
   if(isEmpty(s))
    return;
   return s->element[s->top];
}
int main()
{
    struct Stack *s = CreateStackCapacity(500);
    push(s,10);
    push(s,100);
    push(s,5);
    pop(s);
    printf("%d\n",peek(s));
    return 0;
}
