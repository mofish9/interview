#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

int ceil(element *root, int target) {
    if(!root)
        return -1;
    if(root->data == target)
        return root->data;
    if(root->data < target) 
        return ceil(root->right, target);
    int c = ceil(root->left, target);
    return (c >= target) ? c : root->data;
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

main()
{
    element *root = makeNode(50);
    root->left = makeNode(25);
    root->left->left = makeNode(12);
    root->left->right = makeNode(30);
    root->right = makeNode(75);
    root->right->right = makeNode(80);
    printf("%d\n", ceil(root, 50));
    printf("%d\n", ceil(root, 10));
    printf("%d\n", ceil(root, 90));
    printf("%d\n", ceil(root, 28));
}
