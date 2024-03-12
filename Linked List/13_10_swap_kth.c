#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr) {
    while(ptr != NULL) {
        printf("element:%d\n",ptr -> data);
        ptr = ptr ->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

int lengthOfLinkedList(struct Node *head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node *swapKthNodes(struct Node *head, int k) {
    int length = lengthOfLinkedList(head);

//     // If k is out of range, return the original linked list
//    if (k <= 0 || k > length)

//         return head;

//     // If k is the same from both ends, no need to swap
//     if (2 * k - 1 == length)
//         return head;

    struct Node *prevBegin = NULL, *curBegin = head;
    for (int i = 1; i < k; i++) {
        prevBegin = curBegin;
        curBegin = curBegin->next;
    }

    struct Node *prevEnd = NULL, *curEnd = head;
    for (int i = 1; i < length - k + 1; i++) {
        prevEnd = curEnd;
        curEnd = curEnd->next;
    }

    // If previous nodes exist, update their next pointers
    if (prevBegin != NULL)
        prevBegin->next = curEnd;
    if (prevEnd != NULL)
        prevEnd->next = curBegin;

    // Swap next pointers of kth nodes f
    struct Node *temp = curBegin->next;
    curBegin->next = curEnd->next;
    curEnd->next = temp;

    // Update head pointer if k is 1 or length
    if (k == 1)
        head = curEnd;
    else if (k == length)
        head = curBegin;

    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *thrid;
    head = (struct Node *) malloc(sizeof(struct Node));
    second= (struct Node *) malloc(sizeof(struct Node));
    thrid = (struct Node *) malloc(sizeof(struct Node));

    head ->data = 7;
    head ->next = second;

    second ->data = 11;
    second -> next = thrid;

    thrid ->data =66;
    thrid ->next =  NULL;

    linkedlisttraversal(head);
    printf("\n");
    head = insertAtFirst(head,56);
    printf("\nLinked List after inserting 56 at the beginning:\n");
    linkedlisttraversal(head);

    // Swap the kth node from beginning with kth node from end
    int k;
    printf("\nEnter the value of k: ");
    scanf("%d", &k);
    head = swapKthNodes(head, k);

    printf("\nLinked List after swapping kth nodes:\n");
    linkedlisttraversal(head);

    return 0;
}
