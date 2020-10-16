#include <iostream>
using namespace std;

struct Fish {
	int x, y, d;
	bool alive;
};

int sx, sy, sd, ans;
int mat[4][4];
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
Fish fish[17];

bool isPossible(int x, int y) {
	if (x < 0 || x > 3 || y < 0 || y > 3 || mat[x][y] == -1) return false;
	return true;
}

void moveFish() {
	for (int i = 1; i <= 16; i++) {
		if (!fish[i].alive) continue;
		int x = fish[i].x;
		int y = fish[i].y;
		int d = fish[i].d;

		for (int j = 1; j <= 8; j++) {
			int tx = x + dx[d];
			int ty = y + dy[d];
			if (!isPossible(tx, ty)) {
				d++;
				if (d > 8) d -= 8;
				fish[i].d = d;
				continue;
			}

			swap(mat[x][y], mat[tx][ty]);
			int num = mat[x][y];
			fish[i].x = tx;
			fish[i].y = ty;
			fish[num].x = x;
			fish[num].y = y;
			break;
		}
	}
}

void backup(Fish fish_bak[17], int mat_bak[4][4], bool isBackup) {
	if (isBackup) {
		fish_bak[0] = { sx, sy, sd, true };
		for (int i = 1; i <= 16; i++) fish_bak[i] = fish[i];
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				mat_bak[x][y] = mat[x][y];
			}
		}
	}
	else {
		sx = fish_bak[0].x;
		sy = fish_bak[0].y;
		sd = fish_bak[0].d;
		for (int i = 1; i <= 16; i++) fish[i] = fish_bak[i];
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				mat[x][y] = mat_bak[x][y];
			}
		}
	}
}

void solve(int sum) {
	ans = max(ans, sum);

	Fish fish_bak[17];
	int mat_bak[4][4];

	moveFish();
	backup(fish_bak, mat_bak, true);

	for (int i = 1; i <= 3; i++) {
		int tx = sx + dx[sd] * i;
		int ty = sy + dy[sd] * i;
		if (!isPossible(tx, ty) || mat[tx][ty] == 0) continue;

		int num = mat[tx][ty];
		fish[num].alive = false;
		mat[tx][ty] = -1;
		mat[sx][sy] = 0;
		sd = fish[num].d;
		sx = tx;
		sy = ty;

		solve(sum + num);
		backup(fish_bak, mat_bak, false);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			int n, d;
			cin >> n >> d;
			mat[x][y] = n;
			fish[n] = { x, y, d, true };
		}
	}
	int num = mat[sx][sy];
	mat[sx][sy] = -1;
	sd = fish[num].d;
	fish[num].alive = false;

	solve(num);
	cout << ans;

	return 0;
}