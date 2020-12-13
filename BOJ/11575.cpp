#include <iostream>
using namespace std;

string solve(string s, int a, int b) {
	string ret;
	for (int i = 0; s[i]; i++) {
		ret += 'A' + (a * (s[i] - 'A') + b) % 26;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		cout << solve(s, a, b) << '\n';
	}

	return 0;
}