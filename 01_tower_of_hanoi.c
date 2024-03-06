// #include<stdio.h>

// void move(int n, char a, char c, char b){
//     if(n==1){
//         printf("move disk 1 from %c to %c\n", a,b);
//         return ;
//     }
//     move(n-1, a,c,b);
//     printf("move disk %d from %c to %c\n", n,a,b);
//     move(n-1, c,b,a);
// }

// int main(){
//     int n;
//     printf("enter the number of disks: ");
//     scanf("%d", &n);
//     printf("the sequene of moves involve in tower of hanoi are: \n");
//     move(n,'A','C','B');
//     return 0;
// }

// // Write a recursive function for Tower of Hanoi Problem.
// #include <stdio.h>
// void TOH( int num , char from , char to , char help ){
//     if(num == 0) return ;
//     TOH(num-1 , from , help , to);
//     printf("%c --> %c \n",from , to);
//     TOH(num-1 , help , to , from);
// }
// int main(){
//     TOH(4,'A','B','C');
// }

#include <stdio.h>
void move(int n,char a,char c,char b){
    if(n==1){
        printf("move disc 1 from %c to %c\n",a,b);
        return;
    }
        move(n-1,a,c,b);
        printf("move %d from %c to %c\n",n,a,b);
        move(n-1,c,b,a);
}
int main(){
    int n;
    printf("Enter the number of disc:");
    scanf("%d",&n);
    printf("The sequence of moves involve in tower of honoi are:\n");
    move(n,'a','c','b');

    return 0;
}