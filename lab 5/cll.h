#ifndef LIST_H
#define LIST_H

class List {
    private:
        struct Node {
            int data;
            Node* next;
        } *head, *tail;
    
    public:
        List(){
            head=nullptr;
            tail=nullptr; 
        }
    
        void insertBeginning(int value);
        void insertEnd(int value);
        void insertPosition(int value, int pos);
        int deleteBeginning();
        int deleteEnd();
        int deletePosition(int pos);
        int search(int value);
        void display();
    
        ~List() {
            if (!head) return;
            Node* temp = head;
            Node* nextNode;
            while (temp != head || temp == head) {
                nextNode = temp->next;
                free(temp);
                temp = nextNode;
                if (temp == head && nextNode != head) break;
            }
            head = tail = nullptr;
        }
        
    };

//==============Function to insert an element at the beginning of the list=========================
void List::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (!head) {
        newNode->next = newNode;
        head = tail = newNode;
    } else {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

//==============Function to insert an element at the end of the list================================
void List::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (!head) {
        newNode->next = newNode;
        head = tail = newNode;
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

//==============Function to insert an element at a positon in the list===============================
void List::insertPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (!head) {
        if (pos == 1) {
            newNode->next = newNode;
            head = tail = newNode;
        } else {
            printf("Invalid position!\n");
        }
        return;
    }
    
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
    
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail)
        tail = newNode;
}

//==============Function to delete an element at the beginning of the list=========================
int List::deleteBeginning() {
    if (!head) return -1;
    Node* temp = head;
    int val = temp->data;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }
    free(temp);
    return val;
}

//==============Function to delete an element at the end of the list=========================
int List::deleteEnd() {
    if (!head) return -1;
    Node* temp = head, *prev = nullptr;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    int val = temp->data;
    if (head == tail)
        head = tail = nullptr;
    else {
        prev->next = head;
        tail = prev;
    }
    free(temp);
    return val;
}

//==============Function to delete an element at a positon in the list===============================
int List::deletePosition(int pos) {
    if (!head || pos < 1) return -1;
    if (pos == 1) return deleteBeginning();
    Node* temp = head, *prev = nullptr;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == tail) return deleteEnd();
    int val = temp->data;
    prev->next = temp->next;
    free(temp);
    return val;
}

//==============Function to search for an element in the list=================================================
int List::search(int value) {
    if (!head) return -1;
    Node* temp = head;
    int idx = 1;
    while (temp->next != head) {
        if (temp->data == value) return idx;
        temp = temp->next;
        idx++;
    }
    // Check the last node
    if (temp->data == value) return idx;
    return -1;
}

//==============Function to display the whole list and its reverse========================================
void List::display() {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    int idx = 1;
    printf("Forward: ");
    while (temp->next != head) {
        printf("%d(%d) -> ", temp->data, idx);
        temp = temp->next;
        idx++;
    }
    printf("%d(%d) -> (circular)\n", temp->data, idx);
    
    printf("Reverse: ");
    Node* current = tail;
    while (current != tail || current == tail) {
        printf("%d -> ", current->data);
        Node* prev = head;
        while (prev->next != current && prev->next != head) {
            prev = prev->next;
        }
        current = prev;
        if (current == tail && prev != tail) break;
    }
    printf("(circular)\n");
}

#endif