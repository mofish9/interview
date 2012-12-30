#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

void getKLeastSub(element *ele, int *num, int k) {
    if(!ele)
        return;
    getKLeastSub(ele->left, num, k);
    (*num)++;
    if(*num == k)
        printf("%d:%d\n", *num, ele->data);
    getKLeastSub(ele->right, num, k);
}

int getKLeastValue(element *root, int k) {
    int num = 0;
    getKLeastSub(root, &num, k);
}

int getKLeastValueIterative(element *root, int k) {
    stack<element *>s;
    element *curr = root;
    int num = 0;
    while(true) {
        if(curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            if(s.empty())
                break;
            curr = s.top();
            s.pop();
            num++;
            if(num == k)
                return curr->data;
            curr = curr->right;
        }
    }
}

void getKLargestSub(element *ele, int *num, int k) {
    if(!ele)
        return;
    getKLargestSub(ele->right, num, k);
    (*num)++;
    if(*num == k)
        printf("%d:%d\n", *num, ele->data);
    getKLargestSub(ele->left, num, k);
}

void getKLargestValue(element *root, int k) {
    int num = 0;
    getKLargestSub(root, &num, k);
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
    root->right->left = makeNode(60);
    getKLeastValue(root, 10);
    getKLargestValue(root, 2);
    printf("%d\n", getKLeastValueIterative(root, 2));
}
