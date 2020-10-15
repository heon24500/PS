#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

struct Pass {
	int sy, sx, dy, dx;
};

const int N = 21, M = N * N;
int n, m, remain, y, x;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
Pass pass[M];

bool isPossible(int ty, int tx) {
	if (ty < 1 || ty > n || tx < 1 || tx > n || mat[ty][tx] == -1) return false;
	return true;
}

int goPass() {
	queue<pii> q;
	q.push({ y, x });

	int dist[N][N] = { 0 };
	bool visited[N][N] = { 0 };
	visited[y][x] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny = now.first;
		int nx = now.second;
		for (int i = 0; i < 4; i++) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if (!isPossible(ty, tx) || visited[ty][tx]) continue;
			q.push({ ty, tx });
			dist[ty][tx] = dist[ny][nx] + 1;
			visited[ty][tx] = true;
		}
	}

	int min_dist = 1e9, target = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] || mat[i][j] < 1) continue;
			if (min_dist > dist[i][j]) {
				min_dist = dist[i][j];
				target = mat[i][j];
			}
		}
	}

	y = pass[target].sy;
	x = pass[target].sx;
	mat[y][x] = 0;
	remain -= min_dist;
	return target;
}

void goGoal(int target) {
	queue<pii> q;
	q.push({ y, x });

	int dist[N][N] = { 0 };
	bool visited[N][N] = { 0 };
	visited[y][x] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny = now.first;
		int nx = now.second;
		if (ny == pass[target].dy && nx == pass[target].dx) break;

		for (int i = 0; i < 4; i++) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if (!isPossible(ty, tx) || visited[ty][tx]) continue;
			q.push({ ty, tx });
			dist[ty][tx] = dist[ny][nx] + 1;
			visited[ty][tx] = true;
		}
	}

	y = pass[target].dy;
	x = pass[target].dx;
	if (!visited[y][x]) {
		remain = -1;
		return;
	}

	int d = dist[pass[target].dy][pass[target].dx];
	if (remain < d) remain = -1;
	else remain += d;
}

void solve() {
	for (int i = 1; i <= m; i++) {
		int pn = goPass();
		if (remain <= 0) {
			remain = -1;
			return;
		}

		goGoal(pn);
		if (remain < 0) {
			remain = -1;
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> remain;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) mat[i][j] = -1;
		}
	}
	cin >> y >> x;
	for (int i = 1; i <= m; i++) {
		int sy, sx, dy, dx;
		cin >> sy >> sx >> dy >> dx;
		mat[sy][sx] = i;
		pass[i] = { sy, sx, dy, dx };
	}

	solve();
	cout << remain;

	return 0;
}