/* ═══════════════════════════════════════════════════════════════
   PW 4 — Linked Lists   |   Université Sétif 01
   Algorithmics & Data Structures 02 — Dr. I. Zenbout 2025/2026
   Fill every TODO section after reading each exercise.
═══════════════════════════════════════════════════════════════ */
#include <stdio.h>
#include <stdlib.h>

/* ── Node structure ──────────────────────────────────────────── */
typedef struct Node {
    int          value;
    struct Node *next;
} Node;

/* ── Prototypes ──────────────────────────────────────────────── */
Node* createNode(int val);
int   isEmpty(Node *L);
void  traverse(Node *L);
void  insertAtHead(Node **L, int val);
void  insertAtTail(Node **L, int val);
void  insertAfterValue(Node **L, int target, int val);
void  deleteValue(Node **L, int val);
Node* splitAlternate(Node **L);

/* ── main ────────────────────────────────────────────────────── */
int main() {
    Node *L = NULL;

    /* Build initial list {5,3,4,2,9} */
    insertAtTail(&L, 5); insertAtTail(&L, 3);
    insertAtTail(&L, 4); insertAtTail(&L, 2);
    insertAtTail(&L, 9);
    printf("Initial : "); traverse(L);

    /* Exercise 2a — insert 6 after 4 */
    insertAfterValue(&L, 4, 6);
    printf("After ins 6 after 4 : "); traverse(L);

    /* Exercise 2b — delete 3 */
    deleteValue(&L, 3);
    printf("After del 3         : "); traverse(L);

    /* Exercise 3 — split */
    Node *L2 = splitAlternate(&L);
    printf("L  after split      : "); traverse(L);
    printf("L2 from  split      : "); traverse(L2);

    return 0;
}

/* ══ PROVIDED UTILITIES — do NOT modify ════════════════════════ */

Node* createNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->value = val;
    n->next  = NULL;
    return n;
}

int isEmpty(Node *L) { return L == NULL; }

void traverse(Node *L) {
    if (isEmpty(L)) { printf("[empty] NULL\n"); return; }
    Node *P = L;
    while (P != NULL) {
        printf("%d%s", P->value, P->next ? " -> " : " -> NULL\n");
        P = P->next;
    }
}

/* ══ YOUR IMPLEMENTATIONS — fill in each TODO ══════════════════ */

void insertAtHead(Node **L, int val) {
    /* Exercise 1a — TODO */
}

void insertAtTail(Node **L, int val) {
    /* Exercise 1b — TODO */
}

void insertAfterValue(Node **L, int target, int val) {
    /* Exercise 2a — TODO */
}

void deleteValue(Node **L, int val) {
    /* Exercise 2b — TODO */
}

Node* splitAlternate(Node **L) {
    /* Exercise 3 — TODO */
    return NULL;
}