#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Queue Overflow (Out of memory)\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        printf("%d enqueued to queue\n", value);
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("%d enqueued to queue\n", value);
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow (Queue is empty)\n");
        return;
    }
    struct Node* temp = q->front;
    printf("%d dequeued from queue\n", temp->data);
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}


void display(struct Queue* q) {
    
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    
    struct Node* temp = q->front;
    
    printf("Queue elements: ");
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; 
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();
    
   
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q); 
    
   
    dequeue(q);
    dequeue(q);
    display(q); 
    
   
    enqueue(q, 40);
    display(q); 
    
    dequeue(q);
    dequeue(q);
    display(q); 
    
    dequeue(q); 
    return 0;
}

