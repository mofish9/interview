#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if(a < b && a < c) return a;
    if(b < a && b < c) return b;
    if(c < a && c < b) return c;
}

int editDistance(char *a, char *b) {
    int alen = strlen(a), blen = strlen(b);
    int dis[alen + 1][blen + 1];
    int i, j;
    for(i = 0; i < alen + 1; i++)
        for(j = 0; j < blen + 1; j++)
            dis[i][j] = 0;
    for(i = 0; i < alen + 1; i++)
        dis[i][0] = i;
    for(j = 0; j < blen + 1; j++)
        dis[0][j] = j;
    for(i = 1; i < alen + 1; i++) {
        for(j = 1; j < blen + 1; j++) {
            int t = dis[i - 1][j - 1];
            if(a[i - 1] != b[j - 1])
                t++;
            dis[i][j] = min(dis[i - 1][j] + 1, dis[i][j - 1] + 1, t);
        }
    }
    return dis[alen][blen];
}

main()
{
    char *a = "abcd";
    char *b = "ace";
    printf("%d\n", editDistance(a, b));
}
