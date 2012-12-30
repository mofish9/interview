#include <stdio.h>
#include <stdlib.h>

int LCS(char *a, char *b) {
    int la = strlen(a), lb = strlen(b);
    int **L = (int **)malloc((la + 1) * sizeof(int *));
    int i, j;
    for(i = 0; i < la + 1; i++) {
        L[i] = (int*)malloc((lb + 1) * sizeof(int));
        memset(L[i], 0, lb + 1);
    }
    int max = 0, max_i = 0, max_j = 0;
    for(i = 1; i <= la; i++) {
        for(j = 1; j <= lb; j++) {
            if(a[i - 1] == b[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                if(L[i][j] > max) {
                    max = L[i][j];
                    max_i = i;
                    max_j = j;
                }
            } else {
                L[i][j] = 0;
            }
        }
    }
    return max;
}

main()
{
    char *a = "abcdef";
    char *b = "adcdff";
    printf("%d\n", LCS(a, b));
}
