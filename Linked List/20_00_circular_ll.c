#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct Node *insertAtFirst(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    
    while(p->next !=head){
        p = p->next;
    }
    //At this point  p poionts to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
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

     fourth ->data =6;
     fourth ->next =  head;

     linkedlisttraversal(head);
     printf("\n");
     head = insertAtFirst(head,80);
     linkedlisttraversal(head);
    return 0;
}