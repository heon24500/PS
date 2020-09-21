#include <iostream>
using namespace std;

int mat[5][5];

int bingo() {
	int cnt_row[5] = { 0 }, cnt_column[5] = { 0 }, diag[2] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cnt_row[i] += mat[i][j];
			cnt_column[i] += mat[j][i];
			if (i == j) diag[0] += mat[i][j];
			if (i + j == 4) diag[1] += mat[i][j];
		}
	}

	int ret = 0;
	for (int i = 0; i < 5; i++) {
		if (cnt_row[i] == 0) ret++;
		if (cnt_column[i] == 0) ret++;
	}
	for (int i = 0; i < 2; i++) {
		if (diag[i] == 0) ret++;
	}

	return ret;
}

void go(int n) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (mat[i][j] == n) {
				mat[i][j] = 0;
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int num;
			cin >> num;
			go(num);
			cnt++;
			if (bingo() >= 3) {
				cout << cnt;
				return 0;
			}
		}
	}

	return 0;
}