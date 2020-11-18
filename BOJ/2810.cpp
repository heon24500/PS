#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int ans = 1;
	bool flag = false;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'S') ans++;
		else {
			if (flag) {
				ans++;
				flag = false;
			}
			else flag = true;
		}
	}
	if (ans > n) cout << n;
	else cout << ans;

	return 0;
}