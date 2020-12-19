#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		string str;
		cin >> str;
		if (str == "#") break;

		string ans;
		for (int i = 0; str[i]; i++) {
			if (str[i] == 'b') ans = "d" + ans;
			else if (str[i] == 'd') ans = "b" + ans;
			else if (str[i] == 'p') ans = "q" + ans;
			else if (str[i] == 'q') ans = "p" + ans;
			else if (str[i] == 'i' || str[i] == 'o' || str[i] == 'v' || str[i] == 'w' || str[i] == 'x') ans = str[i] + ans;
			else {
				ans = "INVALID";
				break;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}