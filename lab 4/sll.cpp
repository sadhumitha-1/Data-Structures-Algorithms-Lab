#include <stdio.h>
#include <stdlib.h>

class LinkedList {
private:
    // Node structure as a private member
    struct Node {
        int data;
        Node* next;
        
        // Constructor for Node
        Node(int value) {
            data = value;
            next = NULL;
        }
    };
    
    Node* head;
    Node* tail;
    int size;
    
    // Helper function for recursive display in reverse
    void displayReverseRecursive(Node* node) {
        if (node == NULL) {
            return;
        }
        
        displayReverseRecursive(node->next);
        printf("%d ", node->data);
    }
    
public:
    // Constructor
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        Node* next;
        
        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        
        head = NULL;
        tail = NULL;
    }
    
    // 1. Insert Beginning - O(1)
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            // List is empty
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
        printf("Inserted %d at the beginning\n", value);
    }
    
    // 2. Insert End - O(1) with tail pointer
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            // List is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        printf("Inserted %d at the end\n", value);
    }
    
    // 3. Insert Position - O(n) where n is the position
    void insertPosition(int value, int position) {
        if (position < 1 || position > size + 1) {
            printf("Invalid position! Position should be between 1 and %d\n", size + 1);
            return;
        }
        
        if (position == 1) {
            insertBeginning(value);
            return;
        }
        
        if (position == size + 1) {
            insertEnd(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
        size++;
        printf("Inserted %d at position %d\n", value, position);
    }
    
    // 4. Delete Beginning - O(1)
    void deleteBeginning() {
        if (head == NULL) {
            printf("List is empty! Nothing to delete.\n");
            return;
        }
        
        Node* temp = head;
        int deletedValue = temp->data;
        
        if (head == tail) {
            // Only one node in the list
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
        }
        
        delete temp;
        size--;
        printf("Deleted %d from the beginning\n", deletedValue);
    }
    
    // 5. Delete End - O(n)
    void deleteEnd() {
        if (head == NULL) {
            printf("List is empty! Nothing to delete.\n");
            return;
        }
        
        Node* temp = tail;
        int deletedValue = temp->data;
        
        if (head == tail) {
            // Only one node in the list
            head = NULL;
            tail = NULL;
        } else {
            // Find the node before tail
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            tail = current;
            current->next = NULL;
        }
        
        delete temp;
        size--;
        printf("Deleted %d from the end\n", deletedValue);
    }
    
    // 6. Delete Position - O(n)
    void deletePosition(int position) {
        if (head == NULL) {
            printf("List is empty! Nothing to delete.\n");
            return;
        }
        
        if (position < 1 || position > size) {
            printf("Invalid position! Position should be between 1 and %d\n", size);
            return;
        }
        
        if (position == 1) {
            deleteBeginning();
            return;
        }
        
        if (position == size) {
            deleteEnd();
            return;
        }
        
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        
        Node* temp = current->next;
        int deletedValue = temp->data;
        current->next = temp->next;
        
        delete temp;
        size--;
        printf("Deleted %d from position %d\n", deletedValue, position);
    }
    
    // 7. Search - O(n)
    void search(int value) {
        if (head == NULL) {
            printf("List is empty! Nothing to search.\n");
            return;
        }
        
        Node* current = head;
        int position = 1;
        int found = 0;
        
        while (current != NULL) {
            if (current->data == value) {
                printf("Value %d found at position %d\n", value, position);
                found = 1;
            }
            current = current->next;
            position++;
        }
        
        if (!found) {
            printf("Value %d not found in the list\n", value);
        }
    }
    
    // 8. Display - O(n)
    void display() {
        if (head == NULL) {
            printf("List is empty!\n");
            return;
        }
        
        printf("List elements: ");
        Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
    
    // 9. Display Reverse - O(n)
    void displayReverse() {
        if (head == NULL) {
            printf("List is empty!\n");
            return;
        }
        
        printf("List elements in reverse order: ");
        displayReverseRecursive(head);
        printf("\n");
    }
    
    // 10. Reverse Link - O(n)
    void reverseLink() {
        if (head == NULL || head == tail) {
            // Empty list or list with only one node
            return;
        }
        
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        
        // Save the tail before reversing
        tail = head;
        
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        printf("List has been reversed\n");
    }
    
    // Get the size of the list
    int getSize() {
        return size;
    }
};

int main() {
    LinkedList list;
    
    int choice, value, position;
    
    do {
        printf("\n---- Singly Linked List ADT Menu ----\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Display Reverse\n");
        printf("10. Reverse Link\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                list.insertBeginning(value);
                break;
                
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                list.insertEnd(value);
                break;
                
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (1 to %d): ", list.getSize() + 1);
                scanf("%d", &position);
                list.insertPosition(value, position);
                break;
                
            case 4:
                list.deleteBeginning();
                break;
                
            case 5:
                list.deleteEnd();
                break;
                
            case 6:
                printf("Enter position to delete (1 to %d): ", list.getSize());
                scanf("%d", &position);
                list.deletePosition(position);
                break;
                
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                list.search(value);
                break;
                
            case 8:
                list.display();
                break;
                
            case 9:
                list.displayReverse();
                break;
                
            case 10:
                list.reverseLink();
                break;
                
            case 11:
                printf("Exiting program\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11);
    
    return 0;
}