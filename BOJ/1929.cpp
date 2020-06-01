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

	int m, n, sum = 0, min = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (is_sosu(i)) cout << i << "\n";
	}

	return 0;
}