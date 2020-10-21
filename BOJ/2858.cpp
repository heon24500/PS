#include <iostream>
using namespace std;

int main() {
	int r, b;
	cin >> r >> b;
	int sum = r + b;
	for (int l = 3; l < sum; l++) {
		for (int w = 3; w <= l; w++) {
			if (l * w != sum) continue;
			if (b != (l - 2) * (w - 2)) continue;
			cout << l << " " << w;
			return 0;
		}
	}

	return 0;
}