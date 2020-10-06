#include <iostream>
using namespace std;

const int N = 101, M = 101;
int n, m;
int mat[N][M];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			cout << mat[i][j] + num << ' ';
		}
		cout << '\n';
	}

	return 0;
}