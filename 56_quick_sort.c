#include <stdio.h>
void print(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int partition(int A[], int low, int high) {
    int temp;
    int pivot = A[low];
    int i = low+1;
    int j = high;
    do{
    while(A[i]<=pivot){
        i++;
    }
    while(A[j]>pivot){
        j--;
    }
    if(i<j){
        temp = A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    }while(i<j);

        temp = A[low];
        A[low]=A[j];
        A[j]=temp;
    return j;
}
void quicksort(int* A, int low, int high){
    int partitionindex; // index of pivot after partition
    if(low<high){
    partitionindex = partition(A,low,high);
    quicksort(A,low,partitionindex-1);//sort left subarray
    quicksort(A,partitionindex+1,high);//sort right subarray
    }
}
int main(){
    int A[]  = {3,5,2,13,12};
    int n =5;
    print(A,n);
    quicksort(A,0,n-1);
    print(A,n);
    return 0;
}