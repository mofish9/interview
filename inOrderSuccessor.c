#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    struct elementT *parent;
    int data;
} element;

element *minValue(element *ele) {
    element *curr = ele;
    while(curr->left) {
        curr = curr->left;
    }
    return curr;
}

element *getNode(element *ele) {
    element *curr = ele;
    while(curr) {
        if(!(curr->parent)) {
            if(curr == ele)
                return NULL;
            return curr;
        }
        if(curr == curr->parent->left)
            return curr->parent;
        curr = curr->parent;
    }
    return NULL;
}

element *inOrderSuccessor(element *root, int target) {
    element *curr = root;
    while(curr) {
        if(curr->data == target) {
            if(curr->right) {
                return minValue(curr->right);
            } else {
                return getNode(curr);
            }
        } else if(curr->data > target) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return NULL;
}

element *inOrderSuccessorWithoutParent(element *root, int target) {
    element *curr = root;
    while(curr) {
        if(curr->data == target)
            break;
        else if(curr->data > target)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(!curr)
        return NULL;
    if(curr->right != NULL)
        return minValue(curr->right);
    element *e = root, *succ = NULL;
    while(e != NULL) {
        if(target < e->data) {
            succ = e;
            e = e->left;
        } else if(target > e->data)
            e = e->right;
        else
            break;
    }
    return succ;
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

main() {
    element *root = makeNode(50);
    root->left = makeNode(25);
    root->left->parent = root;
    root->right = makeNode(75);
    root->right->parent = root;
    root->left->left = makeNode(15);
    root->left->left->parent = root->left;
    root->left->right = makeNode(40);
    root->left->right->parent = root->left;
    root->left->right->right = makeNode(45);
    root->left->right->right->parent = root->left->right;
    root->right->left = makeNode(60);
    root->right->left->parent = root->right;
    root->right->right = makeNode(80);
    root->right->right->parent = root->right;
    printf("%d\n", inOrderSuccessorWithoutParent(root, 50)->data);
    printf("%d\n", inOrderSuccessorWithoutParent(root, 25)->data);
    printf("%d\n", inOrderSuccessorWithoutParent(root, 40)->data);
    printf("%d\n", inOrderSuccessorWithoutParent(root, 60)->data);
}
