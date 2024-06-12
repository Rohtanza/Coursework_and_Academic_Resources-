#include <stdio.h>
#include <math.h>

int main(void)
{
    int dist = 0, steps = 0, temp;

    // The object starts off at the “origin” (x = 0 and y = 0)
    int x0 = 0, y0 = 0, x1 = 0, y1 = 0;

    printf("\n");

    while (1)
    {
        // You will input two real numbers that will represent the next coordinates of the object
        printf("Input 2 Real Numbers (x1 y1): ");
        scanf("%d %d", &x1, &y1);

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        else
        {
            dist += sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))); // Use the following formula to calculate the distance of the step
            steps++;
            x0 = x1;
            y0 = y1;

        }
    }

    if (steps != 0)
    {
        printf("\nDistance Is: %d\n", dist);
        printf("Steps Are: %d\n", steps);
        printf("Average Distance Per Steps Is: %d\n\n", dist / steps); // will display 0 if object returns to origin
    }

    else
    {
        printf("No Steps Traveled!\n\n");
    }

    return 0;
}