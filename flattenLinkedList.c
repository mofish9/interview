#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *right;
    struct elementT *down;
    int data;
} element;

element *merge(element *a, element *b) {
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    element *ele;
    if(a->data < b->data) {
        ele = a;
        ele->down = merge(a->down, b);
    } else {
        ele = b;
        ele->down = merge(a, b->down);
    }
    return ele;
}

element *flatten(element *root) {
    if(root == NULL || root->right == NULL)
        return root;
    return merge(root, flatten(root->right));
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

void printList(element *h) {
    while(h) {
        printf("%d ", h->data);
        h = h->down;
    }
    printf("\n");
}

main()
{
    element *root = makeNode(4);
    root->down = makeNode(6);
    root->down->down = makeNode(7);
    root->down->down->down = makeNode(10);
    root->right = makeNode(5);
    root->right->down = makeNode(8);
    root->right->down->down = makeNode(9);
    root->right->down->down->down = makeNode(15);
    root->right->right = makeNode(20);
    root->right->right->right = makeNode(22);
    element *e = flatten(root);
    printList(e);
}
