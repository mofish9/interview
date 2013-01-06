#include <iostream>
#include <queue>
using namespace std;

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

int checkBSTCompleteOrNot(element *root) {
    if(!root)
        return 1;
    queue<element *>q;
    q.push(root);

    int flag = 0;

    while(!q.empty()) {
        element *ele = q.front();
        q.pop();
        if(ele->left) {
            q.push(ele->left);
            if(flag == 1)
                return 0;
        } else
            flag = 1;

        if(ele->right) {
            q.push(ele->right);
            if(flag == 1)
                return 0;
        } else
            flag = 1;
    }
    return 1;
}

element *makeNode(int d) {
    element *e = new element;
    e->data = d;
    return e;
}

main()
{
    element *root = makeNode(50);
    root->left = makeNode(25);
    root->left->left = makeNode(12);
    root->left->right = makeNode(30);
    root->right = makeNode(75);
    root->right->left = makeNode(80);
    cout << checkBSTCompleteOrNot(root) << endl;
}
