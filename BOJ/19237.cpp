#include <iostream>
using namespace std;

struct Shark {
	int y;
	int x;
	int d;
	bool alive;
};

struct Map {
	int s;
	int t;
};

const int N = 20, M = N * N + 1;
int n, m, k, times;
int dir[M][5][5];
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
Shark shark[M];
Map map[N][N];
int beforeMap[N][N];

void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			beforeMap[i][j] = map[i][j].s;
		}
	}
}

bool isFinish() {
	for (int i = 2; i <= m; i++) {
		if (shark[i].alive) return false;
	}
	return true;
}

bool isBoundary(int ty, int tx) {
	if (ty < 0 || ty >= n || tx < 0 || tx >= n) return true;
	return false;
}

bool isSmell(int ty, int tx, int shark_num) {
	int tshark = map[ty][tx].s;
	if (tshark == 0) return false;
	if (beforeMap[ty][tx] == 0) return false;
	return true;
}

void removeSmell() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int shark_num = map[i][j].s;
			if (shark_num == 0) continue;
			if (shark[shark_num].y == i && shark[shark_num].x == j) continue;
			map[i][j].t--;
			if (map[i][j].t == 0) map[i][j].s = 0;
		}
	}
}

void solve() {
	while (true) {
		if (isFinish()) return;
		if (times >= 1000) {
			times = -1;
			return;
		}

		copyMap();

		for (int i = 1; i <= m; i++) {
			if (!shark[i].alive) continue;

			int y = shark[i].y;
			int x = shark[i].x;
			int d = shark[i].d;

			bool flag = false;
			for (int j = 1; j <= 4; j++) {
				int td = dir[i][d][j];
				int ty = y + dy[td];
				int tx = x + dx[td];
				if (isBoundary(ty, tx)) continue;
				if (isSmell(ty, tx, i)) continue;

				int tshark = map[ty][tx].s;
				if (tshark == 0 || tshark > i) {
					map[ty][tx].s = i;
					map[ty][tx].t = k;
				}
				shark[i].y = ty;
				shark[i].x = tx;
				shark[i].d = td;
				flag = true;
				break;
			}
			if (!flag) {
				for (int j = 1; j <= 4; j++) {
					int td = dir[i][d][j];
					int ty = y + dy[td];
					int tx = x + dx[td];
					if (isBoundary(ty, tx)) continue;
					if (map[ty][tx].s != i) continue;
					shark[i].y = ty;
					shark[i].x = tx;
					shark[i].d = td;
					map[ty][tx].t = k;
					break;
				}
			}
		}

		for (int i = 1; i <= m; i++) {
			if (!shark[i].alive) continue;
			for (int j = 1; j <= m; j++) {
				if (!shark[j].alive || i == j) continue;
				if (shark[i].y == shark[j].y && shark[i].x == shark[j].x) {
					if (i > j) shark[i].alive = false;
					else shark[j].alive = false;
				}
			}
		}

		removeSmell();
		times++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			map[i][j].s = num;
			if (num != 0) {
				map[i][j].t = k;
				shark[num].y = i;
				shark[num].x = j;
				shark[num].alive = true;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> shark[i].d;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int l = 1; l <= 4; l++) {
				cin >> dir[i][j][l];
			}
		}
	}

	solve();
	cout << times;

	return 0;
}