#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b ? a : b);
}

int getLongestUniqueSubstr(char *str) {
    int len = strlen(str);
    printf("Len:%d\n", len);
    int i = 0, j = 0;
    int maxLen = 0;
    int exist[256];
    memset(exist, 0, 256);
    while(j < len) {
        if(exist[str[j]] == 1) {
            maxLen = max(maxLen, j - i);
            while(str[i] != str[j]) {
                exist[str[i]] = 0;
                i++;
            }
            i++;
            j++;
        } else {
            exist[str[j]] = 1;
            j++;
        }
    }
    maxLen = max(maxLen, len - i);
    return maxLen;
}

int main()
{
    //char *a = (char *)malloc(sizeof(char) * 8);
    //memset(a, "abcdefg", 7);
    //a[7] = '\0';
    char *a = "abcaefg";
    printf("%d\n", getLongestUniqueSubstr(a));
    return 0;
}
