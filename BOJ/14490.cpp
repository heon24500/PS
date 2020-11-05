#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n1 = 0, n2 = 0;
	bool flag = false;
	for (int i = 0; s[i]; i++) {
		if (s[i] == ':') {
			flag = true;
			continue;
		}

		if (!flag) n1 = (n1 * 10) + s[i] - '0';
		else n2 = (n2 * 10) + s[i] - '0';
	}

	int n = min(n1, n2);
	for (int i = n; i >= 1; i--) {
		if (n1 % i == 0 && n2 % i == 0) {
			cout << n1 / i << ":" << n2 / i;
			break;
		}
	}

	return 0;
}
