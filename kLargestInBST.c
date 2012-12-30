#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

void getKLargestValue(element *root, int k) {
    int num = 0;
    getKLargestValueSub(root, k, &num);
}

void getKLargestValueSub(element *root, int k, int *num) {
    if(!root)
        return;
    getKLargestValueSub(root->right, k, num);
    (*num)++;
    if(*num == k)
        printf("%d\n", root->data);
    getKLargestValueSub(root->left, k, num);
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
    root->right->left = makeNode(60);
    root->right->right = makeNode(80);
    getKLargestValue(root, 1);
    getKLargestValue(root, 5);
    getKLargestValue(root, 3);



}
