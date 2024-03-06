#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedlisttraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("element:%d\n",ptr -> data);
        ptr = ptr ->next;
    }
}


int isEmpty(struct Node* top){
    if (top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node* top,int x){
    if(isFull(top)){
        printf("Stack overflow\n");
    }
    else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node* top,int pos){
    struct Node* ptr = top;
    for(int i = 0;(i<pos-1 && ptr!=NULL);i++){
        ptr = ptr->next;
    }
    if(ptr!= NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int main(){
    struct Node* top = NULL;
    top = push(top,79);
    top = push(top,18);
    top = push(top,8);
    // int element = pop(&top);
    // printf("popped element is %d\n",element);
    linkedlisttraversal(top);
    for(int i = 0;i<3;i++){
    printf("Value at position %d is : %d\n",i,peek(top,i+1));
    }
    return 0;
}