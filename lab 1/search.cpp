//This program is to implement linear and binary search
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include "sort_headers.h"

int linear_search(int ar[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (ar[i] == target) {
            return i;
        }
    }
    printf("Not found\n");
    return -1;
}

int binary_search(int ar[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ar[mid] == target) {
            return mid;
        }
        if (ar[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    printf("Not found\n");
    return -1;
}

int main(void) {
    int choice;
    int size;
    int target;
    int* ar = NULL;
    
    printf("MENU\n");
    printf("Choose one among the below.\n");
    printf("1 - Linear Search\n");
    printf("2 - Binary Search\n");
    printf("3 - Exit\n");

    while (1) {
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1 || choice == 2) {
            printf("Enter the array size: ");
            scanf("%d", &size);
            
            if (ar != NULL) {
                free(ar);
            }
            
            ar = (int*)malloc(size * sizeof(int));
            if (ar == NULL) {
                printf("Memory allocation failed\n");
                continue;
            }
            
            for (int i = 0; i < size; i++) {
                printf("Enter the array element: ");
                scanf("%d", &ar[i]);
            }
            
            insertion_sort(ar, size);
            
            printf("Which element do you wish to find? ");
            scanf("%d", &target);
            
            int result_index;
            
            if (choice == 1) {
                result_index = linear_search(ar, size, target);
            } else {
                result_index = binary_search(ar, size, target);
            }
            
            if (result_index != -1) {
                printf("The element is at index %d\n", result_index);
            }
        }
        else if (choice == 3) {
            printf("Exiting the program...\n");
            if (ar != NULL) {
                free(ar);
            }
            return 0;
        }
        else {
            printf("Invalid input\n");
        }
    }
}