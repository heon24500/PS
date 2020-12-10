#include <iostream>
using namespace std;

int arr[100][100];
int n, m;

void print() {
	if (m == 1) {
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) for (int j = 0; j <= i; j++) arr[i][j] = cnt++;
			else for (int j = i; j >= 0; j--) arr[i][j] = cnt++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
	}
	else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) cout << "  ";
			for (int j = 2 * (n - i) + 1; j > 0; j--) cout << i - 1 << " ";
			cout << '\n';
		}
	}
	else if (m == 3) {
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt; j++) cout << j << " ";
			cout << '\n';
			if (i > n / 2) cnt--;
			else cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	if (n >= 1 && n <= 100 && n % 2 != 0 && m >= 1 && m <= 3) print();
	else cout << "INPUT ERROR!";

	return 0;
}