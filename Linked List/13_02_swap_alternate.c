#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swapAlternateData(struct Node* head) {
    struct Node* current = head;

    // Traverse the linked list
    while (current != NULL && current->next != NULL) {
        // Swap data of current node and its next node
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        // Move to the next next node
        current = current->next->next;
    }
}

void linkedListTraversal(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    // Allocate memory for nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printf("Original Linked List: ");
    linkedListTraversal(head);

    // Swap alternate data
    swapAlternateData(head);

    printf("Linked List after Swapping Alternate Data: ");
    linkedListTraversal(head);

    return 0;
}
