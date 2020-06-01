#include <iostream>
#include <algorithm>
using namespace std;

#define N 55
#define M 55

char mat[N][M];

int calc(int y, int x) {
	int ret1 = 0, ret2 = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if ((i - y) % 2 == 0) {
				if ((j - x) % 2 == 0) {
					if (mat[i][j] == 'B') ret1++;
					else ret2++;
				}
				else {
					if (mat[i][j] == 'W') ret1++;
					else ret2++;
				}
			}
			else {
				if ((j - x) % 2 == 0) {
					if (mat[i][j] == 'W') ret1++;
					else ret2++;
				}
				else {
					if (mat[i][j] == 'B') ret1++;
					else ret2++;
				}
			}
		}
	}

	return min(ret1, ret2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int min = 2500;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int ret = calc(i, j);
			if (min > ret) min = ret;
		}
	}

	cout << min;

	return 0;
}