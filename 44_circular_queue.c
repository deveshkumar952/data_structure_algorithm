#include <stdio.h>
#include <stdlib.h>

struct circulaQueue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct circulaQueue *q){
    if(q->r ==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct circulaQueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct circulaQueue *q,int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}
int dequeue(struct circulaQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is Empty\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}
int main(){
    struct circulaQueue *q;
    q->size = 3;
    q->f = q->r = 0;
    q->arr = (int*)malloc(q->size*sizeof(int));
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }

    //Enqueue few elements
    enqueue(q,12);
    enqueue(q,2);
    // enqueue(q,1);
    // enqueue(q,6);

    //Dequeue few elemenets
    // printf("Dequeuing element %d\n",dequeue(q));
    printf("Dequeuing element %d\n",dequeue(q));
    printf("Dequeuing element %d\n",dequeue(q));
    // printf("Dequeuing element %d\n",dequeue(q));
    enqueue(q,6);

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    if(isFull(q)){
        printf("Queue us full");
    }
    
    return 0;
}