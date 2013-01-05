#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

element *reverseLinkedListInGroupK(element *head, int k) {
    element *curr = head, *next = NULL, *pre = NULL;
    int count = 0;
    while(curr != NULL && count < k) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        count++;
    }
    if(next != NULL) {
        head->next = reverseLinkedListInGroupK(next, k);
    }
    return pre;
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

void printList(element * head) {
    while(head) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

main()
{
    element *head = makeNode(1);
    head->next = makeNode(2);
    head->next->next = makeNode(3);
    head->next->next->next = makeNode(4);
    head->next->next->next->next = makeNode(5);
    printList(head);
    head = reverseLinkedListInGroupK(head, 2);
    //reverseLinkedListRecursive(&head, head);
    printList(head);
}
