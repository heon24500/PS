#include <iostream>
using namespace std;

const int R = 250, C = 250;
int r, c, zr, zc;
char src_mat[R][C], dest_mat[R][C];

void fill(int y, int x) {
	for (int i = y * zr; i < y * zr + zr; i++) {
		for (int j = x * zc; j < x * zc + zc; j++) {
			dest_mat[i][j] = src_mat[y][x];
		}
	}
}

void print() {
	for (int i = 0; i < r * zr; i++) {
		for (int j = 0; j < c * zc; j++) {
			cout << dest_mat[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> zr >> zc;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> src_mat[i][j];
			fill(i, j);
		}
	}

	print();

	return 0;
}