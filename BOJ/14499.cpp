#include <iostream>
using namespace std;

const int N = 20, M = 20;
int n, m, y, x, k, b = 6;
int mat[N][M];
int dice[7];

bool moveDice(int d) {
	if (d == 1) {
		if (x == m - 1) return false;
		int temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
		x++;
	}
	if (d == 2) {
		if (x == 0) return false;
		int temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
		x--;
	}
	if (d == 3) {
		if (y == 0) return false;
		int temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
		y--;
	}
	if (d == 4) {
		if (y == n - 1) return false;
		int temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
		y++;
	}

	return true;
}

void copyDice() {
	if (mat[y][x] == 0) mat[y][x] = dice[6];
	else {
		dice[6] = mat[y][x];
		mat[y][x] = 0;
	}
}

void solve(int d) {
	if (!moveDice(d)) return;
	copyDice();
	cout << dice[1] << '\n';
}

int main() {
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int d;
		cin >> d;
		solve(d);
	}

	return 0;
}