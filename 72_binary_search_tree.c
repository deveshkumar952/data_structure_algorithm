#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBSTUtil(struct node* root, struct node** prev) {
    if (root != NULL) {
        if (!isBSTUtil(root->left, prev)) {
            return 0;
        }
        // Check if the current node's data is less than or equal to the previous node's data
        if (*prev != NULL && root->data <= (*prev)->data) {
            return 0;
        }
        // Update the previous node to the current node
        *prev = root;
        return isBSTUtil(root->right, prev);
    }
    return 1;
}

int isBST(struct node* root) {
    struct node* prev = NULL;
    return isBSTUtil(root, &prev);
}

int main() {
    struct node *p = createNode(5);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(10);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Inorder traversal of the tree: ");
    inorder(p);

    if (isBST(p)) {
        printf("\nIt is a Binary Search Tree (BST).\n");
    } else {
        printf("\nIt is not a Binary Search Tree (BST).\n");
    }

    return 0;
}
