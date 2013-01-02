#include <stdio.h>
#include <stdlib.h>

void findPaths(int x1, int y1, int x2, int y2, int *count) {
    if(x1 > x2 || y1 > y2)
        return;
    if(x1 == x2 && y1 == y2) {
        (*count)++;
        return;
    }
    findPaths(x1 + 1, y1, x2, y2, count);
    findPaths(x1, y1 + 1, x2, y2, count);
}

main()
{
    int count = 0;
    findPaths(0, 0, 1, 1, &count);
    printf("%d\n", count);
}
