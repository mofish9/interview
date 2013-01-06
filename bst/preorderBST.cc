#include <iostream>
#include <stack>
using namespace std;

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

void preorderRec(element *root) {
    if(!root)
        return;
    cout << root->data << endl;
    preorderRec(root->left);
    preorderRec(root->right);
}

void preorderIter(element *root) {
    if(!root)
        return;
    stack<element *>s;
    s.push(root);
    element *ele = NULL;
    while(!s.empty()) {
        ele = s.top();
        cout << ele->data << endl;
        s.pop();

        if(ele->right)
            s.push(ele->right);
        if(ele->left)
            s.push(ele->left);
    }
}

element *makeNode(int d) {
    element *ele = new element;
    ele->data = d;
    return ele;
}

main()
{
    element *root = makeNode(50);
    root->left = makeNode(25);
    root->left->left = makeNode(10);
    root->right = makeNode(75);
    root->right->left = makeNode(60);
    preorderRec(root);
    cout << "##" << endl;
    preorderIter(root);
}
