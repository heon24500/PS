#include <iostream>
using namespace std;

int arr[100][100];
int n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void fill() {
	int cnt = 1, m = n, dir = 1;
	for (int i = 0; i < n; i++) arr[0][i] = cnt++;
	int y = 0, x = n - 1;
	while (m--) {
		for (int i = 0; i < m; i++) {
			y += dy[dir];
			x += dx[dir];
			arr[y][x] = cnt++;
		}
		dir = (dir + 1) % 4;

		for (int i = 0; i < m; i++) {
			y += dy[dir];
			x += dx[dir];
			arr[y][x] = cnt++;
		}
		dir = (dir + 1) % 4;
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fill();
	print();

	return 0;
}