#include <cstdio>
#include <cstdlib>

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

        ~stack(){
            while (top!=nullptr){
                node* temp=top;
                top=top->next;
                free(temp);
            }
        }
};

int main(){
    stack s;
    char ch;
    int choice;
    bool running=true;

    while(running){
        printf("\nMENU\n");
        printf("1. Push\n2. Pop\n3. Peek\n4.Exit\n");
        printf("Choose one: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf(" %c",&ch);
                s.push(ch);
                break;
            
            case 2:
                ch=s.pop();
                if (ch!=' '){
                    printf("Deleted element is %c",ch);
                }
                printf("\n");
                break;

            case 3:
                ch=s.peek();
                if (ch!=' '){
                    printf("The top element is %c",ch);
                }
                printf("\n");
                break;

            case 4:
                printf("Exiting...");
                running=false;
                break;

            default:
                printf("Invalid choice!\n");
                
        }
    }
    return 0;
}

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