#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int *b, int n) {
        int aIndex = 0, bIndex = n;
            int i = 0;
                for(i = 0; i < n; i++)
                            b[i + n] = b[i];
                                for(i = 0; i < 2 * n; i++) {
                                            if(a[aIndex] < b[bIndex])
                                                            b[i] = a[aIndex++];
                                                                    else
                                                                                    b[i] = b[bIndex++];
                                                                                        }
}

main()
{
        int n = 5;
            int *a = (int*)malloc(sizeof(int) * n);
                int *b = (int*)malloc(sizeof(int) * 2 * n);
                    int i = 0;
                        for( i = 0; i < n; i++) {
                                    a[i] = i;
                                            b[i] = 2 * i;
                                                }
                                                    merge(a, b, n);
                                                        for(i = 0; i < 2 * n; i++)
                                                                    printf("%d ", b[i]);
                                                                        printf("\n");
}
