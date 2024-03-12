#include <stdio.h>
#include <stdlib.h>

struct Node {
    float coeff;
    int expo;
    struct Node* next;
};

struct Node* insert(struct Node* head,float co , int ex){
    struct Node* temp = NULL;
    struct Node* newP = malloc(sizeof(struct Node));
    newP->coeff = co;
    newP->expo = ex;
    newP->next = NULL;

    if(head == NULL || ex > head->expo){
    newP->next = head;
    head = newP;
    }
    else{
        temp = head;
        while(temp->next != NULL && temp->next->expo>=ex){
            temp = temp->next;
        }
            newP->next = temp->next;
            temp->next = newP;
        }
        return head;
    
}

struct Node* create(struct Node* head){
    int n,i;
    float coeff;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        printf("Enter the coefficient for term %d: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent for term %d: ",i+1);
        scanf("%d",&expo);
        head = insert(head,coeff,expo);
    }
    return head;
}

void print(struct Node* head){
    if(head == NULL){
        printf("No polynomial.");
    }
    else{
        struct Node* temp = head;
        while(temp !=NULL){
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp = temp->next;
            if(temp!=NULL){
            printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}
int main(){
    struct Node* head = NULL;
    printf("Enter the polynomial \n");
    head = create(head);
    print(head);

    return 0;
}