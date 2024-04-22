#include <stdio.h>
void print(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void bubblesort(int *A,int n){
    printf("Sorted array using Bubble Sort:\n");
    int temp;
    int issorted = 0;
    for(int i = 0;i<n-1;i++){
        printf("Working on pass number %d\n",i+1);
        issorted = 1;
         for (int j = 0; j < n - 1 - i; j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j]=A[j+1];
                A[j+1] = temp;
                issorted = 0;
            }
            if(issorted){
                return ;
            }
        }
    }
  
}

int main(){
    int A[] = {54,9,1,7,3,416,653};
    // int A[]={1,2,3,4,5,6,};
    int n =  sizeof(A)/sizeof(A[0]);
    printf("original Array");
    print(A,n);
    bubblesort(A,n);
      print(A,n);
    return 0;
}