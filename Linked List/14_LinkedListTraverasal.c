#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("element:%d\n",ptr -> data);
        ptr = ptr ->next;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *thrid;
    head = (struct Node *) malloc(sizeof(struct Node));
    second= (struct Node *) malloc(sizeof(struct Node));
    thrid = (struct Node *) malloc(sizeof(struct Node));
     
     head ->data = 7;
     head ->next = second;

     second ->data = 11;
     second -> next = thrid;

     thrid ->data =66;
     thrid ->next =  NULL;

     linkedlisttraversal(head);
    return 0;
}