#include <iostream>
using namespace std;

bool is_equal(int n) {
	int sum_10 = 0, sum_12 = 0, sum_16 = 0;
	int temp = n;
	while (n > 0) {
		sum_10 += n % 10;
		n /= 10;
	}
	n = temp;

	while (n > 0) {
		sum_12 += n % 12;
		n /= 12;
	}
	n = temp;

	while (n > 0) {
		sum_16 += n % 16;
		n /= 16;
	}

	if (sum_10 == sum_12 && sum_10 == sum_16) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1000; i <= 9999; i++) {
		if (is_equal(i)) cout << i << "\n";
	}

	return 0;
}