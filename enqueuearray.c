#include <stdio.h>

#define MAX 5  

int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
   
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); 
    for(int i = 0 ; i<MAX ; i++){
        printf("%d ",queue[i]);

    }

    return 0;
}
