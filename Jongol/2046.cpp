#include <iostream>
using namespace std;

int arr[100][100];
int n, m, num = 1;

void fill() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m == 1) arr[i][j] = i + 1;
			else if (m == 2) {
				if (i % 2 == 0) arr[i][j] = j + 1;
				else arr[i][j] = n - j;
			}
			else if (m == 3) {
				arr[i][j] = (i + 1) * (j + 1);
			}
		}
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

	cin >> n >> m;
	fill();
	print();

	return 0;
}