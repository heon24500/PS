#include <iostream>
using namespace std;

int n, m;

void print() {
	if (m == 1) {
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt; j++) cout << "*";
			cout << '\n';
			if (i > n / 2) cnt--;
			else cnt++;
		}
	}
	else if (m == 2) {
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n / 2 - cnt; j++) cout << " ";
			for (int j = 1; j <= cnt; j++) cout << "*";
			cout << '\n';
			if (i > n / 2) cnt--;
			else cnt++;
		}
	}
	else if (m == 3) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt; j++) cout << " ";
			for (int j = 1; j <= n - 2 * cnt; j++) cout << "*";
			cout << '\n';
			if (i > n / 2) cnt--;
			else cnt++;
		}
	}
	else if (m == 4) {
		int cnt = 0, k = n / 2 + 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= cnt; j++) cout << " ";
			for (int j = 1; j <= k; j++) cout << "*";
			cout << '\n';
			if (i > n / 2) k++;
			else {
				cnt++;
				k--;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	if (n >= 1 && n <= 100 && n % 2 != 0 && m >= 1 && m <= 4) print();
	else cout << "INPUT ERROR!";

	return 0;
}