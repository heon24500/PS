#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = 100;
int n, ans1, ans2;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
char mat[N][N];
bool check1[N][N], check2[N][N];
queue<pii> q;

bool isBoundary(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n) return true;
	return false;
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check1[i][j]) {
				q.push({ i, j });
				check1[i][j] = true;

				ans1++;

				while (!q.empty()) {
					pii now = q.front();
					q.pop();

					int y = now.first;
					int x = now.second;
					for (int k = 0; k < 4; k++) {
						int ty = y + dy[k];
						int tx = x + dx[k];
						if (isBoundary(ty, tx) || check1[ty][tx] || mat[y][x] != mat[ty][tx]) continue;
						q.push({ ty, tx });
						check1[ty][tx] = true;
					}
				}
			}
			if (!check2[i][j]) {
				q.push({ i, j });
				check2[i][j] = true;

				ans2++;

				while (!q.empty()) {
					pii now = q.front();
					q.pop();

					int y = now.first;
					int x = now.second;
					for (int k = 0; k < 4; k++) {
						int ty = y + dy[k];
						int tx = x + dx[k];
						if (isBoundary(ty, tx) || check2[ty][tx]) continue;
						if (mat[y][x] == mat[ty][tx] || ((mat[y][x] == 'R' || mat[y][x] == 'G') && (mat[ty][tx] == 'R' || mat[ty][tx] == 'G'))) {
							q.push({ ty, tx });
							check2[ty][tx] = true;
						}
					}
				}
			}
		}
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

	solve();
	cout << ans1 << " " << ans2;

	return 0;
}