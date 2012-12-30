#include <stdio.h>
#include <stdlib.h>

void quickSort(int data[], int left, int right) {
    if(left < right) {
        int pivot = partition(data, left, right);
        quickSort(data, left, pivot - 1);
        quickSort(data, pivot + 1, right);
    }
}

int partition(int data[], int left, int right) {
    int i = left, j = left;
    int flag = data[right];
    for(j = left; j < right; j++) {
        if(data[j] <= flag) {
            int t = data[i];
            data[i] = data[j];
            data[j] = t;
            i++;
        }
    }
    int t = data[i];
    data[i] = flag;
    data[right] = t;
    return i; 
}

main()
{
    int data[] = {6, 5, 7, 4, 8, 3, 9, 2};
    quickSort(data, 0, 7);
    int i;
    for(i = 0; i < 8; i++)
        printf("%d ", data[i]);
    printf("\n");
}
