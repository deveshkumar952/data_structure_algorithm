#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
};

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int isBST(struct node* root){
   static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node * itersearch(struct node* root,int key){
    while(root!=NULL){
    if(key == root->data){
        return root;
    }
    else if(key<root->data){
        root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
    }

void insert(struct node *root,int key){
    struct node *prev = NULL;
    while(root != NULL) {
        prev = root;
        if(key == root->data){
            printf("Can not insert alread in BST");
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
    
}
int main(){
    struct node *p = createNode(4);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);


    //Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1 ->left = p3;
    p1->right = p4;
    insert(p,7);
    printf("%d",p->right->right->data); 

    return 0;
}

