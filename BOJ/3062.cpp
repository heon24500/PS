#include <iostream>
#include <string>
using namespace std;

string rev(string str) {
	string ret;
	int len = str.length();
	for (int i = len - 1; i >= 0; i--) {
		ret += str[i];
	}
	return ret;
}

string strPlus(string s1, string s2) {
	int sum = stoi(s1) + stoi(s2);
	return to_string(sum);
}

bool isSame(string str) {
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		string rev_str = rev(str);
		string ret = strPlus(str, rev_str);
		if (isSame(ret)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}