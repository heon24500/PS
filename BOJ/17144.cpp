#include <iostream>
using namespace std;

typedef pair<int, int> pii;

const int R = 51, C = 51;
int r, c, t;
int mat[R][C];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
pii machine;

bool isPossible(int y, int x) {
	if (y < 0 || y >= r || x < 0 || x >= c || mat[y][x] == -1) return false;
	return true;
}

void spread() {
	int next_mat[R][C] = { 0 };
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mat[i][j] == -1) next_mat[i][j] = -1;
			if (mat[i][j] <= 0) continue;

			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ty = i + dy[k];
				int tx = j + dx[k];
				if (!isPossible(ty, tx)) continue;
				next_mat[ty][tx] += mat[i][j] / 5;
				cnt++;
			}

			next_mat[i][j] += mat[i][j] - (mat[i][j] / 5) * cnt;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			mat[i][j] = next_mat[i][j];
		}
	}
}

void run() {
	int y = machine.first;
	int x = machine.second;

	int idx = y - 2;
	while (idx >= 0) {
		mat[idx + 1][x] = mat[idx][x];
		idx--;
	}
	for (int i = 0; i < c - 1; i++) mat[0][i] = mat[0][i + 1];
	for (int i = 0; i < y; i++) mat[i][c - 1] = mat[i + 1][c - 1];
	for (int i = c - 1; i > 0; i--) mat[y][i] = mat[y][i - 1];
	mat[y][x + 1] = 0;

	idx = y + 3;
	while (idx < r) {
		mat[idx - 1][x] = mat[idx][x];
		idx++;
	}
	for (int i = 0; i < C - 1; i++) mat[r - 1][i] = mat[r - 1][i + 1];
	for (int i = r - 1; i > y + 1; i--) mat[i][c - 1] = mat[i - 1][c - 1];
	for (int i = c - 1; i > 0; i--) mat[y + 1][i] = mat[y + 1][i - 1];
	mat[y + 1][x + 1] = 0;
}

void solve() {
	while (t--) {
		spread();
		run();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == -1 && machine.first == 0) {
				machine.first = i;
				machine.second = j;
			}
		}
	}

	solve();
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mat[i][j] <= 0) continue;
			ans += mat[i][j];
		}
	}
	cout << ans;

	return 0;
}