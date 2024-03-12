
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* addToEmpty(int data){
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct Node* addAtBeg(struct Node* tail,int data){
    struct Node* newP = malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    return tail;
}
void print(struct Node* tail){
    struct Node* p = tail->next;
    do{
        printf("%d ",p->data);
        p = p->next;
        }while(p!=tail->next);
            
}

int main(){
    struct Node* tail;
    tail = addToEmpty(45);
    tail = addAtBeg(tail,34);
    print(tail);
    return 0;
}