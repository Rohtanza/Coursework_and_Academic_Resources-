#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAXN 1005

int N, M;
int adj[MAXN][MAXN], cnt[MAXN][MAXN];
vector<int> crossings;

void floydWarshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(adj[i][j] == adj[i][k] + adj[k][j]) {
                    cnt[i][j] += cnt[i][k] * cnt[k][j];
                } else if(adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    cnt[i][j] = cnt[i][k] * cnt[k][j];
                }
            }
        }
    }
}

void solve() {
    crossings.clear();
    crossings.resize(N + 1);

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i != j && j != k && k != i) {
                    if(adj[i][j] == adj[i][k] + adj[k][j]) {
                        crossings[k] += cnt[i][j];
                    }
                }
            }
        }
    }

    vector<pair<int, int>> order;
    for(int i = 1; i <= N; i++) {
        order.push_back({-crossings[i], i});
    }

    sort(order.begin(), order.end());

    for(int i = 0; i < 5; i++) {
        cout << order[i].second << endl;
    }
}

int main() {

    int T;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                adj[i][j] = (i == j ? 0 : INF);
                cnt[i][j] = (i == j ? 1 : 0);
            }
        }

        for(int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = adj[v][u] = 1;
            cnt[u][v] = cnt[v][u] = 1;
        }

        floydWarshall();
        solve();
    }

    return 0;
}

