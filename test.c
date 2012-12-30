#include<stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int strlen(char *s) 
{
	int result = 0;
	for(; *s != '\0'; s++)
		result++;
	return result;
}

main()
{
	int a = 0, b = 1;
	int *x, *y;
	x = &a;
	y = &b;
	swap(x, y);
	printf("%d\t%d\n", a, b);

	int result = strlen("Hello World");
	printf("%d\n", result);
}
