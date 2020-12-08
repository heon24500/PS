#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		cin >> str;
		if (str == "#") break;

		int n = str.length();
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (str[i] == '1') cnt++;
			cout << str[i];
		}

		if (str[n - 1] == 'e') {
			if (cnt % 2 == 0) cout << "0\n";
			else cout << "1\n";
		}
		else {
			if (cnt % 2 == 0) cout << "1\n";
			else cout << "0\n";
		}
	}

	return 0;
}