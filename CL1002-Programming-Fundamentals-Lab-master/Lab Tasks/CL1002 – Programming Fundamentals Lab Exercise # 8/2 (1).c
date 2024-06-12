#include <stdio.h>
int main()
{
    int count = 0;
    int f[60];
    for (int i = 0; i < 20; i++)
    {
        f[i] = i * i;
    }
    for (int j = 20; j < 40; j++)
    {
        f[j] = j * j * j;
    }
    for (int k = 40; k < 60; k++)
    {
        f[k] = k + count;
        count++;
    }
    for (int z = 0; z < 60; z++)
    {

        if (z % 10 == 0)
        {
            printf("\n");
        }

        printf("%d ", f[z]);
    }
}