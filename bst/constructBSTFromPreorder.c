#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

element *construct(int pre[], int *index, int low, int high, int size) {
    if(*index >= size || low > high)
        return NULL;
    element *ele = makeNode(pre[*index]);
    *index = *index + 1;

    if(low == high)
        return ele;

    int i = low;
    for(; i <= high; i++) 
        if(pre[i] > ele->data)
            break;
    ele->left = construct(pre, index, *index, i - 1, size);
    ele->right = construct(pre, index, i, high, size);
    return ele;
}

element *constructBST(int pre[], int size) {
    int index = 0;
    return construct(pre, &index, 0, size - 1, size);
}

void printInorder(element *root) {
    if(root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);
    element *root = constructBST(pre, size);

    printInorder(root);
}
