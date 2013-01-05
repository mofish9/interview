#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    struct elementT *left;
    struct elementT *right;
    int data;
} element;

int countElements(element *h) {
    int sum = 0;
    while(h) {
        sum++;
        h = h->next;
    }
    return sum;
}

void printList(element *h) {
    while(h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

element *sortedSinglyListToBST(element *head) {
    if(!head)
        return NULL;
    if(!(head->next))
        return head;
    element *slow = head, *fast = head->next, *pre = NULL;
    while(fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    element *r = slow;
    if(pre != NULL)
        pre->next = NULL;
    //printList(head);
    if(slow != head)
        r->left = sortedSinglyListToBST(head);
    r->right = sortedSinglyListToBST(slow->next);
    //printf("%d\n", slow->data);
    return r;
}

element *sortedSinglyListToBSTRecSub(element **ele, int n) {
    if(n <= 0)
        return NULL;
    element *left = sortedSinglyListToBSTRecSub(ele, n/2);

    element *root = makeNode((*ele)->data);
    root->left = left;

    *ele = (*ele)->next;

    root->right = sortedSinglyListToBSTRecSub(ele, n - n / 2 - 1);
    return root;
}

element *sortedSinglyListToBSTRec(element *head) {
    int n = countElements(head);

    return sortedSinglyListToBSTRecSub(&head, n);
}

main()
{
    element *head = makeNode(2);
    head->next = makeNode(4);
    head->next->next = makeNode(5);
    head->next->next->next = makeNode(6);
    element *root = sortedSinglyListToBSTRec(head);
}
