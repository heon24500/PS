#include <iostream>
using namespace std;

int main() {
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		int inNum;

		cin >> inNum;

		if (inNum < 40) {
			inNum = 40;
		}

		sum += inNum;
	}

	int grade = sum / 5;
	cout << grade << endl;

	return 0;
}