#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    int m = a;
    if(m > b)
        m = b;
    if(m > c)
        m = c;
    return m;
}

void printMaxSubSquare(int m[6][5], int r, int c) {
    int i, j;
    int s[r][c];
    int max_s, max_i, max_j;

    for(i = 0; i < r; i++)
        s[i][0] = m[i][0];
    for(i = 0; i < c; i++)
        s[0][i] = m[0][i];

    max_s = s[0][0];
    max_i = 0;
    max_j = 0;

    for(i = 1; i < r; i++) {
        for(j = 1; j < c; j++) {
            if(m[i][j] == 1) {
                s[i][j] = min(s[i][j - 1], s[i - 1][j], s[i - 1][j - 1]) + 1;
                if(s[i][j] > max_s) {
                    max_s = s[i][j];
                    max_i = i;
                    max_j = j;
                }
            } else 
                s[i][j] = 0;
        } 
    }

    printf("Maximum sub matrix is: \n");
    printf("%d %d %d\n", max_s, max_i, max_j);
    for(i = max_i; i > max_i - max_s + 1; i--) {
        for(j = max_j; j > max_j - max_s + 1; j--) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

main()
{
    int m[6][5] = {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    printMaxSubSquare(m, 6, 5);
}
