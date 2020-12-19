#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	string now, ans;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '.') {
			if (now.length() > 0) {
				if (now.length() % 2 != 0) {
					ans = "-1";
					now = "";
					break;
				}
				else {
					int idx = 0;
					while (idx != now.length()) {
						if (now.length() - idx >= 4) {
							ans += "AAAA";
							idx += 4;
						}
						else {
							ans += "BB";
							idx += 2;
						}
					}
				}
			}

			now = "";
			ans += ".";
		}
		else now += str[i];
	}
	if (now.length() > 0) {
		if (now.length() % 2 != 0) {
			ans = "-1";
		}
		else {
			int idx = 0;
			while (idx != now.length()) {
				if (now.length() - idx >= 4) {
					ans += "AAAA";
					idx += 4;
				}
				else {
					ans += "BB";
					idx += 2;
				}
			}
		}
	}
	cout << ans;

	return 0;
}