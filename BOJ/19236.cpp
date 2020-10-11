#include <iostream>
using namespace std;

struct Fish {
	int x;
	int y;
	int d;
	bool alive;
};

Fish fish[20];
int mat[4][4];
int ans;
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void backup(Fish fish_bak[20], int mat_bak[4][4], bool backup) {
	if (backup) {
		for (int i = 0; i < 20; i++) fish_bak[i] = fish[i];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mat_bak[i][j] = mat[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 20; i++) fish[i] = fish_bak[i];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mat[i][j] = mat_bak[i][j];
			}
		}
	}
}

bool isPossible(int tx, int ty) {
	if (ty < 0 || ty >= 4 || tx < 0 || tx >= 4) return false;
	return true;
}

void moveShark(int x, int y, int tx, int ty, int fish_num, bool move) {
	if (move) {
		mat[x][y] = 0;
		mat[tx][ty] = -1;
		fish[fish_num].alive = false;
	}
	else {
		mat[x][y] = -1;
		mat[tx][ty] = fish_num;
		fish[fish_num].alive = true;
	}
}

void moveFish() {
	for (int i = 1; i <= 16; i++) {
		if (!fish[i].alive) continue;

		int x = fish[i].x;
		int y = fish[i].y;
		int d = fish[i].d;

		for (int j = 0; j < 9; j++) {
			int td = d + j;
			if (td > 8) td -= 8;
			int tx = x + dx[td];
			int ty = y + dy[td];
			int target = mat[tx][ty];

			if (!isPossible(tx, ty) || target == -1) continue;

			fish[i].x = tx;
			fish[i].y = ty;
			fish[i].d = td;
			fish[target].x = x;
			fish[target].y = y;
			mat[x][y] = target;
			mat[tx][ty] = i;

			break;
		}
	}
}

// DFS를 활용한 Backtracking. 상어의 위치 x, y와 방향 d, 먹은 물고기 총합 sum
void solve(int x, int y, int dir, int sum) {
	ans = max(ans, sum);

	// Backtracking을 위해 mat과 fish를 저장함
	Fish fish_bak[20];
	int mat_bak[4][4];
	backup(fish_bak, mat_bak, true);

	// 작업
	moveFish();

	for (int i = 1; i <= 3; i++) {
		int tx = x + dx[dir] * i;
		int ty = y + dy[dir] * i;
		if (!isPossible(tx, ty) || mat[tx][ty] == 0) continue;

		int fish_num = mat[tx][ty];
		int td = fish[fish_num].d;
		moveShark(x, y, tx, ty, fish_num, true);
		solve(tx, ty, td, sum + fish_num);
		moveShark(x, y, tx, ty, fish_num, false);
	}

	backup(fish_bak, mat_bak, false);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			mat[i][j] = num;
			fish[num] = { i, j, dir, true };
		}
	}

	int target = mat[0][0];
	fish[target].alive = false;
	mat[0][0] = -1;
	solve(0, 0, fish[target].d, target);
	cout << ans;
}