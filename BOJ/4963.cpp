#include <iostream>
#include <queue>
using namespace std;

const int W = 51;
const int H = 51;
int a[H][W];

int d_x[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int d_y[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
bool visited[H][W];

queue<pair<int, int> > q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}

		int ret = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 0 || visited[i][j]) continue;

				visited[i][j] = true;
				q.push(make_pair(i, j));

				ret++;

				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					int y = now.first;
					int x = now.second;
					for (int i = 0; i < 8; i++) {
						int ny = y + d_y[i];
						int nx = x + d_x[i];

						if (ny >= 0 && ny < h && nx >= 0 && nx < w && a[ny][nx] == 1 && !visited[ny][nx]) {
							visited[ny][nx] = true;
							q.push(make_pair(ny, nx));
						}
					}
				}
			}
		}

		cout << ret << '\n';
		while (!q.empty()) {
			q.pop();
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visited[i][j] = false;
			}
		}
	}

	return 0;
}