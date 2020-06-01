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

	int t;
	cin >> t;
	while (t--) {
		int n, i, ret;
		cin >> n;
		for (i = 2; i <= n / 2; i++) {
			if (is_sosu(i) && is_sosu(n - i)) ret = i;
		}
		cout << ret << " " << n - ret << "\n";
	}

	return 0;
}