#include <stdio.h>
#include <stdlib.h>

//int *temp;

void mergeSort(int data[], int left, int right) {
    if(left >= right)
        return;
    int mid = (left + right) >> 1;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

void merge(int data[], int left, int mid, int right) {
    int leftCurr = left, rightCurr = mid + 1, curr = 0;
    int temp[right - left + 1];
    while(leftCurr <= mid && rightCurr <= right) {
        if(data[leftCurr] < data[rightCurr]) {
            temp[curr] = data[leftCurr];
            leftCurr++;
        } else {
            temp[curr] = data[rightCurr];
            rightCurr++;
        }
        curr++;
    } 
    while(leftCurr <= mid) {
        temp[curr] = data[leftCurr];
        curr++;
        leftCurr++;
    }
    while(rightCurr <= right) {
        temp[curr] = data[rightCurr];
        curr++;
        rightCurr++;
    }
    for(curr = left; curr <= right; curr++)
        data[curr] = temp[curr - left];
}

main()
{
    int data[] = {4, 3, 2, 5, 1, 9, 7};
    //temp = (int *)malloc(sizeof(data) / sizeof(int));
    mergeSort(data, 0, sizeof(data) / sizeof(int) - 1);
    int i = 0;
    for(i = 0; i < sizeof(data) / sizeof(int); i++)
        printf("%d ", data[i]);
    printf("\n");
}
