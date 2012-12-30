#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

void reversePrint(element *ele) {
    if(!ele)
        return;
    reversePrint(ele->next);
    printf("%d\n", ele->data);
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

main() 
{
    element *head = makeNode(1);
    head->next = makeNode(2);
    head->next->next = makeNode(3);
    head->next->next->next = makeNode(4);
    reversePrint(head);
}
