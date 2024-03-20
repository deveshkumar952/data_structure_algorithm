#include <stdio.h>
void print(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void selction(int *A,int n){
    printf("the selction sort is running...");
    int temp,indexofmin;
    for(int i=0;i<n-1;i++){
        indexofmin = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[indexofmin]){
                indexofmin = j;
        }
    }
    //swap A[i] and A[indexofmin] 
    temp = A[i];
    A[i]=A[indexofmin];
    A[indexofmin]=temp;
}}
int main(){
    int A[] = {8,45,7,2,11};
    int n = 5;
    print(A,n);
    selction(A,n);
        print(A,n);

    return 0;
}