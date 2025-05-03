#include <cstdio>
#include "list.h"

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert List1\n");
    printf("2. Insert List2\n");
    printf("3. Merge into List3\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    List list1, list2, list3;
    int choice, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List1: ");
                scanf("%d", &value);
                list1.insertAscending(value);
                printf("List1: ");
                list1.display();
                break;

            case 2:
                printf("Enter value to insert in List2: ");
                scanf("%d", &value);
                list2.insertAscending(value);
                printf("List2: ");
                list2.display();
                break;

            case 3:
                list3 = List::merge(list1, list2);
                printf("Merged List3: ");
                list3.display();
                break;

            case 4:
                printf("List1: ");
                list1.display();
                printf("List2: ");
                list2.display();
                printf("List3: ");
                list3.display();
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}