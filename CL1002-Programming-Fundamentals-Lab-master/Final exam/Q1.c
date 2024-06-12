// Question no 01, Using pointer for the ease of my program.
#include <stdio.h>
float overs(int *a, int *b, int ballnumber);
int main()
{
    int ball_number;
    printf("Enter the ball delivered by the baller:\n");
    scanf("%d", &ball_number);
    int over, remaining;
    overs(&over,&remaining,ball_number);
    printf("%.d overs and %d were bowled by the bowler.\n", over,remaining);
    return 0;
}
float overs(int *a, int *b, int ballnumber)
{
    *a = ballnumber / 6;
    *b = ballnumber % 6;
    return 0.0 ;
}
