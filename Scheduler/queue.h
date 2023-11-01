/**
 * queue data structure containing the tasks in the system
 */

#include "task.h"

typedef struct node {
    Task *task;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// insert and delete operations.
void create(Queue *);
void enqueue(Queue *, Task *task);
Task* dequeue(Queue *);
void delete(Queue *, Task *task);
void traverse(Queue *);
