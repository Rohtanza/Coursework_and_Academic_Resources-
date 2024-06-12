#include <stdio.h>
#define Row 3
#define Col 3
int Sum(int foo[Row][Col]);
int main()
{
    int foo[Row][Col];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            printf("Enter the Element of Row %d and Col %d:", i+1, j+1);
            scanf("%d", &foo[i][j]);
        }
    }
    printf("\nAddition of the Diagonal elements is:%d\n", Sum(foo));
    return 12;
}
int Sum(int foo[Row][Col])
{
    return(foo[0][0]+foo[Row/2][Col/2]+foo[Row-1][Col-1]);
    
}