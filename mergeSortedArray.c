#include <stdio.h>
#include <stdlib.h>

int* merge(int left[], int right[], int llen, int rlen) {
    int lindex = 0, rindex = 0, index = 0;
    int *res = (int *)malloc(sizeof(int) * (llen + rlen));
    while(lindex < llen && rindex < rlen) {
        if(left[lindex] <= right[rindex]) {
            res[index] = left[lindex];
            lindex++;
        } else {
            res[index] = right[rindex];
            rindex++;
        }
        index++;
    }
    while(lindex < llen) {
        res[index++] = left[lindex++];
    }
    while(rindex < rlen) {
        res[index++] = right[rindex++];
    }
    return res;
}

main()
{
    int left[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int right[] = {1, 2, 4, 8, 16, 32, 64, 128};
    int llen = sizeof(left)/sizeof(left[0]), rlen = sizeof(right)/sizeof(right[0]);
    //int res[17];
    int *res = merge(left, right, llen, rlen);
    int i;
    for(i = 0; i < llen + rlen; i++)
        printf("%d ", res[i]);
    printf("\n");
}
