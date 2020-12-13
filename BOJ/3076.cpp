#include <iostream>
using namespace std;

const int R = 100, C = 100;
int r, c, a, b;
char mat[R][C];

void fill(int y, int x, int n) {
	for (int i = y * a; i < y * a + a; i++) {
		for (int j = x * b; j < x * b + b; j++) {
			if (n == 0) mat[i][j] = 'X';
			else mat[i][j] = '.';
		}
	}
}

void print() {
	for (int i = 0; i < r * a; i++) {
		for (int j = 0; j < c * b; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	cin >> a >> b;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			fill(i, j, (i + j) % 2);
		}
	}

	print();

	return 0;
}