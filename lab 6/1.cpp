//================This program is to implement stack ADT using an array====================================================
#include <cstdio>
#define MAX_SIZE 5

class stack{
    private:
        char arr[MAX_SIZE];
        int top;

    public:
        stack(){
         top=-1;
         printf("constructor");
        }
    
    void push(char ch);
    char pop();
    char peek();

};

int main(){
    stack s;
    char ch;
    int choice;

    while(true){
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
                return 0;

            default:
                printf("Invalid choice!\n");
                
        }
    }
    return 0;
}

void stack::push(char ch){
    if (top==MAX_SIZE-1){
        printf("Stack Overflow!\n");
        return;
    }
    top=top+1;
    arr[top]=ch;
}

char stack::pop(){
    if (top==-1){
        printf("Stack Underflow!\n");
        return ' ';
    }
    return arr[top--];
}

char stack::peek(){
    if (top==-1){
        printf("Stack Underflow!\n");
        return ' ';
    }
    return arr[top];
}

