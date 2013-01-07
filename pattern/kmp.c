#include <stdio.h>
#include <stdlib.h>

/**
 * KMP
 * Whenever we detect a mismatch (after some matches), we already know some of the characters in the text.
 * We take advantage of this information to avoid matching the characters that we know will anyway match. 
 *
 **/

void getNext(char *pattern, int M, int *next) {
    int len = 0, i;
    next[0] = 0;
    i = 1;
    while(i < M) {
        if(pattern[i] == pattern[len]) {
            len++;
            next[i] = len;
            i++;
        } else {
            if(len != 0)
                len = next[len - 1];
            else {
                next[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);

    int *next = (int *)malloc(sizeof(int) * M);

    getNext(pattern, M, next);

    printf("%s\n", pattern);
    int x = 0;
    for(x = 0; x < M; x++)
        printf("%d ", next[x]);
    printf("\n");

    int i = 0, j = 0;
    while(i < N) {
        if(pattern[j] == text[i]) {
            j++;
            i++;
        }
        if(j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = next[j - 1];
        } else if(pattern[j] != text[i]) {
            if(j != 0)
                j = next[j - 1];
            else 
                i++;
        }
    }
    free(next);
}

main()
{
    char *text = "ABABDABACDABABCABAB";
    char *pattern = "ABABCABAB";
    kmp(pattern, text);
}
