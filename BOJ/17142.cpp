#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 50, M = 10;
int n, m, ans = -1, len, remain;
int mat[N][N], dist[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool check[M];
vector<pii> v;

bool isPossible(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n || mat[y][x] == 1) return false;
	return true;
}

void bfs() {
	int now_remain = remain;
	queue<pii> q;
	bool visited[N][N] = { 0 };
	int dist[N][N] = { 0 };
	for (int i = 0; i < len; i++) {
		if (!check[i]) continue;
		q.push(v[i]);
		visited[v[i].first][v[i].second] = true;
	}

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int y = now.first;
		int x = now.second;

		if (now_remain == 0) break;

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];
			if (!isPossible(ty, tx)) continue;
			if (visited[ty][tx] && dist[ty][tx] <= dist[y][x] + 1) continue;
			if (!visited[ty][tx] && mat[ty][tx] == 0) now_remain--;
			q.push({ ty, tx });
			visited[ty][tx] = true;
			dist[ty][tx] = dist[y][x] + 1;
		}
	}

	if (now_remain != 0) return;

	int max_dist = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 1) continue;
			max_dist = max(max_dist, dist[i][j]);
		}
	}
	if (ans == -1) ans = max_dist;
	else ans = min(ans, max_dist);
}

void solve(int depth, int idx) {
	if (depth == m) {
		bfs();
		return;
	}

	for (int i = idx; i < len; i++) {
		if (check[i]) continue;
		check[i] = true;
		solve(depth + 1, i);
		check[i] = false;
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
			if (mat[i][j] == 1) dist[i][j] = -1;
			if (mat[i][j] == 2) v.push_back({ i, j });
			if (mat[i][j] == 0) remain++;
		}
	}

	len = v.size();
	solve(0, 0);
	cout << ans;

	return 0;
}