#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to traverse and print the circular linked list
void linkedlisttraversal(struct Node *head) {
    struct Node *ptr = head;
    do {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Function to insert a new node at the beginning of the circular linked list
struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;

    while (p->next != head) {
        p = p->next;
    }
    // At this point, p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    return ptr; // Update the head pointer
}

// Function to insert a new node at the end of the circular linked list
void insertAtLast(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;

    while (p->next != head) {
        p = p->next;
    }
    // At this point, p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
}

// Function to insert a new node at a specific index in the circular linked list
void insertAtIndex(struct Node *head, int index, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    int i = 0;

    while (i < index - 1) {
        p = p->next;
        i++;
    }
    // At this point, p points to the node before the specified index
    ptr->next = p->next;
    p->next = ptr;
}

// Function to delete the first node from the circular linked list
void deleteAtFirst(struct Node *head) {
    struct Node *p = head->next;

    while (p->next != head) {
        p = p->next;
    }
    // At this point, p points to the last node of this circular linked list
    p->next = head->next->next;
    free(head->next);
    head->next = p->next;
}

// Function to delete the last node from the circular linked list
void deleteAtLast(struct Node *head) {
    struct Node *p = head->next;
    struct Node *q = NULL;

    while (p->next != head) {
        q = p;
        p = p->next;
    }
    // At this point, p points to the last node and q to the second last node
    q->next = head;
    free(p);
}

// Function to delete the node at a specific index from the circular linked list
void deleteAtIndex(struct Node *head, int index) {
    struct Node *p = head->next;
    struct Node *q = NULL;
    int i = 0;

    while (i < index - 1) {
        q = p;
        p = p->next;
        i++;
    }
    // At this point, p points to the node to be deleted and q to the previous node
    q->next = p->next;
    free(p);
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = fourth;

    fourth->data = 6;
    fourth->next = head;

    printf("Circular Linked List before insertion and deletion:\n");
    linkedlisttraversal(head);
    printf("\n\n");

    // Inserting elements
    head = insertAtFirst(head, 80);
    insertAtLast(head, 99);
    insertAtIndex(head, 2, 55);

    printf("Circular Linked List after insertion:\n");
    linkedlisttraversal(head);
    // printf("\n\n");

    // // Deleting elements
    // deleteAtFirst(head);
    // deleteAtLast(head);
    // deleteAtIndex(head, 2);

    // printf("Circular Linked List after deletion:\n");
    // linkedlisttraversal(head);

    return 0;
}
