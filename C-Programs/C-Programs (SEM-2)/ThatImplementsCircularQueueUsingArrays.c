#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct CircularQueue {
    int queue[SIZE];
    int front;
    int rear;
};

void cpush(struct CircularQueue* q, int data) {
    if ((q->rear + 1) % SIZE == q->front) {
        printf("Queue is Full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % SIZE;
    }
    q->queue[q->rear] = data;
}

int cpop(struct CircularQueue* q) {
    int temp = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return temp;
}

int cpeek(struct CircularQueue* q) {
    return q->queue[q->front];
}

void cdisplay(struct CircularQueue* q) {
    if (q->front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Front -> ");
    int i = q->front;
    while (1) {
        printf("%d -> ", q->queue[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("Rear\n");
}

void main() {
    struct CircularQueue cq;
    cq.front = -1;
    cq.rear = -1;

    int choice, data;

    while (1) {
        printf("0. Exit\n");
        printf("1. Push  2. Pop\n3. Peek  4. Display\n");
        scanf(" %d", &choice);

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Input data : ");
                scanf("%d", &data);
                cpush(&cq, data);
                cdisplay(&cq);
                break;
            case 2:
                if (cq.front == -1) {
                    printf("Queue is Empty!\n");
                    break;
                }
                printf("Popped %d!\n", cpop(&cq));
                cdisplay(&cq);
                break;
            case 3:
                if (cq.front == -1) {
                    printf("Queue is Empty!\n");
                    break;
                }
                printf("Front is %d!\n", cpeek(&cq));
                break;
            case 4:
                cdisplay(&cq);
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    }
}
