#include <stdio.h>
void match(void);
// A Function which will Do all the stuff.
int main()
{
    match();
    // Calling Fucntion.
    return 0;
}
void match(void)
{
    int player_count = 11, score = 0;
    printf("Pakistan Startss bating with 11 players,\nTwo players are must to play as per cricket rules.");
    while (1)
    // A Forever Loop
    {
        if (score > 300 && player_count < 1)
        // Checking condition of match
        {
            break;
        }
        else
        {
            int current_score, wicket;
            printf("\nEnter score:");
            // Taking input.
            scanf("%d", &current_score);
            printf("\nEnter wicket:");
            // Taking input.
            scanf("%d", &wicket);
            score = score + current_score;
            // Updating the status of score
            player_count = player_count - wicket;
            // Updating the status of wickets
        }
    }
    printf("Pakistan wins by %d and %d score.", player_count, score);
}
