#include <iostream>
#include <vector>

class HashTable {
private:
    class Node {
    public:
        int key;
        Node* next;
        
        Node(int k) : key(k), next(nullptr) {}
    };
    
    std::vector<Node*> table;
    int size;
    
    int hashFunction(int key) {
        return key % size;
    }
    
public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, nullptr);
    }
    
    ~HashTable() {
        // Clean up all allocated nodes
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
    
    bool insert(int key) {
        int index = hashFunction(key);
        
        // Check if key already exists
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                std::cout << "Key " << key << " already exists\n";
                return false;
            }
            current = current->next;
        }
        
        // Insert at the beginning of the chain (head insertion)
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
        return true;
    }
    
    bool remove(int key) {
        int index = hashFunction(key);
        
        Node* current = table[index];
        Node* prev = nullptr;
        
        // Search for key
        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }
        
        // Key not found
        if (current == nullptr) {
            std::cout << "Key " << key << " not found\n";
            return false;
        }
        
        // Remove the node
        if (prev == nullptr) {
            // First node matches
            table[index] = current->next;
        } else {
            // Match is not in the first node
            prev->next = current->next;
        }
        
        delete current;
        return true;
    }
    
    bool search(int key) {
        int index = hashFunction(key);
        
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        
        return false;
    }
    
    void display() {
        std::cout << "Hash Table (Separate Chaining with Linked List):\n";
        for (int i = 0; i < size; i++) {
            std::cout << "Index " << i << ": ";
            if (table[i] == nullptr) {
                std::cout << "Empty";
            } else {
                Node* current = table[i];
                while (current != nullptr) {
                    std::cout << current->key << " -> ";
                    current = current->next;
                }
                std::cout << "NULL";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int tableSize;
    std::cout << "Enter the size of the hash table: ";
    std::cin >> tableSize;
    
    HashTable hashTable(tableSize);
    
    int choice, key;
    bool running = true;
    
    while (running) {
        std::cout << "\n==== Hash Table with Separate Chaining ====\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Display\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                if (hashTable.insert(key)) {
                    std::cout << "Key " << key << " inserted successfully\n";
                }
                break;
                
            case 2:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                if (hashTable.remove(key)) {
                    std::cout << "Key " << key << " deleted successfully\n";
                }
                break;
                
            case 3:
                std::cout << "Enter key to search: ";
                std::cin >> key;
                if (hashTable.search(key)) {
                    std::cout << "Key " << key << " found\n";
                } else {
                    std::cout << "Key " << key << " not found\n";
                }
                break;
                
            case 4:
                hashTable.display();
                break;
                
            case 5:
                running = false;
                std::cout << "Exiting program\n";
                break;
                
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}