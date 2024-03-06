#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    float coff;
    int expo;
    struct node *link;
};

struct node * insert(struct node *head, float co, int ex) {
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));
    newP->coff = co;
    newP->expo = ex;
    newP->link = NULL;

    if (head == NULL || ex > head->expo) {
        temp = head;
        head = newP;
    }
    else {
        temp = head;
        while (temp->link != NULL && temp->link->expo == ex)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }

    return head;
}

struct node * create(struct node *head) {
    int n, i;
    float coff;
    int expo;

    printf("enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coff);
        printf("enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coff, expo);
    }
    return head;
}

void print(struct node *head) {
    if (head == NULL)
        printf("NO POLYNOMIAL\n");
    else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("(%.1fx^%d)", temp->coff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

int main() {
    struct node *head = NULL;
    printf("enter the polynomial\n");
    head = create(head);
    print(head);
    return 0;
}