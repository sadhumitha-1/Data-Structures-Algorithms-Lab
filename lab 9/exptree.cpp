//This program implements an expression tree using a postfix expression and a binary search tree (BST) for integer values.
#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include "bst.h"  

using namespace std;

class ExpressionTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;

        Node(char value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    ExpressionTree() : root(nullptr) {}

    Node* constructTree(const char* postfix) {
        stack<Node*> st;
        for (int i = 0; i < strlen(postfix); i++) {
            char ch = postfix[i];
            if (isalnum(ch)) {
                st.push(new Node(ch));
            } else {
                Node* node = new Node(ch);
                node->right = st.top(); st.pop();
                node->left = st.top(); st.pop();
                st.push(node);
            }
        }
        root = st.top();
        return root;
    }

    void preorder(Node* node) {
        if (!node) return;
        printf("%c ", node->data);
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        printf("%c ", node->data);
    }

    void printPreorder() {
        printf("Preorder Traversal: ");
        preorder(root);
        printf("\n");
    }

    void printInorder() {
        printf("Inorder Traversal: ");
        inorder(root);
        printf("\n");
    }

    void printPostorder() {
        printf("Postorder Traversal: ");
        postorder(root);
        printf("\n");
    }
};

int main() {
    ExpressionTree expTree;
    BinarySearchTree bst; // Using BST from bst.h
    char postfix[100];
    int choice, value;

    while (true) {
        printf("\n--- Expression Tree & BST Operations ---\n");
        printf("1. Postfix Expression\n");
        printf("2. Construct Expression Tree\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Insert into BST\n");
        printf("7. BST Inorder Traversal\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                break;

            case 2:
                expTree.constructTree(postfix);
                printf("Expression tree constructed successfully!\n");
                break;

            case 3:
                expTree.printPreorder();
                break;

            case 4:
                expTree.printInorder();
                break;

            case 5:
                expTree.printPostorder();
                break;

            case 6:
                printf("Enter value to insert into BST: ");
                scanf("%d", &value);
                bst.insert(value);
                break;

            case 7:
                bst.inorder();
                break;

            case 8:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
