#include <stdio.h>
#include <stdlib.h>

int kLeastValue(int data[], int k, int left, int right) {
    if(k <= 0)
        return -1;
    if(left + k <= right + 1) {
        int pivot = partition(data, left, right);
        if(pivot == left + k - 1)
            return data[pivot];
        else if(pivot > left + k - 1)
            return kLeastValue(data, k, left, pivot - 1);
        else
            return kLeastValue(data, k - pivot - 1, pivot + 1, right);
    }
    return -1;
}

int partition(int data[], int left, int right) {
    int i = left, j = left, x = data[right];
    for(j = left; j < right; j++) {
        if(data[j] < x) {
            int t = data[j];
            data[j] = data[i];
            data[i] = t;
            i++;
        }
    }
    data[right] = data[i];
    data[i] = x;
    return i;
}

main()
{
    int data[] = {5, 4, 3, 2, 6, 8, 9};
    printf("%d, it should be %d\n", kLeastValue(data, 1, 0, 6), 2);
    printf("%d, it should be %d\n", kLeastValue(data, 0, 0, 6), -1);
    printf("%d, it should be %d\n", kLeastValue(data, 5, 0, 6), 6);
    printf("%d, it should be %d\n", kLeastValue(data, 8, 0, 6), -1);
    printf("%d, it should be %d\n", kLeastValue(data, 3, 0, 6), 4);
}


