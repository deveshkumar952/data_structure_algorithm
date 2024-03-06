#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *head)
{struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("element:%d\n",ptr -> data);
        ptr = ptr ->next;
        if(ptr==head){
            break;
        }
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *thrid;
    struct Node *fourth;
    head = (struct Node *) malloc(sizeof(struct Node));
    second= (struct Node *) malloc(sizeof(struct Node));
    thrid = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
     
     head ->data = 7;
     head ->next = second;

     second ->data = 11;
     second -> next = thrid;

     thrid ->data =66;
     thrid ->next =  fourth;

     fourth ->data = 1;
     fourth ->next = head;

     linkedlisttraversal(head);
    return 0;
}