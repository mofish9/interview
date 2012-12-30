#include <stdio.h>
#include <stdlib.h>

int getMaximum(int arr[], int low, int high) {
    if(low == high) 
        return arr[low];
    if(high - low == 1)
        return (arr[low] > arr[high] ? arr[low] : arr[high]);
    int mid = (low + high) >> 1;
    if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        return arr[mid];
    if(arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        return getMaximum(arr, low, mid - 1);
    else
        return getMaximum(arr, mid + 1, high);
}

main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 1};
    printf("%d\n", getMaximum(a, 0, 9));
}
