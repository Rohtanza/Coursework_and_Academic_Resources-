#include <stdio.h>
void find_small_val(int A[],int size);
int main()
{
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    int A[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element:");
        scanf("%d", &A[i]);
    }
    find_small_val(A,size);
    return 0;
}
void find_small_val(int A[],int size)
{
    int num = 1;
    while (1)
    {

        int checker = 0;
        for (int i = 0; i < size; i++)
        {
            if (num == A[i])
            {
                checker++;
            }
        }
        if (checker == 0)
        {
            printf("%d", num);
            break;
        }
        num++;
    }
}
