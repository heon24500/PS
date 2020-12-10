#include <iostream>
using namespace std;

int n, m;

void print() {
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cout << "*";
			}
			cout << '\n';
		}
	}
	else if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				cout << "*";
			}
			cout << '\n';
		}
	}
	else if (m == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) cout << " ";
			for (int j = 0; j < 2 * (i + 1) - 1; j++) cout << "*";
			cout << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	if (n >= 1 && n <= 100 && m >= 1 && m <= 3) print();
	else cout << "INPUT ERROR!";

	return 0;
}