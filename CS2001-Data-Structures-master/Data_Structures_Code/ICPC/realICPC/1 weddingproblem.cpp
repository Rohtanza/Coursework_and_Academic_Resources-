#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int M, C;
        cin >> M >> C;
        vector<vector<int>> garments(C);
        for(int i = 0; i < C; i++) {
            int K;
            cin >> K;
            garments[i].resize(K);
            for(int j = 0; j < K; j++) {
                cin >> garments[i][j];
            }
        }
        vector<vector<int>> dp(C+1, vector<int>(M+1, -1));
        dp[0][0] = 0;
        for(int i = 0; i < C; i++) {
            for(int j = 0; j <= M; j++) {
                if(dp[i][j] != -1) {
                    for(int k = 0; k < garments[i].size(); k++) {
                        if(j + garments[i][k] <= M) {
                            dp[i+1][j+garments[i][k]] = dp[i][j];
                        }
                    }
                }
            }
        }
        int maxCost = -1;
        for(int j = M; j >= 0; j--) {
            if(dp[C][j] != -1) {
                maxCost = j;
                break;
            }
        }
        if(maxCost == -1) {
            cout << -1 << endl;
        } else {
            cout << maxCost << endl;
        }
    }
    return 0;
}

