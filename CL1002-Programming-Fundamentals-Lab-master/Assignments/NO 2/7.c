#include <stdio.h>
int main()
{
    int n = 5;
    for (int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
          printf("%d",i);
        }
        printf("\n");
    }
}
{
    int n = 5;
    for (int i = 0; i <= n; i++)
    {
        for (int z = n; z < 1; z--)
        {
            printf("-");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}