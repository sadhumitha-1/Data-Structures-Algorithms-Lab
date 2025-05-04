#include <iostream>
#include <vector>

class HashTable {
private:
    struct HashNode {
        int key;
        bool isOccupied;
        bool isDeleted;
        
        HashNode() : key(0), isOccupied(false), isDeleted(false) {}
    };
    
    std::vector<HashNode> table;
    int size;
    int count;
    
    int hashFunction(int key) {
        return key % size;
    }
    
public:
    HashTable(int tableSize) : size(tableSize), count(0) {
        table.resize(size);
    }
    
    bool insert(int key) {
        if (count >= size) {
            std::cout << "Hash table is full\n";
            return false;
        }
        
        int index = hashFunction(key);
        int i = 0;
        
        while (i < size) {
            // Found an empty slot or a deleted slot
            if (!table[(index + i) % size].isOccupied || table[(index + i) % size].isDeleted) {
                table[(index + i) % size].key = key;
                table[(index + i) % size].isOccupied = true;
                table[(index + i) % size].isDeleted = false;
                count++;
                return true;
            }
            // Key already exists
            else if (table[(index + i) % size].key == key && !table[(index + i) % size].isDeleted) {
                std::cout << "Key " << key << " already exists\n";
                return false;
            }
            i++;
        }
        
        std::cout << "Could not insert key " << key << "\n";
        return false;
    }
    
    bool remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        
        while (i < size) {
            int currentIndex = (index + i) % size;
            
            // If slot is empty, key doesn't exist
            if (!table[currentIndex].isOccupied) {
                break;
            }
            
            // If key is found and not already deleted
            if (table[currentIndex].isOccupied && 
                !table[currentIndex].isDeleted && 
                table[currentIndex].key == key) {
                
                table[currentIndex].isDeleted = true;
                count--;
                return true;
            }
            
            i++;
        }
        
        std::cout << "Key " << key << " not found\n";
        return false;
    }
    
    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;
        
        while (i < size) {
            int currentIndex = (index + i) % size;
            
            // If slot is empty, key doesn't exist
            if (!table[currentIndex].isOccupied) {
                break;
            }
            
            // Key found and not deleted
            if (table[currentIndex].isOccupied && 
                !table[currentIndex].isDeleted && 
                table[currentIndex].key == key) {
                
                return true;
            }
            
            i++;
        }
        
        return false;
    }
    
    void display() {
        std::cout << "Hash Table (Linear Probing):\n";
        std::cout << "Index\tKey\tStatus\n";
        for (int i = 0; i < size; i++) {
            std::cout << i << "\t";
            if (table[i].isOccupied && !table[i].isDeleted) {
                std::cout << table[i].key << "\tOccupied\n";
            } else if (table[i].isDeleted) {
                std::cout << "---\tDeleted\n";
            } else {
                std::cout << "---\tEmpty\n";
            }
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
        std::cout << "\n==== Hash Table with Linear Probing ====\n";
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