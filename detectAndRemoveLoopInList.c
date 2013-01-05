#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

void removeLoop(element *l, element *head) {
    element *p1 = l, *p2 = l;
    // count the number of nodes in the loop
    int k = 1;
    while(p1->next != p2) {
        p1 = p1->next;
        k++;
    }

    p1 = head;
    p2 = head;
    int i;
    for(i = 0; i < k; i++)
        p2 = p2->next;

    // meet p1 and p2, but p2 is one loop ahead of p1
    // the meeting node is the starting node of the loop
    while(p2 != p1) {
        p1 = p1->next;
        p2 = p2->next;
    }

    p2 = p2->next;
    while(p2->next != p1)
        p2 = p2->next;

    p2->next = NULL;
}

int detectLoopInList(element *head) {
    element *slow = head, *fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            removeLoop(slow, head);
            return 1;
        }
    }
    return 0;
}

element *makeNode(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

element *printList(element *h) {
    while(h) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

main()
{
    element *head = makeNode(5);
    head->next = makeNode(6);
    head->next->next = head;
    printf("%d\n", detectLoopInList(head));
    printList(head);
}
