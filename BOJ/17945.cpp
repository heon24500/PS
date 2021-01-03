#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = -1000; i <= 1000; i++) {
		if (i * i + 2 * a * i + b == 0) cout << i << " ";
	}

	return 0;
}