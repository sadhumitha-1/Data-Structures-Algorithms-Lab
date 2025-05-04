#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "2.h"

// Function to process the string according to the given rules
void processString(char* input) {
    stack charStack;  // Using the stack class from 2.h
    int len = strlen(input);
    
    // Process each character in the input
    for (int i = 0; i < len; i++) {
        if (input[i] == '+') {
            // When '+' is encountered, remove the top character if stack is not empty
            if (!charStack.isEmpty()) {
                charStack.pop();
            }
        } else {
            // Otherwise, push the character onto the stack
            charStack.push(input[i]);
        }
    }
    
    // Now we need to reverse the stack to get characters in the right order
    // Create temporary stacks for reversing
    stack tempStack;
    
    // First, count how many elements are in the stack and transfer to tempStack
    int count = 0;
    while (!charStack.isEmpty()) {
        char ch = charStack.pop();
        tempStack.push(ch);
        count++;
    }
    
    // Create a buffer for the result using dynamic allocation
    char* result = (char*)malloc((count + 1) * sizeof(char));  // +1 for null terminator
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Pop from tempStack to get characters in the correct order
    for (int i = 0; i < count; i++) {
        result[i] = tempStack.pop();
    }
    
    // Add null terminator
    result[count] = '\0';
    
    // Copy result back to input
    strcpy(input, result);
    
    // Free the dynamically allocated memory
    free(result);
}

int main() {
    char input[100];  // Assuming maximum input length of 100
    
    printf("Enter the string: ");
    scanf("%s", input);
    
    processString(input);
    
    printf("Output: %s\n", input);
    
    return 0;
}