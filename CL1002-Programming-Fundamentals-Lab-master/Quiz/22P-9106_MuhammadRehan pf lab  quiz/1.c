#include <stdio.h>
int main()
{
    // Decalaring the array
    int foo[9];
    int prime = 0;
    // A variable to keep the prime number count
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
        case 0:
            printf("Enter the %dst in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;
        case 1:
            printf("Enter the %dnd in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;
        case 2:
            printf("Enter the %drd in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;

        default:
            printf("Enter the %dth in the foo array:", (i + 1));
            scanf("%d", &foo[i]);
            break;
        }
    }
    for (int i = 0; i < 9; i++) // A outer loop which which test each element in the array
    {
        int flag = 0;
        // A varaible to keep count of factors in the element of array which give zero on module with running loop number
        for (int j = 1; j <= foo[i]; j++)
        {
            if (foo[i] % j == 0)   // Checking if j is factor of i element of tha array
            {
                flag = flag + 1;
                // if its a factor then updating the factor count
            }
        }
        if (flag == 2)
        {
            // if i index of array is prime then updating the prime count.
            prime++;
        }
    }
    printf("\nThere are %d prime number(s) in the array \n\n", prime);
    // Printing the prime number count in the array.
    return 0;
}
