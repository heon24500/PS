#include <iostream>
using namespace std;

bool broken[10];

int PressBtn(int x) {
	if (x == 0) {
		if (broken[0]) return 0;
		else return 1;
	}

	int len = 0;
	while (x > 0) {
		len++;
		if (broken[x % 10]) return 0;
		x /= 10;
	}

	return len;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}

	int ans = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		int press = PressBtn(i);
		if (press == 0) continue;

		press += abs(i - n);
		if (ans > press) ans = press;
	}

	cout << ans;

	return 0;
}