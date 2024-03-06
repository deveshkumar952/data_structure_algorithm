#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
}

// Function to convert a singly linked list into a circular linked list
void convertToCircular(struct Node** head) {
    if (*head == NULL) {
        // If the list is empty, no need to convert
        return;
    }

    struct Node* temp = *head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Make the last node point to the head, closing the loop
    temp->next = *head;
}

// Function to print the circular linked list
void printCircularLinkedList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        // If the list is empty, nothing to print
        return;
    }

    // Traverse the circular linked list and print until we reach back to the head
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Convert the singly linked list into a circular linked list
    convertToCircular(&head);

    // Printing the circular linked list
    printf("Circular Linked List: ");
    printCircularLinkedList(head);

    return 0;
}
