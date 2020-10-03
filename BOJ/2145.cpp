#include <iostream>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		while (n >= 10) {
			int sum = 0;
			while (n > 0) {
				sum += n % 10;
				n /= 10;
			}
			n = sum;
		}

		cout << n << '\n';
	}

	return 0;
}