#include <cstdio>
#define MAX_SIZE 5

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = rear = -1;
        printf("Circular Queue initialized.\n");
    }

    void enqueue(int value);
    int dequeue();
    int peek();
};

// Function to enqueue an element in circular queue
void CircularQueue::enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {  // Queue is full
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {  // First element being inserted
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;  // Move rear circularly
    }
    arr[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from circular queue
int CircularQueue::dequeue() {
    if (front == -1) {  // Queue is empty
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = arr[front];

    if (front == rear) {  // Reset when last element is dequeued
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;  // Move front circularly
    }
    return value;
}

// Function to get the front element
int CircularQueue::peek() {
    if (front == -1) {  // Queue is empty
        printf("Queue Underflow!\n");
        return -1;
    }
    return arr[front];
}

int main() {
    CircularQueue q;
    int value;
    int choice;

    while (true) {
        printf("\nMENU\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
        printf("Choose one: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                q.enqueue(value);
                break;

            case 2:
                value = q.dequeue();
                if (value != -1) {
                    printf("Deleted element is %d\n", value);
                }
                break;

            case 3:
                value = q.peek();
                if (value != -1) {
                    printf("The front element is %d\n", value);
                }
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
