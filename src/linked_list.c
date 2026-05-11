#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/* ===== SINGLY LINKED LIST ===== */

void initList(ArrayList* L) {
    L->head = NULL; // no elements yet
    L->size = 0;
}

int insertBeginning(ArrayList* L, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // allocate node
    if (!newNode) return -1;
    newNode->data = value;
    newNode->next = L->head; // point to old head
    L->head = newNode;       // new node becomes head
    L->size++;
    return 0;
}

int insertEnd(ArrayList* L, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // allocate node
    if (!newNode) return -1;
    newNode->data = value;
    newNode->next = NULL;
    if (L->head == NULL) {
        L->head = newNode; // list was empty
    } else {
        Node* cur = L->head;
        while (cur->next != NULL) cur = cur->next; // go to last node
        cur->next = newNode;
    }
    L->size++;
    return 0;
}

int insertAtPosition(ArrayList* L, int pos, int value) {
    if (pos < 0 || pos > L->size) return -1; // invalid position
    if (pos == 0) return insertBeginning(L, value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;
    newNode->data = value;
    Node* cur = L->head;
    int i;
    for (i = 0; i < pos - 1; i++) cur = cur->next; // go to pos-1
    newNode->next = cur->next; // link new node
    cur->next = newNode;
    L->size++;
    return 0;
}

int deleteBeginning(ArrayList* L) {
    if (L->head == NULL) return -1; // empty list
    Node* temp = L->head;
    int val = temp->data;
    L->head = L->head->next; // move head forward
    free(temp);              // free old head
    L->size--;
    return val;
}

int deleteEnd(ArrayList* L) {
    if (L->head == NULL) return -1; // empty list
    if (L->head->next == NULL) return deleteBeginning(L);
    Node* cur = L->head;
    while (cur->next->next != NULL) cur = cur->next; // go to second-to-last
    int val = cur->next->data;
    free(cur->next); // free last node
    cur->next = NULL;
    L->size--;
    return val;
}

int deleteByValue(ArrayList* L, int value) {
    if (L->head == NULL) return -1;
    if (L->head->data == value) return deleteBeginning(L);
    Node* cur = L->head;
    while (cur->next != NULL && cur->next->data != value)
        cur = cur->next; // find node before target
    if (cur->next == NULL) return -1; // not found
    Node* temp = cur->next;
    cur->next = temp->next; // skip over deleted node
    free(temp);
    L->size--;
    return value;
}

Node* searchValue(ArrayList* L, int value) {
    Node* cur = L->head;
    while (cur != NULL) {
        if (cur->data == value) return cur; // found
        cur = cur->next;
    }
    return NULL; // not found
}

void displayList(ArrayList* L) {
    Node* cur = L->head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void reverseList(ArrayList* L) {
    Node* prev = NULL;
    Node* cur = L->head;
    Node* next = NULL;
    while (cur != NULL) {
        next = cur->next;  // save next
        cur->next = prev;  // reverse link
        prev = cur;
        cur = next;
    }
    L->head = prev; // new head
}

void sortListBubble(ArrayList* L) {
    if (L->head == NULL) return;
    int swapped, temp;
    Node* cur;
    do {
        swapped = 0;
        cur = L->head;
        while (cur->next != NULL) {
            if (cur->data > cur->next->data) {
                temp = cur->data;           // swap values
                cur->data = cur->next->data;
                cur->next->data = temp;
                swapped = 1;
            }
            cur = cur->next;
        }
    } while (swapped); // repeat until no swaps
}

void mergeSortedLists(ArrayList* A, ArrayList* B, ArrayList* result) {
    initList(result);
    Node* a = A->head;
    Node* b = B->head;
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) { insertEnd(result, a->data); a = a->next; } // pick from A
        else { insertEnd(result, b->data); b = b->next; }                     // pick from B
    }
    while (a != NULL) { insertEnd(result, a->data); a = a->next; } // remaining A
    while (b != NULL) { insertEnd(result, b->data); b = b->next; } // remaining B
}

/* ===== DOUBLY LINKED LIST ===== */

void initListDLL(DLL* L) {
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
}

int insertBeginningDLL(DLL* L, int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) return -1;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = L->head;          // point to old head
    if (L->head != NULL) L->head->prev = newNode; // link back
    L->head = newNode;
    if (L->tail == NULL) L->tail = newNode; // first element
    L->size++;
    return 0;
}

int insertEndDLL(DLL* L, int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) return -1;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = L->tail;          // point back to old tail
    if (L->tail != NULL) L->tail->next = newNode; // link forward
    L->tail = newNode;
    if (L->head == NULL) L->head = newNode; // first element
    L->size++;
    return 0;
}

int deleteByValueDLL(DLL* L, int value) {
    DNode* cur = L->head;
    while (cur != NULL && cur->data != value) cur = cur->next; // find node
    if (cur == NULL) return -1; // not found
    if (cur->prev != NULL) cur->prev->next = cur->next; // unlink from left
    else L->head = cur->next;
    if (cur->next != NULL) cur->next->prev = cur->prev; // unlink from right
    else L->tail = cur->prev;
    free(cur);
    L->size--;
    return value;
}

void displayForward(DLL* L) {
    DNode* cur = L->head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next; // move forward
    }
    printf("NULL\n");
}

void displayBackward(DLL* L) {
    DNode* cur = L->tail;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->prev; // move backward
    }
    printf("NULL\n");
}
