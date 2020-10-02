#include <iostream>
using namespace std;

const int N = 100, M = 100;
int n, m;
int cnt[5];
char mat[5 * M + 1][5 * N + 1];

void countBlind(int y, int x) {
	int ret = 0;
	for (int i = y; i < y + 4; i++) {
		if (mat[i][x] == '*') ret++;
		else {
			cnt[ret]++;
			return;
		}
	}
	cnt[ret]++;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < 5 * m + 1; i++) {
		for (int j = 0; j < 5 * n + 1; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i < 5 * m + 1; i += 5) {
		for (int j = 1; j < 5 * n + 1; j += 5) {
			countBlind(i, j);
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << cnt[i] << ' ';
	}

	return 0;
}