#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

void split(element *head, element **a, element **b) {
    element *fast, *slow;
    if(head == NULL || head->next == NULL) {
        *a = head;
        *b = NULL;
    } else {
        slow = head;
        fast = head->next;
        while(fast != NULL) {
            fast = fast->next;
            if(fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }
}

element *merge(element *a, element *b) {
    element *ele = NULL;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    if(a->data < b->data) {
        ele = a;
        ele->next = merge(a->next, b);
    } else {
        ele = b;
        ele->next = merge(a, b->next);
    }
    return ele;
}

void mergeSortLinkedList(element **head) {
    if((*head) == NULL || (*head)->next == NULL)
        return;
    element *a, *b;
    split(*head, &a, &b);

    mergeSortLinkedList(&a);
    mergeSortLinkedList(&b);

    (*head) = merge(a, b);
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

void printList(element *h) {
    while(h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

main()
{
    element *h = makeNode(5);
    h->next = makeNode(1);
    h->next->next = makeNode(10);
    h->next->next->next = makeNode(7);
    h->next->next->next->next = makeNode(15);
    h->next->next->next->next->next = makeNode(12);
    printList(h);
    mergeSortLinkedList(&h);
    printList(h);
}
