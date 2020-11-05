#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, ans;
	getline(cin, s);

	bool flag = false;
	string str;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			ans += str + " ";
			str = "";
			continue;
		}

		if (s[i] == '<') {
			flag = true;
			ans += str;
			str = "";
		}

		if (flag) str += s[i];
		else str = s[i] + str;

		if (s[i] == '>') {
			flag = false;
			ans += str;
			str = "";
		}
	}
	ans += str;
	cout << ans;

	return 0;
}
