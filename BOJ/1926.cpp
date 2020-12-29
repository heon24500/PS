#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 501, M = 501;
int n, m, cnt, ans;
int mat[N][M];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[N][M];

bool isPossible(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m || mat[y][x] == 0 || visited[y][x]) return false;
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0 || visited[i][j]) continue;
			ans = max(ans, bfs(i, j));
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	solve();
	cout << cnt << '\n' << ans;

	return 0;
}