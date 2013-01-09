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

float getMedian(float a[], float b[], int n) {
    if(n <= 0)
        return -1;
    if(n == 1)
        return (a[0] + b[0]) / 2;
    if(n == 2) 
        return (max(a[0], b[0]) + min(a[1], b[1])) / 2;
    float m1 = median(a, n);
    float m2 = median(b, n);

    if(m1 == m2)
        return m1;

    if(m1 < m2) {
        if(n % 2 == 0)
            return getMedian(a + n / 2 - 1, b, n - n / 2 + 1);
        else
            return getMedian(a + n / 2, b, n - n / 2);
    } else {
        if(n % 2 == 0)
            return getMedian(b + n / 2 - 1, a, n - n / 2 + 1);
        else
            return getMedian(b + n / 2, a, n - n / 2);
    }
}

main()
{
    float a[] = {1, 2, 3, 6};
    float b[] = {4, 6, 8, 10};
    printf("Median is %f\n", getMedian(a, b, 4));
}
