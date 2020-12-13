#include <iostream>
using namespace std;

string solve(string str) {
	string ret;
	bool isJava = false;
	bool isCpp = false;
	bool upper = false;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '_') {
			if (i == 0 || i == str.length() - 1) return "Error!";
			if (isJava) return "Error!";
			if (str[i - 1] == '_') return "Error!";
			isCpp = true;
			upper = true;
		}
		else {
			if (str[i] >= 'a' && str[i] <= 'z') {
				if (upper) {
					ret += str[i] - 32;
					upper = false;
				}
				else ret += str[i];
			}
			else if (str[i] >= 'A' && str[i] <= 'Z') {
				if (i == 0) return "Error!";
				if (isCpp) return "Error!";
				isJava = true;
				ret += "_";
				ret += str[i] + 32;
			}
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	cout << solve(str);

	return 0;
}