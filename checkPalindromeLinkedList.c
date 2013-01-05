#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

int isPalindromeRec(element *head) {
    return isPalindromeRecSub(&head, head);
}

int isPalindromeRecSub(element **left, element *right) {
    if(!right)
        return 1;
    int r = isPalindromeRecSub(left, right->next);
    if(r == 0)
        return 0;

    int r2 = (right->data == (*left)->data);

    *left = (*left)->next;
    return r2;
}

void reverse(element **mid) {
    element *pre = NULL, *curr = *mid, *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    *mid = pre;
}

int compare(element *left, element *right) {
    element *e1 = left, *e2 = right;
    while(e1 && e2) {
        if(e1->data == e2->data) {
            e1 = e1->next;
            e2 = e2->next;
        } else 
            return 0;
    }

    if(e1 == NULL && e2 == NULL)
        return 1;
    return 0;
}

int isPalindrome(element *head) {
    if(head == NULL)
        return 1;
    element *slow = head, *fast = head, *pre = head, *mid = NULL;
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        pre = slow;
        slow = slow->next;
    }

    int res;

    // we have even no of elements.
    if(fast->next != NULL) {
        mid = slow->next;
        reverse(&mid);
        slow->next = NULL;
        res = compare(head, mid);
        reverse(&mid);
        slow->next = mid;
    } else {
        mid = slow->next;
        pre->next = NULL;
        reverse(&mid);
        res = compare(head, mid);
        reverse(&mid);
        pre->next = slow;
        slow->next = mid;
    }
    return res;
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

main()
{
    element *h = makeNode(5);
    h->next = makeNode(6);
    h->next->next = makeNode(6);
    h->next->next->next = makeNode(5);
    //h->next->next->next->next = makeNode(5);
    printf("%d %d\n", isPalindromeRec(h), isPalindrome(h));
}
