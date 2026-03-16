#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void init(Queue *q) { q->front = -1; q->rear = -1; }
bool isFull(Queue *q) { return q->rear == MAX - 1; }
bool isEmpty(Queue *q) { return q->front == -1; }

void enqueue(Queue *q, int val) {
    if (isFull(q)) printf("Queue Full\n");
    else {
        if (q->front == -1) q->front = 0;
        q->items[++(q->rear)] = val;
        printf("Enqueued: %d\n", val);
    }
}

void dequeue(Queue *q) {
    if (isEmpty(q)) printf("Queue Empty\n");
    else {
        printf("Dequeued: %d\n", q->items[q->front++]);
        if (q->front > q->rear) init(q);
    }
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    dequeue(&q);
    return 0;
}

