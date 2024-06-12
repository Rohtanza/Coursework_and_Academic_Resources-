#include <iostream>
#include <vector>
#include <algorithm>

int max_carrots(int N) {
    std::vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 3; j < i; j++) {
            dp[i] = std::max(dp[i], dp[i - j] * (j - 1));
        }
    }
    return dp[N];
}

int main() {
    int T;
    std::cin >> T;
    std::vector<int> results;
    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        int result = max_carrots(N);
        results.push_back(result);
    }
    for (int result: results) {
        std::cout << result << std::endl;
    }
    return 0;
}
