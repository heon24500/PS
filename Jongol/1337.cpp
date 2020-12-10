#include <iostream>
using namespace std;

int arr[100][100];
int n;

void fill() {
	int cnt = 0, dir = 0, m = n, i = -1, j = -1;
	while (m) {
		for (int k = 0; k < m; k++) {
			if (dir == 0) arr[++i][++j] = cnt++;
			else if (dir == 1) arr[i][--j] = cnt++;
			else if (dir == 2) arr[--i][j] = cnt++;
		}

		dir = (dir + 1) % 3;
		m--;
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << arr[i][j] % 10 << " ";
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