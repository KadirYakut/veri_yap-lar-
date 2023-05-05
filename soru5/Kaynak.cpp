#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Queue {
    char items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue* q, char value) {
    if (q->rear == MAX_SIZE - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

char dequeue(struct Queue* q) {
    char item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = '\0';
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

int main() {
    struct Queue* q = createQueue();
    char str[MAX_SIZE];
    printf("String girin: ");
    fgets(str, MAX_SIZE, stdin);
    int length = strlen(str);
    if (str[length - 1] == '\n')
        str[length - 1] = '\0';
    int i, j;
    for (i = 0; i < length; i++) {
        if (isEmpty(q) || str[i] != q->items[q->rear])
            enqueue(q, str[i]);
        else
            dequeue(q);
    }
    printf("Sonuç: ");
    if (isEmpty(q))
        printf("Empty\n");
    else {
        for (j = q->front; j <= q->rear; j++)
            printf("%c", q->items[j]);
        printf("\n");
    }
    return 0;
}
