#include <iostream>
#include <string>
using namespace std;

int IsGroupWord(string);

int main() {
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (IsGroupWord(str)) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}

int IsGroupWord(string str) {
	int chFlag[26];
	for (int i = 0; i < 26; i++) {
		chFlag[i] = 0;
	}

	int strLen = str.size();

	int ch = (int)str[0] - (int)'a';
	chFlag[ch] = 1;

	for (int i = 1; i < strLen; i++) {
		int new_ch = (int)str[i] - (int)'a';

		if (ch != new_ch) {
			if (chFlag[new_ch] == 1) {
				return 0;
			}
			else {
				chFlag[new_ch] = 1;
			}
		}

		ch = new_ch;
	}

	return 1;
}