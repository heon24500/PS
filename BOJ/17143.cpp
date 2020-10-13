#include <iostream>
#include <queue>
using namespace std;

struct Shark {
	int y;
	int x;
	int s;
	int d;
	int z;
	bool alive;
};

const int R = 101, C = 101, M = R * C;
int r, c, m, ans;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };
int mat[R][C];
Shark shark[M];
queue<int> q[R][C];

int changeDir(int d) {
	if (d == 1) return 2;
	if (d == 2) return 1;
	if (d == 3) return 4;
	if (d == 4) return 3;
}

bool isBoundary(int y, int x) {
	if (y < 1 || y > r || x < 1 || x > c) return true;
	return false;
}

void dieShark(int num) {
	shark[num].y = -1;
	shark[num].x = -1;
	shark[num].alive = false;
}

void moveShark(int num, int y, int x) {
	mat[y][x] = num;
	shark[num].y = y;
	shark[num].x = x;
}

void move() {
	for (int i = 1; i <= m; i++) {
		if (!shark[i].alive) continue;
		int y = shark[i].y;
		int x = shark[i].x;
		int s = shark[i].s;
		int d = shark[i].d;
		int z = shark[i].z;
		mat[y][x] = 0;

		for (int j = 0; j < s; j++) {
			int ty = y + dy[d];
			int tx = x + dx[d];
			if (isBoundary(ty, tx)) {
				d = changeDir(d);
				shark[i].d = d;
				ty = y + dy[d];
				tx = x + dx[d];
			}
			y = ty;
			x = tx;
		}

		q[y][x].push(i);
	}

	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			if (q[y][x].empty()) continue;
			int ms = q[y][x].front();
			q[y][x].pop();

			while (!q[y][x].empty()) {
				int now = q[y][x].front();
				q[y][x].pop();
				if (shark[ms].z > shark[now].z) dieShark(now);
				else {
					dieShark(ms);
					ms = now;
				}
			}

			moveShark(ms, y, x);
		}
	}
}

void solve() {
	for (int x = 1; x <= c; x++) {
		for (int y = 1; y <= r; y++) {
			int num = mat[y][x];
			if (num == 0 || !shark[num].alive) continue;
			ans += shark[num].z;
			dieShark(num);
			break;
		}
		move();
	}
}

int main() {
	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		if (d == 1 || d == 2) s %= (r - 1) * 2;
		if (d == 3 || d == 4) s %= (c - 1) * 2;
		shark[i] = { y, x, s, d, z };
		shark[i].alive = true;
		mat[shark[i].y][shark[i].x] = i;
	}
	solve();
	cout << ans;

	return 0;
}