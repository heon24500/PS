#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	string str;
	getline(cin, str);

	while (t--) {
		int cnt[150] = { 0 };

		getline(cin, str);
		for (int i = 0; str[i]; i++) {
			if (str[i] == ' ') continue;
			cnt[str[i]]++;
		}

		int maxi = 0;
		bool flag = true;
		for (int i = 'a'; i <= 'z'; i++) {
			if (cnt[maxi] < cnt[i]) {
				maxi = i;
				flag = false;
			}
			else if (cnt[maxi] == cnt[i]) flag = true;
		}
		if (flag) cout << "?\n";
		else cout << (char)maxi << '\n';
	}

	return 0;
}