#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 8, M = 8;
int n, m, ret = 1e9, ans;
int mat[N][M];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[N][M];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

bool isPossible(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m || visited[y][x] || mat[y][x] == 1) return false;
	return true;
}

int bfs(int y, int x) {
	int cnt = 0;
	queue<pii> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny = now.first;
		int nx = now.second;
		cnt++;
		for (int i = 0; i < 4; i++) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if (!isPossible(ty, tx)) continue;
			q.push(make_pair(ty, tx));
			visited[ty][tx] = true;
		}
	}
	return cnt;
}

void solve(int depth, int y, int x) {
	if (depth == 3) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] != 2 || visited[i][j]) continue;
				cnt += bfs(i, j);
				if (ret < cnt) {
					init();
					return;
				}
			}
		}
		if (ret > cnt) ret = cnt;
		init();
		return;
	}

	for (int i = y; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == y && j < x) continue;
			if (mat[i][j] != 0) continue;
			mat[i][j] = 1;
			solve(depth + 1, i, j);
			mat[i][j] = 0;
		}
	}
}

int main() {
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) cnt++;
		}
	}
	solve(0, 0, 0);
	ans = n * m - cnt - 3 - ret;
	cout << ans;

	return 0;
}