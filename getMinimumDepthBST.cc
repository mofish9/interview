#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

int min(int a, int b) {
    return (a < b ? a : b);
}

int getMinDepthDFS(element *root) {
    if(!root)
        return 0;
    if(!(root->left) && !(root->right))
        return 1;
    return min(1 + getMinDepthDFS(root->left), 1 + getMinDepthDFS(root->right));
}

int getMinDepthBFS(element *root) {
    if(!root)
        return 0;
    queue<element *> q;
    q.push(root);

    int level = 1;
    int nCurNode = 1;
    int nNextLev = 0;

    while(!q.empty()) {
        element *t = q.front();
        q.pop();
        if(!(t->left) && !(t->right))
            break;

        nCurNode--;

        if(t->left) {
            nNextLev++;
            q.push(t->left);
        }
        if(t->right) {
            nNextLev++;
            q.push(t->right);
        }
        if(nCurNode <= 0) {
            nCurNode = nNextLev;
            nNextLev = 0;
            level++;
        }
    }
    return level;
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
    root->left->left = makeNode(12);
    printf("%d %d\n", getMinDepthBFS(root), getMinDepthDFS(root));
}
