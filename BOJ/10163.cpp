#include <iostream>
using namespace std;

const int N = 101;
int mat[N][N];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y1 + y2; y++) {
			for (int x = x1; x < x1 + x2; x++) {
				mat[y][x] = i;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (mat[y][x] == i) cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}