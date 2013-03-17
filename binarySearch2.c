#include <stdio.h>
#include <stdlib.h>

int binarySearch(int d[], int target, int start, int end) {
    int low = start, high = end, mid = (low + high) >> 1;
    while(low <= high) {
        mid = (low + high) >> 1;
        if(d[mid] == target)
            return mid;
        else if(d[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

main()
{
    int d[8] = {1, 4, 5, 7, 10, 15, 18, 20};
    printf("%d\n", binarySearch(d, 10, 0, 7));
    printf("%d\n", binarySearch(d, 1, 0, 7));
    printf("%d\n", binarySearch(d, 20, 0, 7));
    printf("%d\n", binarySearch(d, 19, 0, 7));
    printf("%d\n", binarySearch(d, 6, 0, 7));
}
