#include <stdio.h>

// Function to calculate the Collatz sequence length for a given starting number
long collatz_length(long n) {
    long length = 1; // The starting number is included in the sequence
    while (n > 1) {
        if (n % 2 == 0) { // If even, divide by 2
            n = n / 2;
        } else { // If odd, multiply by 3 and add 1
            n = 3 * n + 1;
        }
        length++; // Increment the sequence length
    }
    return length; // Return the sequence length when it reaches 1
}

// Function to find the starting number under a given limit that produces the longest Collatz sequence
long longest_collatz_sequence(long limit) {
    long longest_start = 1; // The starting number with the longest sequence
    long longest_length = 1; // The length of the longest sequence

    for (long i = 2; i < limit; i++) { // Iterate through all starting numbers
        long length = collatz_length(i); // Calculate the sequence length
        if (length > longest_length) { // Update the longest sequence if found
            longest_start = i;
            longest_length = length;
        }
    }

    printf("The starting number %ld produces the longest Collatz sequence with length %ld.\n", longest_start, longest_length);

    return longest_start; // Return the starting number with the longest sequence
}

int main() {
    long limit;
    printf("Enter the limit for the starting numbers: "); // Get the upper limit
    scanf("%ld", &limit); // Read the upper limit
    if (limit < 2) { // Ensure the limit is greater than 1
        printf("The limit must be greater than 1.\n");
        return 1; // Exit if the limit is invalid
    }

    longest_collatz_sequence(limit); // Find the starting number with the longest Collatz sequence

    return 0; // Program completed successfully
}

