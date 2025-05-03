void bubble_sort(int ar[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if (ar[j]>ar[j+1]){
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }

}

//Insertion sort's function defn
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