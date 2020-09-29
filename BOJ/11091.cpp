#include <iostream>
#include <string>
using namespace std;

int cnt[50];

int main() {
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		int len = str.length();
		for (int j = 0; j < len; j++) {
			if (str[j] >= 'A' && str[j] <= 'Z') cnt[str[j] - 'A'] = 1;
			if (str[j] >= 'a' && str[j] <= 'z') cnt[str[j] - 'a'] = 1;
		}

		len = 'z' - 'a';
		bool flag = true;
		for (int j = 0; j <= len; j++) {
			if (flag && cnt[j] == 0) {
				flag = false;
				cout << "missing ";
			}

			if (cnt[j] == 0) cout << (char)('a' + j);
			cnt[j] = 0;
		}
		if (flag) cout << "pangram";
		cout << '\n';
	}

	return 0;
}