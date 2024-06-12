#include <stdio.h>
#include <stdbool.h>
int main()
{
    int lenght;
    printf("Enter the lenth of the stock array:");
    scanf("%d", &lenght);
    int stocks[lenght];
    puts("Enter the stocks:");
    for (int i = 0; i < lenght; i++)
    {
        printf("\tEnter the stock#%d : ", i + 1);
        scanf("%d", &stocks[i]);
    }

    int profit;
    int buyday = 2;
    int sellday = (4) + buyday;
    while (true)
    {
        if (sellday > lenght)
            break;
        if (stocks[sellday] > stocks[buyday])
        {
            profit = stocks[sellday] - stocks[buyday];
            // printf("the %d is > %d\n", stocks[sellday], stocks[buyday]);   
            //The above line is for testing
        }
        else
            printf("the %d is < %d\n", stocks[sellday], stocks[buyday]);
        buyday = sellday + 2;
        sellday = buyday + 4;
    }
    if (profit <= 0)
        profit = -1;
    printf("the profit is %d\n", profit);
    return 0;
}
