/* 2819. 격자판의 숫자 이어 붙이기 */
#include <iostream>
using namespace std;

int cnt[10000000];
int mat[4][4];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isPossible(int y, int x) {
	if (y >= 0 && y < 4 && x >= 0 && x < 4) return true;
	else return false;
}

void solve(int depth, int y, int x, int num) {
	num *= 10;
	num += mat[y][x];

	if (depth == 0) {
		cnt[num] = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		if (!isPossible(ty, tx)) continue;
		solve(depth - 1, ty, tx, num);
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> mat[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				solve(6, i, j, 0);
			}
		}

		int ans = 0;
		for (int i = 0; i < 10000000; i++) {
			if (cnt[i] == 1) {
				ans++;
				cnt[i] = 0;
			}
		}

		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}