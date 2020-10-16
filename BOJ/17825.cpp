#include <iostream>
using namespace std;

struct Horse {
	int y, x;
	bool alive;
};

int ans;
int mat[5][30], dice[10];
Horse horse[4];

bool isPossible(int hn, int dist) {
	int y = horse[hn].y;
	int x = horse[hn].x;

	if (y == 0) {
		if (x == 5) {
			y = 1;
			x = 1;
			dist--;
		}
		else if (x == 10) {
			y = 2;
			x = 1;
			dist--;
		}
		else if (x == 15) {
			y = 3;
			x = 1;
			dist--;
		}
		else {
			x += dist;
			dist = 0;
		}
	}

	if (y == 1 || y == 3) {
		if (x + dist > 3) {
			dist -= 4 - x;
			y = 4;
			x = 1;
		}
		else {
			x += dist;
			dist = 0;
		}
	}

	if (y == 2) {
		if (x + dist > 2) {
			dist -= 3 - x;
			y = 4;
			x = 1;
		}
		else {
			x += dist;
			dist = 0;
		}
	}

	if (y == 4) {
		if (x + dist > 4) {
			horse[hn].alive = false;
			return true;
		}
		else if (x + dist == 4) {
			y = 0;
			x = 20;
			dist = 0;
		}
		else {
			x += dist;
			dist = 0;
		}
	}

	if (y == 0 && x > 20) {
		horse[hn].alive = false;
		return true;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i == hn || !horse[i].alive) continue;
			if (horse[i].y == y && horse[i].x == x) return false;
		}
	}

	horse[hn].y = y;
	horse[hn].x = x;
	return true;
}

void backup(Horse horse_bak[4], bool isBackup) {
	if (isBackup) {
		for (int i = 0; i < 4; i++) horse_bak[i] = horse[i];
	}
	else {
		for (int i = 0; i < 4; i++) horse[i] = horse_bak[i];
	}
}

void solve(int depth, int sum) {
	ans = max(ans, sum);
	if (depth == 10) return;

	Horse horse_bak[4];
	backup(horse_bak, true);
	for (int i = 0; i < 4; i++) {
		if (!horse[i].alive) continue;
		if (!isPossible(i, dice[depth])) continue;
		if (horse[i].alive) solve(depth + 1, sum + mat[horse[i].y][horse[i].x]);
		else solve(depth + 1, sum);
		backup(horse_bak, false);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 20; i++) mat[0][i] = i * 2;
	for (int i = 1; i <= 3; i++) mat[1][i] = 10 + i * 3;
	for (int i = 1; i <= 2; i++) mat[2][i] = 20 + i * 2;
	for (int i = 1; i <= 3; i++) mat[3][i] = 29 - i;
	for (int i = 1; i <= 3; i++) mat[4][i] = 20 + i * 5;
	for (int i = 0; i < 4; i++) horse[i].alive = true;

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	solve(0, 0);
	cout << ans;

	return 0;
}