#include <iostream>
using namespace std;

#define N 105
#define K 10005

int coin[N], dp[K];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k];

    return 0;
}