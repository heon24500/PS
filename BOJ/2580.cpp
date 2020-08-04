/* 2580. ½ºµµÄí */
#include <iostream>
using namespace std;

const int N = 9;
int mat[N][N];

bool isPossible(int y, int x, int n)
{
	for (int i = 0; i < N; i++) {
		if (mat[y][i] == n || mat[i][x] == n) return false;
	}

	int ny = (y / 3) * 3;
	int nx = (x / 3) * 3;
	for (int i = ny; i < ny + 3; i++) {
		for (int j = nx; j < nx + 3; j++) {
			if (mat[i][j] == n) return false;
		}
	}

	return true;
}

void solve(int n)
{
	int y = n / N;
	int x = n % N;

	if (n == N * N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << mat[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	if (mat[y][x] != 0) solve(n + 1);
	else {
		for (int k = 1; k <= 9; k++) {
			if (!isPossible(y, x, k)) continue;
			mat[y][x] = k;
			solve(n + 1);
			mat[y][x] = 0;
		}
	}
}

int main()
{
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	solve(0);

	return 0;
}