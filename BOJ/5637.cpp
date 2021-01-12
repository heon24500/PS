#include <iostream>
using namespace std;

int main() {
	string str = "", ans;
	int max_len = 0;

	while (str != "E-N-D") {
		cin >> str;
		string temp = "";
		for (int i = 0; str[i]; i++) {
			if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == '-') temp += str[i];
			if (str[i] >= 'A' && str[i] <= 'Z') temp += str[i] + 32;
		}

		if (max_len < temp.length()) {
			max_len = temp.length();
			ans = temp;
		}
	}
	cout << ans;

	return 0;
}