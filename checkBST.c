#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

int checkBST(element *root, int left, int right) {
    element *ele = root;
    if(!ele)
        return 1;
    return (ele->data > left && ele->data < right && checkBST(ele->left, left, ele->data) && checkBST(ele->right,
    ele->data, right));
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
    root->right = makeNode(75);
    root->left->right = makeNode(60);
    printf("%d\n", checkBST(root, INT_MIN, INT_MAX));
}
