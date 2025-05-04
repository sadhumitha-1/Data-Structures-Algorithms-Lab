#include <stdio.h>
#include <stdlib.h>

class Queue {
private:
    // Node structure inside the Queue class
    struct Node {
        int data;
        Node* next;
        
        // Constructor for the Node
        Node(int value) : data(value), next(NULL) {}
    };
    
    Node* front;   // Points to the front of the queue
    Node* rear;    // Points to the rear of the queue
    int size;      // Tracks the number of elements in the queue
    
public:
    // Constructor
    Queue() : front(NULL), rear(NULL), size(0) {}
    
    // Destructor to free allocated memory
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        size = 0;
    }
    
    // Enqueue operation - add element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        
        // If queue is empty, both front and rear point to the new node
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        printf("Enqueued %d successfully\n", value);
    }
    
    // Dequeue operation - remove element from the front of the queue
    bool dequeue() {
        if (isEmpty()) {
            printf("Queue Underflow! Cannot dequeue from an empty queue\n");
            return false;
        }
        
        Node* temp = front;
        int removedValue = front->data;
        
        // If this is the last node
        if (front == rear) {
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
        }
        
        delete temp;
        size--;
        printf("Dequeued %d successfully\n", removedValue);
        return true;
    }
    
    // Peek operation - view the front element without removing it
    bool peek() {
        if (isEmpty()) {
            printf("Queue is empty! Nothing to peek\n");
            return false;
        }
        
        printf("Front element: %d\n", front->data);
        return true;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return (front == NULL);
    }
    
    // Get the current size of the queue
    int getSize() {
        return size;
    }
    
    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            printf("Queue is empty!\n");
            return;
        }
        
        printf("Queue elements: ");
        Node* current = front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
};

int main() {
    Queue queue;
    int choice, value;
    
    do {
        printf("\n===== Queue ADT Menu =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                queue.enqueue(value);
                break;
                
            case 2:
                queue.dequeue();
                break;
                
            case 3:
                queue.peek();
                break;
                
            case 4:
                queue.display();
                break;
                
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}