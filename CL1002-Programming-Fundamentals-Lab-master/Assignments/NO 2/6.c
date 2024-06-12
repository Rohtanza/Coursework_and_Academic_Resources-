#include <stdio.h>
#include <math.h>
//math library to use sqrt function.
void position(float current_x, float current_y, float next_x, float next_y);
//Fuction to calculate distance and steps
void operation();
//Function which will do all the operation
float distance_traveled;
// a Global varaible and i think global varaible are not a bad practice.
int main()
{
    operation();
    // Calling function
    return 0;
}
void operation(void)
{
    float next_x, next_y, current_x = 0, current_y = 0, count = 0;
    printf("Right now, You are at the origin where x and y are zero.");
    while (1)
    // Now this loop will keep asking input 
    {
        printf("\nEnter the x:");
        scanf("%f", &next_x);
        printf("Enter the y:");
        scanf("%f", &next_y);
        if (current_x != next_x && current_x != next_y)
        // Conditon to check if cordinates are same as previous
        {
            position(current_x, current_y, next_x, next_y);
            count++;
            current_x = next_x;
            current_y = next_y;
        }
        else
        {
            // Breaking if condition is not meet.
            break;
        }
    }
    printf("\nWalk ended because you added the same cordinates as prevoius.");
    printf("\n1.You Covered distance is %.2f", distance_traveled);
    printf("\n2.You took totol fo %.0f steps.", count - 1);
    printf("\n3.You'r average distance is %.2f", distance_traveled / count);
    return;
}
void position(float current_x, float current_y, float next_x, float next_y)
{
    float Current_distance = sqrt((next_x - current_x) * (next_x - current_x) + (next_y - current_y) * (next_y - current_y));
    distance_traveled = Current_distance + distance_traveled;
}