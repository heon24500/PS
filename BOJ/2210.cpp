#include <iostream>
using namespace std;

int ans;
int mat[5][5];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool check[1000000];

bool isPossible(int y, int x) {
	if (y < 0 || y >= 5 || x < 0 || x >= 5) return false;
	return true;
}

void dfs(int y, int x, int depth, int num) {
	if (depth == 6) {
		if (!check[num]) {
			check[num] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (isPossible(ty, tx)) dfs(ty, tx, depth + 1, (num * 10) + mat[ty][tx]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 1, mat[i][j]);
		}
	}
	cout << ans;

	return 0;
}