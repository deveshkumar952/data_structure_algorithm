#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr,char val){
    if(isFull(ptr)){
        printf("stack overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;

    }
}
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow\n");
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


char stackTop(struct stack* sp){
    return sp->arr[sp->top];
}


int match(char a, char b){
    if(a == '{' && b=='}'){
        return 1;
    }
    if(a == '(' && b==')'){
        return 1;
    }
    if(a == '[' && b==']'){
        return 1;
    }
return 0;
}

int parenthesisMatch(char * exp){
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    char popped_ch;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for(int i = 0;exp[i]!='\0';i++){
        if(exp[i]=='(' ||exp[i]=='{' || exp[i]=='['){
            push(sp,exp[i]);
        }
        else if(exp[i]==')' ||exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch,exp[i])){
            return 0;
        }
    }
        if(isEmpty(sp)){
            return 1;
        }
        else{
        return 0;
        }}
}
int main(){

char * exp = "{45+[8*(9))";
    if(parenthesisMatch(exp)){
        printf("The parenthesis is Matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}