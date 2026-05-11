#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

/* Initialize empty stack */
void initStack(Stack* S) {
    S->top = NULL; // no elements
}

/* Push value onto stack */
int push(Stack* S, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // allocate node
    if (!newNode) return -1;
    newNode->data = value;
    newNode->next = S->top; // point to old top
    S->top = newNode;       // new top
    return 0;
}

/* Pop top value — returns -1 if empty */
int pop(Stack* S) {
    if (S->top == NULL) return -1; // empty stack
    Node* temp = S->top;
    int val = temp->data;
    S->top = S->top->next; // move top down
    free(temp);             // release node
    return val;
}

/* Peek at top value without removing */
int peek(Stack* S) {
    if (S->top == NULL) return -1; // empty stack
    return S->top->data;
}

/* Check if stack is empty */
int isEmptyStack(Stack* S) {
    return S->top == NULL; // 1 if empty
}
