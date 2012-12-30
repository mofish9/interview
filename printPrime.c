#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printPrime(int n) {
    int flag[n + 1];
    int i = 2, m = (int)sqrt((float)n), j;
    for(; i < n + 1; i++)
        flag[i] = 1;
    for(i = 2; i <= m; i++) {
        if(flag[i] == 1) {
            for(j = i * i; j <= n; j += i)
                flag[j] = 0;
        }
    }
    for(i = 2; i <= n; i++)
        if(flag[i] == 1)
            printf("%d ", i);
    printf("\n");
}

main()
{
    printPrime(50);
}
