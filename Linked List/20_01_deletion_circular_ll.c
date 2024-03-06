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

struct Node *deletionofvalue(struct Node* head, int value){
    struct Node *p= head;
    struct Node *q= head-> next;
    while(q->data != value){
        q=q->next;
        p=p->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
        return head;
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
     head = deletionofvalue(head,66);
      linkedlisttraversal(head);
    return 0;
}