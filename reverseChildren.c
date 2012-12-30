#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left, *right;
    int data;
} element;

void reverseChildren(element *root) {
    if(!root)
        return;
    element *t = root->left;
    root->left = root->right;
    root->right = t;
    reverseChildren(root->left);
    reverseChildren(root->right);
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

void preorder(element *root) {
    if(!root)
        return;
    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

main()
{
   element *root = makeNode(50);
   root->left = makeNode(25);
   root->right = makeNode(75);
   root->left->left = makeNode(12);
   root->left->right = makeNode(30);
   root->left->left->left = makeNode(4);
   root->right->right = makeNode(80);
   preorder(root);
   printf("#########\n");
   reverseChildren(root);
   preorder(root);
}
