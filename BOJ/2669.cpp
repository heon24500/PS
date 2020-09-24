#include <iostream>
using namespace std;

const int Y = 101;
int mat[Y][Y];

int main() {
	for (int i = 0; i < 4; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				mat[y][x] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (mat[i][j] == 1) cnt++;
		}
	}
	cout << cnt;

	return 0;
}