//This program is to implement priority queue with max heap using arrays
#include <stdio.h>
#define MAX_SIZE 100

class PriorityQueue {
private:
    int heap[MAX_SIZE];
    int size;
    
    // Helper function to swap two elements
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Helper function to heapify a subtree with root at given index
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
public:
    // Constructor
    PriorityQueue() {
        size = 0;
    }
    
    // Insert an element into the priority queue
    void insert(int value) {
        if (size >= MAX_SIZE) {
            printf("Priority Queue overflow.\n");
            return;
        }
        
        // Insert the new element at the end
        int i = size;
        heap[i] = value;
        size++;
        
        // Fix the max heap property if it is violated
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        
        printf("%d inserted successfully.\n", value);
    }
    
    // Delete and return the maximum element
    int deleteMax() {
        if (size <= 0) {
            printf("Priority Queue is empty.\n");
            return -1;
        }
        
        // Store the maximum value to return
        int maxItem = heap[0];
        
        // Replace root with last element
        heap[0] = heap[size - 1];
        size--;
        
        // Heapify the root
        int i = 0;
        while (1) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            // If left child is larger than root
            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            
            // If right child is larger than largest so far
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            
            // If largest is not root
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
        
        return maxItem;
    }
    
    // Display the priority queue
    void display() {
        if (size == 0) {
            printf("Priority Queue is empty.\n");
            return;
        }
        
        printf("Priority Queue elements (in heap order):\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }
    
    // Search for an element in the priority queue
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                return i;
            }
        }
        return -1;
    }
    
    // Perform heap sort on the priority queue
    void heapSort() {
        // Build max heap (rearrange array)
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(heap, size, i);
        }
        
        // One by one extract an element from heap
        for (int i = size - 1; i > 0; i--) {
            // Move current root to end
            swap(heap[0], heap[i]);
            
            // Call max heapify on the reduced heap
            heapify(heap, i, 0);
        }
        
        printf("Heap Sort completed. Elements in ascending order:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }
    
    // Check if the priority queue is empty
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;
    
    while (1) {
        printf("\n----- Priority Queue Operations -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Sort (Heap Sort)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                pq.insert(value);
                break;
                
            case 2:
                if (pq.isEmpty()) {
                    printf("Priority Queue is empty.\n");
                } else {
                    value = pq.deleteMax();
                    printf("Deleted maximum value: %d\n", value);
                }
                break;
                
            case 3:
                pq.display();
                break;
                
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                int pos;
                pos = pq.search(value);
                if (pos != -1) {
                    printf("%d found at index %d in the heap.\n", value, pos);
                } else {
                    printf("%d not found in the Priority Queue.\n", value);
                }
                break;
                
            case 5:
                pq.heapSort();
                break;
                
            case 6:
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}