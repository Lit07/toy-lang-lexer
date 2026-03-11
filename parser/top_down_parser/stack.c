#include <stdio.h>
#include <string.h>
#include "stack.h"

void push(Stack *s, char *symbol) {
    strcpy(s->data[++s->top], symbol);
}

void pop(Stack *s) {
    if(s->top >= 0)
        s->top--;
}

char* peek(Stack *s) {
    return s->data[s->top];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void print_stack(Stack *s) {
    for(int i = 0; i <= s->top; i++)
        printf("%s", s->data[i]);
}