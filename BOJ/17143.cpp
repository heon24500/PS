#include <iostream>
#include <queue>
using namespace std;

struct Shark {
	int y, x, s, d, z;
	bool alive;
};

const int R = 101, C = 101, M = R * C;
int r, c, m, ans;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };
int mat[R][C];
Shark shark[M];

void move() {
	queue<int> q[R][C];
	for (int i = 1; i <= m; i++) {
		if (!shark[i].alive) continue;

		int y = shark[i].y;
		int x = shark[i].x;
		int s = shark[i].s;
		int d = shark[i].d;
		mat[y][x] = 0;

		for (int j = 1; j <= s; j++) {
			if (d == 1 && y == 1) {
				d = 2;
				shark[i].d = d;
			}
			else if (d == 2 && y == r) {
				d = 1;
				shark[i].d = d;
			}
			else if (d == 3 && x == c) {
				d = 4;
				shark[i].d = d;
			}
			else if (d == 4 && x == 1) {
				d = 3;
				shark[i].d = d;
			}

			y += dy[d];
			x += dx[d];
		}

		q[y][x].push(i);
	}

	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			if (q[y][x].empty()) continue;

			int num = q[y][x].front();
			q[y][x].pop();

			while (!q[y][x].empty()) {
				int num2 = q[y][x].front();
				q[y][x].pop();
				if (shark[num].z > shark[num2].z) shark[num2].alive = false;
				else {
					shark[num].alive = false;
					num = num2;
				}
			}

			shark[num].y = y;
			shark[num].x = x;
			mat[y][x] = num;
		}
	}
}

void solve() {
	for (int x = 1; x <= c; x++) {
		for (int y = 1; y <= r; y++) {
			int n = mat[y][x];
			if (n == 0 || !shark[n].alive) continue;

			ans += shark[n].z;
			mat[y][x] = 0;
			shark[n].alive = false;
			break;
		}
		move();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		if (d == 1 || d == 2) s %= (r - 1) * 2;
		if (d == 3 || d == 4) s %= (c - 1) * 2;
		shark[i] = { y, x, s, d, z };
		shark[i].alive = true;
		mat[y][x] = i;
	}

	solve();
	cout << ans;

	return 0;
}