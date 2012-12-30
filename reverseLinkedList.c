#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

void reverseLinkedList(element **head) {
    element *first = *head, *second = *head;
    if(*head == NULL || (*head)->next == NULL)
        return;
    second = (*head)->next;
    while(second) {
        element *t = second->next;
        second->next = first;
        first = second;
        second = t;
    }
    (*head)->next = NULL;
    *head = first;
}

void reverseLinkedListRecursive(element **head, element *ele) {
    element *curr = ele, *next = ele->next;
    if(ele->next == NULL) {
        *head = ele; 
        return;
    }
    reverseLinkedListRecursive(head, next);
    curr->next->next = curr;
    curr->next = NULL;
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
    //head->next = makeNode(2);
    //head->next->next = makeNode(3);
    printList(head);
    //reverseLinkedList(&head);
    reverseLinkedListRecursive(&head, head);
    printList(head);
}
