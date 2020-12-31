#include <iostream>
using namespace std;

const int M = 101, N = 101;
int t, m, n, ans;
int mat[M][N];

void solve() {
	ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j > 0; j--) {
			if (mat[j][i] == 0) {
				for (int k = 0; k < j; k++) {
					if (mat[k][i] == 1) {
						swap(mat[j][i], mat[k][i]);
						ans += j - k;
						break;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}

		solve();
		cout << ans << '\n';
	}

	return 0;
}