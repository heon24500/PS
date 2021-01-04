#include <iostream>
using namespace std;

const int N = 10, M = 10;
int n, m;
char mat[N][M];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			cout << mat[i][j];
		}
		cout << '\n';
	}

	return 0;
}