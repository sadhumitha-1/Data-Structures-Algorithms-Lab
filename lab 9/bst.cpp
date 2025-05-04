#include <cstdio>
#include <cstdlib>

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Recursive destructor method
    void destroyTree(Node* node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    Node* insertRecursive(Node* node, int value) {
        // If tree is empty, create new node
        if (node == nullptr) {
            printf("Inserted %d successfully!\n", value);
            return new Node(value);
        }

        // Recursive insertion based on BST property
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        } else {
            printf("Value %d already exists in the tree!\n", value);
        }

        return node;
    }

    void preorder() {
        printf("Preorder Traversal: ");
        preorderRecursive(root);
        printf("\n");
    }

    void preorderRecursive(Node* node) {
        if (node == nullptr) return;
        printf("%d ", node->data);
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    void inorder() {
        printf("Inorder Traversal: ");
        inorderRecursive(root);
        printf("\n");
    }

    void inorderRecursive(Node* node) {
        if (node == nullptr) return;
        inorderRecursive(node->left);
        printf("%d ", node->data);
        inorderRecursive(node->right);
    }

    void postorder() {
        printf("Postorder Traversal: ");
        postorderRecursive(root);
        printf("\n");
    }

    void postorderRecursive(Node* node) {
        if (node == nullptr) return;
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        printf("%d ", node->data);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    bool searchRecursive(Node* node, int value) {
        // Base cases
        if (node == nullptr) {
            printf("%d not found in the tree!\n", value);
            return false;
        }
        
        // If value found
        if (node->data == value) {
            printf("%d found in the tree!\n", value);
            return true;
        }

        // Recursive search in left or right subtree
        if (value < node->data) 
            return searchRecursive(node->left, value);
        else 
            return searchRecursive(node->right, value);
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    while (true) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                bst.insert(value);
                break;

            case 2:
                bst.preorder();
                break;

            case 3:
                bst.inorder();
                break;

            case 4:
                bst.postorder();
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                bst.search(value);
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}