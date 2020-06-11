#include <iostream>
#include <deque>
using namespace std;

typedef pair<int, int> pii;

const int N = 101;
const int M = 101;
bool visited[N][N];
int a[N][M], dist[N][M];
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
deque<pii> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			a[i][j] = ch - '0';
		}
	}

	q.push_back(make_pair(0, 0));
	visited[0][0] = true;
	dist[0][0] = 0;

	while (!q.empty()) {
		pii now = q.front();
		q.pop_front();

		int y = now.first;
		int x = now.second;

		for (int i = 0; i < 4; i++) {
			int ny = y + d_y[i];
			int nx = x + d_x[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx]) {
				if (a[ny][nx] == 1) {
					q.push_back(make_pair(ny, nx));
					visited[ny][nx] = true;
					dist[ny][nx] = dist[y][x] + 1;
				}
				else {
					q.push_front(make_pair(ny, nx));
					visited[ny][nx] = true;
					dist[ny][nx] = dist[y][x];
				}
			}
		}
	}

	cout << dist[n - 1][m - 1];

	return 0;
}