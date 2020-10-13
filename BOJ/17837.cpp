#include <iostream>
#include <queue>
using namespace std;

struct Horse {
	int y;
	int x;
	int d;
};

const int N = 13, K = 11;
int n, k;
int mat[N][N];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };
Horse horse[K];
deque<int> dq[N][N];

bool isFinish() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (dq[y][x].size() >= 4) return true;
		}
	}
	return false;
}

void moveWhite(int num, int y, int x, int ty, int tx) {
	deque<int> temp;
	while (dq[y][x].back() != num) {
		temp.push_back(dq[y][x].back());
		dq[y][x].pop_back();
	}
	dq[y][x].pop_back();
	temp.push_back(num);
	while (!temp.empty()) {
		int h = temp.back();
		dq[ty][tx].push_back(h);
		horse[h].y = ty;
		horse[h].x = tx;
		temp.pop_back();
	}
}

void moveRed(int num, int y, int x, int ty, int tx) {
	deque<int> temp;
	while (dq[y][x].back() != num) {
		temp.push_back(dq[y][x].back());
		dq[y][x].pop_back();
	}
	dq[y][x].pop_back();
	temp.push_back(num);
	while (!temp.empty()) {
		int h = temp.front();
		dq[ty][tx].push_back(h);
		horse[h].y = ty;
		horse[h].x = tx;
		temp.pop_front();
	}
}

int changeDir(int num, int d) {
	if (d == 1) horse[num].d = 2;
	if (d == 2) horse[num].d = 1;
	if (d == 3) horse[num].d = 4;
	if (d == 4) horse[num].d = 3;
	return horse[num].d;
}

bool isBoundary(int num, int y, int x, int ty, int tx, int d) {
	if (ty >= 1 && ty <= n && tx >= 1 && tx <= n && mat[ty][tx] != 2) return false;

	d = changeDir(num, d);
	ty = y + dy[d];
	tx = x + dx[d];
	if (ty >= 1 && ty <= n && tx >= 1 && tx <= n && mat[ty][tx] != 2) {
		if (mat[ty][tx] == 0) moveWhite(num, y, x, ty, tx);
		if (mat[ty][tx] == 1) moveRed(num, y, x, ty, tx);
	}

	return true;
}

int solve() {
	for (int t = 1; t <= 1000; t++) {
		for (int i = 1; i <= k; i++) {
			int y = horse[i].y;
			int x = horse[i].x;
			int d = horse[i].d;

			int ty = y + dy[d];
			int tx = x + dx[d];
			if (!isBoundary(i, y, x, ty, tx, d)) {
				if (mat[ty][tx] == 0) moveWhite(i, y, x, ty, tx);
				if (mat[ty][tx] == 1) moveRed(i, y, x, ty, tx);
			}
			if (isFinish()) return t;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		horse[i] = { y, x, d };
		dq[y][x].push_back(i);
	}

	cout << solve();

	return 0;
}