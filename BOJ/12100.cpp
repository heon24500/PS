#include <iostream>
using namespace std;

const int N = 20;
int n, ans;
int mat[N][N];
int check[5];

void backup(int mat_bak[N][N], bool isBackup) {
	if (isBackup) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				mat_bak[y][x] = mat[y][x];
			}
		}
	}
	else {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				mat[y][x] = mat_bak[y][x];
			}
		}
	}
}

void moveUp() {
	bool visited[N][N] = { 0 };
	for (int x = 0; x < n; x++) {
		for (int y = 1; y < n; y++) {
			int idx = y - 1;
			while (idx >= 0 && mat[idx][x] == 0) idx--;
			if (idx >= 0 && mat[idx][x] == mat[y][x] && !visited[idx][x]) {
				mat[idx][x] *= 2;
				mat[y][x] = 0;
				visited[idx][x] = true;
			}
			else swap(mat[idx + 1][x], mat[y][x]);
		}
	}
}

void moveDown() {
	bool visited[N][N] = { 0 };
	for (int x = 0; x < n; x++) {
		for (int y = n - 2; y >= 0; y--) {
			int idx = y + 1;
			while (idx < n && mat[idx][x] == 0) idx++;
			if (idx < n && mat[idx][x] == mat[y][x] && !visited[idx][x]) {
				mat[idx][x] *= 2;
				mat[y][x] = 0;
				visited[idx][x] = true;
			}
			else swap(mat[idx - 1][x], mat[y][x]);
		}
	}
}

void moveLeft() {
	bool visited[N][N] = { 0 };
	for (int y = 0; y < n; y++) {
		for (int x = 1; x < n; x++) {
			int idx = x - 1;
			while (idx >= 0 && mat[y][idx] == 0) idx--;
			if (idx >= 0 && mat[y][idx] == mat[y][x] && !visited[y][idx]) {
				mat[y][idx] *= 2;
				mat[y][x] = 0;
				visited[y][idx] = true;
			}
			else swap(mat[y][idx + 1], mat[y][x]);
		}
	}
}

void moveRight() {
	bool visited[N][N] = { 0 };
	for (int y = 0; y < n; y++) {
		for (int x = n - 2; x >= 0; x--) {
			int idx = x + 1;
			while (idx < n && mat[y][idx] == 0) idx++;
			if (idx < n && mat[y][idx] == mat[y][x] && !visited[y][idx]) {
				mat[y][idx] *= 2;
				mat[y][x] = 0;
				visited[y][idx] = true;
			}
			else swap(mat[y][idx - 1], mat[y][x]);
		}
	}
}

void solve(int depth) {
	if (depth == 5) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (ans < mat[y][x]) ans = mat[y][x];
			}
		}
		return;
	}

	int mat_bak[N][N];
	backup(mat_bak, true);

	void (*p[4])() = { moveUp, moveDown, moveLeft, moveRight };
	for (int i = 0; i < 4; i++) {
		p[i]();
		solve(depth + 1);
		backup(mat_bak, false);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	solve(0);
	cout << ans;

	return 0;
}