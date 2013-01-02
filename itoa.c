#include <stdio.h>
#include <stdlib.h>

char *itoa(int data) {
    char *r = (char *)malloc(sizeof(char) * 16);
    int i = 0;
    int d = data;
    if(data < 0)
        d = -data;
    while(d > 0) {
        r[i] = '0' + (d % 10);
        i++;
        d /= 10;
    }

    if(data < 0) {
        r[i] = '-';
        i++;
    }

    r[i] = '\0';
    int l = 0, m = i - 1;
    while(l < m) {
        char t = r[l];
        r[l] = r[m];
        r[m] = t;
        l++;m--;
    }
    return r;
}

main()
{
    char *r = itoa(-500);
    printf("%s\n", r);
}
