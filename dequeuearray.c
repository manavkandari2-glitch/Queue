#include <stdio.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
 void traversal(int arr[], int size) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n"); 
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d is inserted in queue\n",queue[rear]);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1; 
    }
    
    int deleted_value = queue[front];
    printf("Dequeued: %d\n", deleted_value);
    
    front++;
    
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    
    return deleted_value;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    traversal(queue, MAX);
    dequeue();
    dequeue();
   traversal(queue, MAX);
    
    return 0;
}
