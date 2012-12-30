#include <stdio.h>
#include <stdlib.h>

void multiplyTwoNum(char *a, char *b, char *res) {
    int len = strlen(a) + strlen(b);
    int i, j, r, v = 0, t;
    for(i = strlen(b) - 1; i >= 0; i --) {
        v = 0;
        for(j = strlen(a) - 1; j >= 0; j--) {
            r = ((int)(b[i] - '0') * (int)(a[j] - '0')) % 10;
            t = (int)(res[i + j + 1] - '0') + v + r;
            res[i + j + 1] = (char)(t % 10 + '0');
            v = t / 10 + ((int)(b[i] - '0') * (int)(a[j] - '0')) / 10;
        }
        while(v != 0) {
            t = (int)(res[i + j + 1] - '0') + v;
            res[i + j + 1] = (char)(t % 10 + '0');
            v = t / 10;
            j--;
        }
    }
    if(res[0] == '0') {
        for(i = 1; res[i] != '\0'; i++) {
            res[i - 1] = res[i];
        }
        res[i - 1] = '\0';
    }
    printf("%s\n", res);
}

main()
{
    char *a = "12345";
    char *b = "23456";
    int len = strlen(a) + strlen(b) + 1;
    char *res = (char *)malloc(len);
    memset(res, '0', len);
    res[len - 1] = '\0';
    multiplyTwoNum(a, b, res);
    free(res);
}
