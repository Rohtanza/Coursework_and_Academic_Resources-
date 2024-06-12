 def max_carrots(N):
    # Create a list to store the maximum carrots for each jump
    dp = [0] * (N + 1)

    for i in range(1, N + 1):
        # Initialize the maximum carrots for this jump with jumping on a Red pad
        dp[i] = dp[i - 1] + 1

        # Check if we can perform the Yellow pad sequence
        for j in range(3, i):
            dp[i] = max(dp[i], dp[i - j] * (j - 1))

    return dp[N]

# Read the number of test cases
T = int(input())
results = []

# Process each test case
for _ in range(T):
    N = int(input())
    result = max_carrots(N)
    results.append(result)

# Print the results for each test case
for result in results:
    print(result)
