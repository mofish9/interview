#include <stdio.h>
#include <stdlib.h>

int substringMatch(char *text, char *pattern) {
    int i, j, found = 1;
    for(i = 0; text[i] != '\0'; i++) {
        found = 1;
        for(j = 0; pattern[j] != '\0'; j++) {
            if(text[i + j] == '\0' || text[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }
        if(found)
            return i;
    }
    return -1;
}

main()
{
    char * text = (char *)malloc(20);
    memcpy(text, "1234567890123456789", 19);
    text[19] = '\0';
    char * pattern = (char *)malloc(5);
    memcpy(pattern, "8911", 4);
    pattern[4] = '\0';
    printf("%d\n", substringMatch(text, pattern));
    free(text);
    free(pattern);
}
