#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int N = 21;
int n, m, y, x, remain;
int mat[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vector<pair<pii, pii> > pass;

bool isPossible(int ty, int tx) {
	if (ty <= 0 || ty > n || tx <= 0 || tx > n || mat[ty][tx] == 1) return false;
	return true;
}

pii searchSrc() {
	queue<pii> q;
	q.push({ y, x });
	bool visited[N][N] = { 0 };
	visited[y][x] = true;
	int dist[N][N] = { 0 };

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny = now.first;
		int nx = now.second;
		for (int i = 0; i < 4; i++) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if (!isPossible(ty, tx)) continue;
			if (visited[ty][tx]) continue;
			q.push({ ty, tx });
			dist[ty][tx] = dist[ny][nx] + 1;
			visited[ty][tx] = true;
		}
	}

	int len = pass.size();
	int min_dist = 1e9;
	int ret = 0;
	for (int i = 0; i < len; i++) {
		if (!visited[pass[i].first.first][pass[i].first.second]) continue;
		if (min_dist > dist[pass[i].first.first][pass[i].first.second]) {
			min_dist = dist[pass[i].first.first][pass[i].first.second];
			ret = i;
		}
	}

	return make_pair(ret, min_dist);
}

int searchDest(int num) {
	queue<pii> q;
	q.push({ y, x });
	bool visited[N][N] = { 0 };
	visited[y][x] = true;
	int dist[N][N] = { 0 };

	int desty = pass[num].second.first;
	int destx = pass[num].second.second;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny = now.first;
		int nx = now.second;
		if (ny == desty && nx == destx) return dist[ny][nx];

		for (int i = 0; i < 4; i++) {
			int ty = ny + dy[i];
			int tx = nx + dx[i];
			if (!isPossible(ty, tx)) continue;
			if (visited[ty][tx]) continue;
			q.push({ ty, tx });
			dist[ty][tx] = dist[ny][nx] + 1;
			visited[ty][tx] = true;
		}
	}

	return -1;
}

int solve() {
	while (true) {
		// 손님 탐색 및 이동
		pii now = searchSrc();
		int num = now.first;
		y = pass[num].first.first;
		x = pass[num].first.second;
		if (remain <= now.second) return -1;  // 승객까지 도달 불가한 경우
		remain -= now.second;

		// 목적지 이동
		int dist = searchDest(num);
		if (dist == -1 || remain < dist) return -1;  // 목적지까지 도달 불가한 경우
		remain += dist;
		y = pass[num].second.first;
		x = pass[num].second.second;
		pass.erase(pass.begin() + num);
		if (pass.empty()) return remain;
	}
}

int main() {
	cin >> n >> m >> remain;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	cin >> y >> x;
	for (int i = 0; i < m; i++) {
		int sy, sx, desty, destx;
		cin >> sy >> sx >> desty >> destx;
		pass.push_back({ {sy, sx}, {desty, destx} });
	}
	sort(pass.begin(), pass.end());
	cout << solve();

	return 0;
}