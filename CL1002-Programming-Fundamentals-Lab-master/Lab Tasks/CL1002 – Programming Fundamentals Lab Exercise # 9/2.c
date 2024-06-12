#include <stdio.h>
int main()
{
    int Row, Col, i, j;
    printf("Enter the size of the Matrix:");
    scanf("%d%d", &Row, &Col);
    int foo[Row][Col];
    for (i = 0; i < Row; i++)
    {
        for (j = 0; j < Col; j++)
        {
            printf("Enter the element for Row %d and Col %d:", i+1, j+1);
            scanf("%d", &foo[i][j]);
        }
    }
    printf("\nYour Array is:\n");
    for (int i = 0; i < Row; i++)
    {
        printf("\n");
        for (j = 0; j < Col; j++)
        {
            printf("%d ", foo[i][j]);
        }
    }
    printf("\n\nThe Transpose is:\n");
    for (int j = 0; j < Row; j++)
    {
        printf("\n");
        for (i = 0; i < Col; i++)
        {
            printf("%d ", foo[i][j]);
        }
    }
    printf("\n");
    return 0;
}