#include <iostream>
using namespace std;

const int N = 65;
int n;
char mat[N][N];
string ans;

bool isFinish(int y, int x, int width) {
	for (int i = y; i < y + width; i++) {
		for (int j = x; j < x + width; j++) {
			if (mat[y][x] != mat[i][j]) return false;
		}
	}
	return true;
}

void solve(int y, int x, int width) {
	if (isFinish(y, x, width)) {
		if (mat[y][x] == '1') ans += '1';
		else ans += '0';
		return;
	}

	ans += '(';
	solve(y, x, width / 2);
	solve(y, x + width / 2, width / 2);
	solve(y + width / 2, x, width / 2);
	solve(y + width / 2, x + width / 2, width / 2);
	ans += ')';
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	solve(0, 0, n);
	cout << ans;

	return 0;
}