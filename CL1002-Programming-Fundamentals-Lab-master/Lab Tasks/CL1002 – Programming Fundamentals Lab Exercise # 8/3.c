#include <stdio.h>
void foo(int array[]);
int Check(int array[], int num);
int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num;
    foo(array);
    printf("Enter the element form the array:");
    scanf("%d", &num);
    printf("The Element %d occurs %d time in the array", num, Check(array,num));
    return 0;
}
int Check(int array[], int num)
{
    int count=0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == num)
        {
            count++;
        }
    }
    return count;
}
void foo(int array[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
}