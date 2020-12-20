#include <iostream>
using namespace std;

const int N = 1005, M = 1005;
int n, m;
int mat[N][M];
int dp[N][M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + mat[i][j];
		}
	}
	cout << dp[n][m];

	return 0;
}