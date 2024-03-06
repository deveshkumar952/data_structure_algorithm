#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swapFirstAndLast(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, no need to swap
        return;
    }

    struct Node* last = head;
    struct Node* secondLast = NULL;

    // Traverse to the last node and keep track of the second last node
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    // Swap data of first and last nodes
    int temp = head->data;
    head->data = last->data;
    last->data = temp;
}

void sortLinkedList(struct Node *head) {
    struct Node* current = head;
    struct Node* index = NULL;
    int temp;

    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
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

    // Allocate memory for nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to nodes
    head->data = 3;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 5;
    third->next = NULL;

    printf("Original Linked List: ");
    linkedListTraversal(head);

    // Swap first and last nodes
    swapFirstAndLast(head);
    printf("Linked List after Swapping First and Last Nodes: ");
    linkedListTraversal(head);

    // Sort the linked list in ascending order
    sortLinkedList(head);
    printf("Linked List after Sorting in Ascending Order: ");
    linkedListTraversal(head);

    return 0;
}
