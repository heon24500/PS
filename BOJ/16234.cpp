#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int N = 50;
int n, l, r;
int a[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool visited[N][N];

bool isPossible(int y, int x, int ty, int tx) {
	if (ty < 0 || ty >= n || tx < 0 || tx >= n || visited[ty][tx]) return false;
	int diff = abs(a[ty][tx] - a[y][x]);
	if (diff < l || diff > r) return false;
	return true;
}

int bfs(pii n) {
	int ret = 0;
	queue<pii> q;
	q.push(n);
	visited[n.first][n.second] = true;

	vector<pii> u;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		u.push_back(now);

		int y = now.first;
		int x = now.second;

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];
			if (!isPossible(y, x, ty, tx)) continue;
			q.push(make_pair(ty, tx));
			visited[ty][tx] = true;
		}
	}
	if (u.size() > 1) {
		ret++;
		int sum = 0;
		for (int i = 0; i < u.size(); i++) {
			sum += a[u[i].first][u[i].second];
		}
		sum /= u.size();
		for (int i = 0; i < u.size(); i++) {
			a[u[i].first][u[i].second] = sum;
		}
	}
	return ret;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ret = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				cnt += bfs(make_pair(i, j));
			}
		}
		if (cnt == 0) break;
		ret++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
			}
		}
	}
	cout << ret;

	return 0;
}