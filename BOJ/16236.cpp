#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int N = 20;
int n, y, x, ans, cnt, shark = 2;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool isPossible(int ty, int tx) {
	if (ty < 0 || ty >= n || tx < 0 || tx >= n || mat[ty][tx] > shark) return false;
	return true;
}

pipii bfs() {
	queue<pii> q;
	q.push({ y, x });
	bool visited[N][N] = { 0 };
	int dist[N][N] = { 0 };
	visited[y][x] = true;

	pii ret = { -1, -1 };
	int min_dist = 1e9;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		if (!(now.first == y && now.second == x) && mat[now.first][now.second] != 0 && mat[now.first][now.second] < shark) {
			if (min_dist > dist[now.first][now.second]) {
				ret = { now.first, now.second };
				min_dist = dist[now.first][now.second];
			}
			else if (min_dist == dist[now.first][now.second]) {
				if ((ret.first > now.first) || ((ret.first == now.first) && (ret.second > now.second))) ret = { now.first, now.second };
			}
		}

		for (int i = 0; i < 4; i++) {
			int ty = now.first + dy[i];
			int tx = now.second + dx[i];
			if (!isPossible(ty, tx)) continue;
			if (visited[ty][tx]) continue;
			q.push({ ty, tx });
			visited[ty][tx] = true;
			dist[ty][tx] = dist[now.first][now.second] + 1;
		}
	}

	return { min_dist, ret };
}

void solve() {
	while (true) {
		pipii ret = bfs();
		int dist = ret.first;
		pii fish = ret.second;
		if (fish.first == -1 && fish.second == -1) return;
		mat[y][x] = 0;
		y = fish.first;
		x = fish.second;
		mat[y][x] = 9;
		cnt++;
		if (cnt == shark) {
			shark++;
			cnt = 0;
		}
		ans += dist;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 9) {
				y = i;
				x = j;
			}
		}
	}
	solve();
	cout << ans;

	return 0;
}