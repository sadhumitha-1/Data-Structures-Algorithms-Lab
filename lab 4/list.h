#ifndef LIST_H
#define LIST_H

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    Node* gethead() { return head; }

public:
    List(){
        head=nullptr;
    }
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insertAscending(int value) {
        Node* newNode = new Node(value);
        
        // If list is empty or value is less than head
        if (head == nullptr || value < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    static List merge(const List& list1, const List& list2) {
        List mergedList;
        Node* ptr1 = list1.head;
        Node* ptr2 = list2.head;

        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->data <= ptr2->data) {
                mergedList.insertAscending(ptr1->data);
                ptr1 = ptr1->next;
            } else {
                mergedList.insertAscending(ptr2->data);
                ptr2 = ptr2->next;
            }
        }

        while (ptr1 != nullptr) {
            mergedList.insertAscending(ptr1->data);
            ptr1 = ptr1->next;
        }

        while (ptr2 != nullptr) {
            mergedList.insertAscending(ptr2->data);
            ptr2 = ptr2->next;
        }

        return mergedList;
    }

    void display() const {
        if (head == nullptr) {
            printf("List is empty\n");
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
};

#endif