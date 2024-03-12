#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to reverse the linked list
struct Node* reverseLinkedList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to add the corresponding nodes of two linked lists
struct Node* addCorrespondingNodes(struct Node *head1, struct Node *head2) {
    struct Node *result = NULL;
    while (head1 != NULL && head2 != NULL) {
        result = insertAtEnd(result, head1->data + head2->data);
        head1 = head1->next;
        head2 = head2->next;
    }
    return result;
}

// Function to print the linked list
void printLinkedList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    int n, data;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Original Linked List: ");
    printLinkedList(head);

    // Reverse the linked list
    struct Node *reversedHead = reverseLinkedList(head);

    // Add corresponding nodes of original and reversed linked lists
    struct Node *sumList = addCorrespondingNodes(head, reversedHead);

    printf("New Linked List after Addition: ");
    printLinkedList(sumList);

    // Free dynamically allocated memory
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    while (reversedHead != NULL) {
        temp = reversedHead;
        reversedHead = reversedHead->next;
        free(temp);
    }
    while (sumList != NULL) {
        temp = sumList;
        sumList = sumList->next;
        free(temp);
    }

    return 0;
}
