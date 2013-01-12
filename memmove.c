#include <stdio.h>
#include <stdlib.h>

void *memmove(void *dest, const void *src, int count) {
    if(dest && src) {
        if(src < dest && src + count - 1 >= dest) {
            src += count - 1;
            dest += count -1;
            while(count--) {
                *((char *)dest--) = *((char *)src--);
            }
        } else {
            while(count--) {
                *((char *)dest++) = *((char *)src++);
            }
        }
    }
    return dest;
}

main()
{
    char *dest = (char *)malloc(sizeof(char) * 5); 
    char *src = "abcde";
    printf("Dest: %d, Src: %d\n", dest, src);
    printf("%s\n", src);
    memmove(dest, src, 4);
    printf("%s\n", dest);
}
