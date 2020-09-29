#include <iostream>
using namespace std;

int main() {
	while (true) {
		int num;
		cin >> num;
		if (num == 0) break;

		while (num >= 10) {
			cout << num << ' ';
			int ret = 1;
			while (num > 0) {
				ret *= num % 10;
				num /= 10;
			}
			num = ret;
		}
		cout << num << '\n';
	}

	return 0;
}