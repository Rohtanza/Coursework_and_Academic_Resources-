/*
    INSTRUCTIONS: 
    This program calculates and compares the execution time of computing the Fibonacci sequence for values from 0 to an upper bound ('upperBound').
    It utilizes both recursive and iterative methods, displaying the computation time in milliseconds for each 'n' value.

    - Main function:
    It calls the respective function from 0 to the upper bound and checks the time taken for each call upto n.

    Note:
    - Using 'upperBound' allows us to observe the time difference in Fibonacci calculations for different 'n' values.
    - Going above n = 50 is impractical as recursion takes a large amount of time.
*/

#include <iostream>
#include <chrono>
#include <iomanip>

// Recursive Fibonacci function
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci function
int fibonacciIterative(int n) {
    if (n <= 1)
        return n;

    int prev = 0;
    int current = 1;
    for (int i = 2; i <= n; ++i) {
        int next = prev + current;
        prev = current;
        current = next;
    }
    return current;
}

int main() {
    int upperBound;
    std::cout << "Enter the upper bound value: ";
    std::cin >> upperBound;

    std::cout << "n\tRecursive Time\tIterative Time" << std::endl;
    std::cout << "\t (Miliseconds)\t (Miliseconds)" << std::endl;

    for (int n = 0; n <= upperBound; ++n) {
        // Measure time for recursive Fibonacci
        auto startRecursive = std::chrono::high_resolution_clock::now();
        int resultRecursive = fibonacciRecursive(n);
        auto endRecursive = std::chrono::high_resolution_clock::now();
        auto durationRecursive = std::chrono::duration_cast<std::chrono::microseconds>(endRecursive - startRecursive);

        // Measure time for iterative Fibonacci
        auto startIterative = std::chrono::high_resolution_clock::now();
        int resultIterative = fibonacciIterative(n);
        auto endIterative = std::chrono::high_resolution_clock::now();
        auto durationIterative = std::chrono::duration_cast<std::chrono::microseconds>(endIterative - startIterative);

        std::cout << std::setw(2) << n << "\t" << std::setw(14) << durationRecursive.count() << "\t" << std::setw(14) << durationIterative.count() << std::endl;
    }

    return 0;
}
