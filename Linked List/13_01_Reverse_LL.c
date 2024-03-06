#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while(ptr != NULL) {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prevNode = NULL;
    struct Node *currentNode = head;
    struct Node *nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next; // Store next node
        currentNode->next = prevNode; // Reverse current node's pointer

        // Move pointers one position ahead
        prevNode = currentNode;
        currentNode = nextNode;
    }
    // PrevNode is the new head of the reversed linked list
    return prevNode;
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = NULL;

    printf("Original Linked List:\n");
    linkedListTraversal(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("\nReversed Linked List:\n");
    linkedListTraversal(head);

    return 0;
}
