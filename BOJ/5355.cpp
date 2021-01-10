#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		double num;
		cin >> num;

		string str;
		getline(cin, str);
		for (int i = 0; str[i]; i++) {
			if (str[i] == '@') num *= 3.00;
			if (str[i] == '%') num += 5.00;
			if (str[i] == '#') num -= 7.00;
		}

		cout << fixed;
		cout.precision(2);
		cout << num << '\n';
	}

	return 0;
}