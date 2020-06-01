#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int strLen = str.size();
	int sum = 0;

	for (int i = 0; i < strLen; i++) {
		int chNum = (int)str[i] - (int)'A';

		int num = chNum / 3;

		if (str[i] < 'S') {
			num += 2;
		}
		else if (str[i] == 'S') {
			num += 1;
		}
		else if (str[i] < 'V') {
			num += 2;
		}
		else if (str[i] == 'V') {
			num += 1;
		}
		else if (str[i] < 'Y') {
			num += 2;
		}
		else {
			num += 1;
		}

		sum += num + 1;
	}

	cout << sum << endl;

	return 0;
}