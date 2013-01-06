#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

void print(element *root, int k1, int k2) {
    if(!root)
        return;
    if(root->data > k1)
        print(root->left, k1, k2);

    if(root->data >= k1 && root->data <= k2)
        printf("%d ", root->data);

    if(root->data < k2)
        print(root->right, k1, k2);
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
    print(root, 10, 18);
}
