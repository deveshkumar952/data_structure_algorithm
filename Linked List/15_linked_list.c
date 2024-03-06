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

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
     while (i!=index-1){
        p = p->next;
        i++;
     }
     ptr->data = data;
     ptr->next = p->next;
     p->next = ptr;
     return head;
}

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;
     struct Node * p = head;

     while(p->next!=NULL){
        p = p->next;
     }
     p->next = ptr;
     ptr->next = NULL;
     return head;
}
struct Node * insertAfterNode(struct Node *head,struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;
     return head;
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
     printf("\n");
    //  head = insertAtFirst(head,56);
    //  head = insertAtIndex(head,56,2);
    //  head = insertAtEnd(head,56);
     head = insertAfterNode(head,second,45);
     linkedlisttraversal(head);

    return 0;
}