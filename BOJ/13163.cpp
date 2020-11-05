#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s, ans;
	getline(cin, s);
	while (n--) {
		ans = "god";
		getline(cin, s);

		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				flag = false;
				continue;
			}
			if (flag) continue;
			if (s[i] != ' ') ans += s[i];
		}
		cout << ans << '\n';
	}

	return 0;
}
