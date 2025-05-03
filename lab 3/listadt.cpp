#include <cstdio>
#define MAX_SIZE 5

class List{
private:
    int arr[MAX_SIZE];
    int size=0;

public:
    
    void Insert_end(int value){
        if (size>=MAX_SIZE){
            printf("List is full\n");
            return;
        }
        arr[size]=value;
        size++;
    }

    void Insert_begin(int value){
        if (size>=MAX_SIZE){
            printf("List is full\n");
            return;}
        for (int i=size;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=value;
        size++;
    }

    void Insert_pos(int value,int pos){
        if (size>=MAX_SIZE){
            printf("List is full\n");
            return;}
        if (pos<0 || pos>MAX_SIZE){
            printf("Invalid index\n");
            return;
        }    
        for (int i=size;i>pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=value;
        size++;
    }
    
    int Delete_end(){
        if (size==0){
            printf("Empty list\n");
            return -1;
        }
        size--;
        return arr[size];
    }

    int Delete_begin(){
        int temp;
        if (size==0){
            printf("Empty list\n");
            return -1;
        }
        for (int i=0;i<size-1;i++){
            if (i==0){
                temp=arr[i];
            }
            arr[i]=arr[i+1];
        }
        size--;
        return temp;
    }

    int Delete_pos(int pos){
        int temp;
        if (size==0){
            printf("Empty list\n");
            return -1;
        }
        if (pos<0 || pos>MAX_SIZE){
            printf("Invalid index\n");
            return -1;
        }    
        for (int i=pos;i<size-1;i++){
            if (i==pos){
                temp=arr[i];
            }
            arr[i]=arr[i+1];
        }
        size--;
        return temp;
    }

    void Display(){
        if (size==0){
            printf("Empty list\n");
            return;
        }
        printf("List: ");
        for (int i=0;i<size;i++){
            printf("%d",arr[i]);
        }
    }

    void Search(int value){
        if (size==0){
            printf("Empty list\n");
            return;
        }
        for(int i=0;i<size;i++){
            if (arr[i]==value){
                printf("Element is found at %d index",i);
                return;
            }
        }
        printf("Element not found\n");
    }

    void Rotate(int k){
        if (size==0){
            printf("Empty list\n");
            return;
        }
        k=k%size;
        int temp_arr[MAX_SIZE];
        for (int i=0;i<size;i++){
            temp_arr[(i+k)%size]=arr[i];
        }
        for (int i=0;i<size;i++){
            arr[i]=temp_arr[i];
        }
    }

};

int main(void){
    List list;
    int choice,value,pos,k,retn;
    int arr[MAX_SIZE];

    do{
        printf("\nMENU\n");
        printf("1. Insert at the end\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at the end\n");
        printf("5. Delete at the beginning\n");
        printf("6. Delete at a position\n");
        printf("7. Display the array\n");
        printf("8. Search for an element\n");
        printf("9. Rotate the array by k times\n");
        printf("10. Exit\n");

        printf("Your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            list.Insert_end(value);
            break;
        
            case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            list.Insert_begin(value);
            break;

            case 3:
            printf("Enter the value and position to be inserted: ");
            scanf("%d %d",&value,&pos);
            list.Insert_pos(value,pos);
            break;

            case 4:
            retn=list.Delete_end();
            if (retn!=-1){
            printf("Deleted element is: %d",retn);}
            break;

            case 5:
            retn=list.Delete_begin();
            if (retn!=-1){
            printf("Deleted element is: %d",retn);}
            break;

            case 6:
            printf("Enter the position:");
            scanf("%d",&pos);
            retn=list.Delete_pos(pos);
            if (retn!=-1){
            printf("Deleted element is: %d",retn);}
            break;

            case 7:
            list.Display();
            break;

            case 8:
            printf("Enter the value to be searched for: ");
            scanf("%d",&value);
            list.Search(value);
            break;

            case 9:
            printf("Enter the k value by which the array is to be rotated: ");
            scanf("%d",&k);
            list.Rotate(k);
            break;
            
            case 10:
            printf("Exiting the program...");
            break;

            default:
            if (choice!=10){
                printf("Invalid choice!\n");
                break;
            }
        }
    }while (choice!=10);    
    
    return 0;
}