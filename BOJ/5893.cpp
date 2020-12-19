#include <iostream>
#include <string>
using namespace std;

string addBinary(string s1, string s2) {
	string ret;
	int len = s1.length();
	int carry = 0;
	for (int i = len - 1; i >= 0; i--) {
		int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
		ret = to_string(sum % 2) + ret;
		carry = sum / 2;
	}
	if (carry > 0) ret = "1" + ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	string s1 = str + "0000";
	string s2 = "0000" + str;
	cout << addBinary(s1, s2);

	return 0;
}