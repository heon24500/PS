#include <iostream>
using namespace std;

const int N = 11;
int n, max_value = -1e9, min_value = 1e9;
int mat[N], ops[4];

void solve(int depth, int num) {
	if (depth == n) {
		if (max_value < num) max_value = num;
		if (min_value > num) min_value = num;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (ops[i] == 0) continue;
		ops[i]--;
		if (i == 0) solve(depth + 1, num + mat[depth]);
		else if (i == 1) solve(depth + 1, num - mat[depth]);
		else if (i == 2) solve(depth + 1, num * mat[depth]);
		else if (i == 3) solve(depth + 1, num / mat[depth]);
		ops[i]++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> ops[i];
	}

	solve(1, mat[0]);
	cout << max_value << '\n' << min_value << '\n';

	return 0;
}