#include <stdio.h>
#define Row 4
#define Col 3
void GetData(int foo[Row][Col]);
int small_element(int foo[Row][Col]);
int large_element(int foo[Row][Col]);
int main()
{
    int foo[Row][Col];
    int min, max;
    GetData(foo);
    min = small_element(foo);
    max = large_element(foo);
    printf("\nThe min is %d\nThe max is %d \n", min, max);
    return 0;
}
void GetData(int foo[Row][Col])
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            printf("Enter the Element of Row %d and Col %d:", i+1, j+1);
            scanf("%d", &foo[i][j]);
        }
    }
}
int small_element(int foo[Row][Col])
{
    int min = foo[0][0];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (foo[i][j] < min)
            {
                min = foo[i][j];
            }
        }
    }
    return min;
}

int large_element(int foo[Row][Col])
{
    int max = foo[0][0];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (foo[i][j] > max)
            {
                max = foo[i][j];
            }
        }
    }
    return max;
}
