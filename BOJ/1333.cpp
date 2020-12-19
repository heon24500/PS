#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, d, tm = 0;
	cin >> n >> l >> d;
	for (int i = 0; i < n; i++) {
		tm += l;
		for (int j = 0; j < 5; j++) {
			if (tm % d == 0) {
				cout << tm;
				return 0;
			}
			tm++;
		}
	}

	while (true) {
		if (tm % d == 0) {
			cout << tm;
			break;
		}
		tm++;
	}

	return 0;
}