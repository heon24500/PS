#include <iostream>
using namespace std;

const int N = 21;
int n, ans = 1e9;
int a[N][N];

void solve(int x, int y, int d1, int d2) {
	int mat[N][N] = { 0 };

	for (int i = 0; i <= d1; i++) {
		for (int j = i; j <= d1; j++) {
			mat[x + d1 - i][y - d1 + j] = 5;
		}
	}
	for (int i = 0; i <= d2; i++) {
		for (int j = 0; j <= i; j++) {
			mat[x + i][y + j] = 5;
		}
	}
	for (int i = 0; i <= d2; i++) {
		for (int j = i; j <= d2; j++) {
			mat[x + d1 + i][y - d1 + j] = 5;
		}
	}
	for (int i = 0; i <= d1; i++) {
		for (int j = 0; j <= i; j++) {
			mat[x + d1 + d2 - i][y - d1 + d2 + j] = 5;
		}
	}

	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (mat[i][j] == 0) mat[i][j] = 1;
		}
	}

	for (int i = 1; i <= x + d2; i++) {
		for (int j = y + 1; j <= n; j++) {
			if (mat[i][j] == 0) mat[i][j] = 2;
		}
	}

	for (int i = x + d1; i <= n; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (mat[i][j] == 0) mat[i][j] = 3;
		}
	}

	for (int i = x + d2; i <= n; i++) {
		for (int j = y - d1 + d2; j <= n; j++) {
			if (mat[i][j] == 0) mat[i][j] = 4;
		}
	}

	int cnt[6] = { 0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[mat[i][j]] += a[i][j];
		}
	}
	int max_cnt = 0, min_cnt = 1e9;
	for (int i = 1; i <= 5; i++) {
		max_cnt = max(max_cnt, cnt[i]);
		min_cnt = min(min_cnt, cnt[i]);
	}
	ans = min(ans, max_cnt - min_cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int x = 1; x < n; x++) {
		for (int y = 1; y < n; y++) {
			for (int d1 = 1; d1 < n; d1++) {
				for (int d2 = 1; d2 < n; d2++) {
					if (x + d1 + d2 > n || y - d1 < 1 || y + d2 > n) continue;
					solve(x, y, d1, d2);
				}
			}
		}
	}
	cout << ans;

	return 0;
}