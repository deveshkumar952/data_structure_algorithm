#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createList(struct Node* tail){
    int i,n,data;
    printf("Enter the number of nodes of the linked list: ");
    scanf("%d",&data);
    tail = addToEmpty(data);

    for(i = 1;i<n;i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d", &data);
        tail = addAtEnd(tail,data);
    }
    return tail;
}
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

struct Node *addAtEnd(struct Node *tail,int data){
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
    return tail;

}

struct Node *addAfterPos(struct Node* tail,int data, int pos){
    struct Node *p = tail->next;
    struct Node *newP = malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = NULL;
    while(pos>1){
        p = p->next;
        pos--;
    }
    newP->next = p->next;
    p->next = newP;
    if(p == tail){
        tail = tail->next;

    }
    return tail;
}
struct Node* delFirst(struct Node* tail){
    if(tail == NULL){
    return tail;
}
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    struct Node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}
struct Node* delLast(struct Node* tail){
    if(tail == NULL)
    return tail;
    struct Node* temp = tail->next;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    while(temp->next!=tail){
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}

struct Node* deInter(struct Node* tail,int pos){
    if(tail == NULL)
    return tail;
    struct Node* temp = tail->next;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    while(pos > 2){
        temp = temp->next;
        pos--;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    if(temp2 == tail)
        tail = temp;
        free(temp2);
        temp2 = NULL;
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
    tail = addAtBeg(tail,4);
    print(tail);

    tail =addAtEnd(tail,99);
    printf("\n");
    print(tail);

    tail = addAfterPos(tail,11,3);
    printf("\n");
    print(tail);

    printf("\n");
    tail = delFirst(tail);
    print(tail);

    printf("\n");
    tail = delLast(tail);
    print(tail);

    printf("\n");
    tail = deInter(tail, 2);
    print(tail);
    return 0;
}