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

// Function to merge two linked lists
struct Node* mergeLinkedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        // If the first list is empty, return the second list
        return list2;
    }

    if (list2 == NULL) {
        // If the second list is empty, return the first list
        return list1;
    }

    struct Node* temp = list1;

    // Traverse to the end of the first list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Append the second list to the end of the first list
    temp->next = list2;

    return list1;
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

    printf("Original Linked List 1: ");
    printLinkedList(list1);

    printf("Original Linked List 2: ");
    printLinkedList(list2);

    // Merge list2 into list1
    list1 = mergeLinkedLists(list1, list2);

    printf("Merged Linked List: ");
    printLinkedList(list1);

    return 0;
}
