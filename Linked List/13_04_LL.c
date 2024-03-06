#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;
    newNode->next = newNode; // Points to itself initially

    if (*head == NULL) {
        // If the list is empty, make the new node the head and point to itself
        *head = newNode;
        return;
    }

    // Traverse to the last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->next = *head;
}

// Function to print only the quadrant elements of the circular linked list
void printQuadrantElements(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    struct Node* temp = head;

    // Print the data of every second node, starting from the head
    do {
        printf("%d ", temp->data);
        temp = temp->next->next; // Move two steps forward
    } while (temp != head); // Continue until we reach back to the head
}

int main() {
    struct Node* head = NULL;

    // Inserting elements into the circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Printing the quadrant elements of the circular linked list
    printf("Quadrant Elements of Circular Linked List: ");
    printQuadrantElements(head);

    return 0;
}
