#include <iostream>
using namespace std;

#define N 105

int coor[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = y; j < y + 10; j++) {
			for (int k = x; k < x + 10; k++) {
				coor[j][k] = 1;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (coor[i][j] == 1) ret++;
		}
	}

	cout << ret;

	return 0;
}