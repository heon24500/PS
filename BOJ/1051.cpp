#include <iostream>
using namespace std;

const int N = 50, M = 50;
char mat[N][M];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int ans = 1;
	for (int sz = 1; sz < n; sz++) {
		bool flag = false;
		for (int i = 0; i < n - sz; i++) {
			for (int j = 0; j < m - sz; j++) {
				if (mat[i][j] == mat[i + sz][j] && mat[i][j] == mat[i][j + sz] && mat[i][j] == mat[i + sz][j + sz]) {
					ans = sz + 1;
					flag = true;
				}
				if (flag) break;
			}
			if (flag) break;
		}
	}
	cout << ans * ans;

	return 0;
}
