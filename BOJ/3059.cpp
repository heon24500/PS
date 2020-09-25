#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt[100] = { 0 };
		for (int i = 0; i < s.length(); i++) {
			cnt[s[i]] = 1;
		}
		int ret = 0;
		for (int i = 65; i < 91; i++) {
			if (cnt[i] != 1) ret += i;
		}
		cout << ret << '\n';
	}

	return 0;
}