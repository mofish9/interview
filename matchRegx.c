#include <stdio.h>
#include <stdlib.h>

int match(char *text, char *pattern, int tPos, int pPos) {
    int lenText = strlen(text), lenP = strlen(pattern);
    if(lenP == 0)
        return 0;
    if(pattern[pPos] == '*') {
        if(pPos == lenP - 1)
            return 1;
        return matchStar(text, pattern, tPos, pPos + 1);
    } else if(lenText == 0 || tPos >= lenText) {
        return 0;
    } else if(text[tPos] == pattern[pPos]) {
        if(tPos == lenText - 1 && pPos == lenP - 1)
            return 1;
        else if(pPos < lenP - 1)
            return match(text, pattern, tPos + 1, pPos + 1);
        else
            return 0;
    } else {
        return 0;
    }
}

int matchStar(char *text, char *pattern, int tPos, int pPos) {
    int lenText = strlen(text), i = tPos;
    for(; i < lenText; i++) {
        if(match(text, pattern, i, pPos))
            return 1;
    }
    return 0;
}

main()
{
    char *text = "12345";
    char *pattern = "*45*";
    printf("%d\n", match(text, pattern, 0, 0));
}
