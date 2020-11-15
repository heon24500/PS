#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string s;
		getline(cin, s);
		if (s == "") break;

		int cnt[4] = { 0 };
		for (int i = 0; s[i]; i++) {
			if (s[i] >= 'a' && s[i] <= 'z') cnt[0]++;
			if (s[i] >= 'A' && s[i] <= 'Z') cnt[1]++;
			if (s[i] >= '0' && s[i] <= '9') cnt[2]++;
			if (s[i] == ' ') cnt[3]++;
		}

		for (int i = 0; i < 4; i++) cout << cnt[i] << " ";
		cout << '\n';
	}

	return 0;
}