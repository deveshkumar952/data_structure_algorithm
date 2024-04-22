#include <stdio.h>
void print(int *A, int n){
    for(int i =0 ;i < n-1 ; i++){
        printf("%d  ",A[i]);
    }
    printf("\n");;
}

void insertionsort(int *A,int n){
    int key,j;
    for(int i = 1;i<n-1;i++){
        key = A[i];
        j = i-1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int A[] = {12,54,65,7,23,9};
    int n = 6;
    print(A,n);
    insertionsort(A,n);
    print(A,n);
    return 0;
}