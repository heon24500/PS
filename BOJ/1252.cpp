#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2, ret;
	cin >> s1 >> s2;

	if (s1.length() < s2.length()) swap(s1, s2);
	int len1 = s1.length();
	int len2 = s2.length() - 1;
	int carry = 0;
	for (int i = len1 - 1; i >= 0; i--) {
		int num = (s1[i] - '0') + carry;
		if (len2 >= 0) num += s2[len2--] - '0';
		carry = num / 2;
		num %= 2;
		ret = to_string(num) + ret;
	}
	if (carry) ret = "1" + ret;

	int len = ret.length();
	int i;
	for (i = 0; i < len; i++) {
		if (ret[i] == '1') break;
	}
	if (i == len) ret = "0";
	else ret = ret.substr(i);
	cout << ret;

	return 0;
}