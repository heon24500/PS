#include <iostream>
using namespace std;

struct Horse {
	int y;
	int x;
	bool finish;
};

int mat[5][25], dice[10];
int ans;
Horse horse[5];

bool moveHorse(int n, int d) {
	int y = horse[n].y;
	int x = horse[n].x;

	if (y == 0) {
		if (x == 5) {
			if (d > 3) {
				y = 4;
				x = d - 3;
			}
			else {
				y = 1;
				x = d;
			}
		}
		else if (x == 10) {
			if (d > 2) {
				y = 4;
				x = d - 2;
			}
			else {
				y = 2;
				x = d;
			}
		}
		else if (x == 15) {
			if (d > 3) {
				y = 4;
				x = d - 3;
			}
			else {
				y = 3;
				x = d;
			}
		}
		else {
			x += d;
		}
		d = 0;
	}
	else if (y == 1) {
		if (x + d > 3) {
			y = 4;
			x = x + d - 3;
		}
		else x += d;
		d = 0;
	}
	else if (y == 2) {
		if (x + d > 2) {
			y = 4;
			x = x + d - 2;
		}
		else x += d;
		d = 0;
	}
	else if (y == 3) {
		if (x + d > 3) {
			y = 4;
			x = x + d - 3;
		}
		else x += d;
		d = 0;
	}

	if (y == 4) {
		x += d;
		if (x > 4) {
			horse[n].finish = true;
			return true;
		}
		else if (x == 4) {
			y = 0;
			x = 20;
		}
	}

	if (y == 0 && x > 20) {
		horse[n].finish = true;
		return true;
	}

	for (int i = 0; i < 4; i++) {
		if (i == n || horse[i].finish) continue;
		if (horse[i].y == y && horse[i].x == x) return false;
	}

	horse[n].y = y;
	horse[n].x = x;
	return true;
}

void backup(Horse horse_bak[5], bool isBackup) {
	if (isBackup) {
		for (int i = 0; i < 5; i++) {
			horse_bak[i] = horse[i];
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			horse[i] = horse_bak[i];
		}
	}
}

void solve(int depth, int sum) {
	if (depth == 10) {
		ans = max(ans, sum);
		return;
	}

	Horse horse_bak[5];
	backup(horse_bak, true);

	for (int i = 0; i < 4; i++) {
		if (horse[i].finish) continue;

		if (moveHorse(i, dice[depth])) {
			int cost = mat[horse[i].y][horse[i].x];
			if (horse[i].finish) cost = 0;
			solve(depth + 1, sum + cost);
			backup(horse_bak, false);
		}
	}
}

int main() {
	for (int i = 1; i <= 20; i++) mat[0][i] = i * 2;
	for (int i = 1; i <= 3; i++) mat[1][i] = 10 + i * 3;
	for (int i = 1; i <= 2; i++) mat[2][i] = 20 + i * 2;
	for (int i = 1; i <= 3; i++) mat[3][i] = 30 - i - 1;
	for (int i = 1; i <= 3; i++) mat[4][i] = 20 + i * 5;

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	solve(0, 0);
	cout << ans;

	return 0;
}