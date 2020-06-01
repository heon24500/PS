#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int nums[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	cin >> a >> b >> c;
	int result = a * b * c;

	while (true) {
		int num = result % 10;

		nums[num]++;

		if ((result / 10) == 0) {
			break;
		}
		else {
			result /= 10;
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << nums[i] << endl;
	}

	return 0;
}