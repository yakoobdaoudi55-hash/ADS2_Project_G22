#ifndef COMMON_H
#define COMMON_H

#define MAX_1D          100
#define MAX_ROWS        20
#define MAX_COLS        20
#define MAX_LIST_SIZE   50
#define MAX_STACK_SIZE  50
#define MAX_QUEUE_SIZE  50
#define MAX_STRING_LEN  256

/* Node for singly linked list */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Node for doubly linked list */
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

/* Pointer-based singly linked list */
typedef struct {
    Node* head;   // first element
    int size;
} ArrayList;

/* Pointer-based doubly linked list */
typedef struct {
    DNode* head;
    DNode* tail;
    int size;
} DLL;

/* Pointer-based Stack (linked list) */
typedef struct {
    Node* top;   // top element
} Stack;

/* Pointer-based Queue (linked list) */
typedef struct {
    Node* front;  // first element
    Node* rear;   // last element
    int count;
} Queue;

#endif
