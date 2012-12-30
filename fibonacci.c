#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printFibonacci(int n) {
    if(n == 1 || n == 2){
        printf("1\n");
        return;
    }
    int first = 1, second = 1, i, third;
    for(i = 2; i < n; i++) {
        third = first + second;
        first = second;
        second = third;
    }
    printf("%d\n", third);
}

main()
{
    printFibonacci(1);
    printFibonacci(2);
    printFibonacci(3);
    printFibonacci(4);
    printFibonacci(5);
    printFibonacci(6);
}
