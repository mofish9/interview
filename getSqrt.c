#include <stdio.h>
#include <stdlib.h>

// calculate the sqrt of a
double getSqrt(double a) {
    // if a is negative, return error
    if(a < 0)
        return -1;
    // if a is 0 or 1, return a
    if(a == 0 || a == 1)
        return a;
    double low = 0, high = a, precision = 0.000000001, v, mid;
    if(a < 1)
        high = 1;
    while(high - low > precision) {
        mid = (low + high) / 2;
        v = mid * mid;
        if(v == a)
            return mid;
        else if(v > a) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (high + low) / 2;
}
 
// some test cases
main() 
{
    printf("%f\n", getSqrt(1));
    printf("%f\n", getSqrt(2));
    printf("%f\n", getSqrt(3));
    printf("%f\n", getSqrt(5));
    printf("%f\n", getSqrt(10));
    printf("%f\n", getSqrt(100));
}
