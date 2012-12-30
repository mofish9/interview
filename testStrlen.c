#include <stdio.h>
#include <stdlib.h>

void test(n) {
    int a[n][n], i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            a[i][j] = 0;
}

main()
{
    char *a = (char*)malloc(sizeof(char) * 10);
    memcpy(a, "123456789", 9);
    a[9] = '\0';
    printf("%d\n", strlen(a));
    test(10);
}
