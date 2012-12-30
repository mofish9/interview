#include <stdio.h>
#include <stdlib.h>

void printTele(char **num, char *tele, char *out, int level) {
    if(level == strlen(tele)) {
        printf("%s\n", out);
        return;
    }
    int len = strlen(*(num + (tele[level] - '0')));
    int i;
    for(i = 0; i < len; i++) {
        out[level] = (*(num + (tele[level] - '0')))[i];
        printTele(num, tele, out, level + 1);
    }
}

main()
{
    char **num = (char **)malloc(10 * sizeof(char *));
    num[0] = (char *)malloc(3 * sizeof(char));
    memcpy(num[0], "ab", 2);
    num[0][2] = '\0';
    num[1] = (char *)malloc(4 * sizeof(char));
    memcpy(num[1], "cde", 3);
    num[1][3] = '\0';
    num[2] = (char *)malloc(4 * sizeof(char));
    memcpy(num[2], "fgh", 3);
    num[2][3] = '\0';

    char *tele = (char *)malloc(5 * sizeof(char));
    memcpy(tele, "0120", 4);
    tele[4] = '\0';
    char *out = (char *)malloc(5 * sizeof(char));
    out[4] = '\0';
    printTele(num, tele, out, 0);
}
