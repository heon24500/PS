#include <iostream>
using namespace std;

const int N = 30, M = 30;
int comb[N][M];

void init() {
	for (int i = 1; i < M; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << comb[m][n] << '\n';
	}

	return 0;
}