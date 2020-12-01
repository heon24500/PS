#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		int sum = 0;
		for (int i = 0; str[i]; i++) {
			int num = str[i] - '0';
			if (i % 2 == 1) sum += num;
			else {
				num *= 2;
				if (num >= 10) {
					sum += num / 10;
					sum += num % 10;
				}
				else sum += num;
			}
		}

		if (sum % 10 == 0) cout << "T\n";
		else cout << "F\n";
	}

	return 0;
}