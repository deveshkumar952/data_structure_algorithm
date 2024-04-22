#include <stdio.h>
int linerarSearch(int arr[],int size, int element){
    for (int i = 0;i < size;i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int size,int element){
    int low, mid , high;
    high  = size - 1;
    low = 0;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }}
        return -1;
    }
int main(){
//unsorted array for linerar search
    // int arr[] = {1,3,5,56,4,3,23,5,4,45634,56,34};
    // int size = sizeof(arr)/sizeof(int);

    int arr[] = {1,3,5,56,64,73,123,225,400};
    int size = sizeof(arr)/sizeof(int);
    // int element = 5;
    // int searchIndex = binarySearch(arr,size,element);
    int element = 5;
    int searchIndex = linerarSearch(arr,size,element);

    printf("The element %d was found at index %d \n",element,searchIndex);
    return 0;
}