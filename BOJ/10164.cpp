#include <iostream>
using namespace std;

const int N = 15, M = 15;
int n, m, k;

int solve(int sy, int sx, int ty, int tx) {
	int mat[N][M] = { 0 };
	for (int i = sy; i <= ty; i++) {
		for (int j = sx; j <= tx; j++) {
			if (i == sy || j == sx) mat[i][j] = 1;
			else mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
		}
	}
	return mat[ty][tx];
}

int main() {
	cin >> n >> m >> k;
	if (k == 0) cout << solve(0, 0, n - 1, m - 1);
	else {
		int y = (k - 1) / m;
		int x = (k - 1) % m;
		int ans = solve(0, 0, y, x) * solve(y, x, n - 1, m - 1);
		cout << ans;
	}

	return 0;
}