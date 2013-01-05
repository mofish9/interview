#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

void segregateEvenOdd(element **head) {
    element *end = *head;
    while(end->next != NULL)
        end = end->next;

    element *newEnd = end;

    element *curr = *head, *pre = NULL;
    while(curr->data % 2 != 0 && curr != end) {
        newEnd->next = curr;
        curr = curr->next;
        newEnd->next->next = NULL;
        newEnd = newEnd->next;
    }

    if(curr->data % 2 == 0) {
        *head = curr;

        while(curr != end) {
            if(curr->data % 2 == 0) {
                pre = curr;
                curr = curr->next;
            } else {
                pre->next = curr->next;
                curr->next = NULL;
                newEnd->next = curr;
                newEnd = curr;
                curr = pre->next;
            }
        }
    } else {
        pre = curr;
    }

    if(end->data % 2 != 0) {
        pre->next = end->next;
        end->next = NULL;
        newEnd->next = end;
    }
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
    element *root = makeNode(5);
    root->next = makeNode(6);
    root->next->next = makeNode(7);
    root->next->next->next = makeNode(8);
    printList(root);
    segregateEvenOdd(&root);
    printList(root);
}
