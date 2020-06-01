#include <iostream>
using namespace std;

int Hansu(int);

int main() {
	int n;

	cin >> n;

	int numHansu = Hansu(n);

	cout << numHansu << endl;

	return 0;
}

int Hansu(int n) {
	int cnt = 99;

	if (n < 100) {
		return n;
	}
	else {
		for (int i = 100; i <= n; i++) {
			int a = i % 10;
			int b = i / 10;
			int c = b / 10;
			b %= 10;

			if ((a - b) == (b - c)) {
				cnt++;
			}
		}

		return cnt;
	}
}