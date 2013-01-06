#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

int printPath(element *root, element *target) {
    if(!root)
        return 0;

    if(root == target || printPath(root->left, target) || printPath(root->right, target)) {
        printf("%d\n", root->data);
        return 1;
    }

    return 0;
}

element *makeNode(int d) {
    element *e = (element *)malloc(sizeof(element));
    e->data = d;
    return e;
}

main()
{
    element *root = makeNode(50);
    root->left = makeNode(25);
    root->left->left = makeNode(15);
    root->left->left->left = makeNode(12);
    printPath(root, root->left->left->left);
}
