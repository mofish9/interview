#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

element *mergeTwoSortedLinkedListRecursive(element *a, element *b) {
    element *result = NULL;
    if(a == NULL) 
        return b;
    else if(b == NULL)
        return a;
    if(a->data < b->data) {
        result = a;
        result->next = mergeTwoSortedLinkedListRecursive(a->next, b);
    } else {
        result = b;
        result->next = mergeTwoSortedLinkedListRecursive(a, b->next);
    }
    return result;
}

void copyValue(element **des, element **sour) {
    element *ele = *sour;
    *sour = ele->next;
    ele->next = *des;
    *des = ele;
}

element *mergeTwoSortedLinkedList(element *a, element *b) {
    element head;
    element *tail = &head;
    head.next = NULL;

    while(1) {
        if(a == NULL) {
            tail->next = b;
            break;
        } else if(b == NULL) {
            tail->next = a;
            break;
        }
        if(a->data < b->data) {
            copyValue(&(tail->next), &a);
        } else {
            copyValue(&(tail->next), &b);
        }
        tail = tail->next;
    }
    return head.next;
}

void printList(element *a) {
    while(a) {
        printf("%d\n", a->data);
        a = a->next;
    }
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

main()
{
    element *a = makeNode(1);
    a->next = makeNode(3);
    a->next->next = makeNode(5);
    printList(a);
    element *b = makeNode(2);
    b->next = makeNode(6);
    b->next->next = makeNode(7);
    printList(b);
    printList(mergeTwoSortedLinkedList(a, b));
}
