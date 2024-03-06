#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct ListNode** head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
}

// Function to add two numbers represented by linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = carry;
        current->next = NULL;
    }

    return dummy->next;
}

// Function to print the linked list
void printLinkedList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    // Inserting elements into the first linked list (representing 243)
    insertAtEnd(&l1, 3);
    insertAtEnd(&l1, 4);
    insertAtEnd(&l1, 2);

    // Inserting elements into the second linked list (representing 564)
    insertAtEnd(&l2, 4);
    insertAtEnd(&l2, 6);
    insertAtEnd(&l2, 5);

    printf("Linked List 1: ");
    printLinkedList(l1);

    printf("Linked List 2: ");
    printLinkedList(l2);

    // Adding the two linked lists
    struct ListNode* sum = addTwoNumbers(l1, l2);

    printf("Sum of Linked Lists: ");
    printLinkedList(sum);

    return 0;
}
