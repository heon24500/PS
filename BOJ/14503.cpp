#include <iostream>
using namespace std;

const int N = 50, M = 50;
int n, m, y, x, d, ans;
int mat[N][M];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool visited[N][M];

bool isWall(int ty, int tx) {
	if (ty < 0 || ty >= n || tx < 0 || tx >= m || mat[ty][tx] == 1) return true;
	return false;
}

bool moveBack() {
	int ty = y - dy[d];
	int tx = x - dx[d];
	if (isWall(ty, tx)) return false;

	y = ty;
	x = tx;
	return true;
}

bool canSearch() {
	for (int i = 0; i < 4; i++) {
		d--;
		if (d < 0) d = 3;

		int ty = y + dy[d];
		int tx = x + dx[d];
		if (isWall(ty, tx) || visited[ty][tx]) continue;

		y = ty;
		x = tx;
		return true;
	}

	if (moveBack()) return true;
	return false;
}

void solve() {
	while (true) {
		if (!visited[y][x]) {
			visited[y][x] = true;
			ans++;
		}
		if (!canSearch()) break;
	}
}

int main() {
	cin >> n >> m;
	cin >> y >> x >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) visited[i][j] = true;
		}
	}
	solve();
	cout << ans;

	return 0;
}