#include <stdio.h>
#include <stdlib.h>

int aToi(char *str) {
    int num = 0, i = 0, negative = 0;
    if(str[0] == '-') {
        negative = 1;
        i++;
    }
    while(1) {
        if(str[i] == '\0')
            break;
        num *= 10;
        num += (str[i] - '0');
        i++;
    }
    if(negative)
        num *= -1;
    return num;
}

main()
{
    //char *str = (char *)malloc(10);
    //memcpy(str, "-12345678", 9);
    //str[9] = '\0';
    char *str = "-12345678";
    printf("%d\n", aToi(str));
}
