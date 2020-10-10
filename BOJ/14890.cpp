#include <iostream>
using namespace std;

const int N = 100;
int n, l, ans;
int mat[N][N];

void solve() {
	// 행 검사
	for (int i = 0; i < n; i++) {
		bool flag = true;
		bool visited[N] = { 0 };
		for (int j = 1; j < n; j++) {
			int dif = mat[i][j] - mat[i][j - 1];
			if (dif == 0) continue;
			if (dif > 1 || dif < -1) {
				flag = false;
				break;
			}

			if (dif == 1) {
				for (int x = j - l; x < j; x++) {
					if (x >= 0 && mat[i][x] == mat[i][j - 1] && !visited[x]) {
						visited[x] = true;
						continue;
					}
					flag = false;
					break;
				}
				if (!flag) break;
			}
			if (dif == -1) {
				for (int x = j; x < j + l; x++) {
					if (x < n && mat[i][x] == mat[i][j] && !visited[x]) {
						visited[x] = true;
						continue;
					}
					flag = false;
					break;
				}
				if (!flag) break;
			}
		}
		if (flag) ans++;
	}

	// 열 검사
	for (int i = 0; i < n; i++) {
		bool flag = true;
		bool visited[N] = { 0 };
		for (int j = 1; j < n; j++) {
			int dif = mat[j][i] - mat[j - 1][i];
			if (dif == 0) continue;
			if (dif > 1 || dif < -1) {
				flag = false;
				break;
			}

			if (dif == 1) {
				for (int x = j - l; x < j; x++) {
					if (x >= 0 && mat[x][i] == mat[j - 1][i] && !visited[x]) {
						visited[x] = true;
						continue;
					}
					flag = false;
					break;
				}
				if (!flag) break;
			}
			if (dif == -1) {
				for (int x = j; x < j + l; x++) {
					if (x < n && mat[x][i] == mat[j][i] && !visited[x]) {
						visited[x] = true;
						continue;
					}
					flag = false;
					break;
				}
				if (!flag) break;
			}
		}
		if (flag) ans++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	solve();
	cout << ans;

	return 0;
}