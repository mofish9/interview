#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

void join(element *a, element *b) {
    a->right = b;
    b->left = a;
}

element *append(element *a, element *b) {
    element *l, *r;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;

    l = a->left;
    r = b->left;

    join(l, b);
    join(r, a);
    return a;
}

element *treeToList(element *root) {
    if(root == NULL)
        return NULL;
    element *l, *r;
    l = treeToList(root->left);
    r = treeToList(root->right);
    root->left = root;
    root->right = root;

    l = append(l, root);
    l = append(l, r);
    return l;
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

void printList(element *h) {
    element *ele = h;
    while(ele->right != h) {
        printf("%d ", ele->data);
        ele = ele->right;
    }
    printf("\n");
}

main()
{
    element *root = makeNode(50);
    root->left = makeNode(25);
    root->left->left = makeNode(12);
    root->left->right = makeNode(30);
    root->right = makeNode(75);
    root->right->right = makeNode(80);
    element *e = treeToList(root);
    printList(e);
}
