#include <iostream>
using namespace std;

bool is_sosu(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n, ret = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (is_sosu(i)) ret++;
		}
		cout << ret << "\n";
	}

	return 0;
}