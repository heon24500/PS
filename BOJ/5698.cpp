#include <iostream>
#include <string>
using namespace std;

bool isTau(string str) {
	char ch;
	for (int i = 0; str[i]; i++) {
		if (i == 0) ch = str[i];
		else if (str[i - 1] == ' ') {
			int dif = abs(str[i] - ch);
			if (dif != 0 && dif != 32) return false;
		}
	}
	return true;
}

int main() {
	while (true) {
		string str;
		getline(cin, str);
		if (str == "*") break;
		if (isTau(str)) cout << "Y\n";
		else cout << "N\n";
	}

	return 0;
}