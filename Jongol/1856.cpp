#include <iostream>
using namespace std;

int arr[100][100];
int n, m, num = 1;

void fill() {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) arr[i][j] = num++;
		}
		else {
			for (int j = m - 1; j >= 0; j--) arr[i][j] = num++;
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	fill();
	print();

	return 0;
}