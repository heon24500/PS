#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int R = 50;
const int C = 50;
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
char a[R][C];
int dist[R][C], d[R][C];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	queue<pii> q;

	int sy, sx, dy, dx;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == '*') dist[i][j] = 0;
			else dist[i][j] = -1;
			if (a[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (a[i][j] == 'D') {
				dy = i;
				dx = j;
			}
			d[i][j] = -1;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] != '*') continue;
			q.push(make_pair(i, j));

			while (!q.empty()) {
				pii now = q.front();
				q.pop();

				int y = now.first;
				int x = now.second;

				for (int k = 0; k < 4; k++) {
					int ny = y + d_y[k];
					int nx = x + d_x[k];

					if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
						if (a[ny][nx] == 'D' || a[ny][nx] == 'X') continue;
						if (dist[ny][nx] == -1) {
							q.push(make_pair(ny, nx));
							dist[ny][nx] = dist[y][x] + 1;
						}
						else if (dist[ny][nx] > dist[y][x] + 1) {
							q.push(make_pair(ny, nx));
							dist[ny][nx] = dist[y][x] + 1;
						}
					}
				}
			}
		}
	}

	q.push(make_pair(sy, sx));
	d[sy][sx] = 0;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		int y = now.first;
		int x = now.second;

		for (int i = 0; i < 4; i++) {
			int ny = y + d_y[i];
			int nx = x + d_x[i];

			if (ny >= 0 && ny < r && nx >= 0 && nx < c && d[ny][nx] == -1) {
				if (a[ny][nx] == 'X' || a[ny][nx] == '*') continue;
				if (dist[ny][nx] != -1 && d[y][x] + 1 >= dist[ny][nx]) continue;
				q.push(make_pair(ny, nx));
				d[ny][nx] = d[y][x] + 1;
			}
		}
	}

	if (d[dy][dx] != -1) cout << d[dy][dx];
	else cout << "KAKTUS";

	return 0;
}