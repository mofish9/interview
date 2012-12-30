#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct elementT {
    struct elementT *next;
    int data;
} element;

int checkCycle(element *ele) {
    element *slow = ele, *fast = ele;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}

element *makeEle(int d) {
    element *ele = (element *)malloc(sizeof(element));
    ele->data = d;
    return ele;
}

main()
{
    element *head = makeEle(1);
    element *second = makeEle(2);
    head->next = second;
    second->next = makeEle(3);
    second->next->next = makeEle(4);
    second->next->next->next = makeEle(5);
    second->next->next->next->next = second;
    assert(checkCycle(head) == 1); 
    printf("%d\n", checkCycle(head));
}
