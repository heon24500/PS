#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	int ans = 1;
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) {
			ans = 0;
			break;
		}
	}
	cout << ans;

	return 0;
}