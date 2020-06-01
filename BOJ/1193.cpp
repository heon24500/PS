#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int X;
	cin >> X;

	int part = 0, cnt = 0;
	while (cnt < X) {
		part++;
		for (int i = 1; i <= part; i++) {
			cnt++;
		}
	}

	for (int i = 1; i < part; i++) {
		X -= i;
	}

	int a, b;
	if (part % 2 == 0) {
		a = X;
		b = part - X + 1;
	}
	else {
		a = part - X + 1;
		b = X;
	}

	cout << a << "/" << b;
}