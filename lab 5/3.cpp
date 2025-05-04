//===========This program is to implement the round-robin scheduling algorithm using the circular linked list=====
#include "cll.h"
#include <cstdio>

int fixedtime; // Fixed time slot for round-robin execution

int main() {
    List processQueue;
    int choice, time;
    
    printf("Enter the fixed time for the processes: ");
    scanf("%d", &fixedtime);
    
    while (1) {
        printf("\n1. Insert Process\n2. Execute\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter process execution time: ");
                scanf("%d", &time);
                processQueue.insertEnd(time);
                break;
            
            case 2:
                if (processQueue.search(-1) == -1) { // Check if the queue is empty
                    printf("No processes in the queue!\n");
                    break;
                }
                
                time = processQueue.deleteBeginning();
                time -= fixedtime;
                
                if (time > 0) {
                    printf("Process needs more time, re-inserting with remaining time: %d\n", time);
                    processQueue.insertEnd(time);
                } else {
                    printf("Process completed execution.\n");
                }
                break;
            
            case 3:
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    
    return 0;
}
