#include <stdio.h>
#include <stdlib.h>

float getMedianValue(int a[], int left, int right) {
    int len = right - left + 1;
    if(len <= 0)
        return -1.0f;
    if(len == 1)
        return (float)a[0];
    int mid = (left + right) >> 1;
    if(len % 2 == 0) 
        return ((float)a[mid] + (float)a[mid + 1]) / 2;
}

float max(float a, float b) {
    if(a > b)
        return a;
    else 
        return b;
}

float min(float a, float b) {
    if(a > b)
        return b;
    return a;
}

float getMedian(int a[], int b[]) {
    if(a[1] < b[0])
        return (float)a[1];
    else if(a[0] < b[0])
        return (float)b[0];
    else
        return (float)a[0];
}

float getMediaFromTwoSortedArray(int a[], int b[], int lefta, int righta, int leftb, int rightb) {
    int lena = righta - lefta + 1, lenb = rightb - leftb + 1;
    if(lena <= 0 && lenb > 0)
        return getMedianValue(b, leftb, rightb);
    if(lenb <= 0 && lena > 0)
        return getMedianValue(a, lefta, righta);
    if(lena <= 0 && lenb <= 0)
        return -1.0f;
    if(lena == 1 && lenb == 1)
        return ((float)a[lefta] + (float)b[leftb]) / 2;
    if(lena == 2 && lenb == 2)
        return (max((float)a[lefta], (float)b[leftb]) + min((float)a[righta], (float)b[rightb])) / 2;
    if(lena == 2 && lenb == 1)
        return getMedian(a, b);
    if(lena == 1 && lenb == 2)
        return getMedian(b, a);
    int mida = (lefta + righta) >> 1, midb = (leftb + rightb) >> 1;
    if(a[mida] == b[midb])
        return a[mida];
    else if(a[mida] > b[midb]) {
        int ta = mida - 1, tb = midb + 1;
        if(lena % 2 == 0)
            ta++;
        return getMediaFromTwoSortedArray(a, b, lefta, ta, tb, rightb);
    } else {
        int ta = mida + 1, tb = midb - 1;
        if(lenb % 2 == 0)
            tb++;
        return getMediaFromTwoSortedArray(a, b, ta, righta, leftb, tb);
    }
}

main()
{
    int a[4] = {1, 3, 5, 7};
    int b[5] = {2, 4, 6, 8, 9};
    printf("%f\n", getMediaFromTwoSortedArray(a, b, 0, 3, 0, 4));
}


