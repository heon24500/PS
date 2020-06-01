#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 101, MAX_K = 10001, IMPOSSIBLE = 1000000000;
int N, K, cost[MAX_N], dp[MAX_N][MAX_K];

int coin(int n, int k) {
    if (n == N) {
        if (k == 0) {
            return 0;
        }
        else {
            return IMPOSSIBLE;
        }
    }
    if (dp[n][k] != -1) return dp[n][k];

    int result = coin(n + 1, k);
    if (k >= cost[n]) result = min(result, coin(n, k - cost[n]) + 1);

    dp[n][k] = result;

    return result;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -1;
        }
    }

    int result = coin(0, K);

    if (result == IMPOSSIBLE) {
        cout << "-1";
    }
    else {
        cout << result;
    }

    return 0;
}