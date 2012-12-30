#include <stdio.h>
#include <stdlib.h>

int checkPalindrome(char *d) {
        int start = 0, end = 0;
            while(d[end] != '\0')
                        end++;
                            end--;
                                while(start < end) {
                                            if(d[start++] != d[end--])
                                                            return 0;
                                                                }
                                                                    return 1;
}

main()
{
        char *d = (char *)malloc(sizeof(char) * 10);
            if(d == NULL) {
                        printf("Memory allocation error.\n");
                                exit(-1);
                                    }
                                        memcpy(d, "abcdedcba", 9);
                                            d[9] = '\0';
                                                printf("%d\n", checkPalindrome(d));
                                                    free(d);
                                                        d = NULL;
}
