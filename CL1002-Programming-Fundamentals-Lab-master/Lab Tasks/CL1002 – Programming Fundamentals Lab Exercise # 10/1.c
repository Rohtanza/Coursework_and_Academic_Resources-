#include <stdio.h>
int Least_small_val(int A[], int size);
int main()
{
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    int A[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter the Element:");
        scanf("%d", &A[i]);
    }

    printf("The Least Minimun values is: %d", Least_small_val(A, size));
    return 0;
}
int Least_small_val(int A[], int size)
{
    {
    int min = A[0];
    int Second_min;
    if(A[0]==A[1])
     {Second_min= A[2];}
     else{Second_min=A[1];}
    for (int i = 0; i < size; i++)
    {
        if (A[i] < min)
        {

            Second_min=min;
            min=A[i];
        }
    }

    return Second_min;
}
}