#include <iostream>
using namespace std;

const int N = 2200;
int n, ans[3];
int mat[N][N];

bool isFinish(int y, int x, int w) {
	for (int i = y; i < y + w; i++) {
		for (int j = x; j < x + w; j++) {
			if (mat[y][x] != mat[i][j]) return false;
		}
	}
	return true;
}

void solve(int y, int x, int w) {
	if (isFinish(y, x, w)) {
		if (mat[y][x] == -1) ans[0]++;
		if (mat[y][x] == 0) ans[1]++;
		if (mat[y][x] == 1) ans[2]++;
		return;
	}

	solve(y, x, w / 3);
	solve(y, x + w / 3, w / 3);
	solve(y, x + (w / 3) * 2, w / 3);
	solve(y + w / 3, x, w / 3);
	solve(y + w / 3, x + w / 3, w / 3);
	solve(y + w / 3, x + (w / 3) * 2, w / 3);
	solve(y + (w / 3) * 2, x, w / 3);
	solve(y + (w / 3) * 2, x + w / 3, w / 3);
	solve(y + (w / 3) * 2, x + (w / 3) * 2, w / 3);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	solve(0, 0, n);
	for (int i = 0; i < 3; i++) cout << ans[i] << '\n';

	return 0;
}