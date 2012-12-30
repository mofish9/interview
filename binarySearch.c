#include <stdio.h>
#include <stdlib.h>

int binarySearch(int data[], int length, int toSearch) {
    int low = 0, high = length - 1;
    int mid = (low + high) >> 1;
    while(low <= high) {
        if(data[mid] == toSearch)
            return mid;
        else if(data[mid] < toSearch) 
        {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
       mid = (low + high) >> 1;
    }
    return -1;
}

main()
{
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binarySearch(data, 10, 1));
    printf("%d\n", binarySearch(data, 10, -1));
    int data2[1] = {1};
    printf("%d\n", binarySearch(data2, 1, 1));
    printf("%d\n", binarySearch(data2, 1, 2));
}
