// Code of S=nΣk=0x^k/! is Created by Muhammad Rehan 22P-9106
#include <stdio.h>
float fac(float k);
float power(float k, float x);
float res(float n, float x);
int main()
{
    float n, x, j;
    printf("\nEnter n : ");scanf("%f",&n);
    printf("Enter x : ");scanf("%f",&x);
    printf("\n\"S=nΣk=0x^k/!\" is equal to \"%.2f \"\n", res(n, x));
    return 0;
}
float res(float n, float x)
{
    float sum = 0;
    for (float j = 0; j <= n; j++)
    {
        sum = (power(x, j) / fac(j)) + sum;
    }
    return sum;
}
float power(float j, float x)
{
    float y = 1;
    for (int i = 1; i <= x; i++)
    {
        y = y * j;
    }
    return y;
}

float fac(float j)
{
    float f = 1;
    for (float i = 1; i <= j; ++i)
    {
        f = f * i;
    }
    return f;
}