#include <stdio.h>
#include <stdlib.h>

// Function to convert a card rank character to its numerical value
int card_rank(char rank) {
    switch (rank) {
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default: return -1; // Invalid rank
    }
}

// Function to get the hand's values from a line of input
void parse_poker_hand(const char* hand_str, int hand_ranks[5], char hand_suits[5]) {
    int index = 0;
    while (*hand_str && index < 5) {
        if (*hand_str == ' ') {
            hand_str++;
            continue;
        }

        hand_ranks[index] = card_rank(*hand_str); // Get card rank
        hand_suits[index] = *(hand_str + 1); // Get card suit
        index++;
        hand_str += 2; // Move to the next card
    }

    // Sort the hand by rank
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (hand_ranks[i] > hand_ranks[j]) {
                int temp_rank = hand_ranks[i];
                char temp_suit = hand_suits[i];
                hand_ranks[i] = hand_ranks[j];
                hand_suits[i] = hand_suits[j];
                hand_ranks[j] = temp_rank;
                hand_suits[j] = temp_suit;
            }
        }
    }
}

// Function to check if a poker hand is a flush
int is_flush(const char suits[5]) {
    char suit = suits[0];
    for (int i = 1; i < 5; i++) {
        if (suits[i] != suit) {
            return 0; // Not a flush
        }
    }
    return 1; // It is a flush
}

// Function to check if a poker hand is a straight
int is_straight(const int ranks[5]) {
    for (int i = 1; i < 5; i++) {
        if (ranks[i] != ranks[i - 1] + 1) {
            return 0; // Not a straight
        }
    }
    return 1; // It is a straight
}

// Function to evaluate a poker hand and determine its rank
int evaluate_poker_hand(const int ranks[5], const char suits[5]) {
    int rank_count[15] = {0};
    for (int i = 0; i < 5; i++) {
        rank_count[ranks[i]]++;
    }

    int pairs = 0;
    int triples = 0;
    int quads = 0;

    for (int i = 2; i <= 14; i++) {
        if (rank_count[i] == 2) {
            pairs++;
        } else if (rank_count[i] == 3) {
            triples++;
        } else if (rank_count[i] == 4) {
            quads++;
        }
    }

    if (quads == 1) {
        return 8; // Four of a kind
    } else if (triples == 1 && pairs == 1) {
        return 7; // Full house
    } else if (is_flush(suits)) {
        if (is_straight(ranks)) {
            if (ranks[0] == 10) {
                return 9; // Royal flush
            }
            return 6; // Straight flush
        }
        return 5; // Flush
    } else if (is_straight(ranks)) {
        return 4; // Straight
    } else if (triples == 1) {
        return 3; // Three of a kind
    } else if (pairs == 2) {
        return 2; // Two pairs
    } else if (pairs == 1) {
        return 1; // One pair
    }

    return 0; // High card
}

// Function to compare two poker hands and determine the winner
int compare_poker_hands(const int ranks1[5], const char suits1[5], const int ranks2[5], const char suits2[5]) {
    int rank1 = evaluate_poker_hand(ranks1, suits1);
    int rank2 = evaluate_poker_hand(ranks2, suits2);

    if (rank1 > rank2) {
        return 1; // Hand 1 is better
    } else if (rank2 > rank1) {
        return -1; // Hand 2 is better
    }

    // If ranks are the same, compare high cards
    for (int i = 4; i >= 0; i--) { // Start from the highest card
        if (ranks1[i] > ranks2[i]) {
            return 1;
        } else if (ranks1[i] < ranks2[i]) {
            return -1;
        }
    }

    return 0; // The hands are equal
}

int main() {
    char input[256];

    while (fgets(input, sizeof(input), stdin) != NULL) {
        int hand1_ranks[5], hand2_ranks[5];
        char hand1_suits[5], hand2_suits[5];

        // First poker hand
        parse_poker_hand(strtok(input, "|"), hand1_ranks, hand1_suits);

        // Second poker hand
        parse_poker_hand(strtok(NULL, "|"), hand2_ranks, hand2_suits);

        int result = compare_poker_hands(hand1_ranks, hand1_suits, hand2_ranks, hand2_suits);

        if (result > 0) {
            printf("Player 1 wins.\n");
        } else if (result < 0) {
            printf("Player 2 wins.\n");
        } else {
            printf("It's a tie.\n");
        }
    }

    return 0;
}

