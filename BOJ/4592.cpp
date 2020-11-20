#include <iostream>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		int before = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (i > 0 && before == num) continue;
			before = num;
			cout << num << " ";
		}
		cout << "$\n";
	}

	return 0;
}