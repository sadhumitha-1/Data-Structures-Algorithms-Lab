//=====This program is to convert infix expression to postfix and postfix evaluation using stack.=======
#include <cstdio>
#include <cstdlib>
#include "2.h"

#define MAX_SIZE 100

struct Expression {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
};

//====This function is to get the precedence of the operator.====
int precedence(char op) {
    switch (op) {
        case '=': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        default: return 0;
    }
}

//====This function is to check if the character is an operator or not.====
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=';
}

//====This function is to convert infix expression to postfix expression.====
void infixToPostfix(Expression &exp) {
    stack s;
    int k = 0;
    for (int i = 0; exp.infix[i] != '\0'; i++) {
        char c = exp.infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            exp.postfix[k++] = c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                exp.postfix[k++] = s.peek();
                s.pop();
            }
            s.pop();
        } else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                exp.postfix[k++] = s.peek();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        exp.postfix[k++] = s.peek();
        s.pop();
    }
    exp.postfix[k] = '\0';
}

//====This function is to evaluate the postfix expression.====
int evaluatePostfix(Expression &exp) {
    stack s;
    for (int i = 0; exp.postfix[i] != '\0'; i++) {
        char c = exp.postfix[i];
        if ((c >= '0' && c <= '9')) {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int b = s.peek(); s.pop();
            int a = s.peek(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.peek();
}

int main() {
    Expression exp;
    int choice;
    bool running = true;
    while (running) {
        printf("\nMENU\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\nChoose one: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a valid infix expression: ");
                scanf("%s", exp.infix);
                break;
            case 2:
                infixToPostfix(exp);
                printf("Postfix Expression: %s\n", exp.postfix);
                break;
            case 3:
                printf("Postfix Evaluation Result: %d\n", evaluatePostfix(exp));
                break;
            case 4:
                printf("Exiting...\n");
                running = false;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
