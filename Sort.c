#include<stdio.h>
// Function to read an array
int read(int ar[]){
    int n,i;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    return n;
}

// Function to display the elements of an array
void display(int ar[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
}

// Function for binary sort
void bsort(int ar[],int n){
    int i,j,temp;  
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (ar[j] > ar[j+1]){
                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
    printf("\nThe sorted array is: \n");
    display(ar,n);
}

// Function for selection sort
void ssort(int ar[],int n){
    int i,j,imin,temp;  
    for (i = 0; i < n-1; i++){  
        imin = i;  
        for (j = i+1; j < n; j++)  
            if (ar[j] < ar[imin])  
                imin = j;  
        temp = ar[imin];
        ar[imin] = ar[i];
        ar[i] = temp;  
    }
    display(ar,n); 
}

// Function for insertion sort
void isort(int ar[],int n){
    int i, key, j;  
    for (i = 1; i < n; i++){  
        key = ar[i];  
        j = i - 1;  
        while (j >= 0 && ar[j] > key){  
            ar[j + 1] = ar[j];  
            j = j - 1;  
        }  
        ar[j + 1] = key;  
    }
    display(ar,n);  
}  

void main(){
    int ar[20],c,n,op;
    n = read(ar);
    do{
        printf("\n1. Bubble sort \n2. Selection Sort \n3. Insertion Sort \n Enter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1: bsort(ar,n);
            break;
            case 2: ssort(ar,n);
            break;
            case 3: isort(ar,n);
            break;
            default: printf("Enter a valid choice!!");
            break;
        }
        printf("\nDo you want to continue? (1 for yes and 0 for no.): ");
        scanf("%d",&op);
    }while(op == 1);
}