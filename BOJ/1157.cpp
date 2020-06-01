#include <iostream>
#include <string>
using namespace std;

int main() {
	int isEqual = 0;

	int ch[26];
	for (int i = 0; i < 26; i++) {
		ch[i] = 0;
	}

	string str;
	cin >> str;

	int str_len = str.size();
	int ch_num = 0;

	for (int i = 0; i < str_len; i++) {
		ch_num;

		if (str[i] >= 'a') {
			ch_num = (int)str[i] - (int)'a';
		}
		else {
			ch_num = (int)str[i] - (int)'A';
		}

		ch[ch_num]++;
	}

	int max_num = ch[0];
	int max_index = 0;

	for (int i = 1; i < 26; i++) {
		if (ch[i] > max_num) {
			max_num = ch[i];
			max_index = i;
			isEqual = 0;
		}
		else if (ch[i] == max_num) {
			isEqual = 1;
		}
	}

	char max_ch = (char)max_index + 'A';

	if (isEqual == 1) {
		cout << "?" << endl;
	}
	else {
		cout << max_ch << endl;
	}

	return 0;
}