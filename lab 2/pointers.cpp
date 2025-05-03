#include <cstdio>
#include <cmath>
#include <cstdlib>

//Palindrome func def
bool isPalindrome(int* num) {
    int* rev = (int*)calloc(1, sizeof(int));
    int temp = *num;
    
    while (temp > 0) {
        *rev = (*rev * 10) + (temp % 10);
        temp /= 10;
    }
    
    bool result = *rev == *num;
    free(rev);
    return result;
}

//Armstrong no func def
bool isArmstrong(int* num) {
    int* sum = (int*)calloc(1, sizeof(int));
    int* digits = (int*)calloc(1, sizeof(int));  
    int temp = *num;
    
    // Count digits
    int n = temp;
    while (n > 0) {
        (*digits)++;
        n /= 10;
    }
    
    temp = *num;  
    while (temp > 0) {
        *sum += pow(temp % 10, *digits);
        temp /= 10;
    }
    
    bool result = *sum == *num;
    free(sum);
    free(digits);  
    return result;
}

//Perfect no func def
bool isPerfect(int* num) {
    int* sum = (int*)calloc(1, sizeof(int));
    int* ip = (int*)malloc(sizeof(int));  
    
    for (*ip = 1; *ip <= *num/2; (*ip)++) {
        if (*num % (*ip) == 0) {
            *sum += *ip;
        }
    }
    
    bool result = *sum == *num;
    free(sum);
    free(ip);  
    return result;
}

int main() {
    char* choice = (char*)malloc(sizeof(char));
    int* num = (int*)malloc(sizeof(int));
    
    do {
        printf("\nMENU:\n");
        printf("a. Palindrome\nb. Armstrong Number\nc. Perfect Number\nd. Exit\n");
        printf("Enter your choice (a-d): ");
        scanf(" %c", choice);
        
        if (*choice != 'd') {
            printf("Enter a number: ");
            scanf("%d", num);
            
            switch (*choice) {
                case 'a':
                    printf("%d is%s a Palindrome number\n", *num, isPalindrome(num) ? "" : " not");
                    break;
                case 'b':
                    printf("%d is%s an Armstrong number\n", *num, isArmstrong(num) ? "" : " not");
                    break;
                case 'c':
                    printf("%d is%s a Perfect number\n", *num, isPerfect(num) ? "" : " not");
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    } while (*choice != 'd');
    
    free(choice);
    free(num);
    return 0;
}