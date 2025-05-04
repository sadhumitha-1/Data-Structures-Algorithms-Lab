//====================This is program is to implement a list ADT using a doulbly linked list=====================

#include<cstdio>
#include <cstdlib>

class List{
private:
    struct Node{
        int data;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;

public:
    List(){
        size=0;
        head=nullptr;
        tail=nullptr;
    }

    void InsertBegin(int value);
    void InsertEnd(int value);
    void InsertPos(int value,int pos);
    int DeleteBegin();
    int DeleteEnd();
    int DeletePos(int pos);
    int Search(int value);
    void Display();

    ~List(){
        while (head!=nullptr){
            Node* temp=head;
            head=head->next;
            free(temp);
        }
    }

};


int main(void){
    int choice,value,pos,temp;
    List LL;

    while (1){
        //========================Menu=================================================
        printf("\nMENU\n");
        printf("1. Insert at the beginning\n2.Insert at the end\n3.Insert at a position\n");
        printf("4. Delete at the beginning\n5. Delete at the end\n6.Delete at a position\n");
        printf("7.Search\n8. Display \n9. Exit\n");
        printf("Choose one: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter value: ");
            scanf("%d",&value);
            LL.InsertBegin(value);
            break;

            case 2:
            printf("Enter value: ");
            scanf("%d",&value);
            LL.InsertEnd(value);
            break;

            case 3:
            printf("Enter value and position: ");
            scanf("%d %d",&value,&pos);
            LL.InsertPos(value,pos);
            break;

            case 4:
            temp=LL.DeleteBegin();
            if (temp!=-1){
                printf("Deleted element is %d\n",temp);
            }
            break;

            case 5:
            temp=LL.DeleteEnd();
            if (temp!=-1){
                printf("Deleted element is %d\n",temp);
            }
            break;

            case 6:
            printf("Enter position: ");
            scanf("%d",&pos);
            temp=LL.DeletePos(pos);
            if (temp!=-1){
                printf("Deleted element is %d\n",temp);
            }
            break;

            case 7:
            printf("Enter value: ");
            scanf("%d",&value);
            temp=LL.Search(value);
            if (temp!=-1){
                printf("The element is at position %d",temp);
            }
            break;

            case 8:
            LL.Display();
            break;

            case 9:
            printf("Exiting...");
            return 0;

            default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}

//==============Function to insert an element at the beginning of the list=========================
void List::InsertBegin(int value){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->prev=nullptr;
    newnode->next=nullptr;

    if (head==nullptr){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    size++;
}

//==============Function to insert an element at the end of the list================================
void List::InsertEnd(int value){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->prev=nullptr;
    newnode->next=nullptr;

    if (tail==nullptr){
        tail=head=newnode;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
    size++;
}

//==============Function to insert an element at a positon in the list===============================
void List::InsertPos(int value,int pos){
    if (pos<1 || pos>size+1){
        printf("Invalid Position");
        return;
    }

    if (pos==1){
        InsertBegin(value);
        return;
    }

    if (pos==size+1){
        InsertEnd(value);
        return;
    }

    Node* current=head;
    for (int i=1;i<pos-1;i++){
        current=current->next;
    }
    
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->prev=current;
    newnode->next=current->next;
    current->next->prev=newnode;
    current->next=newnode;

    size++;
}

//==============Function to delete an element at the beginning of the list=========================
int List::DeleteBegin(){
    if (head==nullptr){
        printf("Empty List!\n");
        return -1;
    }
    Node* temp=head;
    int del=head->data;
    head=head->next;
    head->prev=nullptr;
    free(temp);
    size--;
    return del;
}

//==============Function to delete an element at the end of the list=========================
int List::DeleteEnd(){
    if (tail==nullptr){
        printf("Empty List!\n");
        return -1;
    }
    Node* temp=tail;
    int del=tail->data;
    tail=tail->prev;
    tail->next=nullptr;
    free(temp);
    size--;
    return del;
}

//==============Function to delete an element at a positon in the list===============================
int List::DeletePos(int pos){
    if (pos<1 || pos>size){
        printf("Invalid Position");
        return -1;
    }

    if (pos==1){
        return DeleteBegin();
    }

    if (pos==size){
        return DeleteEnd();
    }

    Node* current=head;
    for (int i=1;i<pos;i++){
        current=current->next;
    }
    
    int del=current->data;
    current->prev->next=current->next;
    current->next->prev=current->prev;
    size--;
    free(current);
    return del;

}

//==============Function to search for an element in the list=================================================
int List::Search(int value){
    if (head==nullptr){
        printf("Empty List!\n");
        return -1;
    }
    else{
        Node* current=head;
        int pos=1;
        while (current!=nullptr){
            if (current->data==value){
                return pos;
            }
            current=current->next;
            pos++;
        }
        printf("Element not found!\n");
        return -1;
    }
}

//==============Function to display the whole list and its reverse=================================================
void List::Display(){
    if (head==nullptr){
        printf("Empty List!\n");
    }
    else{
        Node* current=head;
        while (current!=nullptr){
            printf("%d ",current->data);
            current=current->next;
        }
        printf("\n");

        current=tail;
        while (current!=nullptr){
            printf("%d ",current->data);
            current=current->prev;
        }
        printf("\n");
    }
}