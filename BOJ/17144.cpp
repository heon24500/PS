#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > vii;

int r, c, t, r1, r2;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
vii mat;

bool isPossible(int ty, int tx) {
	if (ty < 0 || ty >= r || tx < 0 || tx >= c || mat[ty][tx] == -1) return false;
	return true;
}

void solve() {
	int times = 0;
	while (true) {
		// 확산
		vii ret = mat;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (mat[i][j] <= 0) continue;

				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ti = i + dy[k];
					int tj = j + dx[k];
					if (!isPossible(ti, tj)) continue;

					ret[ti][tj] += mat[i][j] / 5;
					cnt++;
				}
				ret[i][j] -= (mat[i][j] / 5) * cnt;
			}
		}
		mat = ret;

		// 공기청정기 작동
		for (int i = r1 - 2; i >= 0; i--) mat[i + 1][0] = mat[i][0];
		for (int i = 1; i < c; i++) mat[0][i - 1] = mat[0][i];
		for (int i = 1; i <= r1; i++) mat[i - 1][c - 1] = mat[i][c - 1];
		for (int i = c - 2; i >= 1; i--) mat[r1][i + 1] = mat[r1][i];
		mat[r1][1] = 0;

		for (int i = r2 + 2; i < r; i++) mat[i - 1][0] = mat[i][0];
		for (int i = 1; i < c; i++) mat[r - 1][i - 1] = mat[r - 1][i];
		for (int i = r - 2; i >= r2; i--) mat[i + 1][c - 1] = mat[i][c - 1];
		for (int i = c - 2; i >= 1; i--) mat[r2][i + 1] = mat[r2][i];
		mat[r2][1] = 0;

		times++;
		if (times == t) {
			int cnt = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (mat[i][j] > 0) cnt += mat[i][j];
				}
			}
			cout << cnt;
			return;
		}
	}
}

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		vector<int> temp(c);
		for (int j = 0; j < c; j++) {
			cin >> temp[j];
			if (temp[j] == -1) {
				if (r1 == 0) r1 = i;
				else r2 = i;
			}
		}
		mat.push_back(temp);
	}
	solve();

	return 0;
}