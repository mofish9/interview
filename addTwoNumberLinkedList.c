#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

element *addTwoNumber(element *a, element *b) {
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    reverseLinkedList(&a);
    reverseLinkedList(&b);
    element *res = NULL;
    int r = 0, v;
    element *ea = a, *eb = b;
    while(ea != NULL && eb != NULL) {
        int sum = ea->data + eb->data + r;
        r = sum / 10;
        v = sum % 10;
        element *o = (element *)malloc(sizeof(element));
        o->data = v;
        if(res == NULL)
            res = o;
        else {
            element *t = res->next, *p = res;
            while(t) {
                p = t;
                t = t->next;
            }
            p->next = o;
        }
        ea = ea->next;
        eb = eb->next;
    }
    while(ea != NULL) {
        int sum = ea->data + r;
        r = sum / 10;
        v = sum % 10;
        element *o = (element *)malloc(sizeof(element));
        o->data = v;
        element *t = res->next, *p = res;
        while(t) {
            p = t;
            t = t->next;
        }
        p->next = o;
        ea = ea->next;
    }
    while(eb != NULL) {
        int sum = eb->data + r;
        r = sum / 10;
        v = sum % 10;
        element *o = (element *)malloc(sizeof(element));
        o->data = v;
        element *t = res->next, *p = res;
        while(t) {
            p = t;
            t = t->next;
        }
        p->next = o;
        eb = eb->next;
    }
    reverseLinkedList(&res);
    return res;
}

void reverseLinkedList(element **head) {
    if((*head) == NULL || (*head)->next == NULL)
        return;
    element *ele = *head, *next = (*head)->next;
    (*head)->next = NULL;
    while(next) {
        element *t = next->next;
        next->next = ele;
        ele = next;
        next = t;
    }
    (*head) = ele;
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

void printList(element *ele) {
    while(ele) {
        printf("%d ", ele->data);
        ele = ele->next;
    }
    printf("\n");
}

main()
{
    element *a = makeNode(3);
    a->next = makeNode(5);
    a->next->next = makeNode(7);
    a->next->next->next = makeNode(9);
    element *b = makeNode(1);
    //b->next = makeNode(2);
    //b->next->next = makeNode(3);
    printList(a);
    //reverseLinkedList(&a);
    printList(b);
    element *r = addTwoNumber(a, b);
    printList(r);
}
