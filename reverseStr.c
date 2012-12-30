#include <stdio.h>
#include <stdlib.h>

int reverseStr(char *str) {
    int start = 0, end = 0;
    while(str[end] != '\0')
        end++;
    end--;
    while(start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
    printf("%s\n", str);
    return 1;
}

main()
{
    char *str = (char *)malloc(10);
    memcpy(str, "123456789", 9);
    str[9] = '\0';
    printf("%s\n", str);
    reverseStr(str);
    printf("%s\n", str);
    free(str);
}
