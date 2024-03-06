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

// Function to print the middle element of the linked list
void printMiddleElement(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Move fast pointer two steps ahead and slow pointer one step ahead
    // When fast pointer reaches the end, slow pointer will be at the middle
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Print the data of the middle element
    printf("Middle element of the linked list: %d\n", slow->data);
}

int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Printing the middle element of the linked list
    printMiddleElement(head);

    return 0;
}
