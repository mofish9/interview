#include <stdio.h>
#include <stdlib.h>

float power(float x, int y) {
    float temp;
    if(y == 0)
        return 1;
    temp = power(x, y / 2);
    if(y % 2 == 0)
        return temp * temp;
    else {
        if(y > 0)
            return x * temp * temp;
        else 
            return (temp * temp) / x;
    }
}

main()
{
    printf("2^3=%f\n", power(2, 3));
    printf("2^0=%f\n", power(2, 0));
    printf("2^-1=%f\n", power(2, -1));
    printf("2^-3=%f\n", power(2, -3));
}
