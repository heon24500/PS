#include <iostream>
using namespace std;

int main() {
	int num[8];
	int flag = 0;

	for (int i = 0; i < 8; i++) {
		cin >> num[i];
	}

	if (num[0] == 1) {
		for (int i = 0; i < 7; i++) {
			if (num[i] < num[i + 1]) {
				flag = 1;
			}
			else {
				cout << "mixed" << endl;
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			cout << "ascending" << endl;
		}
	}
	else if (num[0] == 8) {
		for (int i = 0; i < 7; i++) {
			if (num[i] > num[i + 1]) {
				flag = 1;
			}
			else {
				cout << "mixed" << endl;
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			cout << "descending" << endl;
		}
	}
	else {
		cout << "mixed" << endl;
	}

	return 0;
}