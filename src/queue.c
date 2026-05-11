#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

/* Initialize empty queue */
void initQueue(Queue* Q) {
    Q->front = NULL; // no elements
    Q->rear  = NULL;
    Q->count = 0;
}

/* Enqueue — add to rear */
int enqueue(Queue* Q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // allocate node
    if (!newNode) return -1;
    newNode->data = value;
    newNode->next = NULL;
    if (Q->rear == NULL) {
        Q->front = Q->rear = newNode; // first element
    } else {
        Q->rear->next = newNode; // link to rear
        Q->rear = newNode;       // update rear
    }
    Q->count++;
    return 0;
}

/* Dequeue — remove from front */
int dequeue(Queue* Q) {
    if (Q->front == NULL) return -1; // empty queue
    Node* temp = Q->front;
    int val = temp->data;
    Q->front = Q->front->next;       // move front forward
    if (Q->front == NULL) Q->rear = NULL; // queue now empty
    free(temp);
    Q->count--;
    return val;
}

/* Return front value without removing */
int frontQueue(Queue* Q) {
    if (Q->front == NULL) return -1; // empty queue
    return Q->front->data;
}

/* Return rear value without removing */
int rearQueue(Queue* Q) {
    if (Q->rear == NULL) return -1; // empty queue
    return Q->rear->data;
}

/* Check if queue is empty */
int isEmptyQueue(Queue* Q) {
    return Q->front == NULL; // 1 if empty
}
