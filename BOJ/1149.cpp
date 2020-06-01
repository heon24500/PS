#include <iostream>
#include <algorithm>
using namespace std;

#define N 1005

int a[N][3];
int dp[N][3];

int color(int n, int c) {
	if (n == 1) return a[1][c];
	if (dp[n][c]) return dp[n][c];
	if (c == 0) return dp[n][c] = min(color(n - 1, 1), color(n - 1, 2)) + a[n][c];
	else if (c == 1) return dp[n][c] = min(color(n - 1, 0), color(n - 1, 2)) + a[n][c];
	else return dp[n][c] = min(color(n - 1, 0), color(n - 1, 1)) + a[n][c];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	int ret[3];
	for (int i = 0; i < 3; i++) {
		ret[i] = color(n, i);
	}
	sort(ret, ret + 3);
	cout << ret[0];

	return 0;
}