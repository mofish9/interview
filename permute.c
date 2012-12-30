#include <stdio.h>
#include <stdlib.h>

void permute(char *charset) {
    printf("%d\n", strlen(charset));
    int *used = (int *)malloc(sizeof(int) * strlen(charset));
    memset(used, 0, strlen(charset));
    char *out = (char *)malloc(sizeof(char) * (strlen(charset) + 1));
    out[strlen(charset)] = '\0';
    doPermute(charset, out, used, strlen(charset), 0);
    free(out);
    free(used);
}

void doPermute(char *charset, char *out, int *used, int length, int level) {
    if(level == length)
        printf("%s\n", out);
    int i = 0;
    for(i = 0; i < length; i++) {
        if(used[i] == 0) {
            out[level] = charset[i];
            used[i] = 1;
            doPermute(charset, out, used, length, level + 1);
            used[i] = 0;
        }
    }
}

main()
{
    char *charset = (char *)malloc(sizeof(char) * 6);
    memcpy(charset, "123", 3);
    charset[3] = '\0';
    permute(charset);
    free(charset);
}
