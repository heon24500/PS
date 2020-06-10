#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int M = 1001;
const int N = 1001;
int a[N][M], dist[N][M], m, n;
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
bool visited[N][M];
queue<pii> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				visited[i][j] = true;
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		int y = now.first;
		int x = now.second;

		for (int i = 0; i < 4; i++) {
			int ny = y + d_y[i];
			int nx = x + d_x[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] == 0) {
				if (visited[ny][nx] && (dist[ny][nx] == -1 || dist[ny][nx] <= dist[y][x] + 1)) continue;
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}

	int days = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1 && dist[i][j] == -1) {
				days = -1;
				break;
			}
			else if (days < dist[i][j]) days = dist[i][j];
		}
		if (days == -1) break;
	}
	cout << days;

	return 0;
}