//This program is to implement bubble sort, insertion sort and selection sort
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>

int size;

//bubble sort's function def
void bubble_sort(int ar[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1-i;j++){
            if (ar[j]>ar[j+1]){
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
}

//Insertion sort's function def
void insertion_sort(int ar[],int size){
    for (int i=1;i<size;i++){
        int key=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>key){
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=key;
    }
}

//Selection sort's function defn
void selection_sort(int ar[],int size){
    for(int i=0;i<size-1;i++){
        int min_idx=i;
        for (int j=i+1;j<size;j++){
            if (ar[j]<ar[min_idx]){
                min_idx=j;
            }
        }
        int temp=ar[i];
        ar[i]=ar[min_idx];
        ar[min_idx]=temp;
    }
}

void Input_array(int** ar){
    printf("Enter the array size:");
    scanf("%d",&size);
    
    // Free previous array if it exists
    if (*ar != NULL) {
        free(*ar);
    }
    
    // Allocate memory for the array
    *ar = (int*)malloc(size * sizeof(int));
    if (*ar == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    for (int i=0;i<size;i++){
        printf("Enter the array element:");
        scanf("%d",&(*ar)[i]);
    }
}

int main(void){
    int choice;
    int* ar = NULL; // Will allocate memory dynamically

    printf("MENU\n");
    printf("Choose one among the below.\n");
    printf("1 - Bubble sort\n");
    printf("2 - Insertion sort\n");
    printf("3 - Selection sort\n");
    printf("4 - Exit\n");
    
    while (1){
        printf("Your choice:");
        scanf("%d",&choice);
        
        switch (choice){
            case 1:
                Input_array(&ar);
                bubble_sort(ar,size);
                printf("The sorted array is:");
                for (int i=0;i<size;i++){
                    printf("%d ",ar[i]);
                }
                printf("\n");
                break;
                
            case 2:
                Input_array(&ar);
                insertion_sort(ar,size);
                printf("The sorted array is:");
                for (int i=0;i<size;i++){
                    printf("%d ",ar[i]);
                }
                printf("\n");
                break;
                
            case 3:
                Input_array(&ar);
                selection_sort(ar,size);
                printf("The sorted array is:");
                for(int i=0;i<size;i++){
                    printf("%d ",ar[i]);
                }
                printf("\n");
                break;
            
            case 4:
                if (ar != NULL) {
                    free(ar);
                }
                printf("Exiting the program...");
                return 0;
                break;
                
            default:
                printf("Invalid choice. Try again.");
        }
    }
}