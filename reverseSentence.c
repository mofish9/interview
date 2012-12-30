#include <stdio.h>
#include <stdlib.h>

int reverseSentence(char *str) {
    int start = 0, end = 0;
    while(str[end] != '\0')
        end++;
    end--;
    reverse(str, start, end);
    printf("%s\n", str);
    int curr = 0;
    while(str[curr] != '\0') {
        while(str[curr] != ' ' && str[curr] != '\0')
            curr++;
        curr--;
        reverse(str, start, curr);
        start = curr + 2;
        curr += 2;
    }
    return 1;
}

int reverse(char *str, int start, int end) {
    while(start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
    return 1;
}

main()
{
    char *str = (char *)malloc(50);
    memcpy(str, "how are you!", 12);
    str[12] = '\0';
    printf("%s\n", str);
    reverseSentence(str);
    printf("%s\n", str);
}
