#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size; 
    int top;
    int * arr;

}; 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct stack* ptr,int val){
    if(isFull(ptr)){
        printf("stack overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;

    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peak(struct stack* sp , int i){
    int arrayInd = sp->top -i +1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

int stackbottom(struct stack* sp) {

    return sp->arr[0];
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int main(){
     struct stack *sp = (struct stack* )malloc(sizeof(struct stack));
     sp->size = 4;
     sp->top = -1;
     sp->arr = (int *)malloc(sp->size * sizeof(int));
    //  printf("stack has been created succesfully\n");

    // printf("before pushing full:%d\n",isFull(sp));
    // printf("before pushing empty:%d\n",isEmpty(sp));

    push(sp,56);
    push(sp,516);
    push(sp,5);
    push(sp,78);

 


    // printf("After pushing, Full:%d\n",isFull(sp));
    // printf("After pushing, Empty: %d\n",isEmpty(sp));



    for(int j=1;j<=sp->top +1;j++){ 
    printf("The value at position %d is %d\n",j,peak(sp,j));
    }
        printf("Popped %d from the stack\n",pop(sp));

    // printf("bottom element of the stack : %d\n",stackbottom(sp));
    // printf("top of the stack elements is:%d",stackTop(sp));
    return 0;
}