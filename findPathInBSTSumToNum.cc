#include <iostream>
#include <vector>
using namespace std;

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

void findPathInBSTSumToNumSub(element *ele, vector<int> *v, int *sum, int num) {
    if(!ele)
        return;
    if(*sum == num) {
        vector<int>::iterator it = (*v).begin();
        for(; it != (*v).end(); it++)
            cout << *it << " ";
        cout << endl;
        return;
    }

    if(ele->left) {
        (*v).push_back(ele->left->data);
        (*sum) += ele->left->data;
        findPathInBSTSumToNumSub(ele->left, v, sum, num);
        (*sum) -= ele->left->data;
        (*v).pop_back();
    }
    if(ele->right) {
        (*v).push_back(ele->right->data);
        (*sum) += ele->right->data;
        findPathInBSTSumToNumSub(ele->right, v, sum, num);
        (*sum) -= ele->right->data;
        (*v).pop_back();
    }
}

void findPathInBSTSumToNum(element *ele, int num) {
    vector<int> v;
    int sum = 0;
    if(ele) {
        sum += ele->data;
        v.push_back(ele->data);
        findPathInBSTSumToNumSub(ele, &v, &sum, num);
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
    root->left->right = makeNode(40);
    root->right->left = makeNode(65);
    root->right->right = makeNode(90);
    findPathInBSTSumToNum(root, 50);
    findPathInBSTSumToNum(root, 87);
    findPathInBSTSumToNum(root, 190);
    findPathInBSTSumToNum(root, 1);

}
