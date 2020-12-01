#include <iostream>
using namespace std;

const int N = 100, M = 100, K = 100;
int n, m, k;
int a[N][M], b[M][K], ans[N][K];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			ans[i][j] = 0;
			for (int l = 0; l < m; l++) {
				ans[i][j] += a[i][l] * b[l][j];
			}
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}