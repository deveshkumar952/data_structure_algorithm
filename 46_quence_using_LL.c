#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
        struct Node *next;
};

    struct Node *f = NULL;
    struct Node *r = NULL;

void linkedlisttraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("element:%d\n",ptr -> data);
        ptr = ptr ->next;
    }
}

void enqueue( int val){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f = r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}

int dequeue(){
    int val=-1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
    }
int main(){

    // linkedlisttraversal(f);
    // printf("Dequeuing elemnet %d\n" , dequeue());
    enqueue(56);
    enqueue(5);
    enqueue(6);
    // enqueue(4);
    linkedlisttraversal(f);
    printf("Dequeuing elemnet %d\n" , dequeue());
    linkedlisttraversal(f);


    return 0;
}