#include <iostream>
using namespace std;

#define K 15
#define N 15

int dp[K][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= N; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= K; i++) {
		dp[i][1] = 1;
	}

	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (dp[j][i]) continue;
				dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
			}
		}
		cout << dp[k][n] << "\n";
	}

	return 0;
}