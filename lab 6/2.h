#ifndef STACK_H
#define STACK_H
class stack{
    private:
        struct node{
            char data;
            node* next;
        }*top;

    public:
        stack(){
            top=nullptr;
        }

        void push(char ch);
        char pop();
        char peek();
        bool isEmpty() {
            return top == nullptr;
        }

        ~stack(){
            while (top!=nullptr){
                node* temp=top;
                top=top->next;
                free(temp);
            }
        }
};

void stack::push(char ch){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=ch;
    newnode->next=top;
    top=newnode;
}

char stack::pop(){
    if (top==nullptr){
        printf("Stack Underflow!\n");
        return ' ';
    }
    char temp=top->data;
    top=top->next;
    return temp;
}

char stack::peek(){
    if (top==nullptr){
        printf("Stack Underflow!\n");
        return ' ';
    }
    return top->data;
}

#endif