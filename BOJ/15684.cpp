#include <iostream>
using namespace std;

const int N = 11, H = 31;
int n, m, h, ans = 1e9;
int mat[H][N];

bool isAns() {
	for (int i = 1; i <= n; i++) {
		int x = i;
		int y = 1;
		while (y <= h) {
			if (mat[y][x] == 1) x++;
			else if (mat[y][x - 1] == 1) x--;
			y++;
		}
		if (x != i) return false;
	}
	return true;
}

void solve(int y, int x, int num) {
	if (ans < num) return;
	if (num > 3) return;

	if (isAns()) {
		ans = min(ans, num);
		return;
	}

	for (int i = y; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (i == y && j < x) continue;
			if (mat[i][j] == 1 || mat[i][j - 1] == 1 || mat[i][j + 1] == 1) continue;
			mat[i][j] = 1;
			solve(i, j, num + 1);
			mat[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mat[a][b] = 1;
	}

	solve(1, 1, 0);
	if (ans == 1e9) cout << -1;
	else cout << ans;

	return 0;
}