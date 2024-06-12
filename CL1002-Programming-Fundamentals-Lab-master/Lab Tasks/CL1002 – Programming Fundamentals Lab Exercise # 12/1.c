//Muhammad Rehan, 22P-9106,BSE-1A
#include <stdio.h>
int main()
{
    int x,y;
    int *a,*b;
    a=&x;
    b=&y;
    printf("Enter num1 & num 2:");
    scanf("%d %d",a,b);
    *a>*b?printf("\nx: %d is greater then y:%d",*a,*b):printf("\ny: %d is greater then x:%d",*b,*a);
    return 0;
}