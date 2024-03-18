#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void traveresal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element %d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


struct Node *sortedLinkedList(struct Node *head){
    struct Node *current= head;
    struct Node *index = NULL;
    int temp;
    while(current!=NULL){
        index = current->next;
        while (index!=NULL){
            if(current->data >index->data){
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index=index->next;
        }
        current=current->next;
        
    }
}
int main(){
    struct Node *head =NULL;
    struct Node *second =NULL;
    struct Node *third =NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = second;
    second->data = 32;
    second->next = third;
    third->data = 45;
    third->next = NULL;
    
    traveresal(head);
    sortedLinkedList(head);
    traveresal(head);
    return 0;
}