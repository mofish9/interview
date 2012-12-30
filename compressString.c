#include <stdio.h>
#include <stdlib.h>

void compressString(char *str) {
    int i = 0, len = strlen(str);
    printf("%d\n", len);
    int count = 0, nextI = 0;
    while(i < len) {
        for(; str[i + count] == str[i]; count++);
        if(count > 1) {
            str[nextI] = str[i];
            str[nextI + 1] = (char)count + '0';
            nextI = nextI + 2;
        } else {
            str[nextI] = str[i];
            nextI += count;
        }
        i += count;
        count = 0;
    }
    str[nextI] = '\0';
    printf("%s\n", str);
}

main()
{
    char *str = (char *)malloc(sizeof(char) * 9);
    memcpy(str, "aacceeef", 8);
    str[8] = '\0';
    compressString(str);
}
