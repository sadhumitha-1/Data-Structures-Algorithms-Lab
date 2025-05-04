#include <stdio.h>
#include <stdlib.h>

// Define a structure for a tree node
struct Node {
    char data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert nodes in level order 
void insert(struct Node** root, char data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

// Preorder traversal (Root → Left → Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal (Left → Root → Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal (Left → Right → Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Function to search for a character in the tree (O(n))
int search(struct Node* root, char key) {
    if (root == NULL)
        return 0;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        if (temp->data == key)
            return 1;

        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
    return 0;
}

// Main function - menu-driven program
int main() {
    struct Node* root = NULL;
    int choice;
    char data;
    
    do {
        printf("\nBinary Tree Menu:\n");
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
                printf("Enter character to insert: ");
                scanf(" %c", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter character to search: ");
                scanf(" %c", &data);
                if (search(root, data))
                    printf("Character '%c' found in the tree.\n", data);
                else
                    printf("Character '%c' not found in the tree.\n", data);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
