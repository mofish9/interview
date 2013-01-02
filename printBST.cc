#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

void printBSTRecursive(element *root) {
    if(!root)
        return;
    printBSTRecursive(root->left);
    printf("%d ", root->data);
    printBSTRecursive(root->right);
}

void printBSTIterative(element *root) {
    stack<element *>s;
    element *curr = root;
    while(true) {
        if(curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            if(s.empty())
                break;
            else {
                element *t = s.top();
                s.pop();
                printf("%d ", t->data);
                curr = t->right;
            }
        }
    }
}

void BFS(element *root) {
    queue<element *>q;
    q.push(root);
    element *curr;
    while(true) {
        if(q.empty())
            break;
        curr = q.front();
        if(curr) {
            q.pop();
            printf("%d ", curr->data);
        }
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}

void BFSZigZag(element *root) {
    queue<element *>q;
    q.push(root);
    element *curr;
    int level = 1;
    int nCurrNode = 1, nNextLev = 0;
    stack<int>s;
    while(!q.empty()) {
        curr = q.front();
        if(curr) {
            if(level % 2 == 1)
                printf("%d ", curr->data);
            else
                s.push(curr->data);
            q.pop();
        }
        
        nCurrNode--;
        if(curr->left) {
            nNextLev++;
            q.push(curr->left);
        }
        if(curr->right) {
            nNextLev++;
            q.push(curr->right);
        }
        if(nCurrNode <= 0) {
            if(level % 2 == 0) {
                while(!s.empty()) {
                    printf("%d ", s.top());
                    s.pop();
                }
                printf("\n");
            } else
                printf("\n");
            nCurrNode = nNextLev;
            nNextLev = 0;
            level++;
        }
    }
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    if(!ele)
        return NULL;
    ele->data = d;
    return ele;
}

main()
{
    element *root = makeNode(50);
    if(root) {
        root->left = makeNode(25);
        root->left->left = makeNode(12);
        root->left->left->left = makeNode(6);
        root->right = makeNode(75);
        root->right->left = makeNode(62);
        root->right->right = makeNode(80);
    }
    //printBSTRecursive(root);
    //printf("\n");
    //printBSTIterative(root);
    //printf("\n");
    BFS(root);
    printf("\n");
    BFSZigZag(root);
}
