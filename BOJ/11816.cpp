#include <iostream>
#include <string>
using namespace std;

int solve(string s) {
	if (s.length() == 1) return s[0] - '0';
	if (s.length() == 2) {
		if (s[0] == '0') return s[1] - '0';
		return stoi(s);
	}

	if (s[0] == '0') {
		if (s[1] == 'x') {
			int num = 0;
			for (int i = 2; s[i]; i++) {
				int n;
				if (s[i] >= 'a') n = s[i] - 'a' + 10;
				else n = s[i] - '0';
				num = (num * 16) + n;
			}
			return num;
		}
		else {
			int num = 0;
			for (int i = 1; s[i]; i++) num = (num * 8) + s[i] - '0';
			return num;
		}
	}

	return stoi(s);
}

int main() {
	string s;
	cin >> s;
	int num = solve(s);
	cout << num;

	return 0;
}
