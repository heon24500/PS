#include <iostream>
#include <string>
using namespace std;

int main() {
	int ch[26];
	for (int i = 0; i < 26; i++) {
		ch[i] = -1;
	}

	string str;
	cin >> str;

	int str_len = str.size();

	for (int i = 0; i < str_len; i++) {
		int inCh = (int)str[i] - (int)'a';

		if (ch[inCh] == -1) {
			ch[inCh] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << ch[i] << " ";
	}

	cout << endl;

	return 0;
}