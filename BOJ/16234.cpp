#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 51;
int n, l, r, ans;
int a[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool isPossible(int y, int x, int ty, int tx) {
	if (ty < 0 || ty >= n || tx < 0 || tx >= n || abs(a[y][x] - a[ty][tx]) < l || abs(a[y][x] - a[ty][tx]) > r) return false;
	return true;
}

void solve() {
	while (true) {
		queue<pii> q;
		int town = 1;
		int mat[N][N] = { 0 };
		bool visited[N][N] = { 0 };

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (visited[y][x]) continue;

				q.push({ y, x });
				visited[y][x] = true;

				while (!q.empty()) {
					pii now = q.front();
					q.pop();

					int ny = now.first;
					int nx = now.second;
					mat[ny][nx] = town;

					for (int i = 0; i < 4; i++) {
						int ty = ny + dy[i];
						int tx = nx + dx[i];
						if (!isPossible(ny, nx, ty, tx) || visited[ty][tx]) continue;
						q.push({ ty, tx });
						visited[ty][tx] = true;
					}
				}

				town++;
			}
		}

		int cnt[N * N] = { 0 }, sum[N * N] = { 0 };
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cnt[mat[y][x]]++;
				sum[mat[y][x]] += a[y][x];
			}
		}

		bool flag = false;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (cnt[mat[y][x]] == 1) continue;

				a[y][x] = sum[mat[y][x]] / cnt[mat[y][x]];
				flag = true;
			}
		}

		if (flag) ans++;
		else break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	solve();
	cout << ans;

	return 0;
}