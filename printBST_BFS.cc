#include <iostream>
#include <queue>
using namespace std;

typedef struct elementT {
    struct elementT* left;
    struct elementT* right;
    int data;
} element;

void printLevel(queue<element *>*firstQ, queue<element *>*secondQ) {
    element *ele;
    while(!(*firstQ).empty()) {
        ele = (*firstQ).front();
        (*firstQ).pop();
        cout << ele->data << " ";

        if(ele->left)
            (*secondQ).push(ele->left);
        if(ele->right)
            (*secondQ).push(ele->right);
    }
    cout << endl;
}

void printBFS(element *root) {
    queue<element *>firstQ;
    queue<element *>secondQ;
    if(!root)
        return;
    firstQ.push(root);
    element *ele;
    while(!(firstQ.empty() && secondQ.empty())) {
        if(!firstQ.empty()) {
            printLevel(&firstQ, &secondQ);
        } else if(!secondQ.empty()) {
            printLevel(&secondQ, &firstQ);
        }
    }
}

element *makeNode(int d) {
    element *ele = new element();
    ele->data = d;
    return ele;
}

main()
{
    element *root = makeNode(50);
    root->left = makeNode(25);
    root->right = makeNode(75);
    root->left->left = makeNode(12);
    root->left->right = makeNode(35);
    root->right->left = makeNode(60);
    root->right->right = makeNode(80);
    printBFS(root);

}
