#include <iostream>
using namespace std;

bool is_sosu(int n) {
	if (n == 1) return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ret = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (is_sosu(num)) ret++;
	}
	cout << ret;

	return 0;
}