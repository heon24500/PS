#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

#define N 105

queue<pii> q;
int d_x[4] = { 1, 0, -1, 0 };
int d_y[4] = { 0, 1, 0, -1 };
int mat[N][N];
bool visited[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			mat[i][j] = num;
			if (max < num) max = num;
		}
	}

	int max_cnt = 0;
	for (int i = 0; i < max; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (mat[j][k] <= i || visited[j][k]) continue;
				cnt++;

				q.push(make_pair(j, k));
				visited[j][k] = true;

				while (!q.empty()) {
					pii now = q.front();
					q.pop();

					int y = now.first;
					int x = now.second;

					for (int l = 0; l < 4; l++) {
						int ty = y + d_y[l];
						int tx = x + d_x[l];

						if (ty >= 0 && ty < n && tx >= 0 && tx < n && mat[ty][tx] > i && !visited[ty][tx]) {
							visited[ty][tx] = true;
							q.push(make_pair(ty, tx));
						}
					}
				}

				while (!q.empty()) {
					q.pop();
				}
			}
		}

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				visited[a][b] = false;
			}
		}

		if (max_cnt < cnt) max_cnt = cnt;
	}

	cout << max_cnt;
}