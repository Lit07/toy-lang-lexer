#ifndef STACK_H
#define STACK_H

#define MAX_STACK 100

typedef struct {
    char data[MAX_STACK][20];
    int top;
} Stack;

void push(Stack *s, char *symbol);
void pop(Stack *s);
char* peek(Stack *s);
int is_empty(Stack *s);
void print_stack(Stack *s);

#endif