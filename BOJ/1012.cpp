#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define M 55
#define N 55
#define K 2505

queue<pii> q;
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
int mat[N][M];
bool visited[N][M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, k;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			mat[y][x] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] || mat[i][j] == 0) continue;

				q.push(make_pair(j, i));
				visited[i][j] = true;
				cnt++;

				while (!q.empty()) {
					pii now = q.front();
					q.pop();

					int nx = now.first;
					int ny = now.second;

					for (int l = 0; l < 4; l++) {
						int tx = nx + d_x[l];
						int ty = ny + d_y[l];

						if (tx >= 0 && tx < m && ty >= 0 && ty < n && mat[ty][tx] == 1 && !visited[ty][tx]) {
							visited[ty][tx] = true;
							q.push(make_pair(tx, ty));
						}
					}
				}
			}
		}

		cout << cnt << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j] = 0;
				visited[i][j] = false;
			}
		}

		while (!q.empty()) {
			q.pop();
		}
	}
}