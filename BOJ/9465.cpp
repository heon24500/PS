#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N, sticker[2][MAX], dp[MAX][3];

// m = 1 then UP, 2 then DOWN, 0 then NO sticker before
int calc(int n, int m) {
    if (n == N) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    int result = calc(n + 1, 0);

    if (m != 1) result = max(result, calc(n + 1, 1) + sticker[0][n]);
    if (m != 2) result = max(result, calc(n + 1, 2) + sticker[1][n]);

    dp[n][m] = result;

    return result;
}

int main() {
    int T;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> sticker[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
        }

        cout << calc(0, 0) << endl;
    }

    return 0;
}