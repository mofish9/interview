#include <stdio.h>
#include <stdlib.h>

void reverse(char *a) {
    int i = 0, j = 0;
    while(a[j] != '\0') 
        j++;
    j--;

    while(i < j) {
        char t = a[j];
        a[j--] = a[i];
        a[i++] = t;
    }
    printf("%s\n", a);
}

main()
{
    char *a = (char *)malloc(sizeof(char) * 8);
    memcpy(a, "1234567", 7);
    a[7] = '\0';
    reverse(a);
}
