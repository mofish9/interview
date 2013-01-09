#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

void removeDuplicates(element *head) {
    element *curr = head, *next = NULL;
    if(curr == NULL)
        return;

    while(curr->next != NULL) {
        if(curr->data == curr->next->data) {
            next = curr->next->next;
            free(curr->next);
            curr->next = next;
        } else {
            curr = curr->next;
        }
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
    element *h = makeNode(5);
    h->next = makeNode(5);
    h->next->next = makeNode(6);
    h->next->next->next = makeNode(7);
    h->next->next->next->next = makeNode(7);
    printList(h);
    removeDuplicates(h);
    printList(h);
}
