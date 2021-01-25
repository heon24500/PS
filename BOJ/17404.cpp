#include <iostream>
using namespace std;

const int N = 1001;
int n, ans = 1e9;
int dp[N][3], cost[N][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) dp[1][j] = cost[1][j];
			else dp[1][j] = 1e9;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
		}

		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			ans = min(ans, dp[n][j]);
		}
	}

	cout << ans;

	return 0;
}