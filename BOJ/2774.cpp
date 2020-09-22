#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, cnt[10] = { 0 };
		cin >> x;
		while (x > 0) {
			cnt[x % 10] = 1;
			x /= 10;
		}

		int ret = 0;
		for (int i = 0; i < 10; i++) {
			if (cnt[i] == 1) ret++;
		}
		cout << ret << '\n';
	}

	return 0;
}