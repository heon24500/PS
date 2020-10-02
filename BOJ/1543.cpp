#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, word;
	getline(cin, str);
	getline(cin, word);

	int max_len = str.length();
	int len = word.length();
	int cnt = 0, i = 0;
	while (i < max_len) {
		if (str.substr(i, len) != word) {
			i++;
			continue;
		}
		cnt++;
		i = i + len;
	}
	cout << cnt;
}