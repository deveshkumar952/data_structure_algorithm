#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to reverse a doubly linked list
void reverseDoublyLinkedList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;

    // Traverse to the last node which will become the new head
    while (current->next != NULL) {
        current = current->next;
    }

    // Swap the head and current pointers
    *head = current;

    // Reverse the pointers of each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->next; // Move to the next node
    }
}

// Function to print the doubly linked list
void printDoublyLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting elements into the doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Printing the original doubly linked list
    printf("Original Doubly Linked List: ");
    printDoublyLinkedList(head);

    // Reversing the doubly linked list
    reverseDoublyLinkedList(&head);

    // Printing the reversed doubly linked list
    printf("Reversed Doubly Linked List: ");
    printDoublyLinkedList(head);

    return 0;
}
