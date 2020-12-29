#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 101, M = 101;
int n, m, k, ans;
int mat[N][M];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[N][M];

bool isPossible(int y, int x) {
	if (y <= 0 || y > n || x <= 0 || x > m || mat[y][x] == 0 || visited[y][x]) return false;
	return true;
}

int bfs(int y, int x) {
	int ret = 0;
	queue<pii> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		ret++;

		for (int i = 0; i < 4; i++) {
			int ty = now.first + dy[i];
			int tx = now.second + dx[i];
			if (!isPossible(ty, tx)) continue;
			q.push({ ty, tx });
			visited[ty][tx] = true;
		}
	}

	return ret;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == 0 || visited[i][j]) continue;
			ans = max(ans, bfs(i, j));
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		mat[r][c] = 1;
	}

	solve();
	cout << ans;

	return 0;
}