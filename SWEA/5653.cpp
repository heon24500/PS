#include <iostream>
using namespace std;

const int N = 650;
int t, n, m, k, ans, l, r, u, d;
int vital[N][N], tm[N][N], state[N][N];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void spread(int y, int x, int time) {
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (vital[ty][tx] == 0) {
			vital[ty][tx] = vital[y][x];
			tm[ty][tx] = time;
			state[ty][tx] = 0;
			l = min(l, tx);
			r = max(r, tx);
			u = min(u, ty);
			d = max(d, ty);
		}
		else {
			if (state[ty][tx] == -1 || state[ty][tx] == 1) continue;
			if (tm[ty][tx] == time) vital[ty][tx] = max(vital[ty][tx], vital[y][x]);
		}
	}
}

void solve() {
	for (int i = 1; i <= k; i++) {
		for (int y = u; y <= d; y++) {
			for (int x = l; x <= r; x++) {
				if (vital[y][x] == 0 || state[y][x] == -1) continue;
				if (state[y][x] == 0) {
					if (vital[y][x] + tm[y][x] == i) state[y][x] = 1;
				}
				else {
					spread(y, x, i);
					if (vital[y][x] * 2 + tm[y][x] == i) state[y][x] = -1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		l = u = 1e9;
		r = d = 0;

		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int num;
				cin >> num;
				if (num == 0) continue;
				int y = 300 + i;
				int x = 300 + j;

				l = min(l, x);
				r = max(r, x);
				u = min(u, y);
				d = max(d, y);

				vital[y][x] = num;
				tm[y][x] = 0;
				state[y][x] = 0;
			}
		}

		solve();
		int ans = 0;
		for (int i = u; i <= d; i++) {
			for (int j = l; j <= r; j++) {
				if (vital[i][j] > 0 && state[i][j] >= 0) ans++;
				vital[i][j] = 0;
				tm[i][j] = 0;
				state[i][j] = 0;
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}