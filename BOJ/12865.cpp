#include <iostream>
using namespace std;

const int N = 101, K = 100001;
int n, k;
int w[N], v[N];
int dp[N][K];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		for (int j = 1; j <= k; j++) {
			if (w[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];

	return 0;
}