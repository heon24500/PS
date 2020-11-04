#include <iostream>
using namespace std;

const int R = 20, C = 20;
int r, c, ans;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
bool check[150];
bool visited[R][C];
char mat[R][C];

bool isPossible(int y, int x, int ty, int tx) {
	if (ty < 0 || ty >= r || tx < 0 || tx >= c || visited[ty][tx] || check[mat[ty][tx]]) return false;
	return true;
}

void solve(int y, int x, int dist) {
	visited[y][x] = true;
	check[mat[y][x]] = true;

	ans = max(ans, dist);

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (!isPossible(y, x, ty, tx)) continue;
		solve(ty, tx, dist + 1);
	}

	visited[y][x] = false;
	check[mat[y][x]] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> mat[y][x];
		}
	}

	solve(0, 0, 1);
	cout << ans;

	return 0;
}