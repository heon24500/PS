#include <iostream>
using namespace std;

bool isUjin(string str) {
	int len = str.length();
	for (int i = 1; i < len; i++) {
		string s1 = str.substr(0, i);
		string s2 = str.substr(i, len - i);
		long long r1 = 1, r2 = 1;
		for (int j = 0; s1[j]; j++) {
			r1 *= s1[j] - '0';
		}
		for (int j = 0; s2[j]; j++) {
			r2 *= s2[j] - '0';
			if (r2 > r1) break;
		}
		if (r1 == r2) return true;
	}
	return false;
}

int main() {
	string str;
	cin >> str;
	if (isUjin(str)) cout << "YES";
	else cout << "NO";

	return 0;
}