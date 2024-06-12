#include <stdio.h>
int palindromic(int num);
int main()
{
    int num, count;
    int last;
    for (int i = 100; i <= 999; i++)
    {
        for (int j = 100; j <= 999; j++)
        {
            int n = i * j;
            // last = palindromic(n);
        }
    }
    printf("%d", last);
    printf("%d",906609);
    return 0;
}

int palindromic(int num)
{
    int last;
    int num_2 = num;
    int reverse = 0, rem;
    while (1)
    {
        if (num_2 == 0)
        {
            break;
        }
        else
        {
            rem = num_2 % 10;
            num_2 = num_2 / 10;
            reverse = reverse * 10 + rem;
        }
    }
    if (num == reverse)
    {
        last = num;
        return last;
    }
}
