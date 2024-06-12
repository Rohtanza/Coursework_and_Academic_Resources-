#include <stdio.h>
void Seat(char seats[13][6]);
void display(char seats[13][6]);
int main()
{
    char seats[13][6];
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            seats[i][j] = '*';
        }
    }
    Seat(seats);
    int try = 1;
    while (try)
    {
        printf("\nWould you like to try again(1 for Yes and anyother for No):");
        scanf("%d", &try);
        if (try != 1)
            break;
        Seat(seats);
    }
    display(seats);
    return 0;
}
void Seat(char seats[13][6])
{
    char ticket_type;
    int Rownumber;
    int seatnumber;

    printf("Hello,\nKindly Enter Ticket Type:\n=>\nF* for Frist Class\nB* for Bussniess Class\nE* for Economy.\n");
    scanf("\n%c", &ticket_type);
    switch (ticket_type)
    {
    case 'f':
        printf("Kindly your Desired Row Number(Between 1 and 2):");
        scanf("%d", &Rownumber);
        if (Rownumber > 2)
        {
            puts("kindly enter between 1 and 2 as you are in Seating for First class\nTry agian.");
            return;
        }
        else
        {
            char seatno;
            printf("Kindly Enter your Desired Seat Alphabat (Between A and F):");
            scanf("\n%c", &seatno);
            if (seatno != 'A' && seatno != 'B' && seatno != 'C' && seatno != 'D' && seatno != 'E' && seatno != 'F')
            {

                puts("kindly enter between A and F as \nTry agian.");
                return;
            }
            else
            {

                if (seatno == 'A')
                    seatnumber = 0;
                if (seatno == 'B')
                    seatnumber = 1;
                if (seatno == 'C')
                    seatnumber = 2;
                if (seatno == 'D')
                    seatnumber = 3;
                if (seatno == 'E')
                    seatnumber = 4;
                if (seatno == 'F')
                    seatnumber = 5;
            }
            if (seats[Rownumber - 1][seatnumber] != 'X')
            {

                seats[Rownumber - 1][seatnumber] = 'X';
                puts("your seat is booked.");
            }
            else
            {
                puts("Sorry the seat is occupied/try again.");
                return;
            }
        }
        break;
    case 'F':
        printf("Kindly your Desired Row Number(Between 1 and 2):");
        scanf("%d", &Rownumber);
        if (Rownumber > 2)
        {
            puts("kindly enter between 1 and 2 as you are in Seating for First class\nTry agian.");
            return;
        }
        else
        {
            char seatno;
            printf("Kindly Enter your Desired Seat Alphabat (Between A and F):");
            scanf("\n%c", &seatno);
            if (seatno != 'A' && seatno != 'B' && seatno != 'C' && seatno != 'D' && seatno != 'E' && seatno != 'F')
            {

                puts("kindly enter between A and F as \nTry agian.");
                return;
            }
            else
            {

                if (seatno == 'A')
                    seatnumber = 0;
                if (seatno == 'B')
                    seatnumber = 1;
                if (seatno == 'C')
                    seatnumber = 2;
                if (seatno == 'D')
                    seatnumber = 3;
                if (seatno == 'E')
                    seatnumber = 4;
                if (seatno == 'F')
                    seatnumber = 5;
            }
            if (seats[Rownumber - 1][seatnumber] != 'X')
            {

                seats[Rownumber - 1][seatnumber] = 'X';
                puts("your seat is booked.");
            }
            else
            {
                puts("Sorry the seat is occupied/try again.");
                return;
            }
        }
        break;
    case 'B':
        printf("Kindly your Desired Row Number(Between 3 and 7):");
        scanf("%d", &Rownumber);
        if (Rownumber > 7 && Rownumber < 3)
        {
            puts("kindly enter between 3 and 7 as you are in Seating for Bussniess class\nTry agian.");
            return;
        }
        else
        {
            char seatno;
            printf("Kindly Enter your Desired Seat Alphabat (Between A and F):");
            scanf("\n%c", &seatno);
            if (seatno != 'A' && seatno != 'B' && seatno != 'C' && seatno != 'D' && seatno != 'E' && seatno != 'F')
            {

                puts("kindly enter between A and F as \nTry agian.");
                return;
            }
            else
            {

                if (seatno == 'A')
                    seatnumber = 0;
                if (seatno == 'B')
                    seatnumber = 1;
                if (seatno == 'C')
                    seatnumber = 2;
                if (seatno == 'D')
                    seatnumber = 3;
                if (seatno == 'E')
                    seatnumber = 4;
                if (seatno == 'F')
                    seatnumber = 5;
            }
            if (seats[Rownumber - 1][seatnumber] != 'X')
            {
                seats[Rownumber - 1][seatnumber] = 'X';
                puts("your seat is booked.");
            }
            else
            {
                puts("Sorry the seat is occupied/try again.");
                return;
            }
        }
        break;
    case 'b':
        printf("Kindly your Desired Row Number(Between 3 and 7):");
        scanf("%d", &Rownumber);
        if (Rownumber > 7 && Rownumber < 3)
        {
            puts("kindly enter between 3 and 7 as you are in Seating for Bussniess class\nTry agian.");
            return;
        }
        else
        {
            char seatno;
            printf("Kindly Enter your Desired Seat Alphabat (Between A and F):");
            scanf("\n%c", &seatno);
            if (seatno != 'A' && seatno != 'B' && seatno != 'C' && seatno != 'D' && seatno != 'E' && seatno != 'F')
            {

                puts("kindly enter between A and F as \nTry agian.");
                return;
            }
            else
            {

                if (seatno == 'A')
                    seatnumber = 0;
                if (seatno == 'B')
                    seatnumber = 1;
                if (seatno == 'C')
                    seatnumber = 2;
                if (seatno == 'D')
                    seatnumber = 3;
                if (seatno == 'E')
                    seatnumber = 4;
                if (seatno == 'F')
                    seatnumber = 5;
            }
            if (seats[Rownumber - 1][seatnumber] != 'X')
            {
                seats[Rownumber - 1][seatnumber] = 'X';
                puts("your seat is booked.");
            }
            else
            {
                puts("Sorry the seat is occupied/try again.");
                return;
            }
        }
        break;
    case 'E':
        printf("Kindly your Desired Row Number(Between 8 and 13):");
        scanf("%d", &Rownumber);
        if (Rownumber > 13 && Rownumber < 8)
        {
            puts("kindly enter between 8 and 13 as you are in Seating for Economy class\nTry agian.");
            return;
        }
        else
        {
            char seatno;
            printf("Kindly Enter your Desired Seat Alphabat (Between A and F):");
            scanf("\n%c", &seatno);
            if (seatno != 'A' && seatno != 'B' && seatno != 'C' && seatno != 'D' && seatno != 'E' && seatno != 'F')
            {

                puts("kindly enter between A and F as \nTry agian.");
                return;
            }
            else
            {

                if (seatno == 'A')
                    seatnumber = 0;
                if (seatno == 'B')
                    seatnumber = 1;
                if (seatno == 'C')
                    seatnumber = 2;
                if (seatno == 'D')
                    seatnumber = 3;
                if (seatno == 'E')
                    seatnumber = 4;
                if (seatno == 'F')
                    seatnumber = 5;
            }
            if (seats[Rownumber][seatnumber] != 'X')
            {
                seats[Rownumber][seatnumber] = 'X';
                puts("your seat is booked.");
            }
            else
            {
                puts("Sorry the seat is occupied/try again.");
                return;
            }
        }
        break;
    case 'e':
        printf("Kindly your Desired Row Number(Between 8 and 13):");
        scanf("%d", &Rownumber);
        if (Rownumber > 13 && Rownumber < 8)
        {
            puts("kindly enter between 8 and 13 as you are in Seating for Economy class\nTry agian.");
            return;
        }
        else
        {
            char seatno;
            printf("Kindly Enter your Desired Seat Alphabat (Between A and F):");
            scanf("\n%c", &seatno);
            if (seatno != 'A' && seatno != 'B' && seatno != 'C' && seatno != 'D' && seatno != 'E' && seatno != 'F')
            {

                puts("kindly enter between A and F as \nTry agian.");
                return;
            }
            else
            {

                if (seatno == 'A')
                    seatnumber = 0;
                if (seatno == 'B')
                    seatnumber = 1;
                if (seatno == 'C')
                    seatnumber = 2;
                if (seatno == 'D')
                    seatnumber = 3;
                if (seatno == 'E')
                    seatnumber = 4;
                if (seatno == 'F')
                    seatnumber = 5;
            }
            if (seats[Rownumber - 1][seatnumber] != 'X')
            {
                seats[Rownumber - 1][seatnumber] = 'X';
                puts("your seat is booked.");
            }
            else
            {
                puts("Sorry the seat is occupied/try again.");
                return;
            }
        }
        break;
    default:
        puts("kindly read the menu carefully\nand then enter your options");
        break;
    }
}
void display(char seats[13][6])
{
    int display;
    printf("Would you like to see your booking on display ( 1 for yes, another for no) :");
    scanf("%d", &display);
    switch (display)
    {
    case 1:
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("%c ", seats[i][j]);
            }
            printf("\n");
        }
        return;
        break;

    default:
        return;
        break;
    }

    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }
}
