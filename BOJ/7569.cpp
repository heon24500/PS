#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int> > pipii;

const int M = 101, N = 101, H = 101;
int m, n, h, day;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int mat[H][N][M], dist[H][N][M];
queue<pipii> q;

bool isPossible(int z, int y, int x) {
	if (z < 0 || z >= h || y < 0 || y >= n || x < 0 || x >= m || mat[z][y][x] != 0) return false;
	return true;
}

bool isFinish() {
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (mat[z][y][x] == 0) return false;
			}
		}
	}
	return true;
}

void solve() {
	while (!q.empty()) {
		pipii now = q.front();
		q.pop();

		int z = now.first;
		int y = now.second.first;
		int x = now.second.second;
		day = max(day, dist[z][y][x]);

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];
			if (!isPossible(z, ty, tx)) continue;
			q.push({ z, {ty, tx} });
			mat[z][ty][tx] = 1;
			dist[z][ty][tx] = dist[z][y][x] + 1;
		}
		if (isPossible(z - 1, y, x)) {
			q.push({ z - 1, {y, x} });
			mat[z - 1][y][x] = 1;
			dist[z - 1][y][x] = dist[z][y][x] + 1;
		}
		if (isPossible(z + 1, y, x)) {
			q.push({ z + 1, {y, x} });
			mat[z + 1][y][x] = 1;
			dist[z + 1][y][x] = dist[z][y][x] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> mat[z][y][x];
				if (mat[z][y][x] == 1) q.push({ z, {y, x} });
			}
		}
	}

	solve();
	if (!isFinish()) day = -1;
	cout << day;

	return 0;
}