#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int ans = 0, temp = 0, value = 0;
	bool isMinus = false;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '+') {
			if (isMinus) {
				temp += value;
				value = 0;
			}
			else {
				ans += value;
				value = 0;
			}
		}
		else if (str[i] == '-') {
			if (isMinus) {
				temp += value;
				ans -= temp;
				temp = 0;
				value = 0;
			}
			else {
				isMinus = true;
				ans += value;
				value = 0;
			}
		}
		else value = (value * 10) + str[i] - '0';
	}
	if (isMinus) {
		temp += value;
		ans -= temp;
	}
	else ans += value;
	cout << ans;

	return 0;
}