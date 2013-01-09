#include <stdio.h>
#include <stdlib.h>

float max(float a, float b) {
    return a > b ? a : b;
}

float min(float a, float b) {
    return a < b ? a : b;
}

float median(float a[], int n) {
    if(n % 2 == 0)
        return (a[n / 2] + a[n / 2 + 1]) / 2;
    else
        return a[n / 2];
}

float m3(float a, float b, float c) {
    return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

float m4(float a, float b, float c, float d) {
    float ma = max(a, max(b, max(c, d)));
    float mi = min(a, min(b, min(c, d)));
    return (a + b + c + d - ma - mi ) / 2;
}

float getMedianSub(float a[], int m, float b[], int n) {
    if(m == 1) {
        if(n == 1) {
            return (a[0] + b[0]) / 2;
        }
        if(n & 1) {
            return (b[n / 2] + m3(a[0], b[n / 2 - 1], b[n / 2 + 1])) / 2;
        }
        return m3(b[n / 2], b[n / 2 - 1], a[0]);
    } else if(m == 2) {
        if(n == 2) {
            return m4(a[0], a[1], b[0], b[1]);
        }
        if(n & 1) {
            return m3(b[n / 2], max(a[0], b[n / 2 - 1]), min(a[1], b[n / 2 + 1]));
        }
        return m4(b[n / 2], b[n / 2 - 1], max(a[0], b[n / 2 - 2]), min(a[1], b[n / 2 + 1]));
    }
    int i = (m - 1) / 2;
    int j = (n - 1) / 2;

    if(a[i] <= b[j]) 
        return getMedianSub(a + i, m / 2 + 1, b, n - i);

    return getMedianSub(a, m / 2 + 1, b + i, n - i);
}

float getMedian(float a[], int m, float b[], int n) {
    if(m > n)
        return getMedianSub(b, n, a, m);
    return getMedianSub(a, m, b, n);
}

main()
{
    float a[] = {1, 2, 3, 6};
    float b[] = {4, 6, 8, 10, 11};
    printf("Median is %f\n", getMedian(a, 4, b, 5));
}
