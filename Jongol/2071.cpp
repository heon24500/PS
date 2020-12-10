#include <iostream>
using namespace std;

int arr[100][100];
int n, m;

void fill() {
	arr[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
}

void print() {
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) cout << arr[i][j] << " ";
			cout << '\n';
		}
	}
	else if (m == 2) {
		for (int i = n; i >= 1; i--) {
			for (int j = 0; j < n - i; j++) cout << " ";
			for (int j = 1; j <= i; j++) cout << arr[i][j] << " ";
			cout << '\n';
		}
	}
	else if (m == 3) {
		for (int i = 1; i <= n; i++) {
			for (int j = i, k = n; j >= 1; j--, k--) cout << arr[k][j] << " ";
			cout << '\n';
		}
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