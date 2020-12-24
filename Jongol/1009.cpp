#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		cin >> str;
		if (str == "0") break;
		int sum = 0;
		bool flag = false;
		for (int i = str.length() - 1; i >= 0; i--) {
			if (str[i] != '0') flag = true;
			if (flag) {
				cout << str[i];
				sum += str[i] - '0';
			}
		}
		cout << " " << sum << '\n';

	}

	return 0;
}