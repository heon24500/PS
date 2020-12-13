#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	string str;
	getline(cin, str);
	while (t--) {
		getline(cin, str);

		int sum = 0, num = 0;
		for (int i = 0; str[i]; i++) {
			if (str[i] == ' ') {
				sum += num;
				num = 0;
			}
			else {
				num *= 10;
				num += str[i] - '0';
			}
		}
		sum += num;
		cout << sum << '\n';
	}

	return 0;
}