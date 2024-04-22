#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct queue *q){
    if(q->r ==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *q){
    if(q->r ==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is Empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void displayQueue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->f + 1; i <= q->r; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue)); // Allocate memory for q
    q->size = 3;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    
    //Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 2);
    enqueue(q, 1);
    displayQueue(q);
    
    // Dequeue few elements
    printf("Dequeuing element %d\n", dequeue(q));
    displayQueue(q);

    free(q->arr); // Free the memory allocated for q->arr
    free(q); // Free the memory allocated for q

    return 0;
}
