#include <stdio.h>
#include <stdlib.h>
#define oldage 65
#define C_M_Y 10
#define C_M_O 5
#define N_M 20
// DEfining all the contants i will use in the program
int main()
{
    char memebership;
    int age;
    printf("Hi there,\nKindly Enter your status,(M for Members & N for Non-Members):");
    scanf("%c", &memebership);
    printf("\nEnter your age:");
    scanf("%d", &age);
    switch (memebership)
    // Using swtich to identify membership status.
    {
    case 'M':
        if (age < oldage)
        //Checking the condition for age.
        {
            printf("\nYour fee is $%d\n", C_M_Y);
        }
        if (age >= oldage)
        //Checking the condition for age.
        {
            printf("\nYour fee is $%d\n", C_M_O);
        }
        break;
    case 'm':
        if (age < oldage)
        //Checking the condition for age.
        {
            printf("\nYour fee is $%d\n", C_M_Y);
        }
        if (age >= oldage)
        //Checking the condition for age.
        {
            printf("\nYour fee is $%d\n", C_M_O);
        }
        break;
    case 'N':
        printf("\nYour fee is $%d\n", N_M);
        //If Non member then fee is same regardless of age.
        break;
    case 'n':
        printf("\nYour fee is $%d\n", N_M);
        //If Non member then fee is same regardless of age.
        break;
            default : printf("\nKindly enter a valid input for membership status.\n");
            //If user enter invalid character for membership status.
        break;
    }
}