#include <stdio.h>
#include <stdlib.h>
struct Node{
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

// Case 1:Deleting the first element from the linked list
struct Node *deletefirst(struct Node *head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// case 2 Deleting the element at a given index from the linked list

struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i = 0;i < index - 1;i++){
        p = p ->next;
        q = q ->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: deleting the last element
struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4: Deleting the elenent with a given value from the linkedl list
struct Node * deleteAnyElement(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p ->next;
        q = q ->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
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

     
     head ->data = 4;
     head ->next = second;

     second ->data = 3;
     second -> next = thrid;

     thrid ->data = 8;
     thrid ->next =  fourth;

     fourth ->data = 1;
     fourth ->next = NULL;
    
    printf("Linked list before daletion\n");
    linkedlisttraversal(head);
    printf("\n");

    // head = deletefirst(head);
    // printf("Linked list after deletion\n");
    // head = deleteAtIndex(head,2);
    // head = deleteAtLast(head);
    head = deleteAnyElement(head,8);
    linkedlisttraversal(head);
    return 0;
}


