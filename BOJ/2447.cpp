/* 2447. º° Âï±â - 10 */
#include <iostream>
#include <vector>
using namespace std;

char a[7000][7000];

void Stars(int y, int x, int n) {
	if (n == 1) {
		a[y][x] = '*';
		return;
	}

	int tn = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			else Stars(y + (i * tn), x + (j * tn), tn);
		}
	}
}

void PrintStars(int n) {
	Stars(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = ' ';
		}
	}

	PrintStars(n);


	return 0;
}