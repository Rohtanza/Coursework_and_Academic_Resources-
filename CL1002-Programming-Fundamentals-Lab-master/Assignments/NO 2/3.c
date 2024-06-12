#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Inclduing Librabries
int main()
{
    // I experimented with int and float both but was getting the ouput nan.
    //Googled it and it came out i should use double.
    double a, b, c, disc;
    printf("\nEnter a:");
    scanf("%lf", &a);
    printf("Enter b:");
    scanf("%lf", &b);
    printf("Enter c:");
    scanf("%lf", &c);

    disc = (b * b) - (4 * a * c);
    //Calculing Disc

    if (disc > 0)
    //Checking the nature of disc
    {
        printf("The First Root is %.3lf",(-b + sqrt(disc)) / (2 * a));
        printf("\nThe Second Root is %.3lf\n",(-b - sqrt(disc)) / (2 * a));
    }
    if (disc == 0)
    //Checking the nature of disc
    {
        printf("The First root is equal to the Second root = %.3lf;\n",-b / (2 * a));
    }
    if (disc < 0)
    //Checking the nature of disc
    {
        double real = -b / (2 * a);
        double imaginary = sqrt(-disc) / (2 * a);
        printf("The First Root is = %.1lf+%.1lfi", real, imaginary);
        printf("\nThe Second Root is = %.1lf-%.1lfi\n", real, imaginary);
        //Now i was failing here, tried everything but then i researched it on google and it came out that i should consule out the resutl like this. declaring two double and then calculating and displaiying them differently.
    }
    return 0;
}