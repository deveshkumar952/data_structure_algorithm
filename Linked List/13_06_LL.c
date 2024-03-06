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

// Function to merge two linked lists at alternate positions
void mergeAtAlternatePositions(struct Node** list1, struct Node** list2) {
    struct Node* current1 = *list1;
    struct Node* current2 = *list2;

    while (current1 != NULL && current2 != NULL) {
        // Store the next pointers
        struct Node* next1 = current1->next;
        struct Node* next2 = current2->next;

        // Insert the current node of the second list into the first list
        current1->next = current2;
        current2->next = next1;

        // Move pointers to the next nodes
        current1 = next1;
        current2 = next2;
    }

    // If the second list still has remaining nodes, append them to the end of the first list
    if (current2 != NULL) {
        struct Node* temp = *list1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = current2;
    }

    // Update the second list pointer to NULL as it's merged into the first list
    *list2 = NULL;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Inserting elements into the first linked list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    // Inserting elements into the second linked list
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);
    insertAtEnd(&list2, 8);
    insertAtEnd(&list2, 10);

    printf("Original Linked List 1: ");
    printLinkedList(list1);

    printf("Original Linked List 2: ");
    printLinkedList(list2);

    // Merge list2 into list1 at alternate positions
    mergeAtAlternatePositions(&list1, &list2);

    printf("Merged Linked List: ");
    printLinkedList(list1);

    return 0;
}
