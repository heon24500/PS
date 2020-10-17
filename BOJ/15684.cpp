#include <iostream>
using namespace std;

const int N = 11, H = 31;
int n, m, h, ans = 1e9;
int mat[H][N];

bool isAnswer() {
	for (int i = 1; i <= n; i++) {
		int x = i, y = 1;
		while (y <= h) {
			if (mat[y][x] == 1) x++;
			else if (mat[y][x - 1] == 1) x--;
			y++;
		}
		if (x != i) return false;
	}
	return true;
}

void solve(int depth, int y, int x) {
	if (depth > 3) return;
	if (ans < depth) return;
	if (isAnswer()) {
		ans = min(ans, depth);
		return;
	}

	for (int i = y; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (i == y && j < x) continue;
			if (mat[i][j] == 1 || mat[i][j - 1] == 1 || mat[i][j + 1] == 1) continue;
			mat[i][j] = 1;
			solve(depth + 1, i, j);
			mat[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mat[a][b] = 1;
	}
	solve(0, 1, 1);
	if (ans == 1e9) ans = -1;
	cout << ans;

	return 0;
}