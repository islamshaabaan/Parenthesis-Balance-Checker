/*
 * C Program to Implement a Stack using Linked List
 */
#include "stack.h"

int count = 0;
/* Create empty stack */
void create()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d\n", count);
}
 
/* Push data into stack */
void push(char data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 
/* Display stack elements */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%c ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack\n");
        return;
    }
    else
        top1 = top1->ptr;
    /*printf("\n Popped value : %c\n", top->info);*/
    free(top);
    top = top1;
    count--;
}
 
/* Return top element */
char topelement()
{
    return(top->info);
}
 
/* Check if stack is empty or not */
bool empty()
{
    if (top == NULL)
    {
        /*printf("\n Stack is empty\n ");*/
	return 1;
    }else
    {
        /*printf("\n Stack is not empty with %d elements\n ", count);*/
	return 0;
    }
}
 
/* Destroy entire stack */
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed\n ");
    count = 0;
}