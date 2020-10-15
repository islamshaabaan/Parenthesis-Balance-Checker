
#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    char info;
    struct node *ptr;
}*top,*top1,*temp;


char topelement();
void push(char data);
void pop();
bool empty();
void display();
void destroy();
void stack_count();
void create();
#endif /* STACK_H_ */
