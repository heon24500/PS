#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		for (int i = 0; s[i]; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
		}
		cout << s << '\n';
	}

	return 0;
}