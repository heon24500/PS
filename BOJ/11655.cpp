#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] + 13 > 'z') s[i] = s[i] - 'z' - 1 + 'a';
			s[i] += 13;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] + 13 > 'Z') s[i] = s[i] - 'Z' - 1 + 'A';
			s[i] += 13;
		}
	}
	cout << s;

	return 0;
}