#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int M = 1001, N = 1001;
int m, n;
char mat[M][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[M][N];

bool isPossible(int y, int x) {
	if (y < 0 || y >= m || x < 0 || x >= n || mat[y][x] == '1' || visited[y][x]) return false;
	return true;
}

bool bfs(int y, int x) {
	queue<pii> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		if (now.first == m - 1) return true;

		for (int i = 0; i < 4; i++) {
			int ty = now.first + dy[i];
			int tx = now.second + dx[i];
			if (!isPossible(ty, tx)) continue;
			q.push({ ty, tx });
			visited[ty][tx] = true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	bool ans = false;
	for (int i = 0; i < n; i++) {
		ans = bfs(0, i);
		if (ans) break;
	}
	if (ans) cout << "YES";
	else cout << "NO";

	return 0;
}