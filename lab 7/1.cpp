#include <cstdio>
#define MAX_SIZE 5

class queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    queue() {
        front = rear = -1;
        printf("Queue initialized.\n");
    }

    void enqueue(int value);
    int dequeue();
    int peek();
};


int main() {
    queue q;
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

// Function to enqueue an element
void queue::enqueue(int value) {
    if (rear == MAX_SIZE - 1) { 
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {  
        front = 0;
    }
    rear++;
    arr[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
int queue::dequeue() {
    if (front == -1 || front > rear) {  
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = arr[front];
    front++;  

    if (front > rear) {
        front = rear = -1;
    }
    return value;
}

// Function to peek the front element
int queue::peek() {
    if (front == -1 || front > rear) {  
        printf("Queue Underflow!\n");
        return -1;
    }
    return arr[front];
}