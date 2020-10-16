#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 51, M = 11;
int n, m, cnt, ans = 1e9;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[M];
vector<pii> v;

bool isPossible(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n || mat[y][x] == 1) return false;
	return true;
}

void bfs() {
	queue<pii> q;
	bool check[N][N] = { 0 };
	int dist[N][N] = { 0 };
	for (int i = 0; i < cnt; i++) {
		if (!visited[i]) continue;

		q.push(v[i]);
		check[v[i].first][v[i].second] = true;
	}

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		int y = now.first;
		int x = now.second;

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];
			if (!isPossible(ty, tx)) continue;
			if (check[ty][tx] && dist[ty][tx] <= dist[y][x] + 1) continue;
			q.push({ ty, tx });
			check[ty][tx] = true;
			dist[ty][tx] = dist[y][x] + 1;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != 0) continue;
			if (!check[i][j]) return;
			ret = max(ret, dist[i][j]);
		}
	}
	ans = min(ans, ret);
}

void solve(int depth, int idx) {
	if (depth == m) {
		bfs();

		return;
	}

	for (int i = idx; i < cnt; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		solve(depth + 1, i);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 2) v.push_back({ i, j });
		}
	}
	cnt = v.size();
	solve(0, 0);
	if (ans == 1e9) ans = -1;
	cout << ans;

	return 0;
}