#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		for (int i = 0; s[i]; i++) {
			if (i == n - 1) continue;
			cout << s[i];
		}
		cout << '\n';
	}

	return 0;
}
