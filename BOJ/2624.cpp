#include <iostream>
using namespace std;

#define T 10005
#define K 100

int p[K], n[K], dp[2][T];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, k;
    cin >> t >> k;
    for (int i = 0; i < k; i++) {
        cin >> p[i] >> n[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n[i]; j++) {
            for (int l = 1; l <= t; l++) {
                if (l - p[i] * j >= 0) dp[1][l] += dp[0][l - p[i] * j];
            }
        }
        for (int j = 1; j <= t; j++) {
            dp[0][j] += dp[1][j];
            dp[1][j] = 0;
        }
    }

    cout << dp[0][t];

    return 0;
}