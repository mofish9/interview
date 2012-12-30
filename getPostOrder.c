#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *left;
    struct elementT *right;
    char d;
} element;

element *getPostOrder(char *inorder, char *preorder, char *postorder, int rootPos, int start, int end) {
    if(start >= 8 || end < 0 || start > end)
        return;
    if(rootPos >= 8 || rootPos < 0)
        return;
    char root = preorder[rootPos];
    element *ele = (element *)malloc(sizeof(element));
    ele->d = root;
    int i = 0;
    for(i = start; i <= end; i++) {
        if(inorder[i] == root)
            break;
    }
    int left = i - start;
    int right = end - i;
    if(left > 0)
        ele->left = getPostOrder(inorder, preorder, postorder, rootPos + 1, start, i - 1);
    if(right > 0)
        ele->right = getPostOrder(inorder, preorder, postorder, rootPos + left + 1, i + 1, end);
    return ele;
}

void printPostOrder(element *root, char *postorder, int *num) {
    if(!root)
        return;
    printPostOrder(root->left, postorder, num);
    printPostOrder(root->right, postorder, num);
    printf("%c", root->d);
}

main()
{
    char *inorder = (char *)malloc(sizeof(char) * 9);
    memcpy(inorder, "adefghlm", 8);
    inorder[8] = '\0';
    char *preorder = (char *)malloc(sizeof(char) * 9);
    memcpy(preorder, "gdafelhm", 8);
    preorder[8] = '\0';
    char *postorder = (char *)malloc(sizeof(char) * 9);
    postorder[8] = '\0';
    element *root = getPostOrder(inorder, preorder, postorder, 0, 0, 7);
    int num = 0;
    printPostOrder(root, postorder, &num);
    printf("%s\n", postorder);
}
