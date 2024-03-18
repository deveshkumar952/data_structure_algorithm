#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data; 
    struct Node*next;
    struct Node*pre;
};

void displayReverse(struct Node*ptr){
    struct Node*last = ptr;
    while(last->next != NULL){
        last = last->next;
    }
    while(last != NULL){
        printf("%d\t", last->data);
        last = last->pre;
    }
}
   
int main(){
    struct Node*first;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;
    
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    
    first->data = 10;
    first->next = second;
    first->pre = NULL;
    second->data = 20;
    second->next = third;
    second->pre =first;
    third->data = 30;
    third->next = fourth;
    third->pre = second;
    fourth->data = 40;
    fourth->next = NULL;
    fourth->pre = third;
    
   
    displayReverse(first);
    return 0;
}