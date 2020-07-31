/* 9663. N-Qeen */
#include <iostream>
using namespace std;

const int N = 20;
int mat[N];
int n, cnt;

bool IsPossible(int num) {
	for (int i = 0; i < num; i++) {
		if (mat[num] == mat[i] || abs(num - i) == abs(mat[num] - mat[i])) return false;
	}
	return true;
}

void Solve(int num) {
	if (num == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		mat[num] = i;
		if (IsPossible(num)) Solve(num + 1);
		mat[num] = 0;
	}
}

int main() {
	cin >> n;
	Solve(0);
	cout << cnt;

	return 0;
}