using namespace std;
#include <iostream>

int main() {
	int n, x, a;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> a;

		if (a < x) {
			cout << a << " ";
		}
	}

	return 0;
}