#include <cstdio>
#include <cstdlib>
#include "2.h"

int main(){
    stack s;
    char* string;
    int choice,size;
    bool running=true;
    while (running){
        printf("\nMENU\n");
        printf("1. Check balance\n2. Exit\n");
        printf("Choose one: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the parenthesis string:");
                scanf(" %s",string);
                size=(int)sizeof(string);
                for (int i=0;i<size;i++){
                    s.push(string[i]);
                }

                if (s.peek()==')'){
                    printf("Balanced.\n");
                    break;
                }
                else{
                    printf("Unbalanced.\n");
                    break;
                }
            
            case 2:
                printf("Exiting...");
                running=false;
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}