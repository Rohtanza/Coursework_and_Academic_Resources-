#include <stdio.h>
int MIN(int foo[]);
int MAX(int foo[]);
int Average(int foo[]);
void Even(int foo[]);
void Odd(int foo[]);
void Reverse(int foo[]);
int main()
{
    int foo[10];
    for (int i = 0; i < 10; i++)
        switch (i)
        {
        case 0:
            printf("Enter the %dst in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;
        case 1:
            printf("Enter the %dnd in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;
        case 2:
            printf("Enter the %drd in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;

        default:
            printf("Enter the %dth in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;
        }
    printf("\nMinimum value in the array:%d", MIN(foo));
    printf("\nMaximum value in the array:%d", MAX(foo));
    printf("\nAverage of the array is:%d", Average(foo));
    printf("\nLast Element of the array is:%d", foo[9]);
    printf("\nIndex 2 of the array is:%d", foo[1]);
    Even(foo);
    Odd(foo);
    Reverse(foo);
    return 0;
}
int MAX(int foo[])
{
    int max = foo[0];
    for (int i = 0; i < 10; i++)
    {
        if (foo[i] > max)
        {
            max = foo[i];
        }
    }
    return max;
}
int MIN(int foo[])
{
    int min = foo[0];
    for (int i = 0; i < 10; i++)
    {
        if (foo[i] < min)
        {
            min = foo[i];
        }
    }
    return min;
}
int Average(int foo[])
{
    int average = 0;
    for (int i = 0; i < 10; i++)
    {
        average = foo[i] + average;
    }
    return average / 10;
}
void Even(int foo[])
{
    printf("\nThe even elements in the array are:");
    for (int i = 0; i < 10; i++)
    {
        if (foo[i] % 2 == 0)
        {
            printf("%d ", foo[i]);
        }
    }
}
void Odd(int foo[])
{
    printf("\nThe Odd elements in the array are:");
    for (int i = 0; i < 10; i++)
    {
        if (foo[i] % 2 != 0)
        {
            printf("%d ", foo[i]);
        }
    }
}
void Reverse(int foo[])
{
    printf("\nThe Reverse of the array is:");
    for (int i = 9; i >= 0; i--)
    {
        printf("%d ", foo[i]);
    }
}