#include <stdio.h>
#include <stdlib.h>

int binaryRotatedSortedArraySearch(int d[], int target, int start, int end) {
    int low = start, high = end, mid;
    if(start > end)
        return -1;
    if(d[start] < d[end])
        return binarySearch(d, target, start, end);
    else {
        mid = (start + end) >> 1;
        int ra = binaryRotatedSortedArraySearch(d, target, start, mid);
        if(ra != -1)
            return ra;
        return binaryRotatedSortedArraySearch(d, target, mid + 1, end);
    }
}

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

main() {
    int d[8] = {5, 7, 9, 10, 15, 17, 1, 3};
    printf("%d\n", binaryRotatedSortedArraySearch(d, 5, 0, 7));
    printf("%d\n", binaryRotatedSortedArraySearch(d, 17, 0, 7));
    printf("%d\n", binaryRotatedSortedArraySearch(d, 11, 0, 7));
    printf("%d\n", binaryRotatedSortedArraySearch(d, 1, 0, 7));
    printf("%d\n", binaryRotatedSortedArraySearch(d, 9, 0, 7));
}
