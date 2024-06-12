#include <limits.h>
#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen(__FILE__, "r");
    char c;
    while ((c = getc(fp)) != EOF)
        putchar(c);
    printf("The max of int is%d and the min of int is %d", INT_MAX, INT_MIN);
    return 0;
}
