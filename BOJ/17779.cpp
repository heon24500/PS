#include <iostream>
using namespace std;

const int N = 21;
int n, x, y, d1, d2, ans = 1e9;
int a[N][N];

void solve() {
	int mat[N][N] = { 0 };
	int cnt[6] = { 0 };
	for (int r = x, c = y; r <= x + d1; r++, c--) mat[r][c] = 5;
	for (int r = x, c = y; r <= x + d2; r++, c++) mat[r][c] = 5;
	for (int r = x + d1, c = y - d1; r <= x + d1 + d2; r++, c++) mat[r][c] = 5;
	for (int r = x + d2, c = y + d2; r <= x + d1 + d2; r++, c--) mat[r][c] = 5;
	for (int r = x + 1; r < x + d1 + d2; r++) {
		bool flag = false;
		for (int c = y - d1; c <= y + d2; c++) {
			if (flag) {
				if (mat[r][c] == 0) mat[r][c] = 5;
				else break;
			}
			if (mat[r][c] == 5) flag = true;
		}
	}

	for (int r = 1; r < x; r++) {
		for (int c = 1; c <= n; c++) {
			if (c <= y) mat[r][c] = 1;
			else mat[r][c] = 2;
		}
	}
	for (int r = x + d1 + d2 + 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (c < y - d1 + d2) mat[r][c] = 3;
			else mat[r][c] = 4;
		}
	}
	for (int c = 1; c < y - d1; c++) {
		for (int r = 1; r <= n; r++) {
			if (r < x + d1) mat[r][c] = 1;
			else mat[r][c] = 3;
		}
	}
	for (int c = y + d2 + 1; c <= n; c++) {
		for (int r = 1; r <= n; r++) {
			if (r <= x + d2) mat[r][c] = 2;
			else mat[r][c] = 4;
		}
	}

	for (int r = x; r <= x + d1 + d2; r++) {
		for (int c = y - d1; c <= y + d2; c++) {
			if (r < x + d1 && c < y && mat[r][c] == 0) mat[r][c] = 1;
			if (r < x + d2 && c > y && mat[r][c] == 0) mat[r][c] = 2;
			if (r > x + d1 && c < y - d1 + d2 && mat[r][c] == 0) mat[r][c] = 3;
			if (r > x + d2 && c > y - d1 + d2 && mat[r][c] == 0) mat[r][c] = 4;
		}
	}

	int max_cnt = 0, min_cnt = 1e9;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			cnt[mat[r][c]] += a[r][c];
		}
	}
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

	for (x = 1; x <= n; x++) {
		for (y = 1; y <= n; y++) {
			for (d1 = 1; d1 <= n; d1++) {
				for (d2 = 1; d2 <= n; d2++) {
					if ((x + d1 + d2 > n) || (y - d1 < 1) || (y + d2 > n)) break;
					solve();
				}
			}
		}
	}

	cout << ans;


	return 0;
}